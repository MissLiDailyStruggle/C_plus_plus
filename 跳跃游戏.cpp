//����һ���Ǹ��������飬�����λ������ĵ�һ��λ�á������е�ÿ��Ԫ�ش������ڸ�λ�ÿ�����Ծ����󳤶ȡ��ж����Ƿ��ܹ��������һ��λ�á�
//��Դ�����ۣ�LeetCode��
//���ӣ�https://leetcode-cn.com/problems/jump-game/
class Solution {
public:
	bool canJump(vector<int>& nums) {
		int most_distance = 0;
		for (int i = 0; i < nums.size(); ++i)
		{
			if (i <= most_distance)
			{
				most_distance = max(most_distance, i + nums[i]);
				if (most_distance >= nums.size() - 1)
					return true;
			}
		}
		return false;
	}
};