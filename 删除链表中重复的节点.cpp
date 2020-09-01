//链接：https://www.nowcoder.com/practice/fc533c45b73a41b0b44ccba763f866ef?tpId=13&&tqId=11209&rp=1&ru=/activity/oj&qru=/ta/coding-interviews/question-ranking
//来源：牛客网
//在一个排序的链表中，存在重复的结点，请删除该链表中重复的结点，重复的结点不保留，返回链表头指针。 例如，链表1->2->3->3->4->4->5 处理后为 1->2->5
/*
struct ListNode {
int val;
struct ListNode *next;
ListNode(int x) :
val(x), next(NULL) {
}
};
*/
class Solution {
public:
	ListNode* deleteDuplication(ListNode* pHead)
	{
		if (pHead == nullptr)
			return nullptr;
		if (pHead->next == nullptr)
			return pHead;
		ListNode* prev = new ListNode(int());
		prev->next = pHead;
		ListNode* prevhead = prev;
		ListNode* cur = pHead;
		ListNode*next = pHead->next;
		while (next)
		{
			while (next && cur->val == next->val)
				next = next->next;
			if (cur->next == next)
			{
				prev = cur;
				next = next->next;
				cur = cur->next;
			}
			else
			{
				prev->next = next;
				cur = next;
				if (next)
					next = next->next;
				/*while(cur != next)
				{
				prev->next = cur->next;
				delete cur;
				cur = prev->next;
				}
				if(next)
				next = next->next;*/
			}
		}
		return prevhead->next;
	}
};