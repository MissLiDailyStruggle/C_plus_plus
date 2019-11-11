//链接：https://www.nowcoder.com/questionTerminal/1183548cd48446b38da501e58d5944eb
//来源：牛客网
//二货小易有一个W*H的网格盒子，网格的行编号为0~H - 1，网格的列编号为0~W - 1。每个格子至多可以放一块蛋糕，任意两块蛋糕的欧几里得
//距离不能等于2。对于两个格子坐标(x1, y1), (x2, y2)的欧几里得距离为 :((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2)) 的算术平方根
//小易想知道最多可以放多少块蛋糕在网格盒子里。
#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int w, h;
	int count = 0;
	cin >> w >> h;
	vector<vector<int>> v;
	v.resize(h);
	for (int i = 0; i < h; i++)
		v[i].resize(w, 1);
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			if (v[i][j] == 1)
			{
				count++;
				if (i + 2 < h)
					v[i + 2][j] = 0;
				if (j + 2 < w)
					v[i][j + 2] = 0;
			}
		}
	}
	cout << count << endl;
}