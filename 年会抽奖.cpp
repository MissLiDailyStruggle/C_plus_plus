//���ӣ�https://www.nowcoder.com/questionTerminal/610e6c0387a0401fb96675f58cda8559
//��Դ��ţ����
//���깫˾���Ľ�Ʒ�ر���������񽱵Ĺ��ȴ�����⣺
//1. ���ȣ�������Ա����һ��д���Լ����ֵ���������齱���У�
//2. ����������������ϣ�ÿ�˴�����ȡһ��������
//3. ����鵽��������д�ľ����Լ������֣���ô����ϲ�㣬�н��ˣ���
//���ڸ�����μ�������������������ж��ٸ��ʻ�������˻񽱣�
#include <iostream>

using namespace std;
double numerator(int n)
{
	if (n == 1)
		return 0;
	if (n == 2)
		return 1;
	return (n - 1) * (numerator(n - 1) + numerator(n - 2));
}
double factoria(int n)
{
	if (n == 0)
		return 1;
	else
		return n * factoria(n - 1);
}
int main()
{
	int n;
	while (cin >> n)
	{
		double res;
		double num = numerator(n);
		double den = factoria(n);
		res = num / den * 100;
		printf("%.2f%%", res);
		cout << endl;
	}
	return 0;
}