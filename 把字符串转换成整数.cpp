//���ӣ�https://www.nowcoder.com/questionTerminal/1277c681251b4372bdef344468e4f26e
//��Դ��ţ����
//��һ���ַ���ת����һ��������Ҫ����ʹ���ַ���ת�������Ŀ⺯���� ��ֵΪ0�����ַ�������һ���Ϸ�����ֵ�򷵻�0
class Solution {
public:
	int StrToInt(string str) {
		int ret = 1;
		int i = 0;
		long res = 0;
		if (str.empty())
			return 0;
		if (str[0] == '-')
		{
			ret = -1;
			i++;
		}
		if (str[0] == '+')
		{
			ret = 1;
			i++;
		}
		while (i < str.size())
		{
			if (str[i] >= '0' && str[i] <= '9')
			{
				res = res * 10 + str[i] - '0';
				i++;
			}
			else
				return 0;
		}
		if (res * ret > 2147483647 || res * ret < -2147483648)
			return 0;
		return res * ret;
	}
};