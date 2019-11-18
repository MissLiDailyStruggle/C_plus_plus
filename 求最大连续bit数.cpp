//链接：https://www.nowcoder.com/questionTerminal/4b1658fd8ffb4217bc3b7e85a38cfaf2
//来源：牛客网
//功能 : 求一个byte数字对应的二进制数字中1的最大连续数，例如3的二进制为00000011，最大连续2个1    
//输入 : 一个byte型的数字    输出 : 无     
//返回 : 对应的二进制数字中1的最大连续数
#include <iostream>

using namespace std;

int main()
{
	int byte;
	while (cin >> byte)
	{
		int res = 0;
		while (byte)
		{
			int count = 0;
			while (byte && (byte & 1 == 1))
			{
				count++;
				byte = byte >> 1;
			}
			if (count > res)
				res = count;
			byte = byte >> 1;
		}
		cout << res << endl;
	}
	return 0;
}