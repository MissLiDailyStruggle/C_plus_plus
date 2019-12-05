//���ӣ�https://www.nowcoder.com/questionTerminal/34f17d5f2a8240bea661a23ec095a062
//��Դ��ţ����
//�Ǽ�ս����չ��100��֮��NowCoder���������������˵����룡���ǵ�������һ��������ͨ��һ�ű������Ϣӳ�������4λ���롣��Ĺ����ǣ�n
//��Ӧ��ֵ�Ǿ���X��n�η������Ͻǣ�������������4λ����0��䣬�������4λ����ֻ������4λ��
#include <iostream>
#include <vector>
#include <cstdio>
#define MAX 10000

using namespace std;

int fib1(int n)
{
	int first = 0;
	int second = 1;
	int cur = 1;
	for (int i = 0; i < n; i++)
	{
		cur = first + second;
		first = second % MAX;
		second = cur%MAX;
	}
	return cur % MAX;
}

int main()
{
	int n;
	while (cin >> n)
	{
		vector<int>password(n);
		for (int i = 0; i < n; i++)
			cin >> password[i];
		for (int i = 0; i < n; i++)
		{
			int res = fib1(password[i]);
			printf("%04d", res);
		}
		cout << endl;
	}
	return 0;
}