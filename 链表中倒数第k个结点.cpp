//链接：https://www.nowcoder.com/questionTerminal/529d3ae5a407492994ad2a246518148a
//来源：牛客网
//输入一个链表，输出该链表中倒数第k个结点。
/*
struct ListNode {
int val;
struct ListNode *next;
ListNode(int x) :
val(x), next(NULL) {
}
};*/
class Solution {
public:
	ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
		if (k == 0 || pListHead == NULL)
			return NULL;
		ListNode* pl1 = pListHead;
		ListNode* pl2 = pListHead;
		for (int i = 0; i < k - 1; i++)
		{
			if (pl1->next != NULL)
				pl1 = pl1->next;
			else
				return NULL;
		}
		while (pl1->next)
		{
			pl1 = pl1->next;
			pl2 = pl2->next;
		}
		return pl2;
	}
};