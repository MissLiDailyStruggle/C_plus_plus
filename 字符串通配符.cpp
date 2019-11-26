//链接：https://www.nowcoder.com/questionTerminal/43072d50a6eb44d2a6c816a283b02036
//来源：牛客网
//问题描述：在计算机中，通配符一种特殊语法，广泛应用于文件搜索、数据库、正则表达式等领域。现要求各位实现字符串通配符的算法。
//要求：实现如下2个通配符：*：匹配0个或以上的字符（字符由英文字母和数字0 - 9组成，不区分大小写。下同）？：匹配1个字符。
#include <iostream>
#include <string>

using namespace std;

int main()
{
	string stan;
	string str;
	while (cin >> stan >> str)
	{
		int i = 0;
		int j = 0;
		bool flag = false;
		while ((i < stan.size()) || j < str.size())
		{
			if (stan[i] == '*')
			{
				i++;
				flag = true;
			}
			else if ((stan[i] == str[j]) || (stan[i] == '?'))
			{
				i++;
				j++;
			}
			else if (flag == true)
			{
				while (stan[i] != str[j])
					j++;
				flag = false;
			}
			else
			{
				cout << "false" << endl;
				break;
			}
		}
		if ((i >= stan.size()) && j >= str.size())
			cout << "true" << endl;
	}
	return 0;
}