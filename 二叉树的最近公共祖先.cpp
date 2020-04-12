//给定一个二叉树, 找到该树中两个指定节点的最近公共祖先。
//百度百科中最近公共祖先的定义为：“对于有根树 T 的两个结点 p、q，最近公共祖先表示为一个结点 x，满足 x 是 p、q 的祖先且 x 的深度尽可能大（一个节点也
//可以是它自己的祖先）。”
//来源：力扣（LeetCode）
//链接：https ://leetcode-cn.com/problems/lowest-common-ancestor-of-a-binary-tree
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
	bool find(TreeNode* root, TreeNode* p)
	{
		if (root == nullptr)
			return false;
		else if (root == p)
			return true;
		else
			return find(root->left, p) || find(root->right, p);
	}

	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		if (root == nullptr || root == p || root == q)
			return root;
		bool ispInLeft = find(root->left, p);
		bool ispInRight = !ispInLeft;

		bool isqInLeft = find(root->left, q);
		bool isqInRight = !isqInLeft;

		if ((ispInLeft && isqInRight) || (ispInRight && isqInLeft))
			return root;
		else if (ispInLeft && isqInLeft)
			return lowestCommonAncestor(root->left, p, q);
		else if (ispInRight && isqInRight)
			return lowestCommonAncestor(root->right, p, q);
		return nullptr;
	}
};