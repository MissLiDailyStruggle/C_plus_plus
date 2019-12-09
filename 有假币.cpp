//链接：https://www.nowcoder.com/questionTerminal/1d18c0841e64454cbc3afaea05e2f63c
//来源：牛客网
//居然有假币！ 现在猪肉涨了，但是农民的工资却不见涨啊，没钱怎么买猪肉啊。nowcoder这就去买猪肉，结果找来的零钱中有假币！！！可惜nowcoder一不小心把它混进了一堆
//真币里面去了。只知道假币的重量比真币的质量要轻，给你一个天平（天平两端能容纳无限个硬币），请用最快的时间把那个可恶的假币找出来。
#include <iostream>

using namespace std;

int main()
{
	int n;
	while (cin >> n)
	{
		if (n == 0)
			return 0;
		long count = 1;
		int res = 0;
		while (count < n)
		{
			count *= 3;
			res++;
		}
		cout << res << endl;
	}
	return 0;
}