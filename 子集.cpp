class Solution {
//给定一组不含重复元素的整数数组 nums，返回该数组所有可能的子集（幂集）。
//链接：https://leetcode-cn.com/problems/subsets/
public:
	vector<vector<int>> subsets(vector<int>& nums) {
		vector<vector<int>> res;
		res.push_back({});
		int size = nums.size();
		int subnum = pow(2, size);
		int i = 1;
		while (i < subnum)
		{
			vector<int> temp;
			for (int k = 0; k < size; k++)
			{
				int a = 1 << k;
				if (i & a)
					temp.push_back(nums[k]);
			}
			res.push_back(temp);
			i++;
		}
		return res;
	}
};