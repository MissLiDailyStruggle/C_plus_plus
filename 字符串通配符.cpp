//���ӣ�https://www.nowcoder.com/questionTerminal/43072d50a6eb44d2a6c816a283b02036
//��Դ��ţ����
//�����������ڼ�����У�ͨ���һ�������﷨���㷺Ӧ�����ļ����������ݿ⡢������ʽ��������Ҫ���λʵ���ַ���ͨ������㷨��
//Ҫ��ʵ������2��ͨ�����*��ƥ��0�������ϵ��ַ����ַ���Ӣ����ĸ������0 - 9��ɣ������ִ�Сд����ͬ������ƥ��1���ַ���
#include <iostream>
#include <string>

using namespace std;

int main()
{
	string stan;
	string str;
	while (cin >> stan >> str)
	{
		int i = 0;
		int j = 0;
		bool flag = false;
		while ((i < stan.size()) || j < str.size())
		{
			if (stan[i] == '*')
			{
				i++;
				flag = true;
			}
			else if ((stan[i] == str[j]) || (stan[i] == '?'))
			{
				i++;
				j++;
			}
			else if (flag == true)
			{
				while (stan[i] != str[j])
					j++;
				flag = false;
			}
			else
			{
				cout << "false" << endl;
				break;
			}
		}
		if ((i >= stan.size()) && j >= str.size())
			cout << "true" << endl;
	}
	return 0;
}