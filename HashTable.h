#pragma once

namespace CLOSE_HASH
{
	enum State
	{
		EMPTY,
		DELETE,
		EXITS,
	};
	template<class T>
	struct HashData
	{
		T _data;
		State _state;
	};
	template<class K,class V>
	class HashTable
	{
	public:
		//线性探测
		//typedef HashData<pair<K, V>> HashDate;
		/*pair<HashData<pair<K,V>>*, bool> Insert(const pair<K, V>& kv)
		{
			if (_dataNum == _tables.size())
			{
				size_t newSize = (_tables.size() == 0 ? 10 : _tables.size() * 2);
				HashTable<K, V> newHashTable;
				newHashTable._tables.resize(newSize);
				for (size_t i = 0; i < _tables.size(); i++)
				{
					if (_tables[i]._state == EXITS)
						newHashTable.Insert(_tables[i]._data);
				}
				_tables.swap(newHashTable._tables);
			}
			size_t index = kv.first % _tables.size();
			while (_tables[index]._state == EXITS)
			{
				if (kv.first == _tables[index]._data.first)
					return make_pair(&_tables[index], false);
				++index;
				if (index == _tables.size())
					index = 0;
			}
			_tables[index]._data = kv;
			_tables[index]._state = EXITS;
			++_dataNum;
			return make_pair(&_tables[index], true);
		}
		HashData<pair<K, V>>* find(const K& key)
		{
			size_t index = key % _tables.size();
			while (_tables[index].state != EMPTY)
			{
				if (_tables[index]._state == EXITS && _tables[index]._data.first == key)
					return _table[index];
				else
					++index;
				if (index == _tables.size())
					index = 0;
			}
			return nullptr;
		}
		void Erase(const K& key)
		{
			HashDate<pair<K,V>> ret = find(key);
			if (ret)
				ret->_state = DELETE;
		}
		V& operator[](const K& key)
		{
			pair<HashData<pair<K, V>>*, bool>ret = Insert(make_pair(key,V()));
			return ret.first->_data.second;
		}*/
		//二次探测
		pair<HashData<pair<K, V>>*, bool> Insert(const pair<K, V>& kv)
		{
			if (_dataNum == _tables.size())
			{
				size_t newSize = (_tables.size() == 0 ? 10 : _tables.size() * 2);
				HashTable<K, V> newHashTable;
				newHashTable._tables.resize(newSize);
				for (size_t i = 0; i < _tables.size(); i++)
				{
					if (_tables[i]._state == EXITS)
						newHashTable.Insert(_tables[i]._data);
				}
				_tables.swap(newHashTable._tables);
			}
			size_t index = kv.first % _tables.size();
			size_t ret = index;
			size_t i = 1;
			while (_tables[index]._state == EXITS)
			{
				if (kv.first == _tables[index]._data.first)
					return make_pair(&_tables[index], false);
				index = ret + i*i;
				i++;
				if (index >= _tables.size())
					index = index % _tables.size();
			}
			_tables[index]._data = kv;
			_tables[index]._state = EXITS;
			++_dataNum;
			return make_pair(&_tables[index], true);
		}
		HashData<pair<K, V>>* find(const K& key)
		{
			size_t index = key % _tables.size();
			size_t ret = index;
			int i = 1;
			while (_tables[index]._state != EMPTY)
			{
				if (_tables[index]._state == EXITS && _tables[index]._data.first == key)
					return &_tables[index];
				else
				{
					index = ret + i*i;
					i++;
				}
				if (index >= _tables.size())
					index = index % _tables.size();
			}
			return nullptr;
		}
		void Erase(const K& key)
		{
			HashData<pair<K, V>>* ret = find(key);
			if (ret)
				ret->_state = DELETE;
		}
		V& operator[](const K& key)
		{
			pair<HashData<pair<K, V>>*, bool>ret = Insert(make_pair(key, V()));
			return ret.first->_data.second;
		}

	private:
		vector<HashData<pair<K,V>>> _tables;
		size_t _dataNum = 0;
	};
	void Test()
	{
		HashTable<int, int> ht;
		ht.Insert(make_pair(1, 1));
		ht.Insert(make_pair(3, 1));
		ht.Insert(make_pair(5, 1));
		ht.Insert(make_pair(7, 1));
		ht.Insert(make_pair(9, 1));
		ht.Insert(make_pair(21, 1));
		ht.Insert(make_pair(11, 1));
		/*ht.Insert(make_pair(13, 1));
		ht.Insert(make_pair(15, 1));
		ht.Insert(make_pair(17, 1));
		ht.Insert(make_pair(19, 1));
		ht.Insert(make_pair(23, 1));
		ht.Insert(make_pair(25, 1));*/
		ht[29] = 29;
		ht.Erase(11);
	}
}
namespace BUCKET_HASH
{
	template<class T>
	struct HashNode
	{
		HashNode<T>* _next;
		T _data;

		HashNode(const T& data)
			:_data(data)
			, _next(nullptr)
		{}
	};

	template<class K>
	struct _Hash
	{
		const K& operator()(const K& key)
		{
			return key;
		}
	};
	template<>
	struct _Hash<string>
	{
		size_t operator()(const string& key)
		{
			size_t hash = 0;
			for (size_t i = 0; i < key.size(); ++i)
			{
				hash = hash * 131 + key[i];
			}
			return hash;
		}
	};
	struct _HashString
	{
		size_t operator()(const string& key)
		{
			size_t hash = 0;
			for (size_t i = 0; i < key.size(); ++i)
			{
				hash = hash * 131 + key[i];
			}
			return hash;
		}
	};
	template<class K, class T, class KeyOfT, class Hash>
	class HashTable;
	template<class K, class T, class KeyOfT, class Hash>
	struct HashTableIterator
	{
		typedef  HashNode<T> Node;
		Node* _node;
		HashTable <K, T, KeyOfT, Hash>* _ht;
		typedef HashTableIterator<K, T, KeyOfT, Hash> Self;
		HashTableIterator(Node* node, HashTable <K, T, KeyOfT, Hash>* ht)
			:_node(node)
			, _ht(ht)
		{}
		T& operator*()
		{
			return _node->_data;
		}
		T* operator->()
		{
			return &_node->_data;
		}
		Self operator++()
		{
			if (_node->_next)
			{
				_node = _node->_next;
			}
			else
			{
				KeyOfT kot;
				size_t index = _ht->HashFunc(kot(_node->_data), _ht->_tables.size());
				++index;
				for (; index < _ht->_tables.size(); index++)
				{
					Node* bucket = _ht->_tables[index];
					if (bucket)
					{
						_node = bucket;
						return *this;
					}
				}
				_node = nullptr;
			}
			return *this;
		}
		bool operator!=(const Self& s)
		{
			return _node != s._node;
		}
	};
	template<class K, class T, class KeyOfT, class Hash>
	class HashTable
	{
		typedef HashNode<T> Node;

		//友元
		template <class K, class T, class KeyOfT, class Hash>
		friend struct HashTableIterator;
	public:
		typedef HashTableIterator<K, T, KeyOfT, Hash > iterator;
		iterator begin()
		{
			for (int i = 0; i < _tables.size(); ++i)
			{
				Node* bucket = _tables[i];
				if (bucket)
					return iterator(bucket, this);
			}
			return end();
		}
		iterator end()
		{
			return iterator(nullptr, this);
		}
		pair<iterator, bool> Insert(const T& data)
		{
			KeyOfT kot;
			if (_dataNum == _tables.size())
			{
				size_t newsize = _tables.size() == 0 ? 10 : _tables.size() * 2;
				vector<Node*>newtables;
				newtables.resize(newsize,nullptr);
				for (int i = 0; i < _tables.size(); i++)
				{
					Node* cur = _tables[i];
					while (cur)
					{
						Node* next = cur->_next;
						size_t index = HashFunc(kot(cur->_data), newtables.size());
						cur->_next = newtables[index];
						newtables[index] = cur;
						cur = next;
					}
					_tables[i] = nullptr;
				}
				_tables.swap(newtables);
			}
			size_t index = HashFunc(kot(data), _tables.size());
			Node* cur = _tables[index];
			while (cur)
			{
				if (kot(cur->_data) == kot(data))
					return make_pair(iterator(cur,this), false);
				cur = cur->_next;
			}
			Node* newnode = new Node(data);
			newnode->_next = _tables[index];
			_tables[index] = newnode;
			++_dataNum;
			return make_pair(iterator(newnode,this), true);
		}
		Node* Find(const K& key)
		{
			size_t index = HashFunc(key, _tables.size());
			Node* cur = _tables[index];
			while (cur)
			{
				if (kot(cur->_data) == key)
					return cur;
				else
					cur = cur->_next;
			}
			return nullptr;
		}
		bool Erase(const K& key)
		{
			size_t index = HashFunc(key, _tables.size());
			Node* cur = _tables[index];
			Node* prev = nullptr;
			while (cur)
			{
				if (kot(cur->_data) == key)
				{
					Node* next = cur->_next;
					if (cur == _tables[index])
					{
						cur = next;
					}
					prev->_next = next;
					delete cur;
					--_dataNum;
					return true;
				}
				else
				{
					prev = cur;
					cur = cur->_next;
				}
			}
			return false;
		}
		size_t HashFunc(const K& key, size_t size)
		{
			Hash hash;
			return hash(key) % size;
		}
	private:
		vector<Node*> _tables;
		size_t _dataNum = 0;
	};
	/*void test()
	{
	HashTable<int, int> ht;
	ht.Insert(make_pair(1, 1));
	ht.Insert(make_pair(3, 1));
	ht.Insert(make_pair(5, 1));
	ht.Insert(make_pair(7, 1));
	ht.Insert(make_pair(9, 1));
	ht.Insert(make_pair(11, 1));
	ht.Insert(make_pair(13, 1));
	ht.Insert(make_pair(15, 1));
	ht.Insert(make_pair(17, 1));
	ht.Insert(make_pair(19, 1));
	ht.Insert(make_pair(21, 1));
	ht.Insert(make_pair(23, 1));
	ht.Insert(make_pair(25, 1));
	}*/
}
