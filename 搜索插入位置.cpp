//����һ�����������һ��Ŀ��ֵ�����������ҵ�Ŀ��ֵ�������������������Ŀ��ֵ�������������У����������ᱻ��˳������λ�á�����Լ������������ظ�Ԫ�ء�
//���ӣ�https://leetcode-cn.com/problems/search-insert-position/
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