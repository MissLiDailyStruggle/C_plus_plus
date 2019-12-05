//链接：https://www.nowcoder.com/questionTerminal/34f17d5f2a8240bea661a23ec095a062
//来源：牛客网
//星际战争开展了100年之后，NowCoder终于破译了外星人的密码！他们的密码是一串整数，通过一张表里的信息映射成最终4位密码。表的规则是：n
//对应的值是矩阵X的n次方的左上角，如果这个数不足4位则用0填充，如果大于4位的则只输出最后4位。
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