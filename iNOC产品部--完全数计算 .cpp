//���ӣ�https://www.nowcoder.com/questionTerminal/7299c12e6abb437c87ad3e712383ff84
//��Դ��ţ����
//��ȫ����Perfect number�����ֳ����������걸������һЩ�������Ȼ����
//�����е������ӣ����������������Լ�����ĺͣ������Ӻ�������ǡ�õ���������
//���磺28������Լ��1��2��4��7��14��28����ȥ������28�⣬����5������ӣ�1 + 2 + 4 + 7 + 14 = 28��
//��������count(int n), ���ڼ���n����(��n)��ȫ���ĸ��������㷶Χ, 0 < n <= 500000
//����n������ȫ���ĸ�����
//�쳣������� - 1
#include <iostream>
#include <cmath>

using namespace std;

int count(int n)
{
	int _count = 0;
	for (int i = 2; i <= n; i++)
	{
		int sum = 0;
		for (int j = 1; j <= i / 2; j++)
		{
			if (i % j == 0)
				sum += j;
		}
		if (sum == i)
			_count++;
	}
	return _count;
}

int main()
{
	int n;
	while (cin >> n)
	{
		int res = count(n);
		cout << res << endl;
	}
	return 0;
}