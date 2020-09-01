//����һ������ͷ��� head �ķǿյ���������������м��㡣����������м��㣬�򷵻صڶ����м��㡣
//��Դ�����ۣ�LeetCode��
//���ӣ�https ://leetcode-cn.com/problems/middle-of-the-linked-list
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