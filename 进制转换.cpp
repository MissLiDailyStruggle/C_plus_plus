//链接：https://www.nowcoder.com/questionTerminal/ac61207721a34b74b06597fe6eb67c52
//来源：牛客网
//给定一个十进制数M，以及需要转换的进制数N。将十进制数M转化为N进制数
#include <iostream>
#include <stack>

using namespace std;

int main()
{
	stack<int> st;
	long m = 0;
	int n = 0;
	int temp = 0;
	cin >> m >> n;
	int flag = 0;
	if (m < 0)
	{
		m = -m;;
		flag = 1;
	}
	while (m)
	{
		temp = m % n;
		if (temp > 9)
		{
			temp = 'A' + (temp - 10);
		}
		st.push(temp);
		m /= n;
	}
	if (flag == 1)
		cout << '-';
	while (!st.empty())
	{
		int top = st.top();
		st.pop();
		if (top < 9)
			cout << top;
		else
			cout << (char)top;
	}
	cout << endl;
}