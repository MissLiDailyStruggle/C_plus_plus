//���ӣ�https://www.nowcoder.com/questionTerminal/ceb89f19187b4de3997d9cdef2d551e8
//��Դ��ţ����
//��ͼ��һ���绰�ľŹ�����������һ�����ֶ�ӦһЩ��ĸ������ڹ�����ҵϲ���ѵ绰������Ƴ����Լ���˾�������Ӧ�����繫˾��Help Desk������4357����
//Ϊ4��ӦH��3��ӦE��5��ӦL��7��ӦP�����4357����HELP��ͬ��TUT - GLOP�ʹ���888 - 4567��310 - GINO����310 - 4466�� NowCoder�ս������󣬲���ϰ����
//����������ʽ�����ڸ���һ���绰�����б��������ת����������ʽ�ĺ��룬��ȥ���ظ��Ĳ��֡�
#include <iostream>
#include <string>
#include <vector>
#include <set>

using namespace std;

int main()
{
	int n;
	while (cin >> n)
	{
		vector<string>arr;
		set<string>brr;
		for (int i = 0; i < n; ++i)
		{
			string str;
			cin >> str;
			arr.push_back(str);
		}
		for (int i = 0; i < n; ++i)
		{
			string tmp;
			for (int j = 0; j < arr[i].size(); ++j)
			{
				if (arr[i][j] == '1')
					tmp += '1';
				else if (arr[i][j] == '2' || (arr[i][j] >= 'A' && arr[i][j] <= 'C'))
					tmp += '2';
				else if (arr[i][j] == '3' || (arr[i][j] >= 'D' && arr[i][j] <= 'F'))
					tmp += '3';
				else if (arr[i][j] == '4' || (arr[i][j] >= 'G' && arr[i][j] <= 'I'))
					tmp += '4';
				else if (arr[i][j] == '5' || (arr[i][j] >= 'J' && arr[i][j] <= 'L'))
					tmp += '5';
				else if (arr[i][j] == '6' || (arr[i][j] >= 'M' && arr[i][j] <= 'O'))
					tmp += '6';
				else if (arr[i][j] == '7' || (arr[i][j] >= 'P' && arr[i][j] <= 'S'))
					tmp += '7';
				else if (arr[i][j] == '8' || (arr[i][j] >= 'T' && arr[i][j] <= 'V'))
					tmp += '8';
				else if (arr[i][j] == '9' || (arr[i][j] >= 'W' && arr[i][j] <= 'Z'))
					tmp += '9';
				else if (arr[i][j] == '0')
					tmp += '0';
				else
					continue;
			}
			brr.insert(tmp);
		}
		set<string>::iterator it = brr.begin();
		while (it != brr.end())
		{
			string res = *it;
			for (int i = 0; i < 3; ++i)
				cout << res[i];
			cout << "-";
			for (int i = 3; i < 7; ++i)
				cout << res[i];
			cout << endl;
			++it;
		}
		cout << endl;
	}
	return 0;
}