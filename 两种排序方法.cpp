//���ӣ�https://www.nowcoder.com/questionTerminal/839f681bf36c486fbcc5fcb977ffe432
//��Դ��ţ����
//
//������n���ַ����ַ��������������ַ������ȶ��ǲ�ͬ�ġ��������ѧϰ���������ַ��������򷽷��� 1.�����ַ������ֵ����������磺
//"car" < "carriage" < "cats" <
//"doggies < "koala"
//2.�����ַ����ĳ����������磺
//"car" < "cats" < "koala" <
//"doggies" < "carriage"
//������֪���Լ�����Щ�ַ�������˳���Ƿ��������������򷽷�������Ҫæ�ų���Ҷ��������Ҫ������æ��֤��
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
	int n;
	string s;
	bool flag1 = 1;
	bool flag2 = 1;
	vector<string> v;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> s;
		v.push_back(s);
	}
	int i = 0;
	while ((i + 1) < v.size())
	{
		if (v[i].compare(v[i + 1]) > 0)
		{
			flag1 = 0;
			break;
		}
		i++;
	}
	i = 0;
	while ((i + 1) < v.size())
	{
		if (v[i + 1].size() < v[i].size())
		{
			flag2 = 0;
			break;
		}
		i++;
	}
	if (flag1 && flag2)
		cout << "both" << endl;
	else if (flag1 && !flag2)
		cout << "lexicographically" << endl;
	else if (!flag1 && flag2)
		cout << "lengths" << endl;
	else
		cout << "none" << endl;
	return 0;
}