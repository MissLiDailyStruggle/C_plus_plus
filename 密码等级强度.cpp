//���ӣ�https://www.nowcoder.com/questionTerminal/52d382c2a7164767bca2064c1c9d5361
//��Դ��ţ����
//���밴���¹�����мƷ֣������ݲ�ͬ�ĵ÷�Ϊ������а�ȫ�ȼ����֡�
//һ�����볤�� :
//5 �� : С�ڵ���4 ���ַ�
//10 �� : 5 ��7 �ַ�
//25 �� : ���ڵ���8 ���ַ�
//������ĸ :
//0 �� : û����ĸ
//10 �� : ȫ����С����д��ĸ
//20 �� : ��Сд�����ĸ
//�������� :
//0 �� : û������
//10 �� : 1 ������
//20 �� : ����1 ������
//�ġ����� :
//0 �� : û�з���
//10 �� : 1 ������
//25 �� : ����1 ������
//�塢���� :
//2 �� : ��ĸ������
//3 �� : ��ĸ�����ֺͷ���
//5 �� : ��Сд��ĸ�����ֺͷ���
//�������ֱ�׼ :
//>= 90 : �ǳ���ȫ
//>= 80 : ��ȫ��Secure��
//>= 70 : �ǳ�ǿ
//>= 60 : ǿ��Strong��
//>= 50 : һ�㣨Average��
//>= 25 : ����Weak��
//>= 0 : �ǳ���
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