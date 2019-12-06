#include <iostream>
//链接：https://www.nowcoder.com/questionTerminal/c67a09062c0f4a5b964eef0945d3dd06
//来源：牛客网
//给定三条边，请你判断一下能不能组成一个三角形。
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{
	double a, b, c;
	while (cin >> a >> b >> c)
	{
		if ((a + b > c) && (b + c > a) && (a + c > b))
		{
			if ((c > abs(a - b)) && (b > abs(a - c)) && (a > abs(b - c)))
				cout << "Yes" << endl;
			else
				cout << "No" << endl;
		}
		else
			cout << "No" << endl;
	}
	return 0;
}