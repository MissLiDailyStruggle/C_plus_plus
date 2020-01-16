//给定一个排序数组和一个目标值，在数组中找到目标值，并返回其索引。如果目标值不存在于数组中，返回它将会被按顺序插入的位置。你可以假设数组中无重复元素。
//链接：https://leetcode-cn.com/problems/search-insert-position/
class Solution {
public:
	int searchInsert(vector<int>& nums, int target) {
		if (target < nums[0] || target == nums[0])
		{
			return 0;
		}
		for (int i = 1; i < nums.size(); i++)
		{
			if (target == nums[i])
			{
				return i;
			}
			if (target < nums[i] && target > nums[i - 1])
			{
				return i;
			}
		}
		return nums.size();
	}
};