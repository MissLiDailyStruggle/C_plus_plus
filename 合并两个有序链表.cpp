//��������������ϲ�Ϊһ���µ� ���� �������ء���������ͨ��ƴ�Ӹ�����������������нڵ���ɵġ�
//��Դ�����ۣ�LeetCode��
//���ӣ�https ://leetcode-cn.com/problems/merge-two-sorted-lists
/**/
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode() : val(0), next(nullptr) {}
*     ListNode(int x) : val(x), next(nullptr) {}
*     ListNode(int x, ListNode *next) : val(x), next(next) {}
* };
*/
class Solution {
public:
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		if (l1 == nullptr && l2 == nullptr)
			return nullptr;
		if (l1 == nullptr)
			return l2;
		if (l2 == nullptr)
			return l1;
		ListNode* head;
		if (l1->val > l2->val)
		{
			head = l2;
			l2 = l2->next;
		}
		else
		{
			head = l1;
			l1 = l1->next;
		}
		ListNode* cur = head;
		while (l1 && l2)
		{
			if (l1->val > l2->val)
			{
				cur->next = l2;
				cur = cur->next;
				l2 = l2->next;
			}
			else
			{
				cur->next = l1;
				cur = cur->next;
				l1 = l1->next;
			}
		}
		while (l1)
		{
			cur->next = l1;
			cur = cur->next;
			l1 = l1->next;
		}
		while (l2)
		{
			cur->next = l2;
			cur = cur->next;
			l2 = l2->next;
		}
		return head;
	}
};