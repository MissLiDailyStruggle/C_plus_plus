//���ӣ�https://www.nowcoder.com/questionTerminal/c0a4b917a15f40a49ca10532ab9019fb
//��Դ��ţ����
//NowCoder�ų��Լ��Ѿ���ס��1 - 100000֮�����е�쳲���������Ϊ�˿���������������һ����n������˵����n��쳲�����������Ȼ��쳲���������ܴ���ˣ���
//����n��쳲�����������6λ����˵������������ֻ˵�����6λ��
#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

int main()
{
	vector<int> arr;
	arr.resize(100001);
	arr[0] = 1;
	arr[1] = 1;
	for (int i = 2; i < 100002; i++)
	{
		arr[i] = arr[i - 1] + arr[i - 2];
		if (arr[i] / 1000000 > 0)
			arr[i] = arr[i] % 1000000;
	}
	int n;
	while (cin >> n)
	{
		if (n < 31)
			cout << arr[n] << endl;
		else
		{
			cout << setfill('0') << setw(6) << arr[n] << endl;
		}
	}
	return 0;
}