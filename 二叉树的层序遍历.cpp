//����һ�������������㷵���䰴������� �õ��Ľڵ�ֵ���������أ������ҷ������нڵ㣩��
//��Դ�����ۣ�LeetCode��
//���ӣ�https ://leetcode-cn.com/problems/binary-tree-level-order-traversal
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