//���ӣ�https://www.nowcoder.com/questionTerminal/1183548cd48446b38da501e58d5944eb
//��Դ��ţ����
//����С����һ��W*H��������ӣ�������б��Ϊ0~H - 1��������б��Ϊ0~W - 1��ÿ������������Է�һ�鵰�⣬�������鵰���ŷ�����
//���벻�ܵ���2������������������(x1, y1), (x2, y2)��ŷ����þ���Ϊ :((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2)) ������ƽ����
//С����֪�������ԷŶ��ٿ鵰������������
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