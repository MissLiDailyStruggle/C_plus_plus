//链接：https://www.nowcoder.com/questionTerminal/a174820de48147d489f64103af152709
//来源：牛客网
//n 只奶牛坐在一排，每个奶牛拥有 ai 个苹果，现在你要在它们之间转移苹果，使得最后所有奶牛拥有的苹果数都相同，每一次，你只能从一只奶牛身上拿走恰好两个
//苹果到另一个奶牛上，问最少需要移动多少次可以平分苹果，如果方案不存在输出 - 1。
#include <iostream>
#include <vector>

using  namespace std;

int main()
{
	int n;
	cin >> n;
	vector<int> arr(n, 0);
	int sum = 0;
	for (int i = 0; i < n; ++i)
	{
		cin >> arr[i];
		sum += arr[i];
	}
	if (sum % n != 0)
	{
		cout << -1 << endl;
		return 0;
	}
	int aver = sum / n;
	int more = 0;
	int res = 0;
	for (int i = 0; i < n; ++i)
	{
		if (arr[i] > aver)
		{
			more = arr[i] - aver;
			if (more % 2 != 0)
			{
				cout << -1 << endl;
				return 0;
			}
			res += more;
		}
	}
	cout << res / 2 << endl;
	return 0;
}