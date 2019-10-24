#include <iostream>
#include<assert.h>

using namespace std;

namespace li
{
	template<class T>
	class vector
	{
	public:
		typedef T* iterator;
		vector()
			:_start(nullptr),
			_finish(nullptr),
			_end_of_storage(nullptr)
		{}
		vector(vector<T>& v)
		{
			_start = new T[v.size()];
			memcpy(_start, v._start, v.size()*sizeof(T));
			_finish = _start + v.size();
			_end_of_storage = _start + v.capacity();
		}
		vector<T>& operator=(vector<T> v)
		{
			swap(v);
			return *this;
		}
		~vector()
		{
			if (_start)
			{
				delete[]_start;
				_start = _finish = _end_of_storage = nullptr;
			}
		}
		iterator begin()
		{
			return _start;
		}
		iterator end()
		{
			return _finish;
		}
		void resize(size_t n, const T& val = T())
		{
			if (n < size())
			{
				_finish = _start + n;
				return;
			}
			if (n > capacity())
				reserve(n);
			while (_finish != _start + n)
			{
				*_finish = val;
				++_finish;
			}
		}
		void reserve(size_t n)
		{
			if (n > capacity())
			{
				int sz = size();
				T* tmp = new T[n];
				if (_start)
				{
					memcpy(tmp, _start, sz*sizeof(T));
					delete[]_start;
				}
				_start = tmp;
				_finish = tmp + sz;
				_end_of_storage = tmp + n;
			}
		}
		void push_back(const T& x)
		{
			insert(end(), x);
		}
		void pop_back()
		{
			erase(--end());
		}
		void insert(iterator pos,const T& x)
		{
			assert(pos <= _finish && pos >= _start);
			if (_finish == _end_of_storage)
			{
				size_t sz = pos - _start;
				size_t newcapacity = capacity() == 0 ? 2 : capacity() * 2;
				reserve(newcapacity);
				pos = _start + sz;
			}
			iterator end = _finish - 1;
			while (end >= pos)
			{
				*(end + 1) = *end;
				--end;
			}
			*pos = x;
			++_finish;
		}
		void erase(iterator pos)
		{
			assert(pos < _finish && pos >= _start);
			iterator begin = pos + 1;
			while (_finish > begin)
			{
				*(begin - 1) = *begin;
				++begin;     
			}
			--_finish;
		}
		void swap(vector<T>& v)
		{
			swap(_start, v._start);
			swap(_finsh, v._finish);
			swap(_end_of_storage, v._end_of_storage);
		}
		size_t size()
		{
			return _finish - _start;

		}
		size_t capacity()
		{
			return _end_of_storage - _start;

		}
		T& operator[](size_t pos)
		{
			return _start[pos];
		}
	private:
		iterator _start;
		iterator _finish;
		iterator _end_of_storage;
	};
};