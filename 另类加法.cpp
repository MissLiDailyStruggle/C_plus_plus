//���ӣ�https://www.nowcoder.com/questionTerminal/e7e0d226f1e84ba7ab8b28efc6e1aebc
//��Դ��ţ����
//���дһ��������������������ӡ�����ʹ�� + �����������������
//��������int A��B���뷵��A��B��ֵ
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