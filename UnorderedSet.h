#include "HashTable.h"
namespace li
{
	template<class K, class Hash = BUCKET_HASH::_Hash<K>>
	class unordered_set
	{
		struct SetKeyOfT
		{
			const K& operator()(const K& k)
			{
				return k;
			}
		};
	public:
		typedef typename BUCKET_HASH::HashTable<K, K, SetKeyOfT, Hash>::iterator iterator;
		iterator begin()
		{
			return _ht.begin();
		}
		iterator end()
		{
			return _ht.end();
		}
		void insert(const K& k)
		{
			_ht.Insert(k);
		}
	private:
		BUCKET_HASH::HashTable<K, K, SetKeyOfT, Hash> _ht;
	};
	void test_unordered_set()
	{
		unordered_set<int> s;
		s.insert(1);
		s.insert(4);
		s.insert(5);
		s.insert(3);
		s.insert(2);
		unordered_set<int>::iterator it = s.begin();
		while (it != s.end())
		{
			cout << *it << " ";
			++it;
		}
		cout << endl;
		unordered_set<string> strs;
		strs.insert("sort");
	}
}
