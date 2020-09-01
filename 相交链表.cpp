//编写一个程序，找到两个单链表相交的起始节点。
//来源：力扣（LeetCode）
//链接：https://leetcode-cn.com/problems/intersection-of-two-linked-lists/
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
	ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
		int lengthA = 0;
		int lengthB = 0;
		ListNode* curA = headA;
		ListNode* curB = headB;
		while (curA)
		{
			++lengthA;
			curA = curA->next;
		}
		while (curB)
		{
			++lengthB;
			curB = curB->next;
		}
		int gap = abs(lengthA - lengthB);
		ListNode* longlist = headA;
		ListNode* shortlist = headB;
		if (lengthA < lengthB)
		{
			longlist = headB;
			shortlist = headA;
		}
		while (gap--)
		{
			longlist = longlist->next;
		}
		while (longlist && shortlist)
		{
			if (longlist == shortlist)
				return longlist;
			else
			{
				longlist = longlist->next;
				shortlist = shortlist->next;
			}
		}
		return nullptr;
	}
};