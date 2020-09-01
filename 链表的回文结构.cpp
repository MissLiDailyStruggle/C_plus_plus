//���ӣ�https://www.nowcoder.com/practice/d281619e4b3e4a60a2cc66ea32855bfa?tpId=49&&tqId=29370&rp=1&ru=/activity/oj&qru=/ta/2016test/question-ranking
//��Դ��ţ����
//����һ�����������һ��ʱ�临�Ӷ�ΪO(n), ����ռ临�Ӷ�ΪO(1)���㷨���ж����Ƿ�Ϊ���Ľṹ��
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