class Solution {
public:
	int evalRPN(vector<string>& tokens) {
		stack<int> s;
		for (size_t i = 0; i < tokens.size(); ++i)
		{
			if (tokens[i].size() == 1
				&& (tokens[i][0] == '+'
				|| tokens[i][0] == '-'
				|| tokens[i][0] == '*'
				|| tokens[i][0] == '/'))
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