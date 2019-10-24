#include "vector.h"

void vector_test()
{
	li::vector<int> v1;
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);
	v1.push_back(4);
	v1.push_back(5);
	auto it = v1.begin();
	v1.insert(it, 0);
	for (size_t i = 0; i < v1.size(); i++)
	{
		cout << v1[i] << " ";
	}
	cout << endl;
	it = v1.begin();
	v1.erase(it);
	for (size_t i = 0; i < v1.size(); i++)
	{
		cout << v1[i] << " ";
	}
	cout << endl;
	li::vector<int>::iterator iter = v1.begin();
	while (iter != v1.end())
	{
		cout << *iter << " ";
		iter++;
	}
	cout << endl;
	for (auto e : v1)
	{
		cout << e << " ";
	}
	cout << endl;
    li::vector<int>v2(v1);
	for (size_t i = 0; i < v2.size(); i++)
	{
		cout << v2[i] << " ";
	}
	cout << endl;
}

int main()
{
	vector_test();
	system("pause");
	return 0;
}