//链接：https://www.nowcoder.com/questionTerminal/181a1a71c7574266ad07f9739f791506
//来源：牛客网
//查找两个字符串a, b中的最长公共子串。若有多个，输出在较短串中最先出现的那个。
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

string lpublic_sub(string str1, string str2)
{
	string str;
	if (str1.size() > str2.size())
		swap(str1, str2);
	for (int i = 0; i < str1.size(); i++)
	{
		for (int j = i; j < str1.size(); j++)
		{
			string temp = str1.substr(i, j - i + 1);
			if ((int)(str2.find(temp)) < 0)
				break;
			else if (temp.size() > str.size())
				str = temp;
		}
	}
	return str;
}

int main()
{
	string str1;
	string str2;
	while (cin >> str1 >> str2)
	{
		string str = lpublic_sub(str1, str2);
		cout << str << endl;
	}
	return 0;
}
