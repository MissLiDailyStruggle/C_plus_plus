//链接：https://www.nowcoder.com/questionTerminal/b0ae3d72444a40e2bb14af7d4cb856ba
//来源：牛客网
//将一句话的单词进行倒置，标点不倒置。比如 I like beijing.经过函数后变为：beijing.like I
#include <iostream>
#include <string>
#include <stdlib.h>
#include <algorithm>

using namespace std;

int main()
{
	string str;
	while (getline(cin, str))
	{
		reverse(str.begin(), str.end());
		auto start = str.begin();
		while (start != str.end())
		{
			auto end = start;
			while (end != str.end() && *end != ' ')
				end++;
			reverse(start, end);
			if (end != str.end())
				start = end + 1;
			else
				start = end;
		}
		cout << str << endl;
	}
	return 0;
}