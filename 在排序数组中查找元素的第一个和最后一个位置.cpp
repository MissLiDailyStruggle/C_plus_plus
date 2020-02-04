//����һ�������������е��������� nums����һ��Ŀ��ֵ target���ҳ�����Ŀ��ֵ�������еĿ�ʼλ�úͽ���λ�á�
//����:https://leetcode-cn.com/problems/find-first-and-last-position-of-element-in-sorted-array/
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