//链接：https://www.nowcoder.com/question/next?pid=1725829&qid=44802&tid=33019548
//来源：牛客网
//小Q最近遇到了一个难题：把一个字符串的大写字母放到字符串的后面，各个字符的相对位置不变，且不能申请额外的空间。你能帮帮小Q吗？
#include <iostream>
#include <string>

using namespace std;

int main()
{
	string str;
	while (cin >> str)
	{
		for (int i = 0; i < str.size(); i++)
		{
			if (str[i] >= 'a' && str[i] <= 'z')
				cout << str[i];
		}
		for (int i = 0; i < str.size(); i++)
		{
			if (str[i] >= 'A' && str[i] <= 'Z')
				cout << str[i];
		}
		cout << endl;
	}
	return 0;
}