#pragma once

#include<iostream>
#include<assert.h>
#include<unordered_map>
#include<thread>
#include<mutex>

#ifdef _WIN32
#include<Windows.h>
#endif //_WIN32

//using namespace std;
using std::cout;
using std::endl;

const size_t MAX_SIZE = 64 * 1024;
const size_t NFREELIST = MAX_SIZE / 8;//freelist�Ĵ�С(ָ������)����8���������8
const size_t MAX_PAGES = 129;
const size_t PAGE_SHIFT = 12;//4kΪҳ��λ

inline void*& NextObj(void* obj)
{//ȡͷ��4���ֽڣ����������ı���
	return *((void**)obj);
}

class FreeList
{
public:
	void Push(void* obj)//�����ȥ
	{
		//ͷ��
		NextObj(obj) = _freelist;
		_freelist = obj;
		++_num;
	}

	void PushRange(void* head, void* tail, size_t num)
	{
		NextObj(tail) = _freelist;
		_freelist = head;
		_num += num;
	}

	size_t PopRange(void*& start, void*& end, size_t num)
	{
		size_t actualNum = 0;
		void* prev = nullptr;
		void* cur = _freelist;
		for (; actualNum < num&&cur != nullptr; ++actualNum)
		{
			prev = cur;
			cur = NextObj(cur);
		}
		start = _freelist;
		end = prev;
		_freelist = cur;
		_num -= actualNum;

		return actualNum;
	}

	void* Pop()
	{
		//ͷɾ
		void* obj = _freelist;
		_freelist = NextObj(obj);
		--_num;
		return obj;
		
	}

	size_t Num()
	{
		return _num;
	}

	bool Empty()
	{
		return _freelist == nullptr;
	}

	void Clear()
	{
		_freelist = nullptr;
		_num = 0;
	}

private:
	void* _freelist = nullptr;
	size_t _num = 0;
};


//ר�ſ��Ƹ��ִ�С
class SizeClass
{
public:

	//��ͨ��д��hhh
	//static size_t ListIndex(size_t size)
	//{//����index
	//	if (size % 8 == 0)
	//	{
	//		return size / 8 - 1;
	//	}
	//	else
	//	{
	//		return size / 8;
	//	}
	//}

	////����size�Ķ���
	//static size_t RoundUp(size_t size)
	//{
	//	if (size % 8 != 0)
	//	{
	//		return (size / 8 + 1) * 8;
	//	}
	//	else
	//	{
	//		return size;
	//	}
	//}


	// ������10%���ҵ�����Ƭ�˷�
	// [1,128] 8byte���� freelist[0,16)
	// [129,1024] 16byte���� freelist[16,72)
	// [1025,8*1024] 128byte���� freelist[72,128)
	// [8*1024+1,64*1024] 512byte���� freelist[128,184)
	static size_t _RoundUp(size_t size, size_t alignment)
	{//����size�Ķ����� alignment�Ƕ�����   //[9 - 16] + 7 = [16 - 23]->16 8 4 2 1    [17 - 32] + 15 + [32,47]->32 16 8 4 2 1
		return (size + alignment - 1)&(~(alignment - 1));
	}

	// �����С����
	static inline size_t RoundUp(size_t size)
	{
		assert(size <= MAX_SIZE);

		if (size <= 128){
			return _RoundUp(size, 8);
		}
		else if (size <= 1024){
			return _RoundUp(size, 16);
		}
		else if (size <= 8192){
			return _RoundUp(size, 128);
		}
		else if (size <= 65536){
			return _RoundUp(size, 512);
		}
		return -1;
	}

	static size_t _ListIndex(size_t size, int align_shift)
	{//����index�±�  align_shift��2��n�η����Ǹ�ָ����ͨ��1<<align_shiftʵ��
		return ((size + (1 << align_shift) - 1) >> align_shift) - 1;
	}
	static inline size_t ListIndex(size_t size)
	{
		assert(size <= MAX_SIZE);
		// ÿ�������ж��ٸ���
		static int group_array[4] = { 16, 56, 56, 56 };
		if (size <= 128){
			return _ListIndex(size, 3);//��������8->2^3
		}
		else if (size <= 1024){
			return _ListIndex(size - 128, 4) + group_array[0];//����group�����ݵĻ������ֻ���ڰ���ĳĳ����ʱ������±�(ֻ����������)����Ӧ�ü���ǰ������䣬�õ��������±�
		}
		else if (size <= 8192){
			return _ListIndex(size - 1024, 7) + group_array[1] + group_array[0];
		}
		else if (size <= 65536){
			return _ListIndex(size - 8192, 9) + group_array[2] + group_array[1] +
				group_array[0];
		}
		return -1;
	}

	//[2,512]��֮��
	static size_t NumMoveSize(size_t size)
	{
		if (size == 0)
			return 0;
		int num = MAX_SIZE / size;
		if (num < 2)
			num = 2;
		if (num > 512)
			num = 512;
		return num;
	}

	//����һ����ϵͳ��ȡ����ҳ
	static size_t NumMovePage(size_t size)
	{
		size_t num = NumMoveSize(size);
		size_t npage = num*size;
		npage >>= 12;//  /4k
		if (npage == 0)
			npage = 1;
		return npage;
	}
};



///////////////////////////////////////////////////////////////////////////////////////////
//span ��� ����ҳΪ��λ���ڴ���󣬱����Ƿ������ϲ�������ڴ���Ƭ

//���windows
#ifdef _WIN32
typedef int PAGE_ID;
#else
typedef unisigned long long PAGE_ID;
#endif//_WIN32

struct Span
{
	PAGE_ID _pageid = 0; //ҳ�� 64λ��int��ʾ����  2^64/4k=2^64/2^12=2^52
	PAGE_ID _pagesize = 0;   //ҳ������

	FreeList _freelist; //������������
	size_t _objSize = 0;//�����������Ĵ�С
	int _use_count = 0;  //�ڴ�����ʹ�ü���

	//size_t objsize  //�����С
	Span* _next = nullptr;      //Span֮��Ҳ��Ҫ������
	Span* _prev = nullptr;
};

class SpanList
{//SpanList���ó�˫��ѭ����ͷ����
public:
	SpanList()
	{
		_head = new Span;
		_head->_next = _head;
		_head->_prev = _head;
	}

	Span* Begin()
	{
		return _head->_next;
	}

	Span* End()
	{
		return _head;//����SpanList��ʱ���ߵ�head��Ϊ����
	}

	void PushFront(Span* newspan)
	{
		Insert(_head->_next, newspan);
	}
	void PopFront()
	{
		Erase(_head->_next);
	}

	void PushBack(Span* newspan)
	{
		Insert(_head, newspan);
	}
	void PopBack()
	{
		Erase(_head->_prev);
	}

	void Insert(Span* pos, Span* newspan)
	{
		Span* prev = pos->_prev;

		//prev newspan pos
		prev->_next = newspan;
		newspan->_next = pos;
		pos->_prev = newspan;
		newspan->_prev = prev;
	}

	void Erase(Span* pos)
	{
		assert(pos != _head);

		Span* prev = pos->_prev;
		Span* next = pos->_next;

		prev->_next = next;
		next->_prev = prev;

	}

	bool Empty()
	{
		return Begin() == End();
	}

	void Lock()
	{//spanlist�е�������_mtx��˽�еģ�Ҫ�ṩ���нӿڣ�����������ɹ�����
		_mtx.lock();
	}

	void Unlock()
	{
		_mtx.unlock();
	}

private:
	Span* _head;
	std::mutex _mtx;
};

inline static void* SystemAlloc(size_t num_page)
{
#ifdef _WIN32
	void* ptr = VirtualAlloc(0, num_page*(1 << PAGE_SHIFT),
		MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE);
#else
	// brk mmap��
#endif
	if (ptr == nullptr)
		throw std::bad_alloc();

	return ptr;
}

inline static void SystemFree(void* ptr)
{
#ifdef _WIN32
	VirtualFree(ptr, 0, MEM_RELEASE);
#else
#endif
}