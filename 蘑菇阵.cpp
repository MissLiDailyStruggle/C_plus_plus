//链接：https://www.nowcoder.com/questionTerminal/ed9bc679ea1248f9a3d86d0a55c0be10
//来源：牛客网
//现在有两个好友A和B，住在一片长有蘑菇的由n＊m个方格组成的草地，A在(1, 1), B在(n, m)。现在A想要拜访B，由于她只想去B的家，所以每次她只会走(i, j + 
//1)或(i + 1, j)这样的路线，在草地上有k个蘑菇种在格子里(多个蘑菇可能在同一方格), 问：A如果每一步随机选择的话(若她在边界上，则只有一种选择)，那么
//她不碰到蘑菇走到B的家的概率是多少？
#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int n, m, k;
	while (cin >> n >> m >> k)
	{
		vector<vector<int>> arr(n + 1, vector<int>(m + 1));
		vector<vector<double>> brr(n + 1, vector<double>(m + 1));
		for (int i = 0; i < k; i++)
		{
			int x, y;
			cin >> x >> y;
			arr[x][y] = 1;
		}
		brr[1][1] = 1.0;
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= m; j++)
			{
				if (!(i == 1 && j == 1))
				{
					brr[i][j] = (brr[i - 1][j] * (j == m ? 1 : 0.5)) + (brr[i][j - 1] * (i == n ? 1 : 0.5));
					if (arr[i][j] == 1)
						brr[i][j] = 0;
				}
			}
		}
		printf("%.2f", brr[n][m]);
		cout << endl;
	}
	return 0;
}