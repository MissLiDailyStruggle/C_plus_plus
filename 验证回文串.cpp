//����һ���ַ�������֤���Ƿ��ǻ��Ĵ���ֻ������ĸ�������ַ������Ժ�����ĸ�Ĵ�Сд��
//˵���������У����ǽ����ַ�������Ϊ��Ч�Ļ��Ĵ���
//���ӣ�https://leetcode-cn.com/problems/valid-palindrome/
class Solution {
public:
	bool is_rightch(char ch)
	{
		if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9'))
			return true;
		else
			return false;
	}
	bool isPalindrome(string s) {
		int left = 0;
		int right = s.size() - 1;
		while (right > left)
		{
			while (!is_rightch(s[left]) && right > left)
				left++;
			while (!is_rightch(s[right]) && right > left)
				right--;
			if (s[left] >= 'A' && s[left] <= 'Z')
				s[left] += 32;
			if (s[right] >= 'A' && s[right] <= 'Z')
				s[right] += 32;
			if (s[left] != s[right])
				return false;
			else
			{
				left++;
				right--;
			}
		}
		return true;
	}
};