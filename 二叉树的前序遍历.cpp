//����һ������������������ǰ�������
//��Դ�����ۣ�LeetCode��
//���ӣ�https ://leetcode-cn.com/problems/binary-tree-preorder-traversal
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
	void _preorderTraversal(TreeNode* root, vector<int>& arr)
	{
		if (root == NULL)
			return;
		arr.push_back(root->val);
		_preorderTraversal(root->left, arr);
		_preorderTraversal(root->right, arr);
	}
	vector<int> preorderTraversal(TreeNode* root) {
		vector<int> arr;
		_preorderTraversal(root, arr);
		return arr;
	}
};