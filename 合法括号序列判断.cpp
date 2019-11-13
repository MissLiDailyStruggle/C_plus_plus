//���ӣ�https://www.nowcoder.com/questionTerminal/d8acfa0619814b2d98f12c071aef20d4
//��Դ��ţ����
//����һ���ַ����������һ���㷨���ж����Ƿ�Ϊһ���Ϸ������Ŵ���
//����һ���ַ���A�����ĳ���n���뷵��һ��boolֵ�������Ƿ�Ϊһ���Ϸ������Ŵ���
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