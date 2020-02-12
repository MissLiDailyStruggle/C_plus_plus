//链接：https://www.nowcoder.com/questionTerminal/fbc417f314f745b1978fc751a54ac8cb
//来源：牛客网
//问题描述：给出4个1 - 10的数字，通过加减乘除，得到数字为24就算胜利 输入： 4个1 - 10的数字。[数字允许重复，但每个数字仅允许使用一次，测试用例保证无异常
//数字] 输出： true or false
#include <iostream>
#include <vector>

using namespace std;

bool isget24(vector<int> arr, double res)
{
	if (arr.empty())
		return res == 24;
	for (int i = 0; i < arr.size(); i++)
	{
		vector<int>brr(arr);
		brr.erase(brr.begin() + i);
		if (isget24(brr, res + arr[i])
			|| isget24(brr, res - arr[i])
			|| isget24(brr, res * arr[i])
			|| isget24(brr, res / arr[i]))
			return true;
	}
	return false;
}

int main()
{
	vector<int> arr(4);
	while (cin >> arr[0] >> arr[1] >> arr[2] >> arr[3])
	{
		if (isget24(arr, 0))
			cout << "true" << endl;
		else
			cout << "false" << endl;
	}
}