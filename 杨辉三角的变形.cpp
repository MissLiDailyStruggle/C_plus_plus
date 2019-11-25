//���ӣ�https://www.nowcoder.com/questionTerminal/8ef655edf42d4e08b44be4d777edbf43
//��Դ��ţ����
//���������ε����󣬵�һ��ֻ��һ����1������ÿ�е�ÿ��������ǡ������������������Ͻ��������Ͻǵ�����3����֮�ͣ����������ĳ��������Ϊ
//��������0�������n�е�һ��ż�����ֵ�λ�á����û��ż��������� - 1����������3, �����2������4�����3��
#include <iostream>
#include <vector>

using namespace std;

int judge_index(int n)
{
	vector<vector<int>> triangle;
	triangle.resize(n + 1, vector<int>(2 * n, 0));
	triangle[1][1] = 1;
	for (int i = 2; i <= n; i++)
	{
		triangle[i][1] = 1;
		for (int j = 2; j <= 2 * i - 1; j++)
			triangle[i][j] = triangle[i - 1][j - 2] + triangle[i - 1][j - 1] + triangle[i - 1][j];
	}
	for (int i = 2; i <= n; i++)
	{
		if ((triangle[n][i] != 0) && (triangle[n][i] % 2 == 0))
			return i;
	}
	return -1;
}

int main()
{
	int n;
	while (cin >> n)
	{
		int index = judge_index(n);
		cout << index << endl;
	}
	return 0;
}