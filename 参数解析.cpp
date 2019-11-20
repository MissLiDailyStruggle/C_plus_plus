//链接：https://www.nowcoder.com/questionTerminal/668603dc307e4ef4bb07bcd0615ea677
//来源：牛客网
//在命令行输入如下命令：
//xcopy / s c : \ d : \，
//各个参数如下：
//参数1：命令字xcopy
//参数2：字符串 / s
//参数3：字符串c : \
//参数4 : 字符串d : \
//请编写一个参数解析程序，实现将命令行各个参数解析出来。
#include <iostream>
#include <string>

using namespace std;

int main()
{
	string s;
	int count = 1;
	getline(cin, s);
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == ' ')
			count++;
	}
	cout << count << endl;
	for (int i = 0; i < s.size(); i++)
	{
		cout << s[i];
		if (s[i] == ' ')
			cout << endl;
	}
	cout << endl;
	return 0;
}
