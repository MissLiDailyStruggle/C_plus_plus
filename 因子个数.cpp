//���ӣ�https://www.nowcoder.com/questionTerminal/e8fb8f89f5d147ec92fd8ecfefe89b0d
//��Դ��ţ����
//һ�����������Էֽ��һ����������Ļ�������36 = 2 * 2 * 3 * 3��������2��3�������ӡ�NowCoder������о����Ӹ����ķֲ����ɣ����ڸ���һϵ������������ϣ���㿪��
//һ���������ÿ�������������Ӹ�����
#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	int n;
	while (cin >> n)
	{
		int count = 0;
		for (int i = 2; i <= sqrt(n); i++)
		{
			if (n % i == 0)
				count++;
			while (n % i == 0)
				n /= i;
		}
		if (n != 1)
			count++;
		cout << count << endl;
	}
	return 0;
}