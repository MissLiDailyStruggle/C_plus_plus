//���ӣ�https://www.nowcoder.com/practice/05fed41805ae4394ab6607d0d745c8e4?tpId=188&&tqId=35471&rp=1&ru=/ta/job-code-high-week&qru=/ta/job-code-high-week/question-ranking
//��Դ��ţ����
//���������ַ���str1��str2���ٸ�����������ic��dc��rc���ֱ������롢ɾ�����滻һ���ַ��Ĵ��ۣ��������str1�༭��str2����С���ۡ�
class Solution {
public:
	/**
	* min edit cost
	* @param str1 string�ַ��� the string
	* @param str2 string�ַ��� the string
	* @param ic int���� insert cost
	* @param dc int���� delete cost
	* @param rc int���� replace cost
	* @return int����
	*/
	//���롢ɾ�����滻
	int minEditCost(string str1, string str2, int ic, int dc, int rc) {
		// write code here
		int length1 = str1.size();
		int length2 = str2.size();
		if (str1.size() == 0)
			return str2.size()*ic;
		if (str2.size() == 0)
			return str1.size()*dc;
		vector<vector<int>>dp(length1 + 1, vector<int>(length2 + 1));
		for (int i = 0; i <= length1; ++i)
			dp[i][0] = i * dc;
		for (int i = 0; i <= length2; ++i)
			dp[0][i] = i * ic;
		int costtmp;
		for (int i = 1; i <= length1; i++)
		{
			for (int j = 1; j <= length2; j++)
			{
				costtmp = (str1[i - 1] == str2[j - 1]) ? 0 : rc;
				dp[i][j] = min(min(dp[i - 1][j] + dc, dp[i][j - 1] + ic), dp[i - 1][j - 1] + costtmp);
			}
		}
		return dp[length1][length2];
	}
};