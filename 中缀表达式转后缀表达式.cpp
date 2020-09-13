//���ӣ�https://www.nowcoder.com/questionTerminal/4e7267b55fdf430d9403aa12206572b3
//��Դ��ţ����
//����׺���ʽתΪ��׺���ʽ������ a + b*c / d - a + f / b ��� abc*d / +a - fb / +Ҫ�����Բ��ޣ����������Ϊ�����ַ������������õ���Сд��
//ĸ��ʾ��������ֻ��֧�� + -*/ ��������������˳��ȷ�����ȼ�������������
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