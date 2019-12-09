//链接：https://www.nowcoder.com/questionTerminal/16f59b169d904f8898d70d81d4a140a0
//来源：牛客网
//输入一个英文句子，把句子中的单词(不区分大小写)按出现次数按从多到少把单词和次数在屏幕上输出来，要求能识别英文句号和逗号，即是说单词由空格、句号和逗号隔开。
#include <iostream>
#include <map>

using namespace std;

int main()
{
	map<string, int>dict;
	string str;
	while (cin >> str)
	{
		for (int i = 0; i < str.size(); i++)
		{
			if (str[i] >= 'A' && str[i] <= 'Z')
				str[i] += 32;
			if (str[i] == ',')
				str.erase(i, 1);
			if (str[i] == '.')
				str.erase(i, 1);
		}
		dict[str]++;
	}
	for (auto e : dict)
	{
		cout << e.first << ":" << e.second << endl;
	}
	return 0;
}