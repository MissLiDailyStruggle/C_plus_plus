//链接：https://www.nowcoder.com/questionTerminal/ceb89f19187b4de3997d9cdef2d551e8
//来源：牛客网
//上图是一个电话的九宫格，如你所见一个数字对应一些字母，因此在国外企业喜欢把电话号码设计成与自己公司名字相对应。例如公司的Help Desk号码是4357，因
//为4对应H、3对应E、5对应L、7对应P，因此4357就是HELP。同理，TUT - GLOP就代表888 - 4567、310 - GINO代表310 - 4466。 NowCoder刚进入外企，并不习惯这
//样的命名方式，现在给你一串电话号码列表，请你帮他转换成数字形式的号码，并去除重复的部分。
#include <iostream>
#include <string>
#include <vector>
#include <set>

using namespace std;

int main()
{
	int n;
	while (cin >> n)
	{
		vector<string>arr;
		set<string>brr;
		for (int i = 0; i < n; ++i)
		{
			string str;
			cin >> str;
			arr.push_back(str);
		}
		for (int i = 0; i < n; ++i)
		{
			string tmp;
			for (int j = 0; j < arr[i].size(); ++j)
			{
				if (arr[i][j] == '1')
					tmp += '1';
				else if (arr[i][j] == '2' || (arr[i][j] >= 'A' && arr[i][j] <= 'C'))
					tmp += '2';
				else if (arr[i][j] == '3' || (arr[i][j] >= 'D' && arr[i][j] <= 'F'))
					tmp += '3';
				else if (arr[i][j] == '4' || (arr[i][j] >= 'G' && arr[i][j] <= 'I'))
					tmp += '4';
				else if (arr[i][j] == '5' || (arr[i][j] >= 'J' && arr[i][j] <= 'L'))
					tmp += '5';
				else if (arr[i][j] == '6' || (arr[i][j] >= 'M' && arr[i][j] <= 'O'))
					tmp += '6';
				else if (arr[i][j] == '7' || (arr[i][j] >= 'P' && arr[i][j] <= 'S'))
					tmp += '7';
				else if (arr[i][j] == '8' || (arr[i][j] >= 'T' && arr[i][j] <= 'V'))
					tmp += '8';
				else if (arr[i][j] == '9' || (arr[i][j] >= 'W' && arr[i][j] <= 'Z'))
					tmp += '9';
				else if (arr[i][j] == '0')
					tmp += '0';
				else
					continue;
			}
			brr.insert(tmp);
		}
		set<string>::iterator it = brr.begin();
		while (it != brr.end())
		{
			string res = *it;
			for (int i = 0; i < 3; ++i)
				cout << res[i];
			cout << "-";
			for (int i = 3; i < 7; ++i)
				cout << res[i];
			cout << endl;
			++it;
		}
		cout << endl;
	}
	return 0;
}