#define _CRT_SECURE_NO_WARNINGS

#include <assert.h>
#include <string.h>
#include <iostream>

using namespace std;

namespace li
{
	class string
	{
	public:

		typedef const char* const_iterator;
		typedef char* iterator;

		string(const char* str = " ")
			:_str(new char [strlen(str) + 1]),
			_size(strlen(str)),
			_capacity(strlen(str))
		{
			strcpy(_str,str);
		}
		string(const string& s)
			:_str(nullptr)
		{
			string tmp(s._str);
			swap(tmp._str,_str);
			_size = s._size;
			_capacity = s._capacity;
		}
		string& operator=(string s)
		{
			if (this != &s)
				swap(_str, s._str);
			_size = s._size;
			_capacity = s._capacity;
			return *this;
		}
		~string()
		{
			delete[]_str;
			_str = nullptr;
			_size = _capacity = NULL;
		}
		iterator begin()
		{
			return _str;
		}
		iterator end()
		{
			return _str + _size;
		}
		const_iterator begin()  const
		{
			return _str;
		}
		const_iterator end()    const
		{
			return _str + _size;
		}
		char& operator[](size_t pos)
		{
			assert(pos <= _size);
			return _str[pos];
		}
		char* c_str()
		{
			return _str;
		}
		size_t size()
		{
			return _size;
		}
		size_t capacity()
		{
			return _capacity;
		}
		void reserve(size_t n)
		{
			if (n > _capacity)
			{
				char* tmp = new char[n + 1];
				strcpy(tmp, _str);
				delete[]_str;
				_str = tmp;
				_capacity = n;
			}
		}
		void insert(size_t pos,const char& ch)
		{
			assert(pos <= _size);
			if (_size == _capacity)
				reserve(_capacity * 2);
			size_t end = _size;
			while (end >= pos)
			{
				_str[end + 1] = _str[end];
				end--;
			}
			_str[pos] = ch;
			_size++;
			_str[_size] = '\0';
		}
		void insert(size_t pos, const char* str)
		{
			assert(pos <= _size);
			size_t len = strlen(str);
			if (_size + len > _capacity)
				reserve(_capacity + len);
			size_t end = _size + len;
			while (end >= pos+len)
			{
				_str[end] = _str[end - len];
				end--;
			}
			while (*str)
			{
				_str[pos] = *str;
				pos++;
				str++;
			}
			_size += len;
			_str[_size] = '\0';
		}
		void push_back(const char& ch)
		{
			insert(_size, ch);
		}
		void append(const char* str)
		{
			insert(_size, str);
		}
		string& operator+=(const char& ch)
		{
			insert(_size, ch);
			return *this;
		}
		string& operator+=(const char* str)
		{
			insert(_size, str);
			return *this;
		}
		int find(char ch)
		{
			for (int i = 0; i < _size; i++)
			{
				if (_str[i] == ch)
					return i;
			}
			return -1;
		}
		int find(const char *str)
		{
			for (int i = 0; i < _size; i++)
			{
				if (_str[i] == *str)
				{
					int temp = i;
					while (*str && i < _size)
					{
						if (*str != _str[i])
							return -1;
						else
						{
							str++;
							i++;
						}
					}
					if (!*str)
						return temp;
				}
			}
			return -1;
		}
		bool operator==(const string &s)const
		{
			const char *str1 = _str;
			const char *str2 = s._str;
			while (*str1 && *str2)
			{
				if (*str1 != *str2)
					return false;
				else
				{
					++str1;
					++str2;
				}
			}
			if (*str1 || *str2)
				return false;
			else 
				return true;
		}
		string operator+(string &s)
		{
		    string tmp = *this;
			const char *str = s._str;
			tmp += str; 
			return tmp;
		}
		friend istream& operator>> (istream& in, string &s);
		friend ostream &operator<<(ostream& out,string &s);
	private:
		char* _str;
		size_t _size;
		size_t _capacity;

	};
	ostream &operator<<(ostream& out,string &s)
	{
		out << s._str << endl;
		return out;
	}
	istream& operator>> (istream& in, string &s)
	{
		if (s._str)
		{
			delete[] s._str;
			s._str = nullptr;
			s._size = s._capacity = NULL;
		}
		char buf[1024] = { 0 };
		cin >> buf;
		int len = strlen(buf);
		s._str = new char[len + 1];
		for (int i = 0; i <= len; i++)
		{
			s._str[i] = buf[i];
		}
		s._size = s._capacity = len;
		return in;
	}
}