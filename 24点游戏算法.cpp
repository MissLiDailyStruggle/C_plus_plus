//���ӣ�https://www.nowcoder.com/questionTerminal/fbc417f314f745b1978fc751a54ac8cb
//��Դ��ţ����
//��������������4��1 - 10�����֣�ͨ���Ӽ��˳����õ�����Ϊ24����ʤ�� ���룺 4��1 - 10�����֡�[���������ظ�����ÿ�����ֽ�����ʹ��һ�Σ�����������֤���쳣
//����] ����� true or false
#include <iostream>
#include <vector>

using namespace std;

bool isget24(vector<int> arr, double res)
{
	if (arr.empty())
		return res == 24;
	for (int i = 0; i < arr.size(); i++)
	{
		vector<int>brr(arr);
		brr.erase(brr.begin() + i);
		if (isget24(brr, res + arr[i])
			|| isget24(brr, res - arr[i])
			|| isget24(brr, res * arr[i])
			|| isget24(brr, res / arr[i]))
			return true;
	}
	return false;
}

int main()
{
	vector<int> arr(4);
	while (cin >> arr[0] >> arr[1] >> arr[2] >> arr[3])
	{
		if (isget24(arr, 0))
			cout << "true" << endl;
		else
			cout << "false" << endl;
	}
}