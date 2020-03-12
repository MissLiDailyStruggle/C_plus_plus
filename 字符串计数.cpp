//链接：https://www.nowcoder.com/questionTerminal/f72adfe389b84da7a4986bde2a886ec3
//来源：牛客网
//求字典序在s1和s2之间的，长度在len1到len2的字符串的个数，结果mod 1000007。
#include <iostream>
#include <math.h>
#include <string>

using namespace std;

int main()
{
	string str1, str2;
	int len1, len2;
	while (cin >> str1 >> str2 >> len1 >> len2)
	{
		int num = 0;
		if (str1.size() < len2)
			str1.append(len2 - str1.size(), 'a');
		if (str2.size() < len2)
			str2.append(len2 - str2.size(), 'a');
		for (int i = len1; i <= len2; i++)
		{
			for (int j = 0; j < i; j++)
				num = num + (str2[j] - str1[j])*pow(26, i - j - 1);
		}
		cout << num - 1 << endl;
	}
	return 0;
}