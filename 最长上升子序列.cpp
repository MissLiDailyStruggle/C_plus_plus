// ���ӣ�https://www.nowcoder.com/questionTerminal/d83721575bd4418eae76c916483493de
//��Դ��ţ����
//�㳡��վ��һ֧���飬����������ȫ�����ص�Ť������ӣ����������ǵ�������ݣ������æ�ҳ�������ε����������С� ����������������ǣ�1��7��3��
//5��9��4��8�����������ε������������У�1��7������1��3��5��9������1��3��4��8���ȣ�������ĳ���Ϊ4��
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	int n;
	while (cin >> n)
	{
		vector<int>arr(n, 0);
		for (int i = 0; i < n; i++)
		{
			cin >> arr[i];
		}
		vector<int>f(n, 1);
		int maxcount = 1;
		for (int i = 1; i < n; i++)
		{
			for (int j = 0; j < i; j++)
			{
				if (arr[i] > arr[j])
					f[i] = max(f[i], f[j] + 1);
			}
			maxcount = max(maxcount, f[i]);
		}
		cout << maxcount << endl;
	}
	return 0;
}