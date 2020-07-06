#pragma once

template<class T,size_t init_num = 100>
class ObjectPool
{
public:
	ObjectPool()
	{
		_item_size = sizeof(T) < sizeof(T*) ? sizeof(T*) : sizeof(T);
		_start = (char*)malloc(init_num * _item_size);
		_end = _start + init_num * _item_size;
		_free_list = nullptr;
	}
	T*& Next_Obj(T*obj)
	{
		return *(T**)obj;
	}
	T* Alloc()
	{
		T* obj = nullptr;
		if (_free_list != nullptr)
		{
			obj = _free_list;
			_free_list = Next_Obj(obj);
		}
		else 
		{
			if (_start == _end)
			{
				_start = (char*)malloc(init_num * _item_size);
				_end = _start + init_num * _item_size;
			}
			obj = (T*)_start;
			_start += _item_size;
		}
		new(obj)T;
		return obj;
	}
	void Delete(T* obj)
	{
		obj->~T();
		Next_Obj(obj) = _free_list;
		_free_list = obj;
	}
private:
	char* _start;
	char* _end;
	size_t _item_size;
	T* _free_list;
};
void TestObjectPool()
{
	ObjectPool<int> pool;
	int* p1 = pool.Alloc();
	int* p2 = pool.Alloc();
	int* p3 = pool.Alloc();

	pool.Delete(p1);
	pool.Delete(p2);
	pool.Delete(p3);

	cout << p1 << endl;
	cout << p2 << endl;
	cout << p3 << endl << endl;;

	int* p4 = pool.Alloc();
	int* p5 = pool.Alloc();
	int* p6 = pool.Alloc();

	pool.Delete(p4);
	pool.Delete(p5);
	pool.Delete(p6);

	cout << p4 << endl;
	cout << p5 << endl;
	cout << p6 << endl;

}

void BenchMark()
{
	size_t n = 100000;

	vector<string*> v1;
	v1.reserve(n);
	size_t begin1 = clock();

	for (size_t i = 0; i < n; ++i)
	{
		v1.push_back(new string);
	}

	for (size_t i = 0; i < n; ++i)
	{
		delete v1[i];
	}

	size_t end1 = clock();

	v1.clear();

	cout << "直接系统申请内存:" << end1 - begin1 << endl;



	vector<string*> v2;
	v2.reserve(n);
	ObjectPool<string> pool;
	size_t begin2 = clock();

	for (size_t i = 0; i < n; ++i)
	{
		v2.push_back(pool.Alloc());
	}

	for (size_t i = 0; i < n; ++i)
	{
		pool.Delete(v2[i]);
	}

	size_t end2 = clock();

	v2.clear();

	cout << "Pool申请内存:" << end2 - begin2 << endl;
}