//���ӣ�https://www.nowcoder.com/questionTerminal/f8538f9ae3f1484fb137789dec6eedb9
//��Դ��ţ����
//����һ��ż��������2����������2��������ɣ����ż����2�������кܶ������������ĿҪ��������ָ��ż��������������ֵ��С�������ԡ�
#include<iostream>
using namespace std;
bool is_PrimeNumber(int a)
{
	for (int i = 2; i<a; i++)
	{
		if (a%i == 0)
		{
			return false;
		}
	}
	return true;
}
int main()
{
	int n;
	while (cin >> n)
	{
		int count = 0;
		int min = 0;
		int index = 0;
		for (int i = n - 2; i >= n / 2; i--)
		{
			if (is_PrimeNumber(i) && is_PrimeNumber(n - i))
			{
				count = 2 * i - n;
				if (min == 0 || min>count)
				{
					min = count;
					index = i;
				}
			}
		}
		cout << index - min << endl;
		cout << index << endl;
	}
	return 0;
}
