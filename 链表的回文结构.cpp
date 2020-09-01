//链接：https://www.nowcoder.com/practice/d281619e4b3e4a60a2cc66ea32855bfa?tpId=49&&tqId=29370&rp=1&ru=/activity/oj&qru=/ta/2016test/question-ranking
//来源：牛客网
//对于一个链表，请设计一个时间复杂度为O(n), 额外空间复杂度为O(1)的算法，判断其是否为回文结构。
/*
struct ListNode {
int val;
struct ListNode *next;
ListNode(int x) : val(x), next(NULL) {}
};*/
class PalindromeList {
public:
	bool chkPalindrome(ListNode* A) {
		// write code here
		if (A == nullptr)
			return nullptr;
		stack<int>st;
		ListNode* cur = A;
		while (cur)
		{
			st.push(cur->val);
			cur = cur->next;
		}
		cur = A;
		while (cur)
		{
			if (cur->val != st.top())
				return false;
			else
			{
				cur = cur->next;
				st.pop();
			}
		}
		return true;
	}
};