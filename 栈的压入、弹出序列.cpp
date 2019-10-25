class Solution {
public:
	bool IsPopOrder(vector<int> pushV, vector<int> popV) {
		stack<int> _st;
		int i = 0;
		int j = 0;
		for (i = 0; i < pushV.size(); i++)
		{
			_st.push(pushV[i]);
			while (!_st.empty() && _st.top() == popV[j])
			{
				_st.pop();
				j++;
			}
		}
		if (_st.empty())
			return true;
		return false;
	}
};