//���ӣ�https://www.nowcoder.com/questionTerminal/28c1dc06bc9b4afd957b01acdf046e69
//��Դ��ţ����
//����һ���ַ���s������Դ���ɾ��һЩ�ַ���ʹ��ʣ�µĴ���һ�����Ĵ������ɾ������ʹ�û��Ĵ���أ������Ҫɾ�����ַ�������
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int min_delete(string str1, string str2)
{
	int length = str1.size();
	vector<vector<int>> maxlen(length + 1, vector<int>(length + 1));
	for (int i = 0; i <= length; ++i)
		maxlen[i][0] = 0;
	for (int i = 0; i <= length; ++i)
		maxlen[0][i] = 0;
	for (int i = 1; i <= length; ++i)
	{
		for (int j = 1; j <= length; ++j)
		{
			if (str1[i - 1] == str2[j - 1])
			{
				maxlen[i][j] = maxlen[i - 1][j - 1] + 1;
			}
			else
			{
				maxlen[i][j] = max(maxlen[i - 1][j], maxlen[i][j - 1]);
			}
		}
	}
	return length - maxlen[length][length];
}

int main()
{
	string str1;
	while (cin >> str1)
	{
		string str2(str1);
		reverse(str2.begin(), str2.end());
		int res = min_delete(str1, str2);
		cout << res << endl;
	}
	return 0;
}