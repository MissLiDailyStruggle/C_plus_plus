//���ӣ�https://www.nowcoder.com/questionTerminal/e1bb714eb9924188a0d5a6df2216a3d1
//��Դ��ţ����
//����һ�������ľ��������̣������һ����Ч�㷨�жϵ�ǰ����Ƿ��ʤ��
//����һ����ά����board������ǰ���̣�����Ԫ��Ϊ1�Ĵ����ǵ�ǰ��ҵ����ӣ�Ϊ0��ʾû�����ӣ�Ϊ - 1�����ǶԷ���ҵ����ӡ�
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