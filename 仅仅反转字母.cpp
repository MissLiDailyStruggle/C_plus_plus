//����һ���ַ��� S������ ����ת��ġ� �ַ��������в�����ĸ���ַ���������ԭ�أ���������ĸ��λ�÷�����ת��
//���ӣ�https://leetcode-cn.com/problems/reverse-only-letters/
class Solution {
private:
	bool ischar(char ch)
	{
		if (('z' >= ch && ch >= 'a') || ('Z' >= ch && ch >= 'A'))
			return true;
		else
			return false;
	}
public:
	string reverseOnlyLetters(string S) {
		int begin = 0;
		int end = S.size() - 1;
		while (end > begin)
		{
			while (!ischar(S[begin]) && begin < end)
				begin++;
			while (!ischar(S[end]) && begin < end)
				end--;
			swap(S[begin], S[end]);
			++begin;
			--end;
		}
		return S;
	}
};