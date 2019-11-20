//链接：https://www.nowcoder.com/questionTerminal/4284c8f466814870bae7799a07d49ec8
//来源：牛客网
//小易来到了一条石板路前，每块石板上从1挨着编号为：1、2、3.......这条石板路要根据特殊的规则才能前进：
//对于小易当前所在的编号为K的 石板，小易单次只能往前跳K的一个约数(不含1和K)步，即跳到K + X(X为K的一个
//非1和本身的约数)的位置。 小易当前处在编号为N的石板，他想跳到编号恰好为M的石板去，小易想知道最少需要
//跳跃几次可以到达。 例如： N = 4，M = 24： 4->6->8->12->18->24 于是小易最少需要跳跃5次，就可以从4号
//石板跳到24号石板。
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void jud_appro(int n, vector<int> &v)
{
	for (int i = 2; i * i <= n; i++)
	{
		if (n % i == 0)
		{
			v.push_back(i);
			if (n / i != i)
				v.push_back(n / i);
		}
	}
}

int main()
{
	int n, m;
	while (cin >> n >> m)
	{
		vector<int> res(m + 1, 0);
		res[n] = 1;
		for (int i = n; i <= m; i++)
		{
			vector<int> v;
			if (res[i] == 0)
				continue;
			jud_appro(i, v);
			for (int j = 0; j < v.size(); j++)
			{
				if (v[j] + i <= m && res[v[j] + i] == 0)
					res[v[j] + i] = res[i] + 1;
				else if ((v[j] + i <= m && res[v[j] + i] != 0))
					res[v[j] + i] = min(res[v[j] + i], res[i] + 1);
			}
		}
		if (res[m] != 0)
			cout << res[m] - 1 << endl;
		else
			cout << -1 << endl;
	}
	return 0;
}