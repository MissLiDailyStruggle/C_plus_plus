//���ӣ�https://www.nowcoder.com/questionTerminal/e2422543519249f292d8435394ab82fe
//��Դ��ţ����
//��������ͨ����һ�����ĸ���λ�ϵ����ּ������õ�������õ�������һλ������ô�������������������������λ�����߰�������λ�����֣�
//��ô�ٰ���Щ���ּ���������˽�����ȥ��ֱ���õ���һλ��Ϊֹ��
#include <iostream>

using namespace std;

int main()
{
	string s;
	while (cin >> s)
	{
		int digroot = 0;
		for (int i = 0; i < s.size(); i++)
			digroot += (s[i] - '0');
		while (digroot >= 10)
		{
			int n = 0;
			while (digroot)
			{
				n += (digroot % 10);
				digroot /= 10;
			}
			digroot = n;
		}
		cout << digroot << endl;
	}
	return 0;
}