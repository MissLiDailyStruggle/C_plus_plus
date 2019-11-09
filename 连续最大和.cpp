//链接：https://www.nowcoder.com/questionTerminal/5a304c109a544aef9b583dce23f5f5db
//来源：牛客网
//一个数组有 N 个元素，求连续子数组的最大和。 例如：[-1, 2, 1]，和最大的连续子数组为[2, 1]，其和为 3
#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int n = 0;
	cin >> n;
	vector<int> v;
	v.resize(n + 1);
	int sum = -1e5;
	int temp = 0;
	for (int i = 0; i < n; i++)
		cin >> v[i];
	for (int i = 0; i < n; i++)
	{
		if (temp >= 0)
			temp += v[i];
		else
			temp = v[i];
		if (temp > sum)
			sum = temp;
	}
	cout << sum << endl;
}