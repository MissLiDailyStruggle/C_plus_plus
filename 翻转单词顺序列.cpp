//链接：https://www.nowcoder.com/questionTerminal/3194a4f4cf814f63919d0790578d51f3
//来源：牛客网
//牛客最近来了一个新员工Fish，每天早晨总是会拿着一本英文杂志，写些句子在本子上。同事Cat对Fish写的内容颇感兴趣，有一天他向Fish借来翻看，但却读不懂它
//的意思。例如，“student.a am I”。后来才意识到，这家伙原来把句子单词的顺序翻转了，正确的句子应该是“I am a student.”。Cat对一一的翻转这些单词顺序
//可不在行，你能帮助他么？
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
