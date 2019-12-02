//链接：https://www.nowcoder.com/questionTerminal/fe6c73cb899c4fe1bdd773f8d3b42c3d
//来源：牛客网
//小易经常沉迷于网络游戏.有一次, 他在玩一个打怪升级的游戏, 他的角色的初始能力值为a.在接下来的一段时间内, 他将会依次遇见n个怪物, 每个
//怪物的防御力为b1, b2, b3...bn.如果遇到的怪物防御力bi小于等于小易的当前能力值c, 那么他就能轻松打败怪物, 并且使得自己的能力值增加bi;
//如果bi大于c, 那他也能打败怪物, 但他的能力值只能增加bi 与c的最大公约数.那么问题来了, 在一系列的锻炼后, 小易的最终能力值为多少 ?
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