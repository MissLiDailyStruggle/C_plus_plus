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
//����һ�ö������������Լ�վ�������Ҳ࣬���մӶ������ײ���˳�򣬷��ش��Ҳ����ܿ����Ľڵ�ֵ��
//���ӣ�https://leetcode-cn.com/problems/binary-tree-right-side-view/
public:
	vector<int> rightSideView(TreeNode* root) {
		vector<int> res;
		if (root == NULL)
			return res;
		queue<TreeNode*> q;
		q.push(root);
		while (!q.empty())
		{
			int size = q.size();
			res.push_back(q.front()->val);
			while (size--)
			{
				TreeNode* temp = q.front();
				q.pop();
				if (temp->right)q.push(temp->right);
				if (temp->left)q.push(temp->left);
			}
		}
		return res;
	}
};