//����һ��ֻ���� '('��')'��'{'��'}'��'['��']' ���ַ������ж��ַ����Ƿ���Ч��
//��Դ�����ۣ�LeetCode��
//���ӣ�https ://leetcode-cn.com/problems/valid-parentheses
class Solution {
public:
	bool isValid(string s) {
		char* symbol[3] = { "()", "[]", "{}" };
		stack<char> st;
		for (int i = 0; i < s.size(); ++i)
		{
			if (s[i] == '(' || s[i] == '{' || s[i] == '[')
			{
				st.push(s[i]);
			}
			else if (s[i] == ')' || s[i] == '}' || s[i] == ']')
			{
				if (st.empty())
					return false;
				char temp = st.top();
				st.pop();
				for (int j = 0; j < 3; ++j)
				{
					if (symbol[j][1] == s[i])
					{
						if (temp != symbol[j][0])
							return false;
						else
							break;
					}
				}
			}
		}
		return st.empty();
	}
};