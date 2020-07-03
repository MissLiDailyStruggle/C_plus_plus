// 链接：https://www.nowcoder.com/practice/4060ac7e3e404ad1a894ef3e17650423?tpId=13&rp=1&ru=%2Fta%2Fcoding-interviews&qru=%2Fta%2Fcoding-interviews%2Fquestion-ranking
//来源：牛客网
//请实现一个函数，将一个字符串中的每个空格替换成“ % 20”。例如，当字符串为We Are Happy.则经过替换之后的字符串为We%20Are % 20Happy。
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