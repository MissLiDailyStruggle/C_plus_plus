//Á´½Ó£ºhttps://leetcode-cn.com/problems/binary-tree-inorder-traversal/
/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };
*
class Solution {
public:
    //µü´ú·¨
	vector<int> inorderTraversal(TreeNode* root) {
		stack<TreeNode*> st;
		vector<int> res;
		TreeNode* cur = root;
		while (cur != NULL || !st.empty())
		{
			if (cur != NULL)
			{
				st.push(cur);
				cur = cur->left;
			}
			else
			{
				cur = st.top();
				st.pop();
				res.push_back(cur->val);
				cur = cur->right;
			}
		}
		return res;
	}
};