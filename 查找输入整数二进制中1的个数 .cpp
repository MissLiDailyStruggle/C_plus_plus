链接：https://www.nowcoder.com/questionTerminal/1b46eb4cf3fa49b9965ac3c2c1caf5ad
来源：牛客网

//链接：https ://www.nowcoder.com/questionTerminal/1b46eb4cf3fa49b9965ac3c2c1caf5ad
//来源：牛客网
//请实现如下接口：
//public static int findNumberOf1(int num)
//{
//	/*请实现*/
//	return 0;
//}
//譬如：输入5 ，5的二进制为101，输出2
#include <iostream>

using namespace std;

int findNumberOf1(int num)
{
	int count = 0;
	while (num)
	{
		if ((num & 1) == 1)
			count++;
		num >>= 1;
	}
	return count;
}

int main()
{
	int num;
	while (cin >> num)
	{
		int res = findNumberOf1(num);
		cout << res << endl;
	}
	return 0;
}