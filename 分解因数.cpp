//链接：https://www.nowcoder.com/questionTerminal/0f6976af36324f8bab1ea61e9e826ef5
//来源：牛客网
//所谓因子分解，就是把给定的正整数a，分解成若干个素数的乘积，即 a = a1 × a2 × a3 × ... × an, 并且 1 < a1≤ a2 ≤ a3 ≤ ... ≤ an。其中a1、a2、
//...、an均为素数。  先给出一个整数a，请输出分解后的因子。
#include <iostream>

using namespace std;

bool is_prime(int num)
{
	if (num == 1 || num == 2)
		return true;
	for (int i = 2; i <= num / 2; i++)
	{
		if (num % i == 0)
			return false;
	}
	return true;
}

int main()
{
	int num;
	while (cin >> num)
	{
		cout << num << " = ";
		for (int i = 2; i <= num / 2; i++)
		{
			while (num != i)
			{
				if (num % i == 0 && is_prime(i))
				{
					cout << i << " * ";
					num = num / i;
				}
				else
					break;
			}
		}
		cout << num << endl;
	}
	return 0;
}