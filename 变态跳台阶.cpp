//���ӣ�https://www.nowcoder.com/questionTerminal/22243d016f6b47f2a6928b4313c85387
//��Դ��ţ����
//һֻ����һ�ο�������1��̨�ף�Ҳ��������2��������Ҳ��������n���������������һ��n����̨���ܹ��ж�����������
class Solution {
public:
	int jumpFloorII(int number) {
		//f(i) = f(i - 1) + f(i - 2)+...+ f(0);
		//f(i - 1) = f(i - 2) + f(i - 3) + f(0);
		//f(i) = 2 * f��i- 1����
		if (number <= 0)
			return 0;
		int count = 1;
		for (int i = 2; i <= number; i++)
			count *= 2;
		return count;
	}
};