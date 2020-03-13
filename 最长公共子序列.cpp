//链接：https://www.nowcoder.com/questionTerminal/9ae56e5bdf4f480387df781671db5172
//来源：牛客网
//我们有两个字符串m和n，如果它们的子串a和b内容相同，则称a和b是m和n的公共子序列。子串中的字符不一定在原字符串中连续。例如字符串“abcfbc”和“abfca
//b”，其中“abc”同时出现在两个字符串中，因此“abc”是它们的公共子序列。此外，“ab”、“af”等都是它们的字串。现在给你两个任意字符串（不包含空格）
//，请帮忙计算它们的最长公共子序列的长度。
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
	string str1, str2;
	while (cin >> str1 >> str2)
	{
		vector<vector<int>> arr;
		int len1 = str1.size();
		int len2 = str2.size();
		arr.resize(len1 + 1, vector<int>(len2 + 1));
		for (int i = 1; i <= len1; i++)
		{
			for (int j = 1; j <= len2; j++)
			{
				if (str1[i - 1] == str2[j - 1])
					arr[i][j] = arr[i - 1][j - 1] + 1;
				else
					arr[i][j] = max(arr[i - 1][j], arr[i][j - 1]);
			}
		}
		cout << arr[len1][len2] << endl;
	}
	return 0;
}