//���ӣ�https://www.nowcoder.com/questionTerminal/5973a31d58234b068fa1fe34f7290855
//��Դ��ţ����
//NowCoderÿ��Ҫ�����ͻ�д�����ʼ�����������֪�����һ���ʼ��а�������ռ��ˣ��ռ�������֮�����һ�����źͿո����������ռ�������Ҳ�����ո��
//�ţ���������Ҫ��˫���Ű��������ڸ���һ���ռ����������������������Ӧ���ռ����б�
#include <iostream>
#include <string>

using namespace std;

int main()
{
	int n;
	while (cin >> n)
	{
		getchar();
		string name;
		for (int i = 0; i < n; i++)
		{
			getline(cin, name);
			if (i != n - 1)
			{
				if (name.find(',') != -1 || name.find(' ') != -1)
					cout << '\"' << name << '\"' << ',' << ' ';
				else
					cout << name << ',' << ' ';
			}
			else
			{
				if (name.find(',') != -1 || name.find(' ') != -1)
					cout << '\"' << name << '\"' << endl;
				else
					cout << name << endl;
			}
		}
	}
	return 0;
}