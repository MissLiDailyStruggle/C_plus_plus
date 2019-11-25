//链接：https://www.nowcoder.com/questionTerminal/8ef655edf42d4e08b44be4d777edbf43
//来源：牛客网
//以上三角形的数阵，第一行只有一个数1，以下每行的每个数，是恰好是它上面的数，左上角数到右上角的数，3个数之和（如果不存在某个数，认为
//该数就是0）。求第n行第一个偶数出现的位置。如果没有偶数，则输出 - 1。例如输入3, 则输出2，输入4则输出3。
#include <iostream>
#include <vector>

using namespace std;

int judge_index(int n)
{
	vector<vector<int>> triangle;
	triangle.resize(n + 1, vector<int>(2 * n, 0));
	triangle[1][1] = 1;
	for (int i = 2; i <= n; i++)
	{
		triangle[i][1] = 1;
		for (int j = 2; j <= 2 * i - 1; j++)
			triangle[i][j] = triangle[i - 1][j - 2] + triangle[i - 1][j - 1] + triangle[i - 1][j];
	}
	for (int i = 2; i <= n; i++)
	{
		if ((triangle[n][i] != 0) && (triangle[n][i] % 2 == 0))
			return i;
	}
	return -1;
}

int main()
{
	int n;
	while (cin >> n)
	{
		int index = judge_index(n);
		cout << index << endl;
	}
	return 0;
}