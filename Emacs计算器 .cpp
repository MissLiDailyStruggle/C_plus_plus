// ���ӣ�https://www.nowcoder.com/questionTerminal/1a92fbc771a54feb9eb5bd9b3ff2d0a9#include <iostream>
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
//��Դ��ţ����
//Emacs�ų���ı༭�������Դ���һ������������������������ͬ�����ǻ��ں�׺���ʽ�ģ���������ڲ������ĺ��档���硰2 3 + ���ȼ�����׺���ʽ�ġ�2 +
//3��������ʵ��һ����׺���ʽ�ļ�������