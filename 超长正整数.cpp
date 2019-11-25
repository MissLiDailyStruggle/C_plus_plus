//链接：https://www.nowcoder.com/questionTerminal/5821836e0ec140c1aa29510fd05f45fc
//来源：牛客网
//请设计一个算法完成两个超长正整数的加法。
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

string AddLongInter(string addend, string augend)
{
	string result;
	reverse(addend.begin(), addend.end());
	reverse(augend.begin(), augend.end());
	int len = addend.size();
	if (augend.size() > len)
		len = augend.size();
	int res = 0;
	int temp = 0;
	for (int i = 0; i < len; i++)
	{
		if (i < addend.size() && i < augend.size())
			res = (addend[i] - '0') + (augend[i] - '0') + temp;
		else if (i >= addend.size())
			res = (augend[i] - '0') + temp;
		else if (i >= augend.size())
			res = (addend[i] - '0') + temp;
		temp = res / 10;
		char sum = (res % 10) + '0';
		result.push_back(sum);
	}
	if (temp != 0)
		result.push_back(temp + '0');
	reverse(result.begin(), result.end());
	return result;
}

int main()
{
	string addend;
	string augend;
	while (cin >> addend >> augend)
	{
		string res = AddLongInter(addend, augend);
		cout << res << endl;
	}
	return 0;
}