//���ӣ�https://www.nowcoder.com/question/next?pid=1725829&qid=44802&tid=33019548
//��Դ��ţ����
//СQ���������һ�����⣺��һ���ַ����Ĵ�д��ĸ�ŵ��ַ����ĺ��棬�����ַ������λ�ò��䣬�Ҳ����������Ŀռ䡣���ܰ��СQ��
#include <iostream>
#include <string>

using namespace std;

int main()
{
	string str;
	while (cin >> str)
	{
		for (int i = 0; i < str.size(); i++)
		{
			if (str[i] >= 'a' && str[i] <= 'z')
				cout << str[i];
		}
		for (int i = 0; i < str.size(); i++)
		{
			if (str[i] >= 'A' && str[i] <= 'Z')
				cout << str[i];
		}
		cout << endl;
	}
	return 0;
}