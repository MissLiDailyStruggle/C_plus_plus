//����Ҫ����ǰ������ķ�ʽ����һ��������ת����һ�������ź�������ɵ��ַ������սڵ�����һ�Կ����� "()" ��ʾ����������Ҫʡ�����в�Ӱ���ַ�����ԭʼ����
//��֮���һ��һӳ���ϵ�Ŀ����Ŷԡ�
//��Դ�����ۣ�LeetCode��
//���ӣ�https ://leetcode-cn.com/problems/construct-string-from-binary-tree

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