//���ӣ�https://www.nowcoder.com/questionTerminal/1221ec77125d4370833fd3ad5ba72395
//��Դ��ţ����
//��һֻ���ӣ��ӳ������3������ÿ���¶���һֻ���ӣ�С���ӳ����������º�ÿ��������һֻ���ӣ��������Ӷ���������ÿ���µ���������Ϊ���٣�
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