//���ӣ�https://www.nowcoder.com/questionTerminal/3549ff22ae2c4da4890e9ad0ccb6150d
//��Դ��ţ����
//NowCoder����һ����͵꣬��ҵ�Ŀ��˶��и���ֵ��ã�����ֻҪ����ҵ�Թ�һ����ͣ��ͻ�ÿ�춼���������ң�����������ҵ����������ͺ󣬽�����ÿ��
//�����һλ������һ����Ʒ�������ǣ���ҵ�Ŀ��˴����һ���˷�չ�ɺƺƵ����ɰ���ǧ�ˣ�1��1��2��3��5�������ڣ�NowCoder�������æͳ��һ�£�ĳһ��ʱ��
//��Χ�����ܹ��������ٷ���ͣ�����ÿλ����ֻ��һ����ͣ���
#include <iostream>

using namespace std;

long fibonacci(int num)
{
	long a = 1;
	long b = 1;
	long c;
	if (num == 1)
		return 1;
	if (num == 2)
		return 1;
	while (num > 2)
	{
		c = a + b;
		a = b;
		b = c;
		num--;
	}
	return c;
}
int main()
{
	int from;
	int to;
	while (cin >> from >> to)
	{
		long long sum = 0;
		for (int i = from; i <= to; i++)
		{
			sum += fibonacci(i);
		}
		cout << sum << endl;
	}
	return 0;
}