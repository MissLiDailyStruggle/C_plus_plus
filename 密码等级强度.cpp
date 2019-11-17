//链接：https://www.nowcoder.com/questionTerminal/52d382c2a7164767bca2064c1c9d5361
//来源：牛客网
//密码按如下规则进行计分，并根据不同的得分为密码进行安全等级划分。
//一、密码长度 :
//5 分 : 小于等于4 个字符
//10 分 : 5 到7 字符
//25 分 : 大于等于8 个字符
//二、字母 :
//0 分 : 没有字母
//10 分 : 全都是小（大）写字母
//20 分 : 大小写混合字母
//三、数字 :
//0 分 : 没有数字
//10 分 : 1 个数字
//20 分 : 大于1 个数字
//四、符号 :
//0 分 : 没有符号
//10 分 : 1 个符号
//25 分 : 大于1 个符号
//五、奖励 :
//2 分 : 字母和数字
//3 分 : 字母、数字和符号
//5 分 : 大小写字母、数字和符号
//最后的评分标准 :
//>= 90 : 非常安全
//>= 80 : 安全（Secure）
//>= 70 : 非常强
//>= 60 : 强（Strong）
//>= 50 : 一般（Average）
//>= 25 : 弱（Weak）
//>= 0 : 非常弱
#include <iostream>
#include <string>

using namespace std;

string GetPwdSecurityLevel(string pPasswordStr)
{
	int count = 0;
	int num = 0;
	int schar = 0;
	int bchar = 0;
	int symbol = 0;
	for (int i = 0; i < pPasswordStr.size(); i++)
	{
		if (pPasswordStr[i] > '0' && pPasswordStr[i] < '9')
			num++;
		else if (pPasswordStr[i] > 'a' && pPasswordStr[i] < 'z')
			schar++;
		else if (pPasswordStr[i] > 'A' && pPasswordStr[i] < 'Z')
			bchar++;
		else
			symbol++;

	}
	if (pPasswordStr.size() <= 4)
		count = 5;
	else if (pPasswordStr.size() >= 5 && pPasswordStr.size() <= 7)
		count = 10;
	else
		count = 25;
	if (schar + bchar == 0)
		count += 0;
	else if (schar == 0 || bchar == 0)
		count += 10;
	else
		count += 20;
	if (num == 0)
		count += 0;
	else if (num == 1)
		count += 10;
	else
		count += 20;
	if (symbol == 0)
		count += 0;
	else if (symbol == 1)
		count += 10;
	else
		count += 25;
	if (schar > 0 && bchar > 0 && num > 0 && symbol > 0)
		count += 5;
	else if ((schar > 0 || bchar > 0) && num > 0 && symbol > 0)
		count += 3;
	else if ((schar > 0 || bchar > 0) && num > 0)
		count += 2;
	if (count >= 90)
		return "VERY_SECURE";
	else if (count >= 80)
		return "SECURE";
	else if (count >= 70)
		return "VERY_STRONG";
	else if (count >= 60)
		return "STRONG";
	else if (count >= 50)
		return "AVERAGE";
	else if (count >= 25)
		return "WEAK";
	else
		return "VERY_WEAK";
}
int main()
{
	string password;
	while (cin >> password)
		cout << GetPwdSecurityLevel(password) << endl;
	return 0;
}