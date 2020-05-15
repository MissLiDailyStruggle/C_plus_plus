// ���ӣ�https://www.nowcoder.com/questionTerminal/88c6d56d78974869aac605a0d26deded
//��Դ��ţ����
//7
//3 8
//8 1 0
//2 7 4 4
//4 5 2 6 5
//����ͼ��ʾ����һ�����������εĶ����ߵ��ײ��кܶ�����ͬ��·����������ֻ�ܴӵ�ǰ�ڵ��ߵ���һ�����ڵĽڵ㣬����һ�����߻��ұߡ���������еڶ�������
//��1��ֻ���ߵ������еĵڶ������֡�7������������֡�4������Ѱ�����һ��·����ʹ������·���Ͻڵ�������ܺ����
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	int n;
	while (cin >> n)
	{
		vector<vector<int>> v(n, vector<int>(n));
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j <= i; ++j)
			{
				cin >> v[i][j];
			}
		}
		for (int i = n - 2; i >= 0; i--)
		{
			for (int j = 0; j <= i; j++)
			{
				v[i][j] += max(v[i + 1][j], v[i + 1][j + 1]);
			}
		}
		cout << v[0][0] << endl;
	}
	return 0;
}