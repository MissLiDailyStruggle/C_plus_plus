//���ӣ�https://www.nowcoder.com/questionTerminal/3194a4f4cf814f63919d0790578d51f3
//��Դ��ţ����
//ţ���������һ����Ա��Fish��ÿ���糿���ǻ�����һ��Ӣ����־��дЩ�����ڱ����ϡ�ͬ��Cat��Fishд�������ĸ���Ȥ����һ������Fish������������ȴ��������
//����˼�����磬��student.a am I������������ʶ������һ�ԭ���Ѿ��ӵ��ʵ�˳��ת�ˣ���ȷ�ľ���Ӧ���ǡ�I am a student.����Cat��һһ�ķ�ת��Щ����˳��
//�ɲ����У����ܰ�����ô��
class Solution {
public:
	string ReverseSentence(string str) {
		string res;
		int i = str.size() - 1, j = str.size() - 1;
		while (i >= 0 && j >= 0)
		{
			if (i == 0 || str[i - 1] == ' ')
			{
				res += str.substr(i, j - i + 1);
				if (i != 0)
				{
					j = i - 2;
					res += ' ';
				}
			}
			i--;
		}
		return res;
	}
};
