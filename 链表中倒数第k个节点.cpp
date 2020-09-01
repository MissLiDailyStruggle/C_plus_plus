//���ӣ�https://www.nowcoder.com/practice/529d3ae5a407492994ad2a246518148a?tpId=13&&tqId=11167&rp=2&ru=/activity/oj&qru=/ta/coding-interviews/question-ranking
//��Դ��ţ����
//����һ����������������е�����k����㡣
/*
struct ListNode {
int val;
struct ListNode *next;
ListNode(int x) :
val(x), next(NULL) {
}
};*/
//����ָ�뷨
class Solution {
public:
	ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
		if (pListHead == nullptr || k == 0)
			return nullptr;
		ListNode* fast = pListHead;
		ListNode* slow = pListHead;
		while (--k)
		{
			if (fast->next != nullptr)
				fast = fast->next;
			else
				return nullptr;
		}
		while (fast->next)
		{
			fast = fast->next;
			slow = slow->next;
		}
		return slow;
	}
};
//˳�������
class Solution {
public:
	ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
		if (pListHead == nullptr)
			return nullptr;
		int count = 0;
		ListNode* cur = pListHead;
		while (cur)
		{
			count++;
			cur = cur->next;
		}
		if (count < k)
			return nullptr;
		int num = count - k + 1;
		cur = pListHead;
		while (--num)
		{
			cur = cur->next;
		}
		return cur;
	}
};