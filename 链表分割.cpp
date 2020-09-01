//链接：https://www.nowcoder.com/practice/0e27e0b064de4eacac178676ef9c9d70?tpId=8&&tqId=11004&rp=2&ru=/activity/oj&qru=/ta/cracking-the-coding-interview/question-ranking
//来源：牛客网
//编写代码，以给定值x为基准将链表分割成两部分，所有小于x的结点排在大于或等于x的结点之前给定一个链表的头指针 ListNode* pHead，请返回重新排列后的链表的头指针。
//注意：分割以后保持原来的数据顺序不变。
/*
struct ListNode {
int val;
struct ListNode *next;
ListNode(int x) : val(x), next(NULL) {}
};*/
class Partition {
public:
	ListNode* partition(ListNode* pHead, int x) {
		// write code here
		if (pHead == nullptr)
			return nullptr;
		ListNode* small = new ListNode(0);
		ListNode* big = new ListNode(0);
		ListNode* sHead = small;
		ListNode* bHead = big;
		ListNode* cur = pHead;
		while (cur)
		{
			if (cur->val < x)
			{
				small->next = cur;
				small = cur;
			}
			else
			{
				big->next = cur;
				big = cur;
			}
			cur = cur->next;
		}
		big->next = nullptr;
		small->next = bHead->next;
		return sHead->next;
	}
};