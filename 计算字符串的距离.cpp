//���ӣ�https://www.nowcoder.com/questionTerminal/3959837097c7413a961a135d7104c314
//��Դ��ţ����
//Levenshtein ���룬�ֳƱ༭���룬ָ���������ַ���֮�䣬��һ��ת������һ����������ٱ༭������������ɵı༭����������һ���ַ��滻��
//��һ���ַ�������һ���ַ���ɾ��һ���ַ����༭������㷨�������ɶ����ѧ��Levenshtein����ģ����ֽ�Levenshtein Distance��
#include <iostream>
#include <vector>
#include<algorithm>
#include <string>

using namespace std;

int calStringDistance(string str1, string str2)
{
	int n = str1.size();
	int m = str2.size();
	vector<vector<int>>dp(n + 1, vector<int>(m + 1));
	dp[0][0] = 0;
	for (int i = 1; i <= n; ++i)
		dp[i][0] = i;
	for (int i = 1; i <= m; ++i)
		dp[0][i] = i;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			int ic = dp[i - 1][j] + 1;
			int dc = dp[i][j - 1] + 1;
			int rc = dp[i - 1][j - 1];
			if (str1[i - 1] != str2[j - 1])
				rc++;
			dp[i][j] = min((min(ic, dc)), rc);
		}
	}
	return dp[n][m];
}

int main()
{
	string str1;
	string str2;
	while (cin >> str1 >> str2)
	{
		int ret = calStringDistance(str1, str2);
		cout << ret << endl;
	}
	return 0;
}