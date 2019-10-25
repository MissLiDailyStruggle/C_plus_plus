#include "list.h"


void list_text1()
{
	li::list<int> ex;
	ex.push_back(1);
	ex.push_back(5);
	ex.push_back(6);
	ex.push_back(7);
	ex.push_back(0);
	li::list<int>ex2(ex);
	li::list<int>ex3 = ex;
	li::print_list(ex);
	li::print_list(ex2);
	li::print_list(ex3);
	li::list<int>::iterator it = ex.begin();
	while (it != ex.end())
	{
		if (*it % 2 == 0)
		{
			it = ex.erase(it);
		}
		++it;
	}
	li::print_list(ex);
}

struct Date
{
	int _year = 1990;
	int _month = 1;
	int _day = 1;
};
void list_text2()
{
	li::list<Date> l;
	l.push_back(Date());
	l.push_back(Date());
	auto it = l.begin();
	while (it != l.end())
	{
		cout << it->_year << "-" << it->_month << "-" << it->_day << endl;
		++it;
	}
}

int main()
{
	//list_text1();
	list_text2();
	system("pause");
	return 0;
}