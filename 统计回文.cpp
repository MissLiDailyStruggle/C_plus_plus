//链接：https://www.nowcoder.com/questionTerminal/9d1559511b3849deaa71b576fa7009dc
//来源：牛客网
//“回文串”是一个正读和反读都一样的字符串，比如“level”或者“noon”等等就是回文串。花花非常喜欢这种拥有对称美
//的回文串，生日的时候她得到两个礼物分别是字符串A和字符串B。现在她非常好奇有没有办法将字符串B插入字符串A使产生的
//字符串是一个回文串。你接受花花的请求，帮助她寻找有多少种插入办法可以使新串是一个回文串。如果字符串B插入的位置不
//同就考虑为不一样的办法。
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

bool plalindrome(string str)
{
	string tmp = str;
	reverse(str.begin(), str.end());
	for (int i = 0; i < tmp.size(); i++)
	{
		if (tmp[i] != str[i])
			return false;
	}
	return true;
}

int main()
{
	string A;
	string B;
	cin >> A;
	cin >> B;
	int count = 0;
	for (int i = 0; i <= A.size(); i++)
	{
		string str = A;
		str.insert(i, B);
		if (plalindrome(str))
			count++;
	}
	cout << count << endl;
}