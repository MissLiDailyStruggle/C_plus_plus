//链接：https://www.nowcoder.com/questionTerminal/22243d016f6b47f2a6928b4313c85387
//来源：牛客网
//一只青蛙一次可以跳上1级台阶，也可以跳上2级……它也可以跳上n级。求该青蛙跳上一个n级的台阶总共有多少种跳法。
class Solution {
public:
	int jumpFloorII(int number) {
		//f(i) = f(i - 1) + f(i - 2)+...+ f(0);
		//f(i - 1) = f(i - 2) + f(i - 3) + f(0);
		//f(i) = 2 * f（i- 1）；
		if (number <= 0)
			return 0;
		int count = 1;
		for (int i = 2; i <= number; i++)
			count *= 2;
		return count;
	}
};