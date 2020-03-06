//链接：https://www.nowcoder.com/questionTerminal/610e6c0387a0401fb96675f58cda8559
//来源：牛客网
//今年公司年会的奖品特别给力，但获奖的规矩却很奇葩：
//1. 首先，所有人员都将一张写有自己名字的字条放入抽奖箱中；
//2. 待所有字条加入完毕，每人从箱中取一个字条；
//3. 如果抽到的字条上写的就是自己的名字，那么“恭喜你，中奖了！”
//现在告诉你参加晚会的人数，请你计算有多少概率会出现无人获奖？
#include <iostream>

using namespace std;
double numerator(int n)
{
	if (n == 1)
		return 0;
	if (n == 2)
		return 1;
	return (n - 1) * (numerator(n - 1) + numerator(n - 2));
}
double factoria(int n)
{
	if (n == 0)
		return 1;
	else
		return n * factoria(n - 1);
}
int main()
{
	int n;
	while (cin >> n)
	{
		double res;
		double num = numerator(n);
		double den = factoria(n);
		res = num / den * 100;
		printf("%.2f%%", res);
		cout << endl;
	}
	return 0;
}