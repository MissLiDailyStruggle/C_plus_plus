//���ӣ�https://www.nowcoder.com/questionTerminal/9d1559511b3849deaa71b576fa7009dc
//��Դ��ţ����
//�����Ĵ�����һ�������ͷ�����һ�����ַ��������硰level�����ߡ�noon���ȵȾ��ǻ��Ĵ��������ǳ�ϲ������ӵ�жԳ���
//�Ļ��Ĵ������յ�ʱ�����õ���������ֱ����ַ���A���ַ���B���������ǳ�������û�а취���ַ���B�����ַ���Aʹ������
//�ַ�����һ�����Ĵ�������ܻ��������󣬰�����Ѱ���ж����ֲ���취����ʹ�´���һ�����Ĵ�������ַ���B�����λ�ò�
//ͬ�Ϳ���Ϊ��һ���İ취��
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

bool plalindrome(string str)
{
	string tmp = str;
	reverse(str.begin(), str.end());
	for (int i = 0; i < tmp.size(); i++)
	{
		if (tmp[i] != str[i])
			return false;
	}
	return true;
}

int main()
{
	string A;
	string B;
	cin >> A;
	cin >> B;
	int count = 0;
	for (int i = 0; i <= A.size(); i++)
	{
		string str = A;
		str.insert(i, B);
		if (plalindrome(str))
			count++;
	}
	cout << count << endl;
}