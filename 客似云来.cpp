//链接：https://www.nowcoder.com/questionTerminal/3549ff22ae2c4da4890e9ad0ccb6150d
//来源：牛客网
//NowCoder开了一家早餐店，这家店的客人都有个奇怪的癖好：他们只要来这家店吃过一次早餐，就会每天都过来；并且，所有人在这家店吃了两天早餐后，接下来每天
//都会带一位新朋友一起来品尝。于是，这家店的客人从最初一个人发展成浩浩荡荡成百上千人：1、1、2、3、5……现在，NowCoder想请你帮忙统计一下，某一段时间
//范围那他总共卖出多少份早餐（假设每位客人只吃一份早餐）。
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