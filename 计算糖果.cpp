//���ӣ�https://www.nowcoder.com/questionTerminal/02d8d42b197646a5bbd0a98785bb3a34
//��Դ��ţ����
//A, B, C�������Ǻ�����, ÿ�������ﶼ��һЩ�ǹ�, ���ǲ�֪������ÿ�������Ͼ����ж��ٸ��ǹ�,��������֪�����µ���Ϣ; 
//A - B, B - C, A + B, B + C.���ĸ���ֵ.ÿ����ĸ����ÿ������ӵ�е��ǹ���.������Ҫͨ�����ĸ���ֵ�����ÿ����������
//���ٸ��ǹ�, ��A, B, C�����ﱣ֤���ֻ��һ������A, B, C������������������
#include <iostream>

using namespace std;

int main()
{
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	int A = (a + c) / 2;
	int B1 = (b + d) / 2;
	int B2 = (c - a) / 2;
	int C = (d - b) / 2;
	if (B1 == B2)
		cout << A << ' ' << B1 << ' ' << C << endl;
	else
		cout << "No" << endl;
}