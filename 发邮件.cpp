//���ӣ�https://www.nowcoder.com/questionTerminal/95e35e7f6ad34821bc2958e37c08918b
//��Դ��ţ����
//NowCoderÿ��Ҫ���ܶ��˷��ʼ�����һ�������ַ������ʼ����ѷ���A���ʼ�������B���ѷ���B���ʼ�������A����������˼����Ҫ��n���˷��ʼ�����ÿ���˽��յ�
//1���ʼ�������£��ж���������������˶��յ��˴�����ʼ�����û�����յ������Լ����ʼ���
// write your code here cpp
#include <iostream>

using namespace std;

long kind(int n)
{
	if (n == 1)
		return 0;
	if (n == 2)
		return 1;
	return (n - 1) * (kind(n - 1) + kind(n - 2));
}

int main()
{
	int n;
	while (cin >> n)
	{
		long res = kind(n);
		cout << res << endl;
	}
	return 0;
}