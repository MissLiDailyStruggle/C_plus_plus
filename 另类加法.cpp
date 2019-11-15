//链接：https://www.nowcoder.com/questionTerminal/e7e0d226f1e84ba7ab8b28efc6e1aebc
//来源：牛客网
//请编写一个函数，将两个数字相加。不得使用 + 或其他算数运算符。
//给定两个int A和B。请返回A＋B的值
class UnusualAdd {
public:
	int addAB(int A, int B) {
		int sum;
		int temp;
		if (B == 0)
			return A;
		if (A == 0)
			return B;
		while (B)
		{
			sum = A ^ B;
			temp = (A & B) << 1;
			B = temp;
			A = sum;
		}
		return sum;
	}
};