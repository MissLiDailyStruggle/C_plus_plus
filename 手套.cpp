//链接：https://www.nowcoder.com/questionTerminal/365d5722fff640a0b6684391153e58d8
//来源：牛客网
//在地下室里放着n种颜色的手套，手套分左右手，但是每种颜色的左右手手套个数不一定相同。A先生现在要出门，所以他要去地下室选手套。
//但是昏暗的灯光让他无法分辨手套的颜色，只能分辨出左右手。所以他会多拿一些手套，然后选出一双颜色相同的左右手手套。现在的问题是
//，他至少要拿多少只手套(左手加右手)，才能保证一定能选出一双颜色相同的手套。给定颜色种数n(1≤n≤13), 同时给定两个长度为n的数组
//left, right, 分别代表每种颜色左右手手套的数量。数据保证左右的手套总数均不超过26，且一定存在至少一种合法方案。
class Gloves {
public:
	int findMinimum(int n, vector<int> left, vector<int> right) {
		// write code here
		int count = 0;
		int leftcount = 0;
		int rightcount = 0;
		int leftmin = 27;
		int rightmin = 27;
		for (int i = 0; i < n; i++)
		{
			if ((left[i] == 0) || (right[i] == 0))
				count += left[i] + right[i];
			else
			{
				leftcount += left[i];
				rightcount += right[i];
				leftmin = min(leftmin, left[i]);
				rightmin = min(rightmin, right[i]);
			}
		}
		if ((leftcount - leftmin + 1) > (rightcount - rightmin + 1))
			count += (rightcount - rightmin + 1 + 1);
		else
			count += (leftcount - leftmin + 1 + 1);
		return count;
	}
};