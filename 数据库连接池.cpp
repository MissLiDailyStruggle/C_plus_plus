//链接：https://www.nowcoder.com/questionTerminal/05f97d9b29944c018578d98d7f0ce56e
//来源：牛客网
//Web系统通常会频繁地访问数据库，如果每次访问都创建新连接，性能会很差。为了提高性能，架构师决定复用已经创建的连接。当收到请求，并且连接池中没有剩余
//可用的连接时，系统会创建一个新连接，当请求处理完成时该连接会被放入连接池中，供后续请求使用。现在提供你处理请求的日志，请你分析一下连接池最多需要
//创建多少个连接。
#include <iostream>
#include <string>
#include <set>

using namespace std;

int main()
{
	int n;
	while (cin >> n)
	{
		set<string> s;
		int count = 0;
		for (int i = 0; i < n; i++)
		{
			string first, second;
			cin >> first >> second;
			if (second == "connect")
				s.insert(first);
			else if (second == "disconnect")
				s.erase(first);
			int size = s.size();
			count = max(size, count);
		}
		cout << count << endl;
	}
	return 0;
}