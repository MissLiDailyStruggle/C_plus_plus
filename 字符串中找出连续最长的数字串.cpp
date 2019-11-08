//链接：https://www.nowcoder.com/questionTerminal/2d3f6ddd82da445d804c95db22dcc471
//来源：牛客网
//读入一个字符串str，输出字符串str中的连续最长的数字串
#include <iostream>
#include <string>

using namespace std;

int main()
{
	string str;
	while (getline(cin, str))
	{
		int i = 0;
		int max = 0;
		int tempi = 0;
		int start = 0;
		while (i<str.size())
		{
			if (str[i] >= '0' && str[i] <= '9')
			{
				int count = 0;
				tempi = i;
				while (str[i] >= '0' && str[i] <= '9')
				{
					++count;
					i++;
				}
				if (count > max)
				{
					max = count;
					start = tempi;
				}
			}
			else
				i++;
		}
		cout << str.substr(start, max) << endl;
	}
	return 0;
}