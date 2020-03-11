//链接：https://www.nowcoder.com/questionTerminal/5017fd2fc5c84f78bbaed4777996213a
//来源：牛客网
//有一间长方形的房子，地上铺了红色、黑色两种颜色的正方形瓷砖。你站在其中一块黑色的瓷砖上，只能向相邻的（上下左右四个方向）黑色瓷砖移动。请写一个
//程序，计算你总共能够到达多少块黑色的瓷砖。
#include <iostream>
#include <vector>

using namespace std;
void RedBlack(vector<vector<char>>& arr, int x, int y, int m, int n, int &res)
{
	if (x < 0 || y < 0 || x >= m || y >= n || v[x][y] == '1' || v[x][y] == '#')
		return;
	++res;
	v[x][y] = '1';
	RedBlack(arr, x - 1, y, m, n, res);
	RedBlack(arr, x + 1, y, m, n, res);
	RedBlack(arr, x, y - 1, m, n, res);
	RedBlack(arr, x, y + 1, m, n, res);
}
int main()
{
	int m, n;
	while (cin >> m >> n)
	{
		vector<vector<char>> arr(m, vector<char>(n));
		int x, y;
		int res = 0;
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cin >> arr[i][j];
				if (arr[i][j] == '@')
				{
					x = i;
					y = j;
				}
			}
		}
		RedBlack(arr, x, y, m, n, res);
		cout << res << endl;

	}
	return 0;
}