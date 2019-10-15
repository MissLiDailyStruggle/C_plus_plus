#include <iostream>
#include "list.h"

using namespace std;

void list_list()
{
	li::list<int> ex;
	ex.push_back(1);
	ex.push_back(5);
	ex.push_back(6);
	ex.push_back(7);
	ex.push_back(0);
	li::list<int>::iterator it = ex.begin();
	while (it != ex.end())
	{
		cout << *it << endl;
		++it;
	}
}

int main()
{
	list_list();
	system("pause");
	return 0;
}