//给定一个二叉树，判断它是否是高度平衡的二叉树。本题中，一棵高度平衡二叉树定义为：一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过1。
//来源：力扣（LeetCode）
//链接：https ://leetcode-cn.com/problems/balanced-binary-tree
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
	int maxDepth(TreeNode* root) {
		if (root == NULL)
			return 0;
		return max(maxDepth(root->left), maxDepth(root->right)) + 1;
	}
	bool isBalanced(TreeNode* root) {
		if (root == NULL)
			return true;
		if (abs(maxDepth(root->left) - maxDepth(root->right)) > 1)
			return false;
		return isBalanced(root->left) && isBalanced(root->right);
	}
};