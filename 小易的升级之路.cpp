//���ӣ�https://www.nowcoder.com/questionTerminal/fe6c73cb899c4fe1bdd773f8d3b42c3d
//��Դ��ţ����
//С�׾���������������Ϸ.��һ��, ������һ�������������Ϸ, ���Ľ�ɫ�ĳ�ʼ����ֵΪa.�ڽ�������һ��ʱ����, ��������������n������, ÿ��
//����ķ�����Ϊb1, b2, b3...bn.��������Ĺ��������biС�ڵ���С�׵ĵ�ǰ����ֵc, ��ô���������ɴ�ܹ���, ����ʹ���Լ�������ֵ����bi;
//���bi����c, ����Ҳ�ܴ�ܹ���, ����������ֵֻ������bi ��c�����Լ��.��ô��������, ��һϵ�еĶ�����, С�׵���������ֵΪ���� ?
#include <iostream>
#include <cmath>
#include <vector>
#include <cstdio>

using namespace std;

int big_common_divisor(int a, int b)
{
	int tmp;
	while (b)
	{
		tmp = b;
		b = a % b;
		a = tmp;
	}
	return a;
}

int main()
{
	int a = 0;
	int n = 0;
	int c = 0;
	while (cin >> n >> a)
	{
		vector<int>p(n);
		c = a;
		for (int i = 0; i < n; i++)
			cin >> p[i];
		for (int i = 0; i < n; i++)
		{
			if (c >= p[i])
				c += p[i];
			else
				c += (big_common_divisor(c, p[i]));
		}
		cout << c << endl;
	}
	return 0;
}