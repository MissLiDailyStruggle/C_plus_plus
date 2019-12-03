//链接：https://www.nowcoder.com/questionTerminal/3959837097c7413a961a135d7104c314
//来源：牛客网
//Levenshtein 距离，又称编辑距离，指的是两个字符串之间，由一个转换成另一个所需的最少编辑操作次数。许可的编辑操作包括将一个字符替换成
//另一个字符，插入一个字符，删除一个字符。编辑距离的算法是首先由俄国科学家Levenshtein提出的，故又叫Levenshtein Distance。
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