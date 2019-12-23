//链接：https://www.nowcoder.com/practice/2b7995aa4f7949d99674d975489cb7da?tpId=46&tqId=29060&tPage=2&rp=2&ru=/ta/leetcode&qru=/ta/leetcode/question-rankin
//来源：牛客网
//给出一个三角形，计算从三角形顶部到底部的最小路径和，每一步都可以移动到下面一行相邻的数字，
class Solution {
public:
	int minimumTotal(vector<vector<int> > &triangle) {
		if (triangle.empty())
			return 0;
		vector<vector<int>>min_path(triangle);
		int line = triangle.size();
		for (int i = line - 2; i >= 0; i--)
		{
			for (int j = 0; j <= i; j++)
			{
				min_path[i][j] = min(min_path[i + 1][j], min_path[i + 1][j + 1]) + triangle[i][j];
			}
		}
		return min_path[0][0];
	}
};