//链接：https://www.nowcoder.com/questionTerminal/1277c681251b4372bdef344468e4f26e
//来源：牛客网
//将一个字符串转换成一个整数，要求不能使用字符串转换整数的库函数。 数值为0或者字符串不是一个合法的数值则返回0
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