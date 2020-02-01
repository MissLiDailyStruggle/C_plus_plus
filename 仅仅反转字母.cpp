//给定一个字符串 S，返回 “反转后的” 字符串，其中不是字母的字符都保留在原地，而所有字母的位置发生反转。
//链接：https://leetcode-cn.com/problems/reverse-only-letters/
class Solution {
private:
	bool ischar(char ch)
	{
		if (('z' >= ch && ch >= 'a') || ('Z' >= ch && ch >= 'A'))
			return true;
		else
			return false;
	}
public:
	string reverseOnlyLetters(string S) {
		int begin = 0;
		int end = S.size() - 1;
		while (end > begin)
		{
			while (!ischar(S[begin]) && begin < end)
				begin++;
			while (!ischar(S[end]) && begin < end)
				end--;
			swap(S[begin], S[end]);
			++begin;
			--end;
		}
		return S;
	}
};