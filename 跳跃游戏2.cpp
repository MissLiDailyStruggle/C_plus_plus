//给定一个非负整数数组，你最初位于数组的第一个位置。数组中的每个元素代表你在该位置可以跳跃的最大长度。你的目标是使用最少的跳跃次数到达数组的最后一
//个位置。
//来源：力扣（LeetCode）
//链接：https ://leetcode-cn.com/problems/jump-game-ii
class Solution {
public:
	int jump(vector<int>& nums) {
		int end = 0;
		int max_pos = 0;
		int step = 0;
		for (int i = 0; i < nums.size() - 1; ++i)
		{
			max_pos = max(max_pos, nums[i] + i);
			if (i == end)
			{
				++step;
				end = max_pos;
			}
		}
		return step;
	}
};