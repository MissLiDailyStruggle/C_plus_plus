#include <iostream>
#include <string>

using namespace std;

int main()
{
	string s;
	while (cin >> s)
	{
		for (size_t i = 0; i < s.size(); i++)
		{
			for (size_t j = i + 1; j < s.size(); j++)
			{
				if (s[i] == s[j])
				{
					s.erase(j, 1);
					j--;
				}
			}
		}
		cout << s << endl;
	}
}