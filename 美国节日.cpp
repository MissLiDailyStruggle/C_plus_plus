//链接：https://www.nowcoder.com/questionTerminal/d95d98a2f96e49078cd7df84ba0c9d79
//来源：牛客网
//和中国的节日不同，美国的节假日通常是选择某个月的第几个星期几这种形式，因此每一年的放假日期都不相同。具体规则如下：
//* 1月1日：元旦
//* 1月的第三个星期一：马丁·路德·金纪念日
//* 2月的第三个星期一：总统节
//* 5月的最后一个星期一：阵亡将士纪念日
//* 7月4日：美国国庆
//* 9月的第一个星期一：劳动节
//* 11月的第四个星期四：感恩节
//* 12月25日：圣诞节
//现在给出一个年份，请你帮忙生成当年节日的日期。
#include <iostream>

using namespace std;

bool is_leap(int year)
{
	if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0))
		return true;
	else
		return false;
}

void festival(int year)
{
	int days = 0;
	//判断year.1.1 - 2000.1.1的天数
	//2000.1.1是周六
	for (int i = 2000; i < year; i++)
	{
		if (is_leap(i))
			days += 366;
		else
			days += 365;
	}
	//判断year.1.1是周几
	int day = abs(days - 2) % 7 + 1;
	if (year == 2000)
		day = 6;
	//元旦
	cout << year << "-" << 0 << 1 << "-" << 0 << 1 << endl;
	//马丁.路德.金纪念日
	int ret;
	if (day == 1)
		ret = 2 * 7 + 1;
	else
		ret = 2 * 7 + 1 + (7 - day + 1);
	cout << year << "-" << 0 << 1 << "-" << ret << endl;
	//判断year.2.1是周几
	day = (days + 31 - 2) % 7 + 1;
	if (day == 1)
		ret = 2 * 7 + 1;
	else
		ret = 2 * 7 + 1 + (7 - day + 1);
	//总统节
	cout << year << "-" << 0 << 2 << "-" << ret << endl;
	//判断year.5.1是周几
	if (is_leap(year))
		day = (days + 152 - 2) % 7 + 1;
	else
		day = (days + 151 - 2) % 7 + 1;
	if (day == 1)
		ret = 25;
	else
		ret = 31 - (day - 1 - 1);
	//阵亡将士纪念日
	cout << year << "-" << 0 << 5 << "-" << ret << endl;
	//美国国庆
	cout << year << "-" << 0 << 7 << "-" << 0 << 4 << endl;
	//判断year.9.1是周几
	if (is_leap(year))
		day = (days + 244 - 2) % 7 + 1;
	else
		day = (days + 243 - 2) % 7 + 1;
	if (day == 1)
		ret = 1;
	else
		ret = 1 + (7 - day + 1);
	//劳动节
	cout << year << "-" << 0 << 9 << "-" << 0 << ret << endl;
	//判断year.11.1是周几
	if (is_leap(year))
		day = (days + 305 - 2) % 7 + 1;
	else
		day = (days + 304 - 2) % 7 + 1;
	if (day <= 4)
		ret = 2 * 7 + 4 + (7 - day + 1);
	else
		ret = 3 * 7 + 4 + (7 - day + 1);
	//感恩节
	cout << year << "-" << 11 << "-" << ret << endl;
	//圣诞节
	cout << year << "-" << 12 << "-" << 25 << endl;
}

int main()
{
	int year;
	while (cin >> year)
	{
		festival(year);
		cout << endl;
	}
	return 0;
}