//你的朋友正在使用键盘输入他的名字 name。偶尔，在键入字符 c 时，按键可能会被长按，而字符可能被输入 1 次或多次。你将会检查键盘输入的字符 typed。如果它对应的可
//能是你的朋友的名字（其中一些字符可能被长按），那么就返回 True。
//链接：https ://leetcode-cn.com/problems/long-pressed-nam
class Solution {
public:
	bool isLongPressedName(string name, string typed) {
		int i = 0;
		int j = 0;
		for (i = 0, j = 0; i < name.size(), j < typed.size();)
		{
			if (name[i] == typed[j])
			{
				i++;
				j++;
			}
			else
				j++;
		}
		return i == name.size();
	}
};