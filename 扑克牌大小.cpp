//链接：https://www.nowcoder.com/questionTerminal/d290db02bacc4c40965ac31d16b1c3eb
//来源：牛客网
//扑克牌游戏大家应该都比较熟悉了，一副牌由54张组成，含3~A、2各4张，小王1张，大王1张。牌面从小到大用如下字符和字符串表示
//（其中，小写joker表示小王，大写JOKER表示大王）：3 4 5 6 7 8 9 10 J Q K A 2 joker JOKER输入两手牌，两手牌之间用"-"连接，
//每手牌的每张牌以空格分隔，"-"两边没有空格，如：4 4 4 4 - joker JOKER。请比较两手牌大小，输出较大的牌，如果不存在比较关
//系则输出ERROR。
#include <iostream>
#include <algorithm>
#include <string>
#include<unordered_map>

using namespace std;

unordered_map<char, int> help{ { '3', 1 }, { '4', 2 }, { '5', 3 }, { '6', 4 }, { '7', 5 }, { '8', 6 }, { '9', 7 }, { '1', 8 }, { 'J', 9 }, { 'Q', 10 }, { 'K', 11 }, { 'A', 12 }, { '2', 13 } };

int main()
{
	string str;
	string str1, str2;
	int win = -1;
	while (getline(cin, str))
	{
		for (int i = 0; (i + 1) < str.size(); i++)
		{
			if (str[i] == '1' && str[++i] == '0')
			{
				str.erase(i, 1);
				i--;
			}
		}
		str1 = str.substr(0, str.find('-'));
		str2 = str.substr(str.find('-') + 1);
		if (str1 == "joker JOKER")
			win = 1;
		else if (str2 == "joker JOKER")
			win = 2;
		else if ((str1.size() == 7) && (str2.size() == 7))
		{
			if (help[str1[0]] > help[str2[0]])
				win = 1;
			else if (help[str1[0]] < help[str2[0]])
				win = 2;
		}
		else if (str1.size() == 7)
			win = 1;
		else if (str2.size() == 7)
			win = 2;
		else if (str1 == "joker" || str1 == "JOKER")
			win = 1;
		else if (str2 == "joker" || str2 == "JOKER")
			win = 2;
		else if ((str1.size() == 1) && (str2.size() == 1))
		{
			if (help[str1[0]] > help[str2[0]])
				win = 1;
			else if (help[str1[0]] < help[str2[0]])
				win = 2;
		}
		else if ((str1.size() == 2) && (str2.size() == 2))
		{
			if (help[str1[0]] > help[str2[0]])
				win = 1;
			else if (help[str1[0]] < help[str2[0]])
				win = 2;
		}
		else if ((str1.size() == 3) && (str2.size() == 3))
		{
			if (help[str1[0]] > help[str2[0]])
				win = 1;
			else if (help[str1[0]] < help[str2[0]])
				win = 2;
		}
		else if ((str1.size() == 5) && (str2.size() == 5))
		{
			if (help[str1[0]] > help[str2[0]])
				win = 1;
			else if (help[str1[0]] < help[str2[0]])
				win = 2;
		}
		else if ((str1.size() >= 9) && (str2.size() == str1.size()))
		{
			if (help[str1[0]] > help[str2[0]])
				win = 1;
			else if (help[str1[0]] < help[str2[0]])
				win = 2;
		}
		else
			win = 0;
		if (win == 1)
		{
			for (int i = 0; i < str1.size(); i++)
			{
				if (str1[i] == '1')
					str1.insert(++i, 1, '0');
			}
			cout << str1 << endl;
		}
		else if (win == 2)
		{
			for (int i = 0; i < str2.size(); i++)
			{
				if (str2[i] == '1')
					str2.insert(++i, 1, '0');
			}
			cout << str2 << endl;
		}
		else
			cout << "ERROR" << endl;
	}
	return 0;
}