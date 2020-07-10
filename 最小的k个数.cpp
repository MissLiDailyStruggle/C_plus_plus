//链接：https://www.nowcoder.com/practice/6a296eb82cf844ca8539b57c23e6e9bf?tpId=13&&tqId=11182&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
//来源：牛客网
//输入n个整数，找出其中最小的K个数。例如输入4,5,1,6,2,7,3,8这8个数字，则最小的4个数字是1,2,3,4,。 
class Solution {
public:
	vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
		vector<int> res;
		if (input.empty() || k <= 0 || input.size() < k)
			return res;
		priority_queue<int> big_heap;
		for (int i = 0; i < k; ++i)
			big_heap.push(input[i]);
		for (int i = k; i < input.size(); ++i)
		{
			if (input[i] < big_heap.top())
			{
				big_heap.pop();
				big_heap.push(input[i]);
			}
		}
		while (!big_heap.empty() && k--)
		{
			res.push_back(big_heap.top());
			big_heap.pop();
		}
		return res;
	}
};