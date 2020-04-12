//���ӣ�https://www.nowcoder.com/practice/947f6eb80d944a84850b0538bf0ec3a5
//��Դ��ţ����//
����һ�ö��������������ö���������ת����һ�������˫������Ҫ���ܴ����κ��µĽ�㣬ֻ�ܵ������н��ָ���ָ��
/*
struct TreeNode {
int val;
struct TreeNode *left;
struct TreeNode *right;
TreeNode(int x) :
val(x), left(NULL), right(NULL) {
}
};*/
class Solution {
public:
	void _Convert(TreeNode* pRootOfTree, TreeNode*& prev)
	{
		if (pRootOfTree == nullptr)
			return;
		_Convert(pRootOfTree->left, prev);
		if (prev)
		{
			prev->right = pRootOfTree;
			pRootOfTree->left = prev;
		}
		prev = pRootOfTree;
		_Convert(pRootOfTree->right, prev);
	}
	TreeNode* Convert(TreeNode* pRootOfTree)
	{
		if (pRootOfTree == nullptr)
			return nullptr;
		TreeNode* prev = nullptr;
		_Convert(pRootOfTree, prev);
		TreeNode* head = pRootOfTree;
		while (head->left)
		{
			head = head->left;
		}
		return head;
	}
};