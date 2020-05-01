//���ӣ�https://www.nowcoder.com/practice/45327ae22b7b413ea21df13ee7d6429c?tpId=13&tqId=11205&tPage=3&rp=3&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
//��ʵ��һ����������ƥ�����'.'��'*'��������ʽ��ģʽ�е��ַ�'.'��ʾ����һ���ַ�����'*'��ʾ��ǰ����ַ����Գ�������Σ�����0�Σ��� �ڱ����У�ƥ����
//ָ�ַ����������ַ�ƥ������ģʽ�����磬�ַ���"aaa"��ģʽ"a.a"��"ab*ac*a"ƥ�䣬������"aa.a"��"ab*a"����ƥ��
class Solution {
public:
	bool match(char* str, char* pattern)
	{
		if (str == nullptr || pattern == nullptr)
			return false;
		if (*str == '\0')
		{
			if (*pattern == '\0' || (*(pattern + 1) == '*' && *(pattern + 2) == '\0'))
				return true;
			return false;
		}
		if (*pattern == '\0')
			return false;
		if (*(pattern + 1) == '*')
		{
			if (*pattern == *str || *pattern == '.')
				return match(str, pattern + 2) || match(str + 1, pattern);
			else
				return match(str, pattern + 2);
		}
		if (*pattern == *str || *pattern == '.')
			return match(str + 1, pattern + 1);
		return false;
	}
};