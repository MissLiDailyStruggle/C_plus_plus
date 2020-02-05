//����һ���������飬����ҪѰ��һ�������������飬���������������������������ô�������鶼���Ϊ�����������ҵ���������Ӧ����̵ģ���������ĳ��ȡ�
//���ӣ�https://leetcode-cn.com/problems/shortest-unsorted-continuous-subarray/
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