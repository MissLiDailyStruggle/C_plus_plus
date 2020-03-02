//链接：https://www.nowcoder.com/questionTerminal/754921e9c98b43d1b2d70c227b844101
//来源：牛客网
//NowCoder在淘宝上开了一家网店。他发现在月份为素数的时候，当月每天能赚1元；否则每天能赚2元。现在给你一段时间区间，请你帮他计算总收益有多少。
#include <iostream>
#include <vector>

using namespace std;

bool is_prime(int month)
{
	if (month == 1)
		return false;
	if (month == 2)
		return true;
	for (int i = 2; i <= month / 2; i++)
	{
		if (month % i == 0)
			return false;
	}
	return true;
}
bool is_leap(int year)
{
	if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0))
		return true;
	else
		return false;
}
int main()
{
	int year1, year2, month1, month2, day1, day2;
	while (cin >> year1 >> month1 >> day1 >> year2 >> month2 >> day2)
	{
		int days = 0;
		vector<int> months = { 0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
		if (year1 == year2)
		{
			if (!is_leap(year1))
				months[2] = 28;
			if (month1 == month2)
			{
				if (!is_prime(month1))
					days += (day2 - day1 + 1) * 2;
				else
					days += (day2 - day1 + 1);
			}
			else
			{
				if (!is_prime(month1))
					days += (months[month1] - day1 + 1) * 2;
				else
					days += (months[month1] - day1 + 1);
				for (int m = month1 + 1; m < month2; m++)
				{
					if (!is_prime(m))
						days += months[m] * 2;
					else
						days += months[m];
				}
				if (!is_prime(month2))
					days += (day2 * 2);
				else
					days += day2;
			}
		}
		else
		{
			if (!is_leap(year1))
				months[2] = 28;
			else
				months[2] = 29;
			if (!is_prime(month1))
				days += (months[month1] - day1 + 1) * 2;
			else
				days += (months[month1] - day1 + 1);
			for (int i = month1 + 1; i <= 12; i++)
			{
				if (!is_prime(i))
					days += months[i] * 2;
				else
					days += months[i];
			}
			for (int i = year1 + 1; i < year2; i++)
			{
				if (is_leap(i))//152 //214 428
					days += 580;
				else
					days += 579;
			}
			if (!is_leap(year2))
				months[2] = 28;
			else
				months[2] = 29;
			for (int i = 1; i < month2; i++)
			{
				if (!is_prime(i))
					days += months[i] * 2;
				else
					days += months[i];
			}
			if (!is_prime(month2))
				days += (day2 * 2);
			else
				days += day2;
		}
		cout << days << endl;
	}
	return 0;
}