//链接：https://www.nowcoder.com/questionTerminal/e2422543519249f292d8435394ab82fe
//来源：牛客网
//数根可以通过把一个数的各个位上的数字加起来得到。如果得到的数是一位数，那么这个数就是数根；如果结果是两位数或者包括更多位的数字，
//那么再把这些数字加起来。如此进行下去，直到得到是一位数为止。
#include <iostream>

using namespace std;

int main()
{
	string s;
	while (cin >> s)
	{
		int digroot = 0;
		for (int i = 0; i < s.size(); i++)
			digroot += (s[i] - '0');
		while (digroot >= 10)
		{
			int n = 0;
			while (digroot)
			{
				n += (digroot % 10);
				digroot /= 10;
			}
			digroot = n;
		}
		cout << digroot << endl;
	}
	return 0;
}