//���ӣ�https://www.nowcoder.com/questionTerminal/1046cd038f7a4b04b2b77b415973de1c
//��Դ��ţ����
//һ�黨������������Щͼ��������һ��ֱ�ӿ��õ�С����������Ҳ��һЩͼ�������ڸ����Ļ�������С����������һ���ܴӻ������о����ܼ�������С�������أ� 
#include <iostream>
#include <string>

using namespace std;

int main()
{
	string str1, str2;
	while (cin >> str1 >> str2)
	{
		int count = 0;
		int i = 0;
		int j = 0;
		while (i < str1.size())
		{
			j = 0;
			while (j < str2.size())
			{
				if (i < str1.size() && j < str2.size() && str1[i] == str2[j])
				{
					i++;
					j++;
				}
				else
				{
					i++;
					break;
				}
			}
			if (j == str2.size())
				count++;
		}
		cout << count << endl;
	}
	return 0;
}