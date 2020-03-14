//链接：https://www.nowcoder.com/questionTerminal/a811535fed784ea492b63622c28c75c5
//来源：牛客网
//NowCoder最近爱上了五子棋，现在给你一个棋局，请你帮忙判断其中有没有五子连珠（超过五颗也算）。
#include <iostream>
#include <vector>
#include <string>
#define ROW 20
#define COLUMN 20

using namespace std;

int count(vector<string>& table, char ch, int x, int y)
{
	int maxcount = 0;
	vector<vector<vector<int>>> dir =
	{ { { -1, 0 }, { 1, 0 } }, { { 0, -1 }, { 0, 1 } }, { { -1, -1 }, { 1, 1 } }, { { -1, 1 }, { 1, -1 } } };
	for (int i = 0; i < dir.size(); ++i)
	{
		int count = 0;
		for (int j = 0; j < dir[0].size(); ++j)
		{
			int nx = x, ny = y;
			while (nx >= 0 && nx < ROW && ny >= 0 && ny < COLUMN && table[nx][ny] == ch)
			{
				nx += dir[i][j][0];
				ny += dir[i][j][1];
				++count;
			}
		}
		maxcount = (maxcount > count ? maxcount : count);
	}
	return maxcount - 1;
}

bool solve(vector<string>& table)
{
	for (int i = 0; i < ROW; ++i)
	{
		for (int j = 0; j < COLUMN; ++j)
		{
			if (table[i][j] == '*' || table[i][j] == '+')
			if (count(table, table[i][j], i, j) >= 5)
				return true;
		}
	}
	return false;
}

int main()
{
	vector<string> board(ROW);
	while (getline(cin, board[0]))
	{
		for (int i = 1; i < ROW; i++)
			getline(cin, board[i]);
		bool res = solve(board);
		if (res)
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}
	return 0;
}