//���ӣ�https://www.nowcoder.com/questionTerminal/2d3f6ddd82da445d804c95db22dcc471
//��Դ��ţ����
//����һ���ַ���str������ַ���str�е�����������ִ�
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