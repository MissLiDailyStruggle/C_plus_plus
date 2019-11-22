//���ӣ�https://www.nowcoder.com/questionTerminal/a5190a7c3ec045ce9273beebdfe029ee
//��Դ��ţ����
//һ������������n����ÿ�������涼��һ������(ӵ����ͬ����������������)�����һ�����������˵ĵ��ҽ���������ĺ���ĺʹ���������ĺ���Ļ���
//���磺��������������ĺ�����{ 1, 1, 2, 3 }��������Ӿ������˵ģ���Ϊ1 + 1 + 2 + 3 > 1 * 1 * 2 * 3
//������ʵ��Ӵ������Ƴ�һЩ��(�����Ƴ�0��, ���Ǳ��Ƴ���)��Ҫʹ�Ƴ���Ĵ��������˵ġ����������̼���һ������Ի�õĶ����ֲ�ͬ�����˵Ĵ��ӡ�
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<int>v;

int solve(int index, int add, int mul)
{
	int count = 0;
	for (int i = index; i < n; i++)
	{
		add += v[i];
		mul *= v[i];
		if (add > mul)
			count += 1 + solve(i + 1, add, mul);
		else if (v[i] == 1)
			count += solve(i + 1, add, mul);
		else
			break;
		add -= v[i];
		mul /= v[i];
		while ((i + 1) < n &&v[i + 1] == v[i])
			i++;
	}
	return count;
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int temp;
		cin >> temp;
		v.push_back(temp);
	}
	sort(v.begin(), v.end());
	int add = 0;
	int mul = 1;
	int res = solve(0, add, mul);
	cout << res << endl;
	system("pause");
	return 0;
}