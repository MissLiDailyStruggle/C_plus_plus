//给你一个二叉树，请你返回其按 层序遍历 得到的节点值。 （即逐层地，从左到右访问所有节点）。
//来源：力扣（LeetCode）
//链接：https://leetcode-cn.com/problems/binary-tree-level-order-traversal/
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
		queue<TreeNode*> nodeq;
		queue<int> levelq;
		vector<vector<int>>vv;

		if (root)
		{
			nodeq.push(root);
			levelq.push(0);
		}
		while (!nodeq.empty())
		{
			TreeNode* frontq = nodeq.front();
			nodeq.pop();
			int level = levelq.front();
			levelq.pop();

			if (level >= vv.size())
			{
				vv.push_back(vector<int>());
			}
			vv[level].push_back(frontq->val);

			if (frontq->left)
			{
				nodeq.push(frontq->left);
				levelq.push(level + 1);
			}
			if (frontq->right)
			{
				nodeq.push(frontq->right);
				levelq.push(level + 1);
			}
		}
		return vv;
	}
};