//���ӣ�https://www.nowcoder.com/questionTerminal/4284c8f466814870bae7799a07d49ec8
//��Դ��ţ����
//С��������һ��ʯ��·ǰ��ÿ��ʯ���ϴ�1���ű��Ϊ��1��2��3.......����ʯ��·Ҫ��������Ĺ������ǰ����
//����С�׵�ǰ���ڵı��ΪK�� ʯ�壬С�׵���ֻ����ǰ��K��һ��Լ��(����1��K)����������K + X(XΪK��һ��
//��1�ͱ����Լ��)��λ�á� С�׵�ǰ���ڱ��ΪN��ʯ�壬�����������ǡ��ΪM��ʯ��ȥ��С����֪��������Ҫ
//��Ծ���ο��Ե�� ���磺 N = 4��M = 24�� 4->6->8->12->18->24 ����С��������Ҫ��Ծ5�Σ��Ϳ��Դ�4��
//ʯ������24��ʯ�塣
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void jud_appro(int n, vector<int> &v)
{
	for (int i = 2; i * i <= n; i++)
	{
		if (n % i == 0)
		{
			v.push_back(i);
			if (n / i != i)
				v.push_back(n / i);
		}
	}
}

int main()
{
	int n, m;
	while (cin >> n >> m)
	{
		vector<int> res(m + 1, 0);
		res[n] = 1;
		for (int i = n; i <= m; i++)
		{
			vector<int> v;
			if (res[i] == 0)
				continue;
			jud_appro(i, v);
			for (int j = 0; j < v.size(); j++)
			{
				if (v[j] + i <= m && res[v[j] + i] == 0)
					res[v[j] + i] = res[i] + 1;
				else if ((v[j] + i <= m && res[v[j] + i] != 0))
					res[v[j] + i] = min(res[v[j] + i], res[i] + 1);
			}
		}
		if (res[m] != 0)
			cout << res[m] - 1 << endl;
		else
			cout << -1 << endl;
	}
	return 0;
}