#include "string.h"

void string_test()
{
	li::string s1("hello");
	li::string s2(s1);
	li::string s3 = s1;
	li::string s4 = s1 + s2;
	li::string s5;
	cin >> s5;
	cout << s5;
	cout << s1;
	s1.insert(3, 'a');
	s1.push_back('b');
	s1 += " yes";
	s2.insert(3,"aaa");
	s2.append("bbb");
	s2 += 'y';
	int temp1 = s1.find('a');
	cout << temp1 << endl;
	int temp2 = s2.find("aaaa");
	cout << temp2 << endl;
	for (size_t i = 0; i < s1.size(); i++)
	{
		cout << s1[i]<<"";
	}
	cout << endl;
	cout << s2.c_str() << endl;
	li::string::iterator it = s3.begin();
	while (it != s3.end())
	{
		cout << *it;
		it++;
	}
	cout << endl;
	cout << s4.c_str() << endl;
}

int main()
{
	string_test();
	system("pause");
	return 0;
}