//���ӣ�https://www.nowcoder.com/questionTerminal/4b1658fd8ffb4217bc3b7e85a38cfaf2
//��Դ��ţ����
//���� : ��һ��byte���ֶ�Ӧ�Ķ�����������1�����������������3�Ķ�����Ϊ00000011���������2��1    
//���� : һ��byte�͵�����    ��� : ��     
//���� : ��Ӧ�Ķ�����������1�����������
#include <iostream>

using namespace std;

int main()
{
	int byte;
	while (cin >> byte)
	{
		int res = 0;
		while (byte)
		{
			int count = 0;
			while (byte && (byte & 1 == 1))
			{
				count++;
				byte = byte >> 1;
			}
			if (count > res)
				res = count;
			byte = byte >> 1;
		}
		cout << res << endl;
	}
	return 0;
}