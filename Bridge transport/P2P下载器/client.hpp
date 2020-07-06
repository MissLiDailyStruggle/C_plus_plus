#pragma once
#include <thread>
#include <boost/filesystem.hpp>
#include "util.hpp"
#include "httplib.h"

#define P2P_PORT 9000
#define MAX_IPBUFFER 16
//1 ����10λ 1k   ����20λ 1M  
#define MAX_RANGE	(5)
#define SHARED_PATH "./Shared/"
#define DOWNLOAD_PATH "./Download/"

class Host
{
public:
	uint32_t _ip_addr;//Ҫ��Ե�������IP��ַ
	bool _pair_ret;//���ڴ����Խ������Գɹ�-ture��ʧ��-false
};

class Client
{
public:
	bool Start() {
		//�ͻ��˳�����Ҫѭ�����У���Ϊ�����ļ�����ֻ����һ��
		//ѭ������ÿ������һ���ļ�֮�󶼻����½����������--������
		while (1) {
			GetOnlineHost();
		}
		return true;
	}
	//������Ե��߳���ں���
	void HostPair(Host *host) {
		//1. ��֯httpЭ���ʽ����������
		//2. �һ��tcp�Ŀͻ��ˣ������ݷ���
		//3. �ȴ��������˵Ļظ��������н���
		//�������ʹ�õ�������httplibʵ��--ע�⣺ͬѧ����Ҫֱ��httplib����ʵ������
		host->_pair_ret = false;
		char buf[MAX_IPBUFFER] = { 0 };
		inet_ntop(AF_INET, &host->_ip_addr, buf, MAX_IPBUFFER);
		httplib::Client cli(buf, P2P_PORT); // ʵ����httplib�ͻ��˶���
		auto rsp = cli.Get("/hostpair");  //�����˷�����ԴΪ/hostpair��GET����//�����ӽ���ʧ��Get�᷵��NULL
		if (rsp && rsp->status == 200) {         //�ж���Ӧ����Ƿ���ȷ
			host->_pair_ret = true;       //����������Խ��
		}
		return;
	}
	//��ȡ��������
	bool GetOnlineHost() {
		char ch = 'Y'; //�Ƿ�����ƥ�䣬Ĭ���ǽ���ƥ��ģ����Ѿ�ƥ�����online������Ϊ�������û�ѡ��
		if (!_online_host.empty()) {
			std::cout << "Is Repair Host?(Y/N): ";
			fflush(stdout);
			std::cin >> ch;
		}
		if (ch == 'Y') {
			std::cout << "Host Pair Start��...\n";
			//1. ��ȡ������Ϣ�������õ������������е�IP��ַ�б�
			std::vector<Adapter> list;
			AdapterUtil::GetAllAdapter(&list);
			//��ȡ��������IP��ַ����ӵ�host_list
			std::vector<Host> host_list;
			for (int i = 0; i < list.size(); i++) {
				uint32_t ip = list[i]._ip_addr;
				uint32_t mask = list[i]._mask_addr;
				//���������
				uint32_t net = (ntohl(ip & mask));
				//�������������
				uint32_t max_host = (~ntohl(mask));
				for (int j = 1; j < (int32_t)max_host; j++) {
					uint32_t host_ip = net + j;  //�������IP�ļ���Ӧ��ʹ�������ֽ��������ź�������
					Host host;
					host._ip_addr = htonl(host_ip);//����������ֽ����IP��ַת��Ϊ�����ֽ���
					host._pair_ret = false;
					host_list.push_back(host);
				}
			}
            /*/-------------------������һ�����ٲ��ԣ�����ƥ������������ֱ�Ӷ�λ����ߵ���Ч��
            host_list.clear();
            Host host;
            inet_pton(AF_INET, "192.168.122.1", &host._ip_addr);
            host._pair_ret = false;
            host_list.push_back(host);
            //-------------------*/
			//��host_list�е����������߳̽������
			std::vector<std::thread*> thr_list(host_list.size());
			for (int i = 0; i < host_list.size(); i++) {
				thr_list[i] = new std::thread(&Client::HostPair, this, &host_list[i]);
			}
			std::cout << "Host Pairing, Wait....\n";
			//�ȴ������߳����������ϣ��ж���Խ����������������ӵ�online_host��
			for (int i = 0; i < host_list.size(); i++) {
				thr_list[i]->join();
				if (host_list[i]._pair_ret == true) {
					_online_host.push_back(host_list[i]);
				}
				delete thr_list[i];
			}
		}
		//����������������IP��ӡ���������û�ѡ��
		for (int i = 0; i < _online_host.size(); i++) {
			char buf[MAX_IPBUFFER] = { 0 };
			inet_ntop(AF_INET, &_online_host[i]._ip_addr, buf, MAX_IPBUFFER);
			std::cout << "\t" << buf << std::endl;
		}
		//3. ���������õ���Ӧ�����Ӧ����λ������������IP��ӵ�_online_host�б���
		//4. ��ӡ���������б�ʹ�û�ѡ��
		std::cout << "Select Host, to Get List: ";
		fflush(stdout);
		std::string select_ip;
		std::cin >> select_ip;
		GetShareList(select_ip);  //�û�ѡ������֮�󣬵��û�ȡ�ļ��б�ӿ�
		return true;
	}
	//��ȡ�ļ��б�
	bool GetShareList(const std::string &host_ip) {
		//�����˷���һ���ļ��б��ȡ����
		//1. �ȷ�������
		//2. �õ���Ӧ֮�󣬽������ģ��ļ����ƣ�
		httplib::Client cli(host_ip.c_str(), P2P_PORT);
		auto rsp = cli.Get("/list");
		if (rsp == NULL || rsp->status != 200) {
			std::cerr << "��ȡ�ļ��б���Ӧ����\n";
			return false;
		}
		//��ӡ����---��ӡ�������Ӧ���ļ������б��û�ѡ��
		//body: filename1\r\nfilename2...
		std::cout << rsp->body << std::endl;
		std::cout << "\nSelect File: ";
		fflush(stdout);
		std::string filename;
		std::cin >> filename;
		RangeDownload(host_ip, filename);
		return true;
	}
	//�����ļ�
	bool DonwloadFile(const std::string &host_ip, const std::string &filename) {
		//���ļ�һ�������أ��������ļ��Ƚ�Σ��
		//1. �����˷����ļ���������  "/filename"
		//2. �õ���Ӧ�������Ӧ����е�body���ľ����ļ�����
		//3. �����ļ������ļ�����д���ļ��У��ر��ļ�
		std::string req_path = "/download/" + filename;
		httplib::Client cli(host_ip.c_str(), P2P_PORT);  
		auto rsp = cli.Get(req_path.c_str());
		if (rsp == NULL || rsp->status != 200) {
			std::cout << "�����ļ�����ȡ��Ӧ��Ϣʧ��:" << rsp->status << std::endl;
			return false;
		}
		if (!boost::filesystem::exists(DOWNLOAD_PATH)) {
			boost::filesystem::create_directory(DOWNLOAD_PATH);
		}
		std::string realpath = DOWNLOAD_PATH + filename;
		if (FileUtil::Write(realpath, rsp->body) == false) {
			std::cerr << "�ļ�����ʧ��\n";
			return false;
		}
		std::cout << "DownLoad Success!\n";
		return true;
	}

    bool rangedown(const std::string &host_ip, const std::string &name, int64_t s, int64_t e){
		std::string req_path = "/download/" + name;
        std::string realpath = DOWNLOAD_PATH + name;
        //httplib::Headers header;
        //header = httplib::make_range_header({{s, e}});
        //header.insert(httplib::make_range_header({ {s, e} }));//����һ��range����
        httplib::Client cli(host_ip.c_str(), P2P_PORT);
        auto rsp = cli.Get(req_path.c_str(), {httplib::make_range_header(s, e)});
        if (rsp == NULL || rsp->status != 206) {
            if (rsp == NULL) { std::cout << "client rsp status NULL\n"; }
            else { std::cout << "��Ӧ״̬��" << rsp->status << "\n"; }
            std::cout << "range download failed\n";
            return false;
        }
        std::cout << "client range write [" << rsp->body << "]\n";
        FileUtil::Write(realpath, rsp->body, s);
        std::cout << "client range write success\n";
        return true;
    }
    int64_t getfilesize(const std::string &host_ip, const std::string &req_path) {
		//1. ����HEAD����ͨ����Ӧ�е�Content-Length��ȡ�ļ���С
		httplib::Client cli(host_ip.c_str(), P2P_PORT);
		auto rsp = cli.Head(req_path.c_str());
		if (rsp == NULL || rsp->status != 200) {
			std::cout << "��ȡ�ļ���С��Ϣʧ��\n";
			return false;
		}
		std::string clen = rsp->get_header_value("Content-Length");
		int64_t filesize = StringUtil::Str2Dig(clen); 
        return filesize;
    }
	bool RangeDownload(const std::string &host_ip, const std::string &name) {
		std::string req_path = "/download/" + name;
		int64_t filesize = getfilesize(host_ip, req_path);
		//2. �����ļ���С���зֿ�
		//int range_count = filesize / MAX_RANGE;
		//a. ���ļ���СС�ڿ��С����ֱ�������ļ�
		if (filesize < MAX_RANGE) {
			std::cout << "�ļ���С,ֱ�������ļ�\n";
			return DonwloadFile(host_ip, name);
		}
		//����ֿ����
		//b. ���ļ���С�����������С����ֿ����λ�ļ���С���Էֿ��СȻ��+1
		//c. ���ļ���С�պ��������С����ֿ���������ļ���С���Էֿ��С
		std::cout << "too max, range download\n";
		int64_t range_count = 0;
		if ((filesize % MAX_RANGE) == 0) {
			range_count = filesize / MAX_RANGE;
		}else {
			range_count = (filesize / MAX_RANGE) + 1;
		}
		// 136   100    0~99  100~135
		int64_t range_start = 0, range_end = 0;
		for (int i = 0; i < range_count; i++) {
			range_start = i * MAX_RANGE;
			if (i == (range_count - 1)) {
				range_end = filesize - 1;
			}else {
				range_end = ((i + 1) * MAX_RANGE) - 1;
			}
			std::cout << "client range req:" << range_start << "-" << range_end << std::endl;
			//3. ��һ����ֿ��������ݣ��õ���Ӧ֮��д���ļ���ָ��λ��
            rangedown(host_ip, name, range_start, range_end);
		}
		std::cout << "Download Success\n";
		return true;
	}
private:
	std::vector<Host> _online_host;
};

class Server
{
public:
	bool Start() {
		//�����Կͻ�������Ĵ���ʽ��Ӧ��ϵ
		_srv.Get("/hostpair", HostPair);
		_srv.Get("/list", ShareList);
		//������ʽ���������ַ���ָ���ĸ�ʽ����ʾ��ʾ���йؼ�����������
		//������ʽ�� .:ƥ���\n��\r֮��������ַ�  *����ʾƥ��ǰ�ߵ��ַ������
		//��ֹ���Ϸ��������ͻ������������м���download·��
		_srv.Get("/download/.*", Download); 

		_srv.listen("0.0.0.0", P2P_PORT);
		return true;
	}
private:
	static void HostPair(const httplib::Request &req, httplib::Response &rsp) {
		rsp.status = 200;
		return;
	}
	//��ȡ�����ļ��б�---������������һ������Ŀ¼���������Ŀ¼�µ��ļ�����Ҫ��������˵�
	static void ShareList(const httplib::Request &req, httplib::Response &rsp) {
		//1. �鿴Ŀ¼�Ƿ���ڣ���Ŀ¼�����ڣ��򴴽����Ŀ¼
		if (!boost::filesystem::exists(SHARED_PATH)) {
			boost::filesystem::create_directory(SHARED_PATH);
		}
		boost::filesystem::directory_iterator begin(SHARED_PATH);//ʵ����Ŀ¼������
		boost::filesystem::directory_iterator end;//ʵ����Ŀ¼��������ĩβ
		//��ʼ����Ŀ¼
		for (; begin != end; ++begin) {
			if (boost::filesystem::is_directory(begin->status())) {
				//��ǰ�汾����֮��ȡ��ͨ�ļ����ƣ�������㼶Ŀ¼�Ĳ���
				continue;
			}
			std::string name = begin->path().filename().string();//ֻҪ�ļ�����Ҫ·��
			rsp.body += name + "\r\n";   //filename1\r\nfilename2\r\n....
		}
		rsp.status = 200;
		return;
	}
    static bool GetRange(std::string &range, int64_t &range_start, int64_t &range_end) {
        size_t pos1, pos2;
        pos1 = range.find("-");
        if (pos1 == std::string::npos) return false;
        pos2 = range.find("bytes=");
        if (pos2 == std::string::npos) return false;
        std::stringstream ss; 
        ss << range.substr(pos2 + 6, pos1 - pos2 - 6); 
        ss >> range_start;
        ss.clear();
        ss << range.substr(pos1 + 1); 
        ss >> range_end;
        return true;
    }
	static void Download(const httplib::Request &req, httplib::Response &rsp) {
		//std::cout << "������յ��ļ���������:" << req.path << std::endl;
			//req.path - �ͻ����������Դ·��  /download/filename.txt
		boost::filesystem::path req_path(req.path);
		//boost::filesystem::path().filename() ֻ��ȡ�ļ����ƣ�abc/filename.txt  ->  filename.txt
		std::string  name = req_path.filename().string();//ֻ��ȡ�ļ����ƣ�  filename.txt
		//std::cout << "������յ�ʵ�ʵ��ļ���������:" << name << " ·��:" << SHARED_PATH << std::endl;
		std::string realpath = SHARED_PATH + name;//ʵ���ļ���·��Ӧ�����ڹ����Ŀ¼��
		//boost::filesystem::exists() �ж��ļ��Ƿ����
		//std::cout << "������յ�ʵ�ʵ��ļ�����·��:" << realpath << std::endl;
		if (!boost::filesystem::exists(realpath) || boost::filesystem::is_directory(realpath)) {
			rsp.status = 404;
			return;
		}
		if (req.method == "GET") {
			//��ǰGET���� ����ֱ�����������ļ����������ڲ�һ���ˣ��������˷ֿ鴫���������
			//�ж��Ƿ��Ƿֿ鴫������ݣ���������������Ƿ���Rangeͷ���ֶ�
			if (req.has_header("Range")) {//�ж�����ͷ���Ƿ����Range�ֶ�
				//�����һ���ֿ鴫��
				//��Ҫ֪���ֿ������Ƕ���
				std::string range_str = req.get_header_value("Range");//bytes=start-end  0-99
                /*
				httplib::Ranges ranges;//vector<Range>   Range-std::pair<start, end>
				httplib::detail::parse_range_header(range_str, ranges);//�����ͻ��˵�Range����
				int64_t range_start = ranges[0].first; //pair��first����range��startλ��
				int64_t range_end = ranges[0].second;  //pair��second����range��endλ��
				int64_t range_len = range_end - range_start + 1;//�����֪range����ĳ���
                */
                int64_t range_start, range_end, range_len;
                GetRange(range_str, range_start, range_end);
                range_len = range_end - range_start + 1;
				std::cout << realpath << ": range:" << range_start << "-" << range_end << std::endl;
                std::string body;
				FileUtil::ReadRange(realpath, &body, range_len, range_start);
                rsp.set_content(body.c_str(), range_len, "text/plain");
                rsp.set_header("Content-Length", std::to_string(rsp.body.size()).c_str());
				rsp.status = 206;
				std::cout << "server rsp range body:[" << rsp.body << "]\n";
			}else {
				//û��Rangeͷ��������һ���������ļ�����
				if (FileUtil::Read(realpath, &rsp.body) == false) {
					rsp.status = 500;
					return;
				}
				rsp.status = 200;
			}
		}else {
			//��������HEAD�����---�ͻ���ֻҪͷ����Ҫ����
			int64_t filesize = FileUtil::GetFileSize(realpath);
			rsp.set_header("Content-Length", std::to_string(filesize).c_str()); //������Ӧͷ����Ϣ
			rsp.status = 200;
		}
		std::cout << "server range response over\n";
		return;
	}
private:
	httplib::Server _srv;
};
