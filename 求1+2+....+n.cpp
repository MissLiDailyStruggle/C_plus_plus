//���ӣ�https://www.nowcoder.com/questionTerminal/7a0da8fc483247ff8800059e12d7caf1
//��Դ��ţ����
//��1 + 2 + 3 + ... + n��Ҫ����ʹ�ó˳�����for��while��if��else��switch��case�ȹؼ��ּ������ж���䣨A ? B : C����
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