//给定一个带有头结点 head 的非空单链表，返回链表的中间结点。如果有两个中间结点，则返回第二个中间结点。
//来源：力扣（LeetCode）
//链接：https ://leetcode-cn.com/problems/middle-of-the-linked-list
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
	ListNode* middleNode(ListNode* head) {
		if (head == nullptr)
			return nullptr;
		int count = 0;
		ListNode* cur = head;
		while (cur)
		{
			count++;
			cur = cur->next;
		}
		int mid = count / 2 + 1;
		cur = head;
		while (--mid)
		{
			cur = cur->next;
		}
		return cur;
	}
};