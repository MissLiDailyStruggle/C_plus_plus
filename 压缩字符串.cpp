//给定一组字符，使用原地算法将其压缩。压缩后的长度必须始终小于或等于原数组长度。数组的每个元素应该是长度为1 的字符（不是 int 整数类型）。在完成原地修改输入数
//组后，返回数组的新长度。
//链接：https ://leetcode-cn.com/problems/string-compression
class Solution {
public:
	int compress(vector<char>& chars) {
		int start = 0, end = 0, count = 0, len = 0;
		while (start < chars.size())
		{
			end = start + 1;
			while (end < chars.size() && chars[start] == chars[end])
				end++;
			count = end - start;
			chars[len++] = chars[start];
			if (count != 1)
			{
				string res = to_string(count);
				for (auto ch : res)
					chars[len++] = ch;
			}
			start = end;
		}
		return len;
	}
};