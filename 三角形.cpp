#include <iostream>
//���ӣ�https://www.nowcoder.com/questionTerminal/c67a09062c0f4a5b964eef0945d3dd06
//��Դ��ţ����
//���������ߣ������ж�һ���ܲ������һ�������Ρ�
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