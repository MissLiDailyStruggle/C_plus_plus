//����һ�������(ransom) �ַ�����һ����־(magazine)�ַ������жϵ�һ���ַ���ransom�ܲ����ɵڶ����ַ���magazines������ַ����ɡ�������Թ��ɣ����� true ��
//���򷵻� false��(��Ŀ˵����Ϊ�˲���¶������ּ���Ҫ����־������������Ҫ����ĸ����ɵ����������˼��)
//���ӣ�https ://leetcode-cn.com/problems/ransom-note
class Solution {
public:
	bool canConstruct(string ransomNote, string magazine) {
		for (int i = 0; i < ransomNote.size(); i++)
		{
			int pos = magazine.find(ransomNote[i]);
			if (pos == -1)
			{
				return false;
			}
			else
			{
				magazine.erase(pos, 1);
			}
		}
		return true;
	}
};