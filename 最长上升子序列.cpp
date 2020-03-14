// 链接：https://www.nowcoder.com/questionTerminal/d83721575bd4418eae76c916483493de
//来源：牛客网
//广场上站着一支队伍，她们是来自全国各地的扭秧歌代表队，现在有她们的身高数据，请你帮忙找出身高依次递增的子序列。 例如队伍的身高数据是（1、7、3、
//5、9、4、8），其中依次递增的子序列有（1、7），（1、3、5、9），（1、3、4、8）等，其中最长的长度为4。
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	int n;
	while (cin >> n)
	{
		vector<int>arr(n, 0);
		for (int i = 0; i < n; i++)
		{
			cin >> arr[i];
		}
		vector<int>f(n, 1);
		int maxcount = 1;
		for (int i = 1; i < n; i++)
		{
			for (int j = 0; j < i; j++)
			{
				if (arr[i] > arr[j])
					f[i] = max(f[i], f[j] + 1);
			}
			maxcount = max(maxcount, f[i]);
		}
		cout << maxcount << endl;
	}
	return 0;
}