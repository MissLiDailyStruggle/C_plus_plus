//���ӣ�https://www.nowcoder.com/questionTerminal/16f59b169d904f8898d70d81d4a140a0
//��Դ��ţ����
//����һ��Ӣ�ľ��ӣ��Ѿ����еĵ���(�����ִ�Сд)�����ִ������Ӷൽ�ٰѵ��ʺʹ�������Ļ���������Ҫ����ʶ��Ӣ�ľ�źͶ��ţ�����˵�����ɿո񡢾�źͶ��Ÿ�����
#include <iostream>
#include <map>

using namespace std;

int main()
{
	map<string, int>dict;
	string str;
	while (cin >> str)
	{
		for (int i = 0; i < str.size(); i++)
		{
			if (str[i] >= 'A' && str[i] <= 'Z')
				str[i] += 32;
			if (str[i] == ',')
				str.erase(i, 1);
			if (str[i] == '.')
				str.erase(i, 1);
		}
		dict[str]++;
	}
	for (auto e : dict)
	{
		cout << e.first << ":" << e.second << endl;
	}
	return 0;
}