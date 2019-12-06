//template<class K>
//struct BSTreeNode
//{
//	BSTreeNode *_left;
//	BSTreeNode *_right;
//	K _key;
//	BSTreeNode(const K& key) :_key(key), _left(nullptr), _right(nullptr)
//	{}
//};
//template<class K>
//class BSTree
//{
//	typedef BSTreeNode<K> Node;
//public:
//	BSTree() :_root(nullptr)
//	{}
//	bool Insert(const K& key)
//	{
//		if (_root == nullptr)
//		{
//			_root = new Node(key);
//			return true;
//		}
//		Node *parent = nullptr;
//		Node *cur = _root;
//		while (cur)
//		{
//			if (cur->_key < key)
//			{
//				parent = cur;
//				cur = cur->_right;
//			}
//			else  if (cur->_key > key)
//			{
//				parent = cur;
//				cur = cur->_left;
//			}
//			else
//				return false;
//		}
//		cur = new Node(key);
//		if (parent->_key < key)
//			parent->_right = cur;
//		else
//			parent->_left = cur;
//	}
//	Node* Find(const K& key)
//	{
//		Node* cur = _root;
//		while (cur)
//		{
//			if (cur->_key < key)
//				cur = cur->_right;
//			else if (cur->_key > key)
//				cur = cur->_left;
//			else
//				return cur;
//		}
//		return nullptr;
//	}
//	bool Erase(const K& key)
//	{
//		Node* parent = nullptr;
//		Node* cur = _root;
//		while (cur)
//		{
//			if (cur->_key < key)
//			{
//				parent = cur;
//				cur = cur->_right;
//			}
//			else if (cur->_key > key)
//			{
//				parent = cur;
//				cur = cur->_left;
//			}
//			else
//			{
//				Node*del = cur;
//				if (cur->_left == nullptr)
//				{
//					if (parent == nullptr)
//						_root = cur->_right;
//					else
//					{
//						if (parent->_left == cur)
//							parent->_left = cur->_right;
//						else
//							parent->_right = cur->_right;
//					}
//				}
//				else if (cur->_right == nullptr)
//				{
//					if (parent == nullptr)
//						_root = cur->_left;
//					else
//					{
//						if (parent->_left == cur)
//							parent->_left = cur->_left;
//						else
//							parent->_right = cur->_left;
//					}
//				}
//				else
//				{
//					Node* lessParent = cur;
//					Node* lessRight = cur->_right;
//					while (lessRight->_left)
//					{
//						lessParent = lessRight;
//						lessRight = lessRight->_left;
//					}
//					cur->_key = lessRight->_key;
//					del = lessRight;
//					if (lessParent->_left == lessRight)
//						lessParent->_left = lessRight->_right;
//					else
//						lessParent->_right = lessRight->_right;
//				}
//				delete del;
//				return true;
//			}
//		}
//	}
//	void Inorder()
//	{
//		_Inorder(_root);
//		cout << endl;
//	}
//	void _Inorder(Node* root)
//	{
//		if (root == nullptr)
//			return;
//		_Inorder(root->_left);
//		cout << root->_key << " ";
//		_Inorder(root->_right);
//	}
//private:
//	Node *_root;
//};
//void TestBSTree()
//{
//	int a[] = { 5, 3, 4, 1, 7, 8, 2, 6, 0, 9 };
//	BSTree<int> tree;
//	for (auto e : a)
//	{
//		tree.Insert(e);
//	}
//	tree.Inorder();
//	tree.Erase(2);
//	tree.Erase(8);
//	tree.Erase(1);
//	tree.Erase(7);
//	tree.Erase(5);
//	tree.Inorder();
//	for (auto e : a)
//	{
//		tree.Erase(e);
//	}
//	tree.Inorder();
//}
template<class K,class V>
struct BSTreeNode
{
	BSTreeNode<K, V>* _left;
	BSTreeNode<K, V>* _right;
	K _key;
	V _value;

	BSTreeNode(const K& key, const V& value)
		:_key(key),
		_value(value),
		_left(nullptr),
		_right(nullptr)
	{}
};
template<class K,class V>
class BSTree
{
	typedef BSTreeNode<K, V> Node;
public:
	BSTree() :_root(nullptr)
	{}
	bool _InsertR(Node*& root, const K& key, const V& value)
	{
		if (root == nullptr)
			root = new Node(key, value);
		else if (root->_key < key)
			return _InsertR(root->_right, key, value);
		else if (root->_key > key)
			return _InsertR(root->_left, key, value);
		else
			return false;
	}
	bool InsertR(const K& key, const V& value)
	{
		return _InsertR(_root, key, value);
	}
	Node* _FindR(Node* root, const K& key)
	{
		if (root == nullptr)
			return nullptr;
		else if (root->_key == key)
			return root;
		else if (root->_key < key)
			return _FindR(root->_right, key);
		else

			return _FindR(root->_left, key);
	}
	Node* FindR(const K& key)
	{
		return _FindR(_root, key);
	}
	void _InOrder(Node* root)
	{
		if (root == nullptr)
			return;
		_InOrder(root->_left);
		cout << root->_key << ":" << root->_value << endl;
		_InOrder(root->_right);
	}
	void InOrder()
	{
		_InOrder(_root);
		cout << endl;
	}
private:
	Node* _root;
};

void TestBSTreeKV1()
{
	BSTree<string, string> dict;
	dict.InsertR("insert", "²åÈë");	
	dict.InsertR("erase", "É¾³ý");
	dict.InsertR("left", "×ó±ß");
	dict.InsertR("right", "ÓÒ±ß");
	string str;
	while (cin >> str)
	{
		BSTreeNode<string, string>* ret = dict.FindR(str);
		if (ret)
			cout << str << ":" << ret->_value << endl;
		else
			cout << str << ":" << "illegal value" << endl;
	}
}
void TestBSTreeKV2()
{
	string strs[] = { "Æ»¹û", "²ÝÝ®", "Î÷¹Ï", "ÆÏÌÑ ", "Æ»¹û", "²ÝÝ®", "²ÝÝ®" };
	BSTree<string, int>countTree;
	for (auto& e : strs)
	{
		auto ret = countTree.FindR(e);
		if (ret)
			ret->_value++;
		else
			countTree.InsertR(e, 1);
	}
	countTree.InOrder();
}