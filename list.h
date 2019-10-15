namespace li
{
	template<class T>
	struct _list_node
	{
		_list_node<T>* _next;
		_list_node<T>* _prev;
		T data;
		_list_node(const T x)
			:data(x),
		    _next(nullptr),
		    _prev(nullptr)
		{}
	};
	template<class T>
	struct _list_iterator
	{
		typedef _list_node<T> node;
		node *_node;
		_list_iterator(node *node)
			:_node(node)
		{}
		T& operator*()
		{
			return _node->data;
		}
		_list_iterator<T>& operator++()
		{
			_node = _node->_next;
			return *this;
		}
		_list_iterator<T> operator++(int)
		{
			_list_iterator<T> tmp(*this);
			_node = _node->_next;
			return tmp;
		}
		bool operator!=(_list_iterator<T>& it)
		{
			return _node != it._node;
		}
	};
	template<class T>
	class list
	{
	public:
		typedef _list_node<T> node;
		typedef  _list_iterator<T> iterator;
		list()
		{
			_head = new node(T());
			_head->_next = _head;
			_head->_prev = _head;
		}
		iterator begin()
		{
			return iterator(_head->_next);
		}
		iterator end()
		{
			return iterator(_head);
		}
		void push_back(const T& x)
		{
			node *tail = _head->_prev;
			node *newnode = new node(x);
			tail->_next = newnode;
			newnode->_prev = tail;
			newnode->_next = _head;
			_head->_prev = newnode;
		}
	private:
		node *_head;
	};
};