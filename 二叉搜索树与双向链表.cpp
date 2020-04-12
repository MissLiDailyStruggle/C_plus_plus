//链接：https://www.nowcoder.com/practice/947f6eb80d944a84850b0538bf0ec3a5
//来源：牛客网//
输入一棵二叉搜索树，将该二叉搜索树转换成一个排序的双向链表。要求不能创建任何新的结点，只能调整树中结点指针的指向。
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