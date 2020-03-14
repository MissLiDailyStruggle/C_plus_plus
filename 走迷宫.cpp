// 链接：https://www.nowcoder.com/questionTerminal/6276dbbda7094978b0e9ebb183ba37b9
//来源：牛客网
// NowCoder最喜欢游乐场的迷宫游戏，他和小伙伴们比赛谁先走出迷宫。现在把迷宫的地图给你，你能帮他算出最快走出迷宫需要多少步吗？
#include <iostream>
#include <vector>
#include <string>

#define N 10

using namespace std;


void calculate(vector<string>& board, vector<vector<int>>& len, int x, int y)
{
	vector<vector<int>> b = { { -1, 0 }, { 1, 0 }, { 0, -1 }, { 0, 1 } };
	for (int i = 0; i < 4; i++)
	{
		int nx = x + b[i][0];
		int ny = y + b[i][1];
		if (nx < 10 && nx >= 0 && ny < 10 && ny >= 0 && board[nx][ny] != '#')
		{
			if (len[nx][ny] == 0 || (len[x][y] + 1 < len[nx][ny]))
			{
				len[nx][ny] = len[x][y] + 1;
				calculate(board, len, nx, ny);
			}
		}
	}
}
int main()
{
	vector<string> board(N);
	while (getline(cin, board[0]))
	{
		vector<vector<int>> len(N, vector<int>(N, 0));
		for (int i = 1; i < N; i++)
			getline(cin, board[i]);
		calculate(board, len, 0, 1);
		cout << len[9][8] << endl;
	}
	return 0;
}