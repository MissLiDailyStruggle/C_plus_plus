//���ӣ�https://www.nowcoder.com/questionTerminal/b0ae3d72444a40e2bb14af7d4cb856ba
//��Դ��ţ����
//��һ�仰�ĵ��ʽ��е��ã���㲻���á����� I like beijing.�����������Ϊ��beijing.like I
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