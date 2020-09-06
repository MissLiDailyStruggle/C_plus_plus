//Á´½Ó£ºhttps://leetcode-cn.com/problems/binary-tree-postorder-traversal/
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
	vector<int> postorderTraversal(TreeNode* root) {
		stack<TreeNode*> st;
		vector<int> res;
		if (root != nullptr)
			st.push(root);
		while (!st.empty())
		{
			TreeNode* node = st.top();
			if (node != nullptr)
			{
				st.pop();
				st.push(node);
				st.push(nullptr);
				if (node->right != nullptr)
					st.push(node->right);
				if (node->left != nullptr)
					st.push(node->left);
			}
			else
			{
				st.pop();
				node = st.top();
				st.pop();
				if (node != nullptr)
					res.push_back(node->val);
			}
		}
		return res;
	}
};