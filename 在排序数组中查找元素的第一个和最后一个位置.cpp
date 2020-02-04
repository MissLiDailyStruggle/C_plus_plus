//给定一个按照升序排列的整数数组 nums，和一个目标值 target。找出给定目标值在数组中的开始位置和结束位置。
//链接:https://leetcode-cn.com/problems/find-first-and-last-position-of-element-in-sorted-array/
class Solution {
public:
	vector<int> searchRange(vector<int>& nums, int target) {
		int begin = -1;
		int end = -1;
		for (int i = 0; i < nums.size(); i++)
		{
			if (nums[i] == target)
			{
				begin = end = i;
				while (i < nums.size() && nums[i] == target)
					i++;
				if (begin != i)
					end = i - 1;
			}
		}
		return{ begin, end };
	}
};