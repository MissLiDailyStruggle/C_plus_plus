#include "client.hpp"

void helloworld(const httplib::Request &req, httplib::Response &rsp)
{
	printf("httplib server recv a req:%s\n", req.path.c_str());
	rsp.set_content("<html><h1>HelloWorld</h1></html>", "text/html");
	rsp.status = 200;
}

void Scandir()
{
	//boost::filesystem::path().filename() ֻ��ȡ�ļ����ƣ�abc/filename.txt  ->  filename.txt
	//boost::filesystem::exists() �ж��ļ��Ƿ����
	const char *ptr = "./";
	boost::filesystem::directory_iterator begin(ptr); //����һ��Ŀ¼����������
	boost::filesystem::directory_iterator end;
	for (; begin != end; ++begin) {
		//begin->status()  Ŀ¼�е�ǰ�ļ���״̬��Ϣ
		//boost::filesystem::is_directory() �жϵ�ǰ�ļ��Ƿ���һ��Ŀ¼
		if (boost::filesystem::is_directory(begin->status())) {
			//begin->path().string() ��ȡ��ǰ�����ļ����ļ���
			std::cout << begin->path().string() << "��һ��Ŀ¼\n";
		}
		else {
			std::cout << begin->path().string() << "��һ����ͨ�ļ�\n";
			//begin->path().filename() ��ȡ·�ļ�·�����е��ļ����ƣ�����Ҫ·��
			std::cout << "�ļ�����" << begin->path().filename().string() << std::endl;
		}
	}
}

void test() {
	//Scandir();
	//Sleep(1111111);
	/*
	httplib::Server srv;

	srv.Get("/", helloworld);

	srv.listen("0.0.0.0", 9000);
	*/
}
void ClientRun()
{
	Client cli;
	cli.Start();
}
int main(int argc, char *argv[])
{
	//�����߳���Ҫ���пͻ���ģ���Լ������ģ��
	//����һ���߳����пͻ���ģ�飬���߳����з����ģ��
	std::thread thr_clilent(ClientRun);//���ͻ������е�ʱ�򣬷���˻�û������
	
	Server srv;
	srv.Start();
	return 0;
}