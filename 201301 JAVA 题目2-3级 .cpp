//���ӣ�https://www.nowcoder.com/questionTerminal/e2a22f0305eb4f2f9846e7d644dba09b
//��Դ��ţ����
//���дһ�����������������Ӻ�����������n x m�����̸��ӣ�nΪ����ĸ�������mΪ����ĸ����������Ÿ��Ա�Ե�ߴ����Ͻ��ߵ����½ǣ�
//�ܹ��ж������߷���Ҫ�����߻�ͷ·������ֻ�����Һ������ߣ���������������ߡ�

#include <iostream>

using namespace std;


int count(int m, int n)
{
	if (m == 0 || n == 0)
		return 1;
	else if (m == 1)
		return n + 1;
	else if (n == 1)
		return m + 1;
	else
		return count(m - 1, n) + count(m, n - 1);
}
int main()
{
	int m, n;
	while (cin >> m >> n)
		cout << count(m, n) << endl;;
}