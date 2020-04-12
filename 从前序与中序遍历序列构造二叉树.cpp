//根据一棵树的前序遍历与中序遍历构造二叉树。
//来源：力扣（LeetCode）
//链接：https://leetcode-cn.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/
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
	TreeNode* _buildTree(vector<int>& preorder, vector<int>& inorder, int& previ, int inbegin, int inend)
	{
		if (inbegin > inend)
			return nullptr;

		int  rootVal = preorder[previ];
		TreeNode* root = new TreeNode(rootVal);

		int inroot = inbegin;
		while (inroot <= inend)
		{
			if (inorder[inroot] == rootVal)
				break;
			else
				++inroot;
		}

		if (inbegin <= inroot - 1)
		{
			root->left = _buildTree(preorder, inorder, ++previ, inbegin, inroot - 1);
		}
		else
			root->left = nullptr;
		if (inend >= inroot + 1)
		{
			root->right = _buildTree(preorder, inorder, ++previ, inroot + 1, inend);
		}
		else
			root->right = nullptr;
		return root;
	}
	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
		int previ = 0;
		int inbegin = 0;
		int inend = inorder.size() - 1;
		return _buildTree(preorder, inorder, previ, inbegin, inend);
	}
};