//链接：https://www.nowcoder.com/questionTerminal/839f681bf36c486fbcc5fcb977ffe432
//来源：牛客网
//
//考拉有n个字符串字符串，任意两个字符串长度都是不同的。考拉最近学习到有两种字符串的排序方法： 1.根据字符串的字典序排序。例如：
//"car" < "carriage" < "cats" <
//"doggies < "koala"
//2.根据字符串的长度排序。例如：
//"car" < "cats" < "koala" <
//"doggies" < "carriage"
//考拉想知道自己的这些字符串排列顺序是否满足这两种排序方法，考拉要忙着吃树叶，所以需要你来帮忙验证。
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
	int n;
	string s;
	bool flag1 = 1;
	bool flag2 = 1;
	vector<string> v;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> s;
		v.push_back(s);
	}
	int i = 0;
	while ((i + 1) < v.size())
	{
		if (v[i].compare(v[i + 1]) > 0)
		{
			flag1 = 0;
			break;
		}
		i++;
	}
	i = 0;
	while ((i + 1) < v.size())
	{
		if (v[i + 1].size() < v[i].size())
		{
			flag2 = 0;
			break;
		}
		i++;
	}
	if (flag1 && flag2)
		cout << "both" << endl;
	else if (flag1 && !flag2)
		cout << "lexicographically" << endl;
	else if (!flag1 && flag2)
		cout << "lengths" << endl;
	else
		cout << "none" << endl;
	return 0;
}