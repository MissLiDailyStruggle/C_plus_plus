//���������ǿն����� s �� t������ s ���Ƿ������ t ������ͬ�ṹ�ͽڵ�ֵ��������s ��һ���������� s ��һ���ڵ������ڵ���������s Ҳ���Կ����������һ��������
//��Դ�����ۣ�LeetCode��
//���ӣ�https ://leetcode-cn.com/problems/subtree-of-another-tree
/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode() : val(0), left(nullptr), right(nullptr) {}
*     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
*     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
* };
*/
class Solution {
public:
	bool isSametree(TreeNode* s, TreeNode* t)
	{
		if (s == nullptr && t == nullptr)
			return true;
		if (s == nullptr || t == nullptr)
			return false;
		if (s->val != t->val)
			return false;
		return isSametree(s->left, t->left) && isSametree(s->right, t->right);
	}
	bool isSubtree(TreeNode* s, TreeNode* t) {
		if (s == nullptr)
			return false;
		if (s->val == t->val)
		{
			if (isSametree(s, t))
				return true;
		}
		return isSubtree(s->left, t) || isSubtree(s->right, t);
	}
};