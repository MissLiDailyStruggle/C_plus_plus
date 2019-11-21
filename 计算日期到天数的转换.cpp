//链接：https://www.nowcoder.com/questionTerminal/769d45d455fe40b385ba32f97e7bcded
//来源：牛客网
//根据输入的日期，计算是这一年的第几天。。
//详细描述：
//输入某年某月某日，判断这一天是这一年的第几天？。
#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int year;
	int month;
	int day;
	while (cin >> year >> month >> day)
	{
		int sum = 0;
		vector<int>v(12, 0);
		v[month] = day;
		for (int i = 1; i < month; i++)
		{
			if (i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10 || i == 12)
				v[i] = 31;
			else if (i == 4 || i == 6 || i == 9 || i == 11)
				v[i] = 30;
			else if (i == 2)
			{
				if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
					v[i] = 29;
				else
					v[i] = 28;
			}
		}
		for (int i = 1; i <= month; i++)
		{
			sum += v[i];
		}
		cout << sum << endl;
	}
	return 0;
}