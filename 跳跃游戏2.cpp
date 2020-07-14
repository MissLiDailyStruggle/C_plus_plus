//����һ���Ǹ��������飬�����λ������ĵ�һ��λ�á������е�ÿ��Ԫ�ش������ڸ�λ�ÿ�����Ծ����󳤶ȡ����Ŀ����ʹ�����ٵ���Ծ����������������һ
//��λ�á�
//��Դ�����ۣ�LeetCode��
//���ӣ�https ://leetcode-cn.com/problems/jump-game-ii
class Solution {
public:
	int jump(vector<int>& nums) {
		int end = 0;
		int max_pos = 0;
		int step = 0;
		for (int i = 0; i < nums.size() - 1; ++i)
		{
			max_pos = max(max_pos, nums[i] + i);
			if (i == end)
			{
				++step;
				end = max_pos;
			}
		}
		return step;
	}
};