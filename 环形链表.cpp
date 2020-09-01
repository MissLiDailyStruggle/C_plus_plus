//给定一个链表，判断链表中是否有环。
//来源：力扣（LeetCode）
//链接：https ://leetcode-cn.com/problems/linked-list-cycle
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
	bool hasCycle(ListNode *head) {
		ListNode *slow = head;
		ListNode *fast = head;
		while (fast && fast->next)
		{
			slow = slow->next;
			fast = fast->next->next;
			if (slow == fast)
				return true;
		}
		return false;
	}
};