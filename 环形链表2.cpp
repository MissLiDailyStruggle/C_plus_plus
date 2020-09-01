//给定一个链表，返回链表开始入环的第一个节点。 如果链表无环，则返回 null。为了表示给定链表中的环，我们使用整数 pos 来表示链表尾连接到链表中的位置（索引从 0 
//开始）。 如果 pos 是 - 1，则在该链表中没有环。
//来源：力扣（LeetCode）
//链接：https ://leetcode-cn.com/problems/linked-list-cycle-ii
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
	ListNode* hasCycle(ListNode *head) {
		ListNode* fast = head;
		ListNode* slow = head;
		while (fast && fast->next)
		{
			slow = slow->next;
			fast = fast->next->next;
			if (slow == fast)
				return slow;
		}
		return NULL;
	}
	ListNode *detectCycle(ListNode *head) {
		ListNode *meet = hasCycle(head);
		if (meet == NULL)
			return NULL;
		//第一个结点到入环口a；入环口到相遇点b，相遇点到入环口c；
		//s = a + b;2S = a + b + c + b;
		//a = c;
		//所以从第一个结点到入环口a和相遇点到入环口c一起走，相遇则为入环口；
		while (head != meet)
		{
			head = head->next;
			meet = meet->next;
		}
		return meet;
	}
};