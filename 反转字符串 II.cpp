class Solution {
public:
	string reverseStr(string s, int k) {
		string::iterator it = s.begin();
		while (it <s.end() && it + k <= s.end())
		{
			reverse(it, it + k);
			it = it + 2 * k;
		}
		if (it + k >s.end())
			reverse(it, s.end());
		return s;
	}
};