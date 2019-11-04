namespace li
{
	template<class T>
	struct less
	{
		bool operator()(const T &a, const T &b)
		{
			return a < b;
		}
	};
	template<class T>
	struct greater
	{
		bool operator()(const T &a, const T &b)
		{
			return a > b;
		}
	};
	template<class T, class Con = vctor<T>, class Compare = less<T>>
	class priority_queue
	{
	public:
		priority_queue():_c(NULL)
		{}
		void AdjustUp(int child)
		{
			int parent = (child - 1) / 2;
			Compare com;
			while (child > 0)
			{
				if (com(_c[parent], _c[child]))
				{
					swap(_c[child], _c[parent]);
					child = parent;
					parent = (child - 1) / 2;
				}
				else
					break;

			}
		}
		void push(const T& x) 
		{ 
			_c.push_back(x);
			AdjustUp(_c.size() - 1);
		}
		void AdjustDown(int parent)
		{
			int child = 2 * parent + 1;
			Compare com;
			while (child < _c.size())
			{
				if (child + 1 < _c.size() && com(_c[child], _c[child+1]))
					++child;
				if (com(_c[parent], _c[child]))
				{
					swap(_c[child], _c[parent]);
					parent = child;
					child = 2 * parent + 1;
				}
				else
					break;
			}
		}
		void pop() 
		{
			swap(_c[0], _c[_c.size() - 1]);
			_c.pop_back();
			AdjustDown(0);
		}
		T& top() 
		{ 
			return _c[0];
		}
		size_t size() 
		{ 
			return _c.size(); 
		}
		bool empty()
		{ 
			return _c.empty(); 
		}
	private:
		Con _c;
	};
	void test_priority_queue()
	{
		priority_queue<int, vector<int>, greater<int>> pq;
		pq.push(10);
		pq.push(8);
		pq.push(13);
		pq.push(3);
		pq.push(5);
		pq.push(11);
		pq.push(9);
		pq.push(2);
		while (!pq.empty())
		{
			cout << pq.top() << " ";
			pq.pop();
		}
		cout << endl;
	}
}