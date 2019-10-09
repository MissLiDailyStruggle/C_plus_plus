class Solution {
public:
	string reverseWords(string s) {
		string::iterator begin = s.begin();
		auto it = begin;
		while (it <s.end())
		{
			if (*it == ' ')
			{
				reverse(begin, it);
				begin = it + 1;
			}
			it++;
		}
		reverse(begin, s.end());
		return s;
	}
};