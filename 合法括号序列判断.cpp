//链接：https://www.nowcoder.com/questionTerminal/d8acfa0619814b2d98f12c071aef20d4
//来源：牛客网
//对于一个字符串，请设计一个算法，判断其是否为一个合法的括号串。
//给定一个字符串A和它的长度n，请返回一个bool值代表它是否为一个合法的括号串。
class Parenthesis {
public:
	bool chkParenthesis(string A, int n) {
		stack<char> stleft;
		if (n % 2 != 0)
			return false;
		for (int i = 0; i < n; i++)
		{
			if (A[i] == '(')
				stleft.push(A[i]);
			else if (A[i] != '(' && A[i] != ')')
				return false;
		}
		for (int i = 0; i < n; i++)
		{
			if (A[i] == ')')
			{
				if (stleft.empty())
					return false;
				else
					stleft.pop();
			}
		}
		return true;
	}
};