//��תһ��������
//��Դ�����ۣ�LeetCode��
//���ӣ�https ://leetcode-cn.com/problems/reverse-linked-list
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
	ListNode* reverseList(ListNode* head) {
		if (head == nullptr)
			return nullptr;
		ListNode* prev = nullptr;
		ListNode* cur = head;
		while (cur)
		{
			ListNode* next = cur->next;
			cur->next = prev;
			prev = cur;
			cur = next;
		}
		return prev;
	}
};
