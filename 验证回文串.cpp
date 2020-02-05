//给定一个字符串，验证它是否是回文串，只考虑字母和数字字符，可以忽略字母的大小写。
//说明：本题中，我们将空字符串定义为有效的回文串。
//链接：https://leetcode-cn.com/problems/valid-palindrome/
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