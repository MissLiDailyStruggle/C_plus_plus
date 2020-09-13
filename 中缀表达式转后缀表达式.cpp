//链接：https://www.nowcoder.com/questionTerminal/4e7267b55fdf430d9403aa12206572b3
//来源：牛客网
//将中缀表达式转为后缀表达式，输入 a + b*c / d - a + f / b 输出 abc*d / +a - fb / +要求：语言不限；输入输出均为单个字符串；操作数用单个小写字
//母表示，操作符只需支持 + -*/ ，按照四则运算顺序确定优先级，不包含括号
#include <iostream>
#include <string>
#include <stack>
#include <map>

using namespace std;

int main()
{
	string str;
	getline(cin, str);
	stack<char>s;
	map<char, int>mm;
	mm['+'] = mm['-'] = 1;
	mm['*'] = mm['/'] = 2;
	for (int i = 0; i < str.size(); ++i)
	{
		if (isalpha(str[i]))
			cout << str[i];
		else
		{
			while (!s.empty() && mm[str[i]] <= mm[s.top()])
			{
				cout << s.top();
				s.pop();
			}
			s.push(str[i]);
		}
	}
	while (!s.empty())
	{
		cout << s.top();
		s.pop();
	}
	cout << endl;
	return 0;
}