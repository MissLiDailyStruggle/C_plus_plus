//���ӣ�https://www.nowcoder.com/questionTerminal/11cc498832db489786f8a03c3b67d02c
//��Դ��ţ����
//������������ n �� m��������1��2��3.......n ������ȡ������, ʹ��͵��� m, Ҫ���������еĿ�������г���
#include <iostream>
#include <vector>

using namespace std;

void group(int n, int m, vector<int>& arr, int beg)
{
	if (m == 0)
	{
		for (int i = 0; i < arr.size(); i++)
		{
			if (i == 0)
				cout << arr[i];
			else
				cout << " " << arr[i];
		}
		cout << endl;
	}
	for (int i = beg; i <= n && i <= m; ++i)
	{
		arr.push_back(i);
		group(n, m - i, arr, i + 1);
		arr.pop_back();
	}
}

int main()
{
	int n, m;
	while (cin >> n >> m)
	{
		vector<int>arr;
		group(n, m, arr, 1);
	}
	return 0;
}