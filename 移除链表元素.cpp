//ɾ�������е��ڸ���ֵ val �����нڵ㡣
//��Դ�����ۣ�LeetCode��
//���ӣ�https://leetcode-cn.com/problems/remove-linked-list-elements/

/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
*/
class Solution {
public:
	ListNode* removeElements(ListNode* head, int val) {
		if (head == nullptr)
			return nullptr;
		ListNode* h = new ListNode(0);
		h->next = head;
		ListNode* prev = h;
		ListNode* cur = nullptr;
		while (prev->next)
		{
			if (prev->next->val == val)
			{
				cur = prev->next;
				prev->next = prev->next->next;
				delete cur;
			}
			else
				prev = prev->next;
		}
		return h->next;
	}
};