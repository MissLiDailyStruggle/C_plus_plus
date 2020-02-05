//给定一个整数数组，你需要寻找一个连续的子数组，如果对这个子数组进行升序排序，那么整个数组都会变为升序排序。你找到的子数组应是最短的，请输出它的长度。
//链接：https://leetcode-cn.com/problems/shortest-unsorted-continuous-subarray/
class Solution {
public:
	int findUnsortedSubarray(vector<int>& nums) {
		vector<int>temp = nums;
		sort(temp.begin(), temp.end());
		int left = 0;
		int right = nums.size() - 1;
		while (left < right && nums[left] == temp[left])
			left++;
		while (left < right && nums[right] == temp[right])
			right--;
		if (left == right)
			return 0;
		return right - left + 1;
	}
};