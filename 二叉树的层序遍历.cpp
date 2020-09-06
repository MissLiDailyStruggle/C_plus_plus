//给你一个二叉树，请你返回其按层序遍历 得到的节点值。（即逐层地，从左到右访问所有节点）。
//来源：力扣（LeetCode）
//链接：https ://leetcode-cn.com/problems/binary-tree-level-order-traversal
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
	vector<vector<int>> levelOrder(TreeNode* root) {
		vector<vector<int>> arr;
		queue<TreeNode*> nodeq;
		queue<int> levelq;
		if (root)
		{
			nodeq.push(root);
			levelq.push(0);
		}
		while (!nodeq.empty())
		{
			TreeNode* front = nodeq.front();
			int level = levelq.front();
			nodeq.pop();
			levelq.pop();
			if (level >= arr.size())
			{
				arr.push_back(vector<int>());
			}
			arr[level].push_back(front->val);
			if (front->left)
			{
				nodeq.push(front->left);
				levelq.push(level + 1);
			}
			if (front->right)
			{
				nodeq.push(front->right);
				levelq.push(level + 1);
			}
		}
		return arr;
	}
};