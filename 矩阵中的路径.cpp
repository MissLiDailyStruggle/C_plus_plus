//链接：https://www.nowcoder.com/practice/c61c6999eecb4b8f88a98f66b273a3cc?tpId=13&&tqId=11218&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
//来源：牛客网
//请设计一个函数，用来判断在一个矩阵中是否存在一条包含某字符串所有字符的路径。路径可以从矩阵中的任意一个格子开始，每一步可以在矩阵中向左，
//向右，向上，向下移动一个格子。如果一条路径经过了矩阵中的某一个格子，则该路径不能再进入该格子。
class Solution {
public:
	bool hasPath(char* matrix, int rows, int cols, char* str)
	{
		if (matrix == nullptr || rows < 1 || cols < 1 || str == nullptr)
			return false;
		vector<bool> flag(rows*cols, 0);
		for (int i = 0; i < rows; ++i)
		{
			for (int j = 0; j < cols; ++j)
			{
				if (helper(matrix, i, j, rows, cols, flag, str, 0))
					return true;
			}
		}
		return false;
	}
	bool helper(char* matrix, int i, int j, int rows, int cols, vector<bool> flag, char* str, int k)
	{
		int index = i * cols + j;
		if (i < 0 || j < 0 || i >= rows || j >= cols || matrix[index] != str[k] || flag[index] == true)
			return false;
		if (str[k + 1] == '\0')
			return true;
		flag[index] = true;
		if (helper(matrix, i - 1, j, rows, cols, flag, str, k + 1)
			|| helper(matrix, i + 1, j, rows, cols, flag, str, k + 1)
			|| helper(matrix, i, j - 1, rows, cols, flag, str, k + 1)
			|| helper(matrix, i, j + 1, rows, cols, flag, str, k + 1))
			return true;
		flag[index] = false;
		return false;
	}
};