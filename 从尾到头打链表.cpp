//链接：https://www.nowcoder.com/practice/d0267f7f55b3412ba93bd35cfa8e8035
//来源：牛客网
//输入一个链表，按链表从尾到头的顺序返回一个ArrayList。
/**
*  struct ListNode {
*        int val;
*        struct ListNode *next;
*        ListNode(int x) :
*              val(x), next(NULL) {
*        }
*  };
*/
class Solution {
public:
	/*void print(ListNode* head,vector<int>& v)
	{
	if(head == NULL)
	return;
	stack<int>st;
	while(head)
	{
	st.push(head->val);
	head = head->next;
	}
	while(!st.empty())
	{
	v.push_back(st.top());
	st.pop();
	}
	}
	vector<int> printListFromTailToHead(ListNode* head) {
	vector<int> v;
	print(head,v);
	return v;
	}*/
	/* void print(ListNode* head,vector<int>& v)
	{
	if(head == NULL)
	return;
	print(head->next,v);
	v.push_back(head->val);
	}
	vector<int> printListFromTailToHead(ListNode* head) {
	vector<int> v;
	print(head,v);
	return v;
	}*/
	vector<int> printListFromTailToHead(ListNode* head) {
		vector<int> v;
		while (head)
		{
			v.push_back(head->val);
			head = head->next;
		}
		reverse(v.begin(), v.end());
		return v;
	}
};