���ӣ�https://www.nowcoder.com/questionTerminal/1b46eb4cf3fa49b9965ac3c2c1caf5ad
��Դ��ţ����

//���ӣ�https ://www.nowcoder.com/questionTerminal/1b46eb4cf3fa49b9965ac3c2c1caf5ad
//��Դ��ţ����
//��ʵ�����½ӿڣ�
//public static int findNumberOf1(int num)
//{
//	/*��ʵ��*/
//	return 0;
//}
//Ʃ�磺����5 ��5�Ķ�����Ϊ101�����2
#include <iostream>

using namespace std;

int findNumberOf1(int num)
{
	int count = 0;
	while (num)
	{
		if ((num & 1) == 1)
			count++;
		num >>= 1;
	}
	return count;
}

int main()
{
	int num;
	while (cin >> num)
	{
		int res = findNumberOf1(num);
		cout << res << endl;
	}
	return 0;
}