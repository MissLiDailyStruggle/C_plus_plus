// 链接：https://www.nowcoder.com/questionTerminal/88c6d56d78974869aac605a0d26deded
//来源：牛客网
//7
//3 8
//8 1 0
//2 7 4 4
//4 5 2 6 5
//如上图所示，从一个数字三角形的顶部走到底部有很多条不同的路径，规则是只能从当前节点走到下一层相邻的节点，即下一层的左边或右边。例如第三行第二个数字
//“1”只能走到第四行的第二个数字“7”与第三个数字“4”。请寻找最佳一条路径，使得这条路径上节点的数字总和最大。
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	int n;
	while (cin >> n)
	{
		vector<vector<int>> v(n, vector<int>(n));
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j <= i; ++j)
			{
				cin >> v[i][j];
			}
		}
		for (int i = n - 2; i >= 0; i--)
		{
			for (int j = 0; j <= i; j++)
			{
				v[i][j] += max(v[i + 1][j], v[i + 1][j + 1]);
			}
		}
		cout << v[0][0] << endl;
	}
	return 0;
}