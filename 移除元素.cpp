//����һ������ nums?��һ��ֵ val������Ҫԭ���Ƴ�������ֵ����?val?��Ԫ�أ������Ƴ���������³��ȡ���Ҫʹ�ö��������ռ䣬�������ԭ���޸��������鲢��ʹ�� O(1) 
//����ռ����������ɡ�Ԫ�ص�˳����Ըı䡣�㲻��Ҫ���������г����³��Ⱥ����Ԫ�ء�
//���ӣ�https ://leetcode-cn.com/problems/remove-element
class Solution {
public:
	int removeElement(vector<int>& nums, int val) {
		int num = 0;
		for (int i = 0; i < nums.size(); i++)
		{
			if (nums[i] != val)
			{
				nums[num++] = nums[i];
			}
		}
		return num;
	}
};