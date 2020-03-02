//���ӣ�https://www.nowcoder.com/questionTerminal/0f6976af36324f8bab1ea61e9e826ef5
//��Դ��ţ����
//��ν���ӷֽ⣬���ǰѸ�����������a���ֽ�����ɸ������ĳ˻����� a = a1 �� a2 �� a3 �� ... �� an, ���� 1 < a1�� a2 �� a3 �� ... �� an������a1��a2��
//...��an��Ϊ������  �ȸ���һ������a��������ֽ������ӡ�
#include <iostream>

using namespace std;

bool is_prime(int num)
{
	if (num == 1 || num == 2)
		return true;
	for (int i = 2; i <= num / 2; i++)
	{
		if (num % i == 0)
			return false;
	}
	return true;
}

int main()
{
	int num;
	while (cin >> num)
	{
		cout << num << " = ";
		for (int i = 2; i <= num / 2; i++)
		{
			while (num != i)
			{
				if (num % i == 0 && is_prime(i))
				{
					cout << i << " * ";
					num = num / i;
				}
				else
					break;
			}
		}
		cout << num << endl;
	}
	return 0;
}