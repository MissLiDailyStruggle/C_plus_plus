#pragma once;

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
};