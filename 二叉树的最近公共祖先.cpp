//����һ��������, �ҵ�����������ָ���ڵ������������ȡ�
//�ٶȰٿ�������������ȵĶ���Ϊ���������и��� T ��������� p��q������������ȱ�ʾΪһ����� x������ x �� p��q �������� x ����Ⱦ����ܴ�һ���ڵ�Ҳ
//���������Լ������ȣ�����
//��Դ�����ۣ�LeetCode��
//���ӣ�https ://leetcode-cn.com/problems/lowest-common-ancestor-of-a-binary-tree
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
	bool find(TreeNode* root, TreeNode* p)
	{
		if (root == nullptr)
			return false;
		else if (root == p)
			return true;
		else
			return find(root->left, p) || find(root->right, p);
	}

	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		if (root == nullptr || root == p || root == q)
			return root;
		bool ispInLeft = find(root->left, p);
		bool ispInRight = !ispInLeft;

		bool isqInLeft = find(root->left, q);
		bool isqInRight = !isqInLeft;

		if ((ispInLeft && isqInRight) || (ispInRight && isqInLeft))
			return root;
		else if (ispInLeft && isqInLeft)
			return lowestCommonAncestor(root->left, p, q);
		else if (ispInRight && isqInRight)
			return lowestCommonAncestor(root->right, p, q);
		return nullptr;
	}
};