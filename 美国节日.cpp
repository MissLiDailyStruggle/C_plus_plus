//���ӣ�https://www.nowcoder.com/questionTerminal/d95d98a2f96e49078cd7df84ba0c9d79
//��Դ��ţ����
//���й��Ľ��ղ�ͬ�������Ľڼ���ͨ����ѡ��ĳ���µĵڼ������ڼ�������ʽ�����ÿһ��ķż����ڶ�����ͬ������������£�
//* 1��1�գ�Ԫ��
//* 1�µĵ���������һ������·�¡��������
//* 2�µĵ���������һ����ͳ��
//* 5�µ����һ������һ��������ʿ������
//* 7��4�գ���������
//* 9�µĵ�һ������һ���Ͷ���
//* 11�µĵ��ĸ������ģ��ж���
//* 12��25�գ�ʥ����
//���ڸ���һ����ݣ������æ���ɵ�����յ����ڡ�
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
	//�ж�year.1.1 - 2000.1.1������
	//2000.1.1������
	for (int i = 2000; i < year; i++)
	{
		if (is_leap(i))
			days += 366;
		else
			days += 365;
	}
	//�ж�year.1.1���ܼ�
	int day = abs(days - 2) % 7 + 1;
	if (year == 2000)
		day = 6;
	//Ԫ��
	cout << year << "-" << 0 << 1 << "-" << 0 << 1 << endl;
	//��.·��.�������
	int ret;
	if (day == 1)
		ret = 2 * 7 + 1;
	else
		ret = 2 * 7 + 1 + (7 - day + 1);
	cout << year << "-" << 0 << 1 << "-" << ret << endl;
	//�ж�year.2.1���ܼ�
	day = (days + 31 - 2) % 7 + 1;
	if (day == 1)
		ret = 2 * 7 + 1;
	else
		ret = 2 * 7 + 1 + (7 - day + 1);
	//��ͳ��
	cout << year << "-" << 0 << 2 << "-" << ret << endl;
	//�ж�year.5.1���ܼ�
	if (is_leap(year))
		day = (days + 152 - 2) % 7 + 1;
	else
		day = (days + 151 - 2) % 7 + 1;
	if (day == 1)
		ret = 25;
	else
		ret = 31 - (day - 1 - 1);
	//������ʿ������
	cout << year << "-" << 0 << 5 << "-" << ret << endl;
	//��������
	cout << year << "-" << 0 << 7 << "-" << 0 << 4 << endl;
	//�ж�year.9.1���ܼ�
	if (is_leap(year))
		day = (days + 244 - 2) % 7 + 1;
	else
		day = (days + 243 - 2) % 7 + 1;
	if (day == 1)
		ret = 1;
	else
		ret = 1 + (7 - day + 1);
	//�Ͷ���
	cout << year << "-" << 0 << 9 << "-" << 0 << ret << endl;
	//�ж�year.11.1���ܼ�
	if (is_leap(year))
		day = (days + 305 - 2) % 7 + 1;
	else
		day = (days + 304 - 2) % 7 + 1;
	if (day <= 4)
		ret = 2 * 7 + 4 + (7 - day + 1);
	else
		ret = 3 * 7 + 4 + (7 - day + 1);
	//�ж���
	cout << year << "-" << 11 << "-" << ret << endl;
	//ʥ����
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