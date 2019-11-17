//链接：https://www.nowcoder.com/questionTerminal/e1bb714eb9924188a0d5a6df2216a3d1
//来源：牛客网
//对于一个给定的井字棋棋盘，请设计一个高效算法判断当前玩家是否获胜。
//给定一个二维数组board，代表当前棋盘，其中元素为1的代表是当前玩家的棋子，为0表示没有棋子，为 - 1代表是对方玩家的棋子。
class Board {
public:
	bool checkWon(vector<vector<int> > board) {
		int row = board.size();
		int col = board[0].size();
		for (int i = 0; i < row; i++)
		{
			int sum = 0;
			for (int j = 0; j < col; j++)
			{
				if (board[i][j] == 1)
					sum++;
			}
			if (sum == row)
				return true;
		}
		for (int j = 0; j < col; j++)
		{
			int sum = 0;
			for (int i = 0; i < row; i++)
			{
				if (board[i][j] == 1)
					sum++;
			}
			if (sum == row)
				return true;
		}
		int sum = 0;
		for (int i = 0; i < row; i++)
		{
			if (board[i][i] == 1)
				sum++;
		}
		if (sum == row)
			return true;
		return false;
	}
};