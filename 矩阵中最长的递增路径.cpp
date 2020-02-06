//����һ�����������ҳ������·���ĳ��ȡ�����ÿ����Ԫ����������ϣ��£������ĸ������ƶ��� �㲻���ڶԽ��߷������ƶ����ƶ����߽��⣨����������)��
//���ӣ�https://leetcode-cn.com/problems/longest-increasing-path-in-a-matrix/
class Solution {
public:
	int longestIncreasingPath(vector<vector<int>>& matrix) {
		if (matrix.empty() || matrix[0].empty())
			return 0;
		int res = 1;
		int m = matrix.size();
		int n = matrix[0].size();
		vector<vector<int>> dp(m, vector<int>(n, 0));
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
				res = max(res, dfs(matrix, dp, i, j));
		}
		return res;
	}
	int dfs(vector<vector<int>> &matrix, vector<vector<int>> &dp, int i, int j)
	{
		if (dp[i][j])
			return dp[i][j];
		int mx = 1;
		int m = matrix.size();
		int n = matrix[0].size();
		vector<vector<int>> dirs = { { 0, -1 }, { -1, 0 }, { 0, 1 }, { 1, 0 } };
		for (auto a : dirs)
		{
			int x = i + a[0], y = j + a[1];
			if (x < 0 || x >= m || y < 0 || y >= n || matrix[x][y] <= matrix[i][j])
				continue;
			int len = 1 + dfs(matrix, dp, x, y);
			mx = max(mx, len);
		}
		dp[i][j] = mx;
		return mx;
	}
};