//���ӣ�https://www.nowcoder.com/practice/2b7995aa4f7949d99674d975489cb7da?tpId=46&tqId=29060&tPage=2&rp=2&ru=/ta/leetcode&qru=/ta/leetcode/question-rankin
//��Դ��ţ����
//����һ�������Σ�����������ζ������ײ�����С·���ͣ�ÿһ���������ƶ�������һ�����ڵ����֣�
class Solution {
public:
	int minimumTotal(vector<vector<int> > &triangle) {
		if (triangle.empty())
			return 0;
		vector<vector<int>>min_path(triangle);
		int line = triangle.size();
		for (int i = line - 2; i >= 0; i--)
		{
			for (int j = 0; j <= i; j++)
			{
				min_path[i][j] = min(min_path[i + 1][j], min_path[i + 1][j + 1]) + triangle[i][j];
			}
		}
		return min_path[0][0];
	}
};