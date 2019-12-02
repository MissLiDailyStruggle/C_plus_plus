//链接：https://www.nowcoder.com/questionTerminal/eaf5b886bd6645dd9cfb5406f3753e15
//来源：牛客网
//MP3 Player因为屏幕较小，显示歌曲列表的时候每屏只能显示几首歌曲，用户要通过上下键才能浏览所有的歌曲。为了简化处理，
//假设每屏只能显示4首歌曲，光标初始的位置为第1首歌。
#include <iostream>

using namespace std;

int main()
{
	int n;
	string str;
	while (cin >> n >> str)
	{
		int cur = 1;
		int first = 1;
		if (n <= 4)
		{
			for (int i = 0; i < str.size(); i++)
			{
				if (str[i] == 'U')
				{
					if (cur == 1)
						cur = n;
					else
						cur--;
				}
				else if (str[i] == 'D')
				{
					if (cur == n)
						cur = 1;
					else
						cur++;
				}
			}
			for (int i = first; i < n; i++)
				cout << i << " ";
			cout << n << endl << cur << endl;
		}
		else
		{
			for (int i = 0; i < str.size(); i++)
			{
				if (str[i] == 'U')
				{
					if (cur == 1)
					{
						cur = n;
						first = n - 3;
					}
					else if (cur == first)
					{
						first--;
						cur--;
					}
					else
						cur--;
				}
				else if (str[i] == 'D')
				{
					if (cur == n)
					{
						cur = 1;
						first = 1;
					}
					else if (cur == first + 3)
					{
						first++;
						cur++;
					}
					else
						cur++;
				}
			}
			for (int i = first; i < (first + 3); i++)
				cout << i << " ";
			cout << first + 3 << endl << cur << endl;
		}
	}
	return 0;
}