//���ӣ�https://www.nowcoder.com/questionTerminal/72a99e28381a407991f2c96d8cb238ab
//��Դ��ţ����
//С�����ڹ�˾Ҫ�����ս�����С��ǡ�û������߸�������Ҫ�ڹ�˾����ϲ���һ���齱��Ϸ����Ϸ��һ��6 * 6�������Ͻ��У��������36����ֵ
//���ȵ����ÿ��С���������������һ���������Ҫ�����Ͻǿ�ʼ��Ϸ��ÿ��ֻ�����»��������ƶ�һ�����������½�ֹͣ��һ·�ϵĸ������
//����С�������õ��������һ���㷨ʹС���õ���ֵ��ߵ����
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