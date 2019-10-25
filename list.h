#include <iostream>
#include <assert.h>
using namespace std;

namespace li
{
	template<class T>
	struct _list_node
	{
		_list_node<T>* _next;
		_list_node<T>* _prev;
		T data;
		_list_node(const T x = T())
			:data(x),
		    _next(nullptr),
		    _prev(nullptr)
		{}
	};
	template<class T,class Ref, class Ptr>
	struct _list_iterator
	{
		typedef _list_node<T> node;
		typedef _list_iterator<T, Ref, Ptr> Self;
		node *_node;
		_list_iterator(node *node)
			:_node(node)
		{}
		Ref operator*()//内置类型
		{
			return _node->data;
		}
		Ptr operator->()//自定义类型
		{
			return &_node->data;
		}
		
		Self& operator++()
		{
			_node = _node->_next;
			return *this;
		}
		Self operator++(int)
		{
			_list_iterator<T> tmp(*this);
			_node = _node->_next;
			return tmp;
		}
		Self& operator--()
		{
			_node = _node->_prev;
			return *this;
		}
		Self operator--(int)
		{
			_list_iterator<T> tmp(*this);
			_node = _node->_prev;
			return tmp;
		}
		bool operator!=(const Self& it)
		{
			return _node != it._node;
		}
		bool operator==(const Self& it)
		{
			return _node == it._node;
		}
	};
	template<class T>
	class list
	{
		typedef _list_node<T> node;
	public:
		typedef  _list_iterator<T,T&,T*> iterator;
		typedef  _list_iterator<T,const T&,const T*> const_iterator;

		const_iterator begin()  const
		{
			return const_iterator(_head->_next);
		}
		const_iterator end()  const
		{
			return const_iterator(_head);
		}
		iterator begin()
		{
			return iterator(_head->_next);
		}
		iterator end()
		{
			return iterator(_head);
		}

		list()
		{
			_head = new node();
			_head->_next = _head;
			_head->_prev = _head;
		}
		~list()
		{
			clear();
			delete _head;
			_head = nullptr;
		}
		list(const list<T>& l)
		{
			_head = new node;
			_head->_next = _head;
			_head->_prev = _head;
			const_iterator it = l.begin();
			while (it != l.end())
			{
				push_back(*it);
				++it;
			}
		}
		list<T>& operator=(const list<T> l)
		{
			swap(_head, l._head);
			return *this;
		}
		void clear()
		{
			iterator it = begin();
			while (it != end())
			{
				it = erase(it);
			}
		}

		void insert(iterator pos,const T& x)
		{
			node *cur = pos._node;
			node *prev = cur->_prev;
			node *newnode = new node(x);
			
			prev->_next = newnode;
			newnode->_prev = prev;
			newnode->_next = cur;
			cur->_prev = newnode;
		}
		iterator erase(iterator pos)
		{
			node *cur = pos._node;
			assert(cur != _head); 
			node *prev = cur->_prev;
			node *next = cur->_next;

			prev->_next = next;
			next->_prev = prev;
			delete cur;

			return iterator(next);
		}
		void push_back(const T& x)
		{
			/*node *tail = _head->_prev;
			node *newnode = new node(x);
			tail->_next = newnode;
			newnode->_prev = tail;
			newnode->_next = _head;
			_head->_prev = newnode;*/
			insert(end(), x);
		}
		void push_front(const T& x)
		{
			
			insert(begin(), x);
		}
		void pop_back()
		{

			erase(--end());
		}
		void pop_front()
		{

			erase(begin());
		}
	private:
		node *_head;
	};
	void print_list(const list<int> & l)
	{
		list<int>::const_iterator it = l.begin();
		while (it != l.end())
		{
			cout << *it << " ";
			++it;
		}
		cout << endl;
	}
};