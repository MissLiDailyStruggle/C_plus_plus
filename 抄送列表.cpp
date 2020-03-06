//链接：https://www.nowcoder.com/questionTerminal/286af664b17243deb745f69138f8a800
//来源：牛客网
//NowCoder每天要处理许多邮件，但他并不是在收件人列表中，有时候只是被抄送。他认为这些抄送的邮件重要性比自己在收件人列表里的邮件低，因此他要过滤掉这些
//次要的邮件，优先处理重要的邮件。现在给你一串抄送列表，请你判断目标用户是否在抄送列表中。
#include <iostream>
#include <map>
#include <string>
using namespace std;

int main()
{
	string str1, str2;
	while (getline(cin, str1))
	{
		getline(cin, str2);
		map<string, int> dict;
		for (int i = 0; i < str1.size(); i++)
		{
			string temp;
			if (str1[i] == '"')
			{
				i++;
				while (i < str1.size() && str1[i] != '"')
				{
					temp += str1[i];
					i++;
				}
				dict.insert(make_pair(temp, 1));
			}
			else
			{
				while (i < str1.size() && str1[i] != ',')
				{
					temp += str1[i];
					i++;
				}
				dict.insert(make_pair(temp, 1));;
			}
		}
		if (dict[str2] == 1)
			cout << "Ignore" << endl;
		else
			cout << "Important!" << endl;
	}
	return 0;
}