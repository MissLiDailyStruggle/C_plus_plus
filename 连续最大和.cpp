//���ӣ�https://www.nowcoder.com/questionTerminal/5a304c109a544aef9b583dce23f5f5db
//��Դ��ţ����
//һ�������� N ��Ԫ�أ�����������������͡� ���磺[-1, 2, 1]������������������Ϊ[2, 1]�����Ϊ 3
#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int n = 0;
	cin >> n;
	vector<int> v;
	v.resize(n + 1);
	int sum = -1e5;
	int temp = 0;
	for (int i = 0; i < n; i++)
		cin >> v[i];
	for (int i = 0; i < n; i++)
	{
		if (temp >= 0)
			temp += v[i];
		else
			temp = v[i];
		if (temp > sum)
			sum = temp;
	}
	cout << sum << endl;
}