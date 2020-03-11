//链接：https://www.nowcoder.com/questionTerminal/433c0c6a1e604a4795291d9cd7a60c7a
//来源：牛客网
//工作中，每当要部署一台新机器的时候，就意味着有一堆目录需要创建。例如要创建目录“ / usr / local / bin”，就需要此次创建“ / usr”、“ / usr / 
//local”以及“ / usr / local / bin”。好在，Linux下mkdir提供了强大的“ - p”选项，只要一条命令“mkdir- p / usr / local / bin”就能自动创建需要
//的上级目录。现在给你一些需要创建的文件夹目录，请你帮忙生成相应的“mkdir - p”命令。
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