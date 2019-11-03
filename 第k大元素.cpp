//在未排序的数组中找到第 k 个最大的元素。请注意，你需要找的是数组排序后的第 k 个最大的元素，而不是第 k 个不同的元素。
//链接：https://leetcode-cn.com/problems/kth-largest-element-in-an-array/
class Solution {
public:
	int findKthLargest(vector<int>& nums, int k) {
		priority_queue<int, vector<int>, greater<int>> p;
		for (int i = 0; i < k; i++)
			p.push(nums[i]);
		for (int i = k; i < nums.size(); i++)
		{
			if (nums[i] > p.top())
			{
				p.pop();
				p.push(nums[i]);
			}
		}
		return p.top();
	}
};