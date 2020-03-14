// 链接：https://www.nowcoder.com/questionTerminal/1a92fbc771a54feb9eb5bd9b3ff2d0a9#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main()
{
	int n;
	while (cin >> n)
	{
		stack<int> s;
		for (int i = 0; i < n; i++)
		{
			string ch;
			cin >> ch;
			if (ch[0] == '+' || ch[0] == '-' || ch[0] == '*' || ch[0] == '/')
			{
				int res;
				int second = s.top();
				s.pop();
				int first = s.top();
				s.pop();
				if (ch[0] == '+')
					res = first + second;
				else if (ch[0] == '-')
					res = first - second;
				else if (ch[0] == '*')
					res = first * second;
				else
					res = first / second;
				s.push(res);
			}
			else
				s.push(atoi(ch.c_str()));
		}
		cout << s.top() << endl;
	}
	return 0;
}
//来源：牛客网
//Emacs号称神的编辑器，它自带了一个计算器。与其他计算器不同，它是基于后缀表达式的，即运算符在操作数的后面。例如“2 3 + ”等价于中缀表达式的“2 +
//3”。请你实现一个后缀表达式的计算器。