//����һ����������������Ƿ��Ǿ���ԳƵġ�
//��Դ�����ۣ�LeetCode��
//���ӣ�https ://leetcode-cn.com/problems/symmetric-tree
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
	bool _isSymmetric(TreeNode* p, TreeNode* q)
	{
		if (p == NULL && q == NULL)
			return true;
		if (p == NULL || q == NULL)
			return false;
		if (p->val != q->val)
			return false;
		return _isSymmetric(p->left, q->right) && _isSymmetric(p->right, q->left);
	}
	bool isSymmetric(TreeNode* root) {
		if (root == NULL)
			return true;
		return _isSymmetric(root->left, root->right);
	}
};