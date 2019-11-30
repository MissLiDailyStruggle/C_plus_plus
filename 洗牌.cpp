//链接：https://www.nowcoder.com/questionTerminal/5a0a2c7e431e4fbbbb1ff32ac6e8dfa0
//来源：牛客网
//洗牌在生活中十分常见，现在需要写一个程序模拟洗牌的过程。 现在需要洗2n张牌，从上到下依次是第1张，第2张，第3张一直到第2n张。首先，我
//们把这2n张牌分成两堆，左手拿着第1张到第n张（上半堆），右手拿着第n + 1张到第2n张（下半堆）。接着就开始洗牌的过程，先放下右手的最后
//一张牌，再放下左手的最后一张牌，接着放下右手的倒数第二张牌，再放下左手的倒数第二张牌，直到最后放下左手的第一张牌。接着把牌合并起来
//就可以了。 例如有6张牌，最开始牌的序列是1, 2, 3, 4, 5, 6。首先分成两组，左手拿着1, 2, 3；右手拿着4, 5, 6。在洗牌过程中按顺序放下了
//6, 3, 5, 2, 4, 1。把这六张牌再次合成一组牌之后，我们按照从上往下的顺序看这组牌，就变成了序列1, 4, 2, 5, 3, 6。 现在给出一个原始牌
//组，请输出这副牌洗牌k次之后从上往下的序列。
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main()
{
	int T;
	int n, k;
	cin >> T;
	while (T--)
	{
		cin >> n >> k;
		int num = 2 * n;
		vector<int> arr(num);
		stack<int> st;
		for (int i = 0; i < num; i++)
			cin >> arr[i];
		while (k--)
		{
			for (int i = n - 1, j = num - 1; i >= 0, j >= n; i--, j--)
			{
				st.push(arr[j]);
				st.push(arr[i]);
			}
			for (int i = 0; i < num; i++)
			{
				int top = st.top();
				st.pop();
				arr[i] = top;
			}
		}
		for (int i = 0; i < num - 1; i++)
			cout << arr[i] << " ";
		cout << arr[num - 1] << endl;
	}
	return 0;
}