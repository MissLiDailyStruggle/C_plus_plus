/*#include <iostream>
#include <utility>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		int n, m;
		cin >> n >> m;
		multimap<int, int> actor;
		multimap<int, int> role;
		map<int, int> res;
		for (int i = 0; i < n; ++i)
		{
			int num;
			cin >> num;
			actor.insert(make_pair(num, i));
		}
		for (int i = 0; i < m; ++i)
		{
			int num;
			cin >> num;
			role.insert(make_pair(num, i));
		}
		multimap<int, int>::iterator it = actor.begin();
		for (auto e : role)
		{
			if (e.first >= it->first)
			{
				res[it->second] = e.second + 1;
				if (it != actor.end())
					it++;
			}
		}
		while (it != actor.end())
		{
			res[it->second] = -1;
			it++;
		}
		for (auto e : res)
		{
			cout << e.second << " ";
		}
		cout << endl;
	}
	system("pause");
	return 0;
}*/