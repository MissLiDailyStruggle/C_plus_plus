//链接：https://www.nowcoder.com/questionTerminal/7a0da8fc483247ff8800059e12d7caf1
//来源：牛客网
//求1 + 2 + 3 + ... + n，要求不能使用乘除法、for、while、if、else、switch、case等关键字及条件判断语句（A ? B : C）。
class assist{
public:
	assist()
	{
		n++;
		sum += n;
	}
	static void reset()
	{
		n = 0;
		sum = 0;
	}
	static int GetSum()
	{
		return sum;
	}
private:
	static int n;
	static int sum;
};
int assist::n = 0;
int assist::sum = 0;
class Solution {
public:
	int Sum_Solution(int n) {
		assist::reset();
		assist * p = new assist[n];
		delete[]p;
		p = nullptr;
		return assist::GetSum();
	}
};