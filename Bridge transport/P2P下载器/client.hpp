#pragma once
#include <thread>
#include <boost/filesystem.hpp>
#include "util.hpp"
#include "httplib.h"

#define P2P_PORT 9000
#define MAX_IPBUFFER 16
//1 左移10位 1k   左移20位 1M  
#define MAX_RANGE	(5)
#define SHARED_PATH "./Shared/"
#define DOWNLOAD_PATH "./Download/"

class Host
{
public:
	uint32_t _ip_addr;//要配对的主机的IP地址
	bool _pair_ret;//用于存放配对结果，配对成功-ture；失败-false
};

class Client
{
public:
	bool Start() {
		//客户端程序需要循环运行，因为下载文件不是只下载一次
		//循环运行每次下载一个文件之后都会重新进行主机配对--不合理
		while (1) {
			GetOnlineHost();
		}
		return true;
	}
	//主机配对的线程入口函数
	void HostPair(Host *host) {
		//1. 组织http协议格式的请求数据
		//2. 搭建一个tcp的客户端，将数据发送
		//3. 等待服务器端的回复，并进行解析
		//这个过程使用第三方库httplib实现--注意：同学们需要直到httplib它的实现流程
		host->_pair_ret = false;
		char buf[MAX_IPBUFFER] = { 0 };
		inet_ntop(AF_INET, &host->_ip_addr, buf, MAX_IPBUFFER);
		httplib::Client cli(buf, P2P_PORT); // 实例化httplib客户端对象
		auto rsp = cli.Get("/hostpair");  //向服务端发送资源为/hostpair的GET请求//若连接建立失败Get会返回NULL
		if (rsp && rsp->status == 200) {         //判断响应结果是否正确
			host->_pair_ret = true;       //重置主机配对结果
		}
		return;
	}
	//获取在线主机
	bool GetOnlineHost() {
		char ch = 'Y'; //是否重新匹配，默认是进行匹配的，若已经匹配锅，online主机不为空则让用户选择
		if (!_online_host.empty()) {
			std::cout << "Is Repair Host?(Y/N): ";
			fflush(stdout);
			std::cin >> ch;
		}
		if (ch == 'Y') {
			std::cout << "Host Pair Start·...\n";
			//1. 获取网卡信息，进而得到局域网中所有的IP地址列表
			std::vector<Adapter> list;
			AdapterUtil::GetAllAdapter(&list);
			//获取所有主机IP地址，添加到host_list
			std::vector<Host> host_list;
			for (int i = 0; i < list.size(); i++) {
				uint32_t ip = list[i]._ip_addr;
				uint32_t mask = list[i]._mask_addr;
				//计算网络号
				uint32_t net = (ntohl(ip & mask));
				//计算最大主机号
				uint32_t max_host = (~ntohl(mask));
				for (int j = 1; j < (int32_t)max_host; j++) {
					uint32_t host_ip = net + j;  //这个主机IP的计算应该使用主机字节序的网络号和主机号
					Host host;
					host._ip_addr = htonl(host_ip);//将这个主机字节序的IP地址转换为网络字节序
					host._pair_ret = false;
					host_list.push_back(host);
				}
			}
            /*/-------------------这里做一个快速测试，不用匹配其它主机，直接定位，提高调试效率
            host_list.clear();
            Host host;
            inet_pton(AF_INET, "192.168.122.1", &host._ip_addr);
            host._pair_ret = false;
            host_list.push_back(host);
            //-------------------*/
			//对host_list中的主机创建线程进行配对
			std::vector<std::thread*> thr_list(host_list.size());
			for (int i = 0; i < host_list.size(); i++) {
				thr_list[i] = new std::thread(&Client::HostPair, this, &host_list[i]);
			}
			std::cout << "Host Pairing, Wait....\n";
			//等待所有线程主机配对完毕，判断配对结果，将在线主机添加到online_host中
			for (int i = 0; i < host_list.size(); i++) {
				thr_list[i]->join();
				if (host_list[i]._pair_ret == true) {
					_online_host.push_back(host_list[i]);
				}
				delete thr_list[i];
			}
		}
		//将所有在线主机的IP打印出来，供用户选择
		for (int i = 0; i < _online_host.size(); i++) {
			char buf[MAX_IPBUFFER] = { 0 };
			inet_ntop(AF_INET, &_online_host[i]._ip_addr, buf, MAX_IPBUFFER);
			std::cout << "\t" << buf << std::endl;
		}
		//3. 若配对请求得到响应，则对应主机位在线主机，则将IP添加到_online_host列表中
		//4. 打印在线主机列表，使用户选择
		std::cout << "Select Host, to Get List: ";
		fflush(stdout);
		std::string select_ip;
		std::cin >> select_ip;
		GetShareList(select_ip);  //用户选择主机之后，调用获取文件列表接口
		return true;
	}
	//获取文件列表
	bool GetShareList(const std::string &host_ip) {
		//向服务端发送一个文件列表获取请求
		//1. 先发送请求
		//2. 得到响应之后，解析正文（文件名称）
		httplib::Client cli(host_ip.c_str(), P2P_PORT);
		auto rsp = cli.Get("/list");
		if (rsp == NULL || rsp->status != 200) {
			std::cerr << "获取文件列表响应错误\n";
			return false;
		}
		//打印正文---打印服务端响应的文件名称列表供用户选择
		//body: filename1\r\nfilename2...
		std::cout << rsp->body << std::endl;
		std::cout << "\nSelect File: ";
		fflush(stdout);
		std::string filename;
		std::cin >> filename;
		RangeDownload(host_ip, filename);
		return true;
	}
	//下载文件
	bool DonwloadFile(const std::string &host_ip, const std::string &filename) {
		//若文件一次性下载，遇到大文件比较危险
		//1. 向服务端发送文件下载请求  "/filename"
		//2. 得到响应结果，响应结果中的body正文就是文件数据
		//3. 创建文件，将文件数据写入文件中，关闭文件
		std::string req_path = "/download/" + filename;
		httplib::Client cli(host_ip.c_str(), P2P_PORT);  
		auto rsp = cli.Get(req_path.c_str());
		if (rsp == NULL || rsp->status != 200) {
			std::cout << "下载文件，获取响应信息失败:" << rsp->status << std::endl;
			return false;
		}
		if (!boost::filesystem::exists(DOWNLOAD_PATH)) {
			boost::filesystem::create_directory(DOWNLOAD_PATH);
		}
		std::string realpath = DOWNLOAD_PATH + filename;
		if (FileUtil::Write(realpath, rsp->body) == false) {
			std::cerr << "文件下载失败\n";
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
        //header.insert(httplib::make_range_header({ {s, e} }));//设置一个range区间
        httplib::Client cli(host_ip.c_str(), P2P_PORT);
        auto rsp = cli.Get(req_path.c_str(), {httplib::make_range_header(s, e)});
        if (rsp == NULL || rsp->status != 206) {
            if (rsp == NULL) { std::cout << "client rsp status NULL\n"; }
            else { std::cout << "响应状态码" << rsp->status << "\n"; }
            std::cout << "range download failed\n";
            return false;
        }
        std::cout << "client range write [" << rsp->body << "]\n";
        FileUtil::Write(realpath, rsp->body, s);
        std::cout << "client range write success\n";
        return true;
    }
    int64_t getfilesize(const std::string &host_ip, const std::string &req_path) {
		//1. 发送HEAD请求，通过响应中的Content-Length获取文件大小
		httplib::Client cli(host_ip.c_str(), P2P_PORT);
		auto rsp = cli.Head(req_path.c_str());
		if (rsp == NULL || rsp->status != 200) {
			std::cout << "获取文件大小信息失败\n";
			return false;
		}
		std::string clen = rsp->get_header_value("Content-Length");
		int64_t filesize = StringUtil::Str2Dig(clen); 
        return filesize;
    }
	bool RangeDownload(const std::string &host_ip, const std::string &name) {
		std::string req_path = "/download/" + name;
		int64_t filesize = getfilesize(host_ip, req_path);
		//2. 根据文件大小进行分块
		//int range_count = filesize / MAX_RANGE;
		//a. 若文件大小小于块大小，则直接下载文件
		if (filesize < MAX_RANGE) {
			std::cout << "文件较小,直接下载文件\n";
			return DonwloadFile(host_ip, name);
		}
		//计算分块个数
		//b. 若文件大小不能整除块大小，则分块个数位文件大小除以分块大小然后+1
		//c. 若文件大小刚好整除块大小，则分块个数就是文件大小除以分块大小
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
			//3. 逐一请求分块区间数据，得到响应之后写入文件的指定位置
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
		//添加针对客户端请求的处理方式对应关系
		_srv.Get("/hostpair", HostPair);
		_srv.Get("/list", ShareList);
		//正则表达式：将特殊字符以指定的格式，表示表示具有关键特征的数据
		//正则表达式中 .:匹配除\n或\r之外的任意字符  *：表示匹配前边的字符任意次
		//防止与上方的请求冲突，因此在请求中加入download路径
		_srv.Get("/download/.*", Download); 

		_srv.listen("0.0.0.0", P2P_PORT);
		return true;
	}
private:
	static void HostPair(const httplib::Request &req, httplib::Response &rsp) {
		rsp.status = 200;
		return;
	}
	//获取共享文件列表---在主机上设置一个共享目录，凡是这个目录下的文件都是要共享给别人的
	static void ShareList(const httplib::Request &req, httplib::Response &rsp) {
		//1. 查看目录是否存在，若目录不存在，则创建这个目录
		if (!boost::filesystem::exists(SHARED_PATH)) {
			boost::filesystem::create_directory(SHARED_PATH);
		}
		boost::filesystem::directory_iterator begin(SHARED_PATH);//实例化目录迭代器
		boost::filesystem::directory_iterator end;//实例化目录迭代器的末尾
		//开始迭代目录
		for (; begin != end; ++begin) {
			if (boost::filesystem::is_directory(begin->status())) {
				//当前版本我们之获取普通文件名称，不做多层级目录的操作
				continue;
			}
			std::string name = begin->path().filename().string();//只要文件名不要路径
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
		//std::cout << "服务端收到文件下载请求:" << req.path << std::endl;
			//req.path - 客户端请求的资源路径  /download/filename.txt
		boost::filesystem::path req_path(req.path);
		//boost::filesystem::path().filename() 只获取文件名称；abc/filename.txt  ->  filename.txt
		std::string  name = req_path.filename().string();//只获取文件名称；  filename.txt
		//std::cout << "服务端收到实际的文件下载名称:" << name << " 路径:" << SHARED_PATH << std::endl;
		std::string realpath = SHARED_PATH + name;//实际文件的路径应该是在共享的目录下
		//boost::filesystem::exists() 判断文件是否存在
		//std::cout << "服务端收到实际的文件下载路径:" << realpath << std::endl;
		if (!boost::filesystem::exists(realpath) || boost::filesystem::is_directory(realpath)) {
			rsp.status = 404;
			return;
		}
		if (req.method == "GET") {
			//以前GET请求 就是直接下载完整文件，但是现在不一样了，现在有了分块传输这个功能
			//判断是否是分块传输的依据，就是这次请求中是否又Range头部字段
			if (req.has_header("Range")) {//判断请求头中是否包含Range字段
				//这就是一个分块传输
				//需要知道分块区间是多少
				std::string range_str = req.get_header_value("Range");//bytes=start-end  0-99
                /*
				httplib::Ranges ranges;//vector<Range>   Range-std::pair<start, end>
				httplib::detail::parse_range_header(range_str, ranges);//解析客户端的Range数据
				int64_t range_start = ranges[0].first; //pair中first就是range的start位置
				int64_t range_end = ranges[0].second;  //pair中second就是range的end位置
				int64_t range_len = range_end - range_start + 1;//计算得知range区间的长度
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
				//没有Range头部，则是一个完整的文件下载
				if (FileUtil::Read(realpath, &rsp.body) == false) {
					rsp.status = 500;
					return;
				}
				rsp.status = 200;
			}
		}else {
			//这个是针对HEAD请求的---客户端只要头部不要正文
			int64_t filesize = FileUtil::GetFileSize(realpath);
			rsp.set_header("Content-Length", std::to_string(filesize).c_str()); //设置响应头部信息
			rsp.status = 200;
		}
		std::cout << "server range response over\n";
		return;
	}
private:
	httplib::Server _srv;
};
