//���ӣ�https://www.nowcoder.com/questionTerminal/286af664b17243deb745f69138f8a800
//��Դ��ţ����
//NowCoderÿ��Ҫ��������ʼ����������������ռ����б��У���ʱ��ֻ�Ǳ����͡�����Ϊ��Щ���͵��ʼ���Ҫ�Ա��Լ����ռ����б�����ʼ��ͣ������Ҫ���˵���Щ
//��Ҫ���ʼ������ȴ�����Ҫ���ʼ������ڸ���һ�������б������ж�Ŀ���û��Ƿ��ڳ����б��С�
#include <iostream>
#include <map>
#include <string>
using namespace std;

int main()
{
	string str1, str2;
	while (getline(cin, str1))
	{
		getline(cin, str2);
		map<string, int> dict;
		for (int i = 0; i < str1.size(); i++)
		{
			string temp;
			if (str1[i] == '"')
			{
				i++;
				while (i < str1.size() && str1[i] != '"')
				{
					temp += str1[i];
					i++;
				}
				dict.insert(make_pair(temp, 1));
			}
			else
			{
				while (i < str1.size() && str1[i] != ',')
				{
					temp += str1[i];
					i++;
				}
				dict.insert(make_pair(temp, 1));;
			}
		}
		if (dict[str2] == 1)
			cout << "Ignore" << endl;
		else
			cout << "Important!" << endl;
	}
	return 0;
}