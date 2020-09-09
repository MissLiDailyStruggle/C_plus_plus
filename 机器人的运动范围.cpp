//���ӣ�https://www.nowcoder.com/practice/6e5207314b5241fb83f2329e89fdecc8?tpId=13&&tqId=11219&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
//��Դ��ţ����
//������һ��m�к�n�еķ���һ�������˴�����0, 0�ĸ��ӿ�ʼ�ƶ���ÿһ��ֻ�������ң��ϣ����ĸ������ƶ�һ�񣬵��ǲ��ܽ�������������������λ
//֮�ʹ���k�ĸ��ӡ� ���磬��kΪ18ʱ���������ܹ����뷽��35, 37������Ϊ3 + 5 + 3 + 7 = 18�����ǣ������ܽ��뷽��35, 38������Ϊ3 + 5 + 3 + 8
//=19�����ʸû������ܹ��ﵽ���ٸ����ӣ�
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