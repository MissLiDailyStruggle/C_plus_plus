//���ӣ�https://www.nowcoder.com/questionTerminal/18ecd0ecf5ef4fe9ba3f17f8d00d2d66
//��Դ��ţ����
//Fibonacci��������������ģ�
//F[0] = 0
//F[1] = 1
//for each i �� 2: F[i] = F[i - 1] + F[i - 2]
//��ˣ�Fibonacci���о����磺0, 1, 1, 2, 3, 5, 8, 13, ...����Fibonacci�����е������ǳ�ΪFibonacci����
//����һ��N�����������Ϊһ��Fibonacci����ÿһ������԰ѵ�ǰ����X��ΪX - 1����X + 1�����ڸ���һ����N
//��������Ҫ���ٲ����Ա�ΪFibonacci����
#include <iostream>

using namespace std;

int main()
{
	int N;
	cin >> N;
	if (N <= 0)
		return -1;
	int f0 = 0;
	int f1 = 1;
	int f;
	while (N > f1)
	{
		f = f0 + f1;
		f0 = f1;
		f1 = f;
	}
	if ((N - f0) < (f1 - N))
		cout << (N - f0) << endl;
	else
		cout << (f1 - N) << endl;

	return 0;
}