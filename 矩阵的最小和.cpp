//���ӣ�https://www.nowcoder.com/practice/2fb62a4500af4f4ba5686c891eaad4a9?tpId=101&&tqId=33254&rp=1&ru=/activity/oj&qru=/ta/programmer-code-interview-guide/question-ranking
//��Դ��ţ����
//����һ�� n * m �ľ��� a�������Ͻǿ�ʼÿ��ֻ�����һ��������ߣ���󵽴����½ǵ�λ�ã�·�������е������ۼ���������·���ͣ�������е�·������С��·���͡�
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


int minpathsum(vector<vector<int>>&arr)
{
	int row = arr.size();
	int col = arr[0].size();
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (i == 0)
				arr[i][j] += arr[i][j - 1];
			else if (j == 0)
				arr[i][j] += arr[i - 1][j];
			else
				arr[i][j] += min(arr[i][j - 1], arr[i - 1][j]);
		}
	}
	return arr[row - 1][col - 1];
}
int main()
{
	int n, m;
	while (cin >> n >> m)
	{
		vector<vector<int>> arr(n, vector<int>(m, 0));
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
				cin >> arr[i][j];
		}
		int res = minpathsum(arr);
		cout << res << endl;
	}
	return 0;
}