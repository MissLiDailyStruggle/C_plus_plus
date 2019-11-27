//链接：https://www.nowcoder.com/questionTerminal/fe298c55694f4ed39e256170ff2c205f
//来源：牛客网
//有这样一道智力题：“某商店规定：三个空汽水瓶可以换一瓶汽水。小张手上有十个空汽水瓶，她最多可以换多少瓶汽水喝？”
//答案是5瓶，方法如下：先用9个空瓶子换3瓶汽水，喝掉3瓶满的，喝完以后4个空瓶子，用3个再换一瓶，喝掉这瓶满的，这时候
//剩2个空瓶子。然后你让老板先借给你一瓶汽水，喝掉这瓶满的，喝完以后用3个空瓶子换一瓶满的还给老板。如果小张手上有n个
//空汽水瓶，最多可以换多少瓶汽水喝？
#include <iostream>

using namespace std;

int main()
{
	int n;
	while (cin >> n)
	{
		int count = 0;
		int temp = 0;
		while (n >= 2)
		{
			if (n == 2)
			{
				count++;
				break;
			}
			temp = n / 3;
			n = n % 3 + temp;
			count += temp;
		}
		cout << count << endl;
	}
	return 0;
}