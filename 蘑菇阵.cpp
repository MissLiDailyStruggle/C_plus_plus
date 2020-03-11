//���ӣ�https://www.nowcoder.com/questionTerminal/ed9bc679ea1248f9a3d86d0a55c0be10
//��Դ��ţ����
//��������������A��B��ס��һƬ����Ģ������n��m��������ɵĲݵأ�A��(1, 1), B��(n, m)������A��Ҫ�ݷ�B��������ֻ��ȥB�ļң�����ÿ����ֻ����(i, j + 
//1)��(i + 1, j)������·�ߣ��ڲݵ�����k��Ģ�����ڸ�����(���Ģ��������ͬһ����), �ʣ�A���ÿһ�����ѡ��Ļ�(�����ڱ߽��ϣ���ֻ��һ��ѡ��)����ô
//��������Ģ���ߵ�B�ļҵĸ����Ƕ��٣�
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