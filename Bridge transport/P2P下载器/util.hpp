#pragma once
#include <stdio.h>
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <boost/filesystem.hpp>
#ifdef _WIN32
//windowsͷ�ļ�
#include <WS2tcpip.h>
#include <Iphlpapi.h>//��ȡ������Ϣ�ӿڵ�ͷ�ļ�
#pragma comment(lib, "Iphlpapi.lib")//��ȡ������Ϣ�ӿڵĿ��ļ�����
#pragma comment(lib, "ws2_32.lib")//windows�µ�socket��
#else
//linuxͷ�ļ�
#include <ifaddrs.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#endif

class StringUtil
{
public:
	static int64_t Str2Dig(const std::string &num) {
		std::stringstream tmp;
		tmp << num;
		int64_t res;
		tmp >> res;
		return res;
	}
};

class FileUtil
{
public:
	static int64_t GetFileSize(const std::string &name) {
		return boost::filesystem::file_size(name);
	}
	static bool Write(const std::string &name, const std::string &body, int64_t offset = 0) {
		std::cout << "write data:" << name << " size:" << body.size() <<" ["<<body<<"]\n";
		std::fstream ofs;
		ofs.open(name, std::ios::in | std::ios::out | std::ios::binary);
		if (ofs.is_open() == false) {
			std::cout << "���ļ�ʧ��:" << name << std::endl;
			return false;
		}
		ofs.seekp(offset, std::ios::beg);//��дλ����ת��������ļ���ʼλ�ÿ�ʼƫ��offset��ƫ����
		ofs.write(&body[0], body.size());
		if (ofs.good() == false) {
			std::cerr << "���ļ�д������ʧ��\n";
			ofs.close();
			return false;
		}
		ofs.close();
		return true;
	}
	//ָ�������ʾ����һ������Ͳ���
	//const & ��ʾ����һ�������Ͳ���
	//& ��ʾ����һ����������Ͳ���
	static bool Read(const std::string &name, std::string *body) {
		int64_t filesize = GetFileSize(name);
		body->resize(filesize);

		std::fstream ifs(name, std::ios::in | std::ios::out | std::ios::binary);
		if (ifs.is_open() == false) {
			std::cerr << "���ļ�ʧ��\n";
			return false;
		}
		//std::cout << "Ҫ��ȡ���ļ���С:" << name << ":" << filesize << std::endl;
		ifs.read(&(*body)[0], filesize);
		
		if (ifs.good() == false) {
			std::cerr << "��ȡ�ļ�����ʧ��\n";
			std::cout << *body << std::endl;
			ifs.close();
			return false;
		}
		ifs.close();
		return true;
	}
	static bool ReadRange(const std::string &name, std::string *body, int64_t len, int64_t offset) {
		body->resize(len);
		std::fstream ifs(name, std::ios::in | std::ios::out | std::ios::binary);
		if (ifs.is_open() == false) {
			std::cerr << "���ļ�ʧ��\n";
			return false;
		}
		ifs.seekg(offset, std::ios::beg);
		ifs.read(&(*body)[0], len);

		if (ifs.good() == false) {
			std::cerr << "��ȡ�ļ�����ʧ��\n";
			std::cout << *body << std::endl;
			ifs.close();
			return false;
		}
		ifs.close();
		return true;
	}
};


class Adapter
{
public:
	uint32_t _ip_addr; // �����ϵ�IP��ַ
	uint32_t _mask_addr;//�����ϵ���������
};

class AdapterUtil
{
public:
#ifdef _WIN32
	//windows�µĻ�ȡ������Ϣʵ��
	static bool GetAllAdapter(std::vector<Adapter> *list) {
		PIP_ADAPTER_INFO p_adapters = new IP_ADAPTER_INFO();//����һ��������Ϣ�ṹ�Ŀռ�
		//GetAdaptersInfo win�»�ȡ������Ϣ�Ľӿ�--������Ϣ�п����ж������˴���һ��ָ��
		//��ȡ������Ϣ�п��ܻ�ʧ�ܣ�
		//��Ϊ�ռ䲻�㣬�����һ������Ͳ������������û���������������Ϣ�ռ�չ���ô�С
		uint64_t all_adapter_size = sizeof(IP_ADAPTER_INFO);
		//all_adapter_size���ڻ�ȡʵ������������Ϣ��ռ�ÿռ��С
		int ret = GetAdaptersInfo(p_adapters, (PULONG)&all_adapter_size);
		if (ret == ERROR_BUFFER_OVERFLOW) { // ��������ʾ�������ռ䲻��
			//���¸�ָ������ռ�
			delete p_adapters;
			p_adapters = (PIP_ADAPTER_INFO)new BYTE[all_adapter_size];
			GetAdaptersInfo(p_adapters, (PULONG)&all_adapter_size);//���»�ȡ������Ϣ
		}
		while (p_adapters) {
			Adapter adapter;
			inet_pton(AF_INET, p_adapters->IpAddressList.IpAddress.String, &adapter._ip_addr);
			inet_pton(AF_INET, p_adapters->IpAddressList.IpMask.String, &adapter._mask_addr);
			if (adapter._ip_addr != 0) {//��Ϊ��Щ������û�����ã�����IP��ַΪ0��
				list->push_back(adapter);  //��������Ϣ��ӵ�vector�з��ظ��û�
				//std::cout << "�������ƣ�" << p_adapters->AdapterName << std::endl;
				//std::cout << "����������" << p_adapters->Description << std::endl;
				//std::cout << "IP��ַ��" << p_adapters->IpAddressList.IpAddress.String << std::endl;
				//std::cout << "�������룺" << p_adapters->IpAddressList.IpMask.String << std::endl;
				//std::cout << std::endl;
			}
			p_adapters = p_adapters->Next;
		}
		delete p_adapters;
		return true;
	}
#else 
	//linux�µĻ�ȡ������Ϣʵ��
	static bool GetAllAdapter(std::vector<Adapter> *list) {
		struct ifaddrs *addrs = NULL;
		uint32_t net_seg, end_host;
		getifaddrs(&addrs);
		while (addrs) {
			if (addrs->ifa_addr->sa_family == AF_INET && strncasecmp(addrs->ifa_name, "lo", 2)) {
				sockaddr_in *addr = (sockaddr_in*)addrs->ifa_addr;
				sockaddr_in *mask = (sockaddr_in*)addrs->ifa_netmask;
				Adapter adapter;
				adapter._ip_addr = addr->sin_addr.s_addr;
				adapter._mask_addr = mask->sin_addr.s_addr;
				list->push_back(adapter);
			}
			addrs = addrs->ifa_next;
		}
		return true;
	}
#endif
};

