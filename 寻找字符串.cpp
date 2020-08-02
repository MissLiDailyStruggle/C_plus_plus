#include <iostream>
#include <string>

using namespace std;

int main()
{
	int count = 0;
	int i, j;
	string str1;
	string str2;
	getline(cin, str1);
	getline(cin, str2);
	for (i = 0; i < str1.size(); ++i)
	{
		int x = i;
		for (j = 0; j < str2.size(); ++j)
		{
			if (str1[x++] != str2[j])
				break;
		}
		if (j == str2.size())
			count++;
	}
	cout << count << endl;
	system("pause");
	return 0;
}