//根据一棵树的中序遍历与后序遍历构造二叉树。
//来源：力扣（LeetCode）
//链接：https ://leetcode-cn.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal
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
	unordered_map<int, int> um;
	TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
		if (inorder.empty())
			return NULL;
		for (int i = 0; i < inorder.size(); ++i)
		{
			um[inorder[i]] = i;
		}
		return _buildTree(inorder, postorder, 0, inorder.size() - 1, 0, postorder.size() - 1);
	}
	TreeNode* _buildTree(vector<int>& inorder, vector<int>& postorder, int il, int ir, int pl, int pr)
	{
		if (il > ir || pl > pr)
			return NULL;
		int rootval = postorder[pr];
		TreeNode* root = new TreeNode(rootval);
		int k = um[rootval];
		root->left = _buildTree(inorder, postorder, il, k - 1, pl, pl + k - il - 1);
		root->right = _buildTree(inorder, postorder, k + 1, ir, pl + k - il, pr - 1);
		return root;
	}
};