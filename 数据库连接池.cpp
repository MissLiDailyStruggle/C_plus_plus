//���ӣ�https://www.nowcoder.com/questionTerminal/05f97d9b29944c018578d98d7f0ce56e
//��Դ��ţ����
//Webϵͳͨ����Ƶ���ط������ݿ⣬���ÿ�η��ʶ����������ӣ����ܻ�ܲΪ��������ܣ��ܹ�ʦ���������Ѿ����������ӡ����յ����󣬲������ӳ���û��ʣ��
//���õ�����ʱ��ϵͳ�ᴴ��һ�������ӣ������������ʱ�����ӻᱻ�������ӳ��У�����������ʹ�á������ṩ�㴦���������־���������һ�����ӳ������Ҫ
//�������ٸ����ӡ�
#include <iostream>
#include <string>
#include <set>

using namespace std;

int main()
{
	int n;
	while (cin >> n)
	{
		set<string> s;
		int count = 0;
		for (int i = 0; i < n; i++)
		{
			string first, second;
			cin >> first >> second;
			if (second == "connect")
				s.insert(first);
			else if (second == "disconnect")
				s.erase(first);
			int size = s.size();
			count = max(size, count);
		}
		cout << count << endl;
	}
	return 0;
}