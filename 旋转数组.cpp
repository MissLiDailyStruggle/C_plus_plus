//����һ�����飬�������е�Ԫ�������ƶ� k ��λ�ã����� k �ǷǸ�����
//���ӣ�https://leetcode-cn.com/problems/rotate-array/
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