//���ӣ�https://www.nowcoder.com/questionTerminal/2d3f6ddd82da445d804c95db22dcc471
//��Դ��ţ����
//ţţ��������������Ϊһ��������һ��������������, ��������������Ƿǵ������߷ǵݼ�����ġ�ţţ��һ������Ϊn����������A, 
//��������һ�������ǰ�����A��Ϊ���ɶ�����������, ţţ��֪�������ٿ��԰���������Ϊ��������������.��������ʾ, ţţ���԰�
//����A����Ϊ[1, 2, 3]��[2, 2, 1]��������������, ������Ҫ����Ϊ2������������, �������2
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int n;
	while (cin >> n)
	{
		vector<int> v;
		v.resize(n + 1);
		for (int i = 0; i < n; i++)
		{
			cin >> v[i];
		}
		int count = 0;
		v[n] = 0;
		int i = 0;
		while (i < n)
		{
			if (v[i] < v[i + 1])
			{
				while (i < n && v[i] <= v[i + 1])
					i++;
				count++;
				i++;
			}
			else if (v[i] == v[i + 1])
				i++;
			else
			{
				while (i < n && v[i] >= v[i + 1])
					i++;
				count++;
				i++;
			}
		}
		cout << count << endl;
	}
	return 0;
}