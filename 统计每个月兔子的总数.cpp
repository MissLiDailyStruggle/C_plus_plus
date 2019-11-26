//链接：https://www.nowcoder.com/questionTerminal/1221ec77125d4370833fd3ad5ba72395
//来源：牛客网
//有一只兔子，从出生后第3个月起每个月都生一只兔子，小兔子长到第三个月后每个月又生一只兔子，假如兔子都不死，问每个月的兔子总数为多少？
#include <iostream>

using namespace std;

int getTotalCount(int month)
{
	int count = 0;
	if (month == 1)
		return 1;
	else if (month == 2)
		return 1;
	else
		return getTotalCount(month - 1) + getTotalCount(month - 2);
}

int main()
{
	int month;
	while (cin >> month)
	{
		int sum = getTotalCount(month);
		cout << sum << endl;
	}
	return 0;
}