//链接：https://www.nowcoder.com/questionTerminal/e8fb8f89f5d147ec92fd8ecfefe89b0d
//来源：牛客网
//一个正整数可以分解成一个或多个数组的积。例如36 = 2 * 2 * 3 * 3，即包含2和3两个因子。NowCoder最近在研究因子个数的分布规律，现在给出一系列正整数，他希望你开发
//一个程序输出每个正整数的因子个数。
#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	int n;
	while (cin >> n)
	{
		int count = 0;
		for (int i = 2; i <= sqrt(n); i++)
		{
			if (n % i == 0)
				count++;
			while (n % i == 0)
				n /= i;
		}
		if (n != 1)
			count++;
		cout << count << endl;
	}
	return 0;
}