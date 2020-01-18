//给定一个赎金信(ransom) 字符串和一个杂志(magazine)字符串，判断第一个字符串ransom能不能由第二个字符串magazines里面的字符构成。如果可以构成，返回 true ；
//否则返回 false。(题目说明：为了不暴露赎金信字迹，要从杂志上搜索各个需要的字母，组成单词来表达意思。)
//链接：https ://leetcode-cn.com/problems/ransom-note
class Solution {
public:
	bool canConstruct(string ransomNote, string magazine) {
		for (int i = 0; i < ransomNote.size(); i++)
		{
			int pos = magazine.find(ransomNote[i]);
			if (pos == -1)
			{
				return false;
			}
			else
			{
				magazine.erase(pos, 1);
			}
		}
		return true;
	}
};