//���ӣ�https://www.nowcoder.com/questionTerminal/eaf5b886bd6645dd9cfb5406f3753e15
//��Դ��ţ����
//MP3 Player��Ϊ��Ļ��С����ʾ�����б��ʱ��ÿ��ֻ����ʾ���׸������û�Ҫͨ�����¼�����������еĸ�����Ϊ�˼򻯴���
//����ÿ��ֻ����ʾ4�׸���������ʼ��λ��Ϊ��1�׸衣
#include <iostream>

using namespace std;

int main()
{
	int n;
	string str;
	while (cin >> n >> str)
	{
		int cur = 1;
		int first = 1;
		if (n <= 4)
		{
			for (int i = 0; i < str.size(); i++)
			{
				if (str[i] == 'U')
				{
					if (cur == 1)
						cur = n;
					else
						cur--;
				}
				else if (str[i] == 'D')
				{
					if (cur == n)
						cur = 1;
					else
						cur++;
				}
			}
			for (int i = first; i < n; i++)
				cout << i << " ";
			cout << n << endl << cur << endl;
		}
		else
		{
			for (int i = 0; i < str.size(); i++)
			{
				if (str[i] == 'U')
				{
					if (cur == 1)
					{
						cur = n;
						first = n - 3;
					}
					else if (cur == first)
					{
						first--;
						cur--;
					}
					else
						cur--;
				}
				else if (str[i] == 'D')
				{
					if (cur == n)
					{
						cur = 1;
						first = 1;
					}
					else if (cur == first + 3)
					{
						first++;
						cur++;
					}
					else
						cur++;
				}
			}
			for (int i = first; i < (first + 3); i++)
				cout << i << " ";
			cout << first + 3 << endl << cur << endl;
		}
	}
	return 0;
}