//���ӣ�https://www.nowcoder.com/questionTerminal/433c0c6a1e604a4795291d9cd7a60c7a
//��Դ��ţ����
//�����У�ÿ��Ҫ����һ̨�»�����ʱ�򣬾���ζ����һ��Ŀ¼��Ҫ����������Ҫ����Ŀ¼�� / usr / local / bin��������Ҫ�˴δ����� / usr������ / usr / 
//local���Լ��� / usr / local / bin�������ڣ�Linux��mkdir�ṩ��ǿ��ġ� - p��ѡ�ֻҪһ�����mkdir- p / usr / local / bin�������Զ�������Ҫ
//���ϼ�Ŀ¼�����ڸ���һЩ��Ҫ�������ļ���Ŀ¼�������æ������Ӧ�ġ�mkdir - p�����
#include <iostream>
#include <set>
#include <string>

using namespace std;

int main()
{
	int n;
	while (cin >> n)
	{
		set<string> arr;
		string temp;
		for (int i = 0; i < n; i++)
		{
			cin >> temp;
			arr.insert(temp);
		}
		for (auto it = arr.begin(); it != --arr.end(); ++it)
		{
			auto j = it++;
			auto pos = (*it).find((*j));
			if ((pos == string::npos) || (pos != 0) || (*it)[(*j).size()] != '\/')
				cout << "mkdir -p " << *j << endl;
			it = j;
		}
		cout << "mkdir -p " << *(--arr.end()) << endl;
		cout << endl;
	}
	return 0;
}