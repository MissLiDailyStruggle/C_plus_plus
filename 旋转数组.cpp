//给定一个数组，将数组中的元素向右移动 k 个位置，其中 k 是非负数。
//链接：https://leetcode-cn.com/problems/rotate-array/
class Solution {
public:
	void rotate(vector<int>& nums, int k) {
		int n = nums.size();
		k %= n;
		vector<int>temp = nums;
		for (int i = 0; i < nums.size(); i++)
		{
			int index = (i + k) % n;
			temp[index] = nums[i];
		}
		for (int i = 0; i < nums.size(); i++)
		{
			nums[i] = temp[i];
		}
	}
};