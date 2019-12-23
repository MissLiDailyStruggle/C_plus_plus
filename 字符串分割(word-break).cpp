//链接：https://www.nowcoder.com/practice/5f3b7bf611764c8ba7868f3ed40d6b2c
//来源：牛客网
//给定一个字符串s和一组单词dict，判断s是否可以用空格分割成一个单词序列，使得单词序列中所有的单词都是dict中的单词（序列可以包含一个或多个单词）。
class Solution {
public:
	bool wordBreak(string s, unordered_set<string> &dict) {
		if (s.empty() || dict.empty())
			return false;
		vector<bool>can_break(s.size() + 1, false);
		can_break[0] = true;
		for (int i = 1; i <= s.size(); i++)
		{
			for (int j = 0; j < i; j++)
			{
				if (can_break[j] && dict.find(s.substr(j, i - j)) != dict.end())
				{
					can_break[i] = true;
					break;
				}
			}
		}
		return can_break[s.size()];
	}
};