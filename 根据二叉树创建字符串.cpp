//你需要采用前序遍历的方式，将一个二叉树转换成一个由括号和整数组成的字符串。空节点则用一对空括号 "()" 表示。而且你需要省略所有不影响字符串与原始二叉
//树之间的一对一映射关系的空括号对。
//来源：力扣（LeetCode）
//链接：https ://leetcode-cn.com/problems/construct-string-from-binary-tree

/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };
*/
class Solution {
public:
	void _tree2str(TreeNode* t, string& str)
	{
		if (t == nullptr)
			return;
		str += to_string(t->val);
		if (t->left || t->right)
		{
			str += "(";
			_tree2str(t->left, str);
			str += ")";
		}
		if (t->right)
		{
			str += "(";
			_tree2str(t->right, str);
			str += ")";
		}
	}

	string tree2str(TreeNode* t) {
		string str;
		_tree2str(t, str);

		return str;
	}
};