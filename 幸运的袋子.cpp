//链接：https://www.nowcoder.com/questionTerminal/a5190a7c3ec045ce9273beebdfe029ee
//来源：牛客网
//一个袋子里面有n个球，每个球上面都有一个号码(拥有相同号码的球是无区别的)。如果一个袋子是幸运的当且仅当所有球的号码的和大于所有球的号码的积。
//例如：如果袋子里面的球的号码是{ 1, 1, 2, 3 }，这个袋子就是幸运的，因为1 + 1 + 2 + 3 > 1 * 1 * 2 * 3
//你可以适当从袋子里移除一些球(可以移除0个, 但是别移除完)，要使移除后的袋子是幸运的。现在让你编程计算一下你可以获得的多少种不同的幸运的袋子。
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<int>v;

int solve(int index, int add, int mul)
{
	int count = 0;
	for (int i = index; i < n; i++)
	{
		add += v[i];
		mul *= v[i];
		if (add > mul)
			count += 1 + solve(i + 1, add, mul);
		else if (v[i] == 1)
			count += solve(i + 1, add, mul);
		else
			break;
		add -= v[i];
		mul /= v[i];
		while ((i + 1) < n &&v[i + 1] == v[i])
			i++;
	}
	return count;
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int temp;
		cin >> temp;
		v.push_back(temp);
	}
	sort(v.begin(), v.end());
	int add = 0;
	int mul = 1;
	int res = solve(0, add, mul);
	cout << res << endl;
	system("pause");
	return 0;
}