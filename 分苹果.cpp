//���ӣ�https://www.nowcoder.com/questionTerminal/a174820de48147d489f64103af152709
//��Դ��ţ����
//n ֻ��ţ����һ�ţ�ÿ����ţӵ�� ai ��ƻ����������Ҫ������֮��ת��ƻ����ʹ�����������ţӵ�е�ƻ��������ͬ��ÿһ�Σ���ֻ�ܴ�һֻ��ţ��������ǡ������
//ƻ������һ����ţ�ϣ���������Ҫ�ƶ����ٴο���ƽ��ƻ�������������������� - 1��
#include <iostream>
#include <vector>

using  namespace std;

int main()
{
	int n;
	cin >> n;
	vector<int> arr(n, 0);
	int sum = 0;
	for (int i = 0; i < n; ++i)
	{
		cin >> arr[i];
		sum += arr[i];
	}
	if (sum % n != 0)
	{
		cout << -1 << endl;
		return 0;
	}
	int aver = sum / n;
	int more = 0;
	int res = 0;
	for (int i = 0; i < n; ++i)
	{
		if (arr[i] > aver)
		{
			more = arr[i] - aver;
			if (more % 2 != 0)
			{
				cout << -1 << endl;
				return 0;
			}
			res += more;
		}
	}
	cout << res / 2 << endl;
	return 0;
}