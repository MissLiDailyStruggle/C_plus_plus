//根据逆波兰表示法，求表达式的值。有效的运算符包括 + , -, *, / 。每个运算对象可以是整数，也可以是另一个逆波兰表达式。
//链接：https://leetcode-cn.com/problems/evaluate-reverse-polish-notation/
class Solution {
public:
	int evalRPN(vector<string>& tokens) {
		stack<int>s;
		for (int i = 0; i < tokens.size(); i++)
		{
			if ((tokens[i].size() == 1) &&
				(
				tokens[i][0] == '+' ||
				tokens[i][0] == '-' ||
				tokens[i][0] == '*' ||
				tokens[i][0] == '/'
				))
			{
				int right = s.top();
				s.pop();
				int left = s.top();
				s.pop();
				if (tokens[i][0] == '+')
					s.push(left + right);
				else if (tokens[i][0] == '-')
					s.push(left - right);
				else if (tokens[i][0] == '*')
					s.push(left * right);
				else if (tokens[i][0] == '/')
					s.push(left / right);
				else
					assert(false);
			}
			else
			{
				s.push(atoi(tokens[i].c_str()));
			}
		}
		return s.top();
	}
};