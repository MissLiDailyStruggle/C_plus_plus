//����һ��������������ʼ�뻷�ĵ�һ���ڵ㡣 ��������޻����򷵻� null��Ϊ�˱�ʾ���������еĻ�������ʹ������ pos ����ʾ����β���ӵ������е�λ�ã������� 0 
//��ʼ���� ��� pos �� - 1�����ڸ�������û�л���
//��Դ�����ۣ�LeetCode��
//���ӣ�https ://leetcode-cn.com/problems/linked-list-cycle-ii
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
		//��һ����㵽�뻷��a���뻷�ڵ�������b�������㵽�뻷��c��
		//s = a + b;2S = a + b + c + b;
		//a = c;
		//���Դӵ�һ����㵽�뻷��a�������㵽�뻷��cһ���ߣ�������Ϊ�뻷�ڣ�
		while (head != meet)
		{
			head = head->next;
			meet = meet->next;
		}
		return meet;
	}
};