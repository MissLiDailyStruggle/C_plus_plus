//���ӣ�https://www.nowcoder.com/questionTerminal/1d18c0841e64454cbc3afaea05e2f63c
//��Դ��ţ����
//��Ȼ�мٱң� �����������ˣ�����ũ��Ĺ���ȴ�����ǰ���ûǮ��ô�����Ⱑ��nowcoder���ȥ�����⣬�����������Ǯ���мٱң�������ϧnowcoderһ��С�İ��������һ��
//�������ȥ�ˡ�ֻ֪���ٱҵ���������ҵ�����Ҫ�ᣬ����һ����ƽ����ƽ�������������޸�Ӳ�ң�����������ʱ����Ǹ��ɶ�ļٱ��ҳ�����
#include <iostream>

using namespace std;

int main()
{
	int n;
	while (cin >> n)
	{
		if (n == 0)
			return 0;
		long count = 1;
		int res = 0;
		while (count < n)
		{
			count *= 3;
			res++;
		}
		cout << res << endl;
	}
	return 0;
}