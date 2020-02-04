//给定两个二进制字符串，返回他们的和（用二进制表示）。输入为非空字符串且只包含数字 1 和 0。
//链接：https://leetcode-cn.com/problems/add-binary/
class Solution {
public:
	string addBinary(string a, string b) {
		string res;
		int la = a.size();
		int lb = b.size();
		if (la < lb)
		{
			swap(a, b);
			swap(la, lb);
		}
		if (la - lb > 0)
			b.insert(0, la - lb, '0');
		int pre = 0, cur = 0;
		for (int i = la - 1; i >= 0; i--)
		{
			int ia = a[i] - '0';
			int ib = b[i] - '0';
			cur = ia ^ ib ^ pre;
			if (ia + ib + pre >= 2)
				pre = 1;
			else
				pre = 0;
			res.insert(0, 1, cur + '0');
		}
		if (pre)
			res.insert(0, 1, pre + '0');
		return res;
	}
};