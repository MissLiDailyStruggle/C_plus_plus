class MinStack {
public:
	/** initialize your data structure here. */
	void push(int x) {
		_st.push(x);
		if (_minst.empty() || _minst.top() >= x)
			_minst.push(x);
	}

	void pop() {
		if (_st.top() == _minst.top())
			_minst.pop();
		_st.pop();
	}

	int top() {
		return _st.top();
	}

	int getMin() {
		return _minst.top();
	}
private:
	std::stack<int>  _st;
	std::stack<int> _minst;
};

/**
* Your MinStack object will be instantiated and called as such:
* MinStack* obj = new MinStack();
* obj->push(x);
* obj->pop();
* int param_3 = obj->top();
* int param_4 = obj->getMin();
*/