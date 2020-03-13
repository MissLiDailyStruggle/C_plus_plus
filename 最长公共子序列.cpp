//���ӣ�https://www.nowcoder.com/questionTerminal/9ae56e5bdf4f480387df781671db5172
//��Դ��ţ����
//�����������ַ���m��n��������ǵ��Ӵ�a��b������ͬ�����a��b��m��n�Ĺ��������С��Ӵ��е��ַ���һ����ԭ�ַ����������������ַ�����abcfbc���͡�abfca
//b�������С�abc��ͬʱ�����������ַ����У���ˡ�abc�������ǵĹ��������С����⣬��ab������af���ȶ������ǵ��ִ������ڸ������������ַ������������ո�
//�����æ�������ǵ�����������еĳ��ȡ�
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
	string str1, str2;
	while (cin >> str1 >> str2)
	{
		vector<vector<int>> arr;
		int len1 = str1.size();
		int len2 = str2.size();
		arr.resize(len1 + 1, vector<int>(len2 + 1));
		for (int i = 1; i <= len1; i++)
		{
			for (int j = 1; j <= len2; j++)
			{
				if (str1[i - 1] == str2[j - 1])
					arr[i][j] = arr[i - 1][j - 1] + 1;
				else
					arr[i][j] = max(arr[i - 1][j], arr[i][j - 1]);
			}
		}
		cout << arr[len1][len2] << endl;
	}
	return 0;
}