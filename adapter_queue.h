#include <iostream>
#include <deque>

using namespace std;

namespace li
{
	template<class T, class Con = deque<T>>
	class queue
	{
	public:
		queue(){}
		void push(const T& x)
		{
			_c.push_back(x);
		}
		void pop()
		{
			_c.pop_front();
		}
		T& back()
		{
			return _c.back();
		}
		const T& back() const
		{
			return _c.back();
		}
		T& front()
		{
			return _c.front();
		}
		const T& front() const
		{
			return _c.front();
		}
		size_t size() const
		{
			return _c.size();
		}
		bool empty() const
		{
			return _c.empty();
		}

	private:
		Con _c;
	};
	void queue_test()
	{
		queue<int> q;
		q.push(1);
		q.push(2);
		q.push(3);
		q.push(4);
		q.push(5);
		cout << q.size() << endl;
		cout << q.back() << endl;
		cout << q.front() << endl;

		while (!q.empty())
		{
			cout << q.front() << " ";
			q.pop();
		}
	}
}