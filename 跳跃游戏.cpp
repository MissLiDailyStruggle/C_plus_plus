//给定一个非负整数数组，你最初位于数组的第一个位置。数组中的每个元素代表你在该位置可以跳跃的最大长度。判断你是否能够到达最后一个位置。
//来源：力扣（LeetCode）
//链接：https://leetcode-cn.com/problems/jump-game/
class Solution {
public:
	bool canJump(vector<int>& nums) {
		int most_distance = 0;
		for (int i = 0; i < nums.size(); ++i)
		{
			if (i <= most_distance)
			{
				most_distance = max(most_distance, i + nums[i]);
				if (most_distance >= nums.size() - 1)
					return true;
			}
		}
		return false;
	}
};