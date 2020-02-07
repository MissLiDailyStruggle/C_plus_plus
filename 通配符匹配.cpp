//给定一个字符串 (s) 和一个字符模式 (p) ，实现一个支持 '?' 和 '*' 的通配符匹配。'?' 可以匹配任何单个字符。'*' 可以匹配任意字符串（包括空字符串）。
//链接：https ://leetcode-cn.com/problems/wildcard-matching
class Solution {
public:
	bool isMatch(string s, string p) {

		int i = 0;
		int j = 0;
		int start = -1;
		int k = 0; // 记录最后一次匹配的位置  + 1

		while (i < s.size())
		{
			if (s[i] == p[j] || p[j] == '?') {
				++i;
				++j;
				continue;
			}

			if (p[j] == '*') {
				start = j++;
				k = i;
				continue;
			}

			// 如果失配了，回溯到 k + 1，即让 * 再多吞噬一个字符。
			if (start != -1) {
				i = ++k;
				j = start + 1;
				continue;
			}
			return false;
		}

		while (j < p.length() && p[j] == '*') ++j;

		return j == p.length();
	}
};