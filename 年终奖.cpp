//链接：https://www.nowcoder.com/questionTerminal/72a99e28381a407991f2c96d8cb238ab
//来源：牛客网
//小东所在公司要发年终奖，而小东恰好获得了最高福利，他要在公司年会上参与一个抽奖游戏，游戏在一个6 * 6的棋盘上进行，上面放着36个价值
//不等的礼物，每个小的棋盘上面放置着一个礼物，他需要从左上角开始游戏，每次只能向下或者向右移动一步，到达右下角停止，一路上的格子里的
//礼物小东都能拿到，请设计一个算法使小东拿到价值最高的礼物。
class Bonus {
public:
	int getMost(vector<vector<int> > board) {
		// write code here
		for (int i = 0; i < board.size(); i++)
		{
			for (int j = 0; j < board[0].size(); j++)
			{
				if (i == 0)
					board[i][j] += board[i][j - 1];
				else if (j == 0)
					board[i][j] += board[i - 1][j];
				else
					board[i][j] += max(board[i][j - 1], board[i - 1][j]);
			}
		}
		return board[5][5];
	}
};