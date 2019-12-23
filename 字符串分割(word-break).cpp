//���ӣ�https://www.nowcoder.com/practice/5f3b7bf611764c8ba7868f3ed40d6b2c
//��Դ��ţ����
//����һ���ַ���s��һ�鵥��dict���ж�s�Ƿ�����ÿո�ָ��һ���������У�ʹ�õ������������еĵ��ʶ���dict�еĵ��ʣ����п��԰���һ���������ʣ���
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