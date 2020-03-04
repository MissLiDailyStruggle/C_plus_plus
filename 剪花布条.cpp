//链接：https://www.nowcoder.com/questionTerminal/1046cd038f7a4b04b2b77b415973de1c
//来源：牛客网
//一块花布条，里面有些图案，另有一块直接可用的小饰条，里面也有一些图案。对于给定的花布条和小饰条，计算一下能从花布条中尽可能剪出几块小饰条来呢？ 
#include <iostream>
#include <string>

using namespace std;

int main()
{
	string str1, str2;
	while (cin >> str1 >> str2)
	{
		int count = 0;
		int i = 0;
		int j = 0;
		while (i < str1.size())
		{
			j = 0;
			while (j < str2.size())
			{
				if (i < str1.size() && j < str2.size() && str1[i] == str2[j])
				{
					i++;
					j++;
				}
				else
				{
					i++;
					break;
				}
			}
			if (j == str2.size())
				count++;
		}
		cout << count << endl;
	}
	return 0;
}