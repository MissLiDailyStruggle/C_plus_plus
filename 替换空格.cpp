// ���ӣ�https://www.nowcoder.com/practice/4060ac7e3e404ad1a894ef3e17650423?tpId=13&rp=1&ru=%2Fta%2Fcoding-interviews&qru=%2Fta%2Fcoding-interviews%2Fquestion-ranking
//��Դ��ţ����
//��ʵ��һ����������һ���ַ����е�ÿ���ո��滻�ɡ� % 20�������磬���ַ���ΪWe Are Happy.�򾭹��滻֮����ַ���ΪWe%20Are % 20Happy��
public:
	void replaceSpace(char *str, int length) {
		string tmp;
		for (int i = 0; i < length; ++i)
		{
			if (str[i] != ' ')
				tmp += str[i];
			else
			{
				tmp += '%';
				tmp += '2';
				tmp += '0';
			}
		}
		strcpy(str, tmp.c_str());
	}
};