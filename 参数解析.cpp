//���ӣ�https://www.nowcoder.com/questionTerminal/668603dc307e4ef4bb07bcd0615ea677
//��Դ��ţ����
//�������������������
//xcopy / s c : \ d : \��
//�����������£�
//����1��������xcopy
//����2���ַ��� / s
//����3���ַ���c : \
//����4 : �ַ���d : \
//���дһ��������������ʵ�ֽ������и�����������������
#include <iostream>
#include <string>

using namespace std;

int main()
{
	string s;
	int count = 1;
	getline(cin, s);
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == ' ')
			count++;
	}
	cout << count << endl;
	for (int i = 0; i < s.size(); i++)
	{
		cout << s[i];
		if (s[i] == ' ')
			cout << endl;
	}
	cout << endl;
	return 0;
}
