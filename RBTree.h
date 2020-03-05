#pragma once
enum Colour
{
	BLACK,
	RED,
};
template<class T>
struct RBTreeNode
{
	RBTreeNode* _left;
	RBTreeNode* _right;
	RBTreeNode* _parent;

	T _data;
	Colour _col;

	RBTreeNode(const T& data)
		:_left(nullptr)
		, _right(nullptr)
		, _parent(nullptr)
		, _data(data)
		, _col(RED)
	{}
};

template<class T>
struct __RBTreeIterator
{
	typedef RBTreeNode<T> Node;
	typedef __RBTreeIterator<T> Self;
	Node* _node;
	
	__RBTreeIterator(Node* node)
		:_node(node)
	{

	}
	T& operator*()
	{
		return _node->_data;
	}
	T* operator->()
	{
		return &_node->_data;
	}
	Self& operator++()
	{
		if (_node->_right)
		{
			Node* left = _node->_right;
			while (left->_left)
				left = left->_left;
			_node = left;
		}
		else
		{
			Node* cur = _node;
			Node* parent = cur->_parent;
			while (parent != nullptr && cur == parent->_right)
			{
				cur = parent;
				parent = parent->_parent;
			}
			_node = parent;
		}
		return *this;

	}
	bool operator!=(const Self& s)
	{
		return _node != s._node;
	}

};

template<class K,class T,class TOfValue>
class RBTree
{
	typedef RBTreeNode<T> Node;
public:
	typedef __RBTreeIterator<T> iterator;
	iterator begin()
	{
		Node* left = _root;
		while (left && left->_left)
		{
			left = left->_left;
		}
		return iterator(left);
	}
	iterator end()
	{
		return nullptr;
	}
	RBTree()
		:_root(nullptr)
	{}
	pair<iterator, bool> Insert(const T&data)
	{
		if (_root == nullptr)
		{
			_root = new Node(data);
			_root->_col = BLACK;
			return make_pair(iterator(_root), true);
		}
		TOfValue tov;
		Node* parent = nullptr;
		Node* cur = _root;
		while (cur)
		{
			if (tov(cur->_data) < tov(data))
			{
				parent = cur;
				cur = cur->_right;
			}
			else if (tov(cur->_data) > tov(data))
			{
				parent = cur;
				cur = cur->_left;
			}
			else
				return make_pair(iterator(cur), false);
		}
		Node* newnode = new Node(data);
		cur = newnode;
		cur->_col = RED;
		if (tov(parent->_data) > tov(data))
		{
			parent->_left = cur;
			cur->_parent = parent;
		}
		else
		{
			parent->_right = cur;
			cur->_parent = parent;
		}
		while (parent && parent->_col == RED)
		{
			Node* grandfather = parent->_parent;
			if (parent == grandfather->_left)
			{
				Node* uncle = grandfather->_right;
				if (uncle && uncle->_col == RED)
				{
					parent->_col = uncle->_col = BLACK;
					grandfather->_col = RED;

					cur = grandfather;
					parent = cur->_parent;
				}
				else
				{
					if (cur == parent->_left)
					{
						//µ¥Ðý
						RotateR(grandfather);
						parent->_col = BLACK;
						grandfather->_col = RED;
					}
					else
					{
						//Ë«Ðý
						RotateLR(grandfather);
						cur->_col = BLACK;
						grandfather->_col = RED;
					}
					break;
				}
			}
			else
			{
				Node* uncle = grandfather->_left;
				if (uncle && uncle->_col == RED)
				{
					parent->_col = uncle->_col = BLACK;
					grandfather->_col = RED;

					cur = grandfather;
					parent = cur->_parent;
				}
				else
				{
					if (cur == parent->_right)
					{
						//µ¥Ðý
						RotateL(grandfather);
						parent->_col = BLACK;
						grandfather->_col = RED;
					}
					else
					{
						//Ë«Ðý
						RotateRL(grandfather);
						cur->_col = BLACK;
						grandfather->_col = RED;
					}
					break;
				}
			}
		}
		_root->_col = BLACK;
		return make_pair(iterator(newnode), true);
	}
	void RotateL(Node* parent)
	{
		Node* subR = parent->_right;
		Node* subRL = subR->_left;
		parent->_right = subRL;
		if (subRL)
			subRL->_parent = parent;
		subR->_left = parent;
		Node* parent_parent = parent->_parent;
		parent->_parent = subR;
		if (_root == parent)
		{
			_root = subR;
			subR->_parent = nullptr;
		}
		else
		{
			if (parent_parent->_left == parent)
				parent_parent->_left = subR;
			else
				parent_parent->_right = subR;
			subR->_parent = parent_parent;
		}
	}
	void RotateR(Node* parent)
	{
		Node* subL = parent->_left;
		Node* subLR = subL->_right;

		parent->_left = subLR;
		if (subLR)
			subLR->_parent = parent;

		subL->_right = parent;
		Node* parent_parent = parent->_parent;
		parent->_parent = subL;

		if (parent == _root)
		{
			_root = subL;
			subL->_parent = nullptr;
		}
		else
		{
			if (parent_parent->_left == parent)
			{
				parent_parent->_left = subL;
			}
			else
			{
				parent_parent->_right = subL;
			}

			subL->_parent = parent_parent;
		}
	}

	void RotateLR(Node* parent)
	{
		RotateL(parent->_left);
		RotateR(parent);
	}

	void RotateRL(Node* parent)
	{
		RotateR(parent->_right);
		RotateL(parent);
	}
	void _InOrder(Node* root)
	{
		if (root == nullptr)
			return;
		_InOrder(root->_left);
		cout << root->_data.first << ":" << root->_data.second << endl;
		_InOrder(root->_right);
	}
	void InOrder()
	{
		_InOrder(_root);
	}
private:
	Node* _root;
};

//void testRBTree()
//{
//	int a[] = { 4, 2, 6, 1, 3, 5, 15, 7, 16, 14 };
//	RBTree<int, int> t;
//	for (auto e : a)
//		t.Insert(make_pair(e, e));
//	t.InOrder();
//}