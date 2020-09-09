//链接：https://www.nowcoder.com/practice/6e5207314b5241fb83f2329e89fdecc8?tpId=13&&tqId=11219&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
//来源：牛客网
//地上有一个m行和n列的方格。一个机器人从坐标0, 0的格子开始移动，每一次只能向左，右，上，下四个方向移动一格，但是不能进入行坐标和列坐标的数位
//之和大于k的格子。 例如，当k为18时，机器人能够进入方格（35, 37），因为3 + 5 + 3 + 7 = 18。但是，它不能进入方格（35, 38），因为3 + 5 + 3 + 8
//=19。请问该机器人能够达到多少个格子？
class Solution {
public:
	int movingCount(int threshold, int rows, int cols)
	{
		vector<vector<int>> flag(rows, vector<int>(cols, 0));
		return help(0, 0, rows, cols, threshold, flag);
	}
	int help(int i, int j, int rows, int cols, int threshold, vector<vector<int>>& flag)
	{
		if (i < 0 || j < 0 || i >= rows || j >= cols || numsize(i) + numsize(j) > threshold || flag[i][j] == 1)
			return 0;
		flag[i][j] = 1;
		return help(i - 1, j, rows, cols, threshold, flag)
			+ help(i + 1, j, rows, cols, threshold, flag)
			+ help(i, j - 1, rows, cols, threshold, flag)
			+ help(i, j + 1, rows, cols, threshold, flag) + 1;
	}
	int numsize(int x)
	{
		int sum = 0;
		while (x)
		{
			sum += x % 10;
			x /= 10;
		}
		return sum;
	}
};