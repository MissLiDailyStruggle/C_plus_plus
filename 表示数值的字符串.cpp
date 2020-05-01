//���ӣ�https://www.nowcoder.com/practice/6f8c901d091949a5837e24bb82a731f2?tpId=13&tqId=11206&rp=3&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
//��Դ��ţ����
//��ʵ��һ�����������ж��ַ����Ƿ��ʾ��ֵ������������С���������磬�ַ���"+100", "5e2", "-123", "3.1416"��"-1E-16"����ʾ��ֵ�� ����"12e", "1a3.14",
//"1.2.3", "+-5"��"12e+4.3"�����ǡ�
class Solution {
public:
	bool isNumeric(char* string)
	{
		if (string == nullptr || *string == '\0')
			return false;
		if (*string == '+' || *string == '-')
			++string;
		bool numeric = true;
		while (*string != '\0' && *string >= '0' && *string <= '9')
			++string;
		if (*string != '\0')
		{
			if (*string == '.')
			{
				string++;
				while (*string != '\0' && *string >= '0' && *string <= '9')
					++string;
			}
			if (*string == 'e' || *string == 'E')
			{
				string++;
				if (*string == '+' || *string == '-')
					++string;
				if (*string == '\0')
					numeric = false;
				while (*string != '\0' && *string >= '0' && *string <= '9')
					++string;
			}
		}
		return numeric && *string == '\0';
	}
};