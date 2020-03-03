//链接：https://www.nowcoder.com/questionTerminal/c0a4b917a15f40a49ca10532ab9019fb
//来源：牛客网
//NowCoder号称自己已经记住了1 - 100000之间所有的斐波那契数。为了考验他，我们随便出一个数n，让他说出第n个斐波那契数。当然，斐波那契数会很大。因此，如
//果第n个斐波那契数不到6位，则说出该数；否则只说出最后6位。
#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

int main()
{
	vector<int> arr;
	arr.resize(100001);
	arr[0] = 1;
	arr[1] = 1;
	for (int i = 2; i < 100002; i++)
	{
		arr[i] = arr[i - 1] + arr[i - 2];
		if (arr[i] / 1000000 > 0)
			arr[i] = arr[i] % 1000000;
	}
	int n;
	while (cin >> n)
	{
		if (n < 31)
			cout << arr[n] << endl;
		else
		{
			cout << setfill('0') << setw(6) << arr[n] << endl;
		}
	}
	return 0;
}