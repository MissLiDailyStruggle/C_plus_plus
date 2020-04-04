
#include"ThreadCache.h"
#include"CentralCache.h"

void* ThreadCache::Allocte(size_t size)
{
	size_t index = SizeClass::ListIndex(size);//Index(size);
	FreeList& freelist = _freeLists[index];
	if (!freelist.Empty())//��ֱ�Ӳ���ָ�룬����������з�װ���ж�
	{//���ڴ�
		return freelist.Pop();
	}
	else
	{//���ڴ棬ȥcentralcache����
		//size_t num = 20;//�Ժ�������͵�������Ĵ�С�й�
		return FetchFromCentralCache(SizeClass::RoundUp(size));//num������������,start����������¿ռ䣨����,������ٴ���ȥ
	}
}

void ThreadCache::Deallocte(void* ptr, size_t size)
{//�����ڴ������
	size_t index = SizeClass::ListIndex(size);//?
	FreeList& freeList = _freeLists[index];
  	freeList.Push(ptr);

	//�ͷŵ�����ʱ���������������һ������ �ڴ��С
	size_t num = SizeClass::NumMoveSize(size);
	if (freeList.Num() >= num)
	{
		//����̫����Ҫ�ͷŸ�centralcache
		ListTooLong(freeList, num, size);
	}
}

void ThreadCache::ListTooLong(FreeList& freeList, size_t num, size_t size)
{
	void* start = nullptr, *end = nullptr;
	freeList.PopRange(start, end, num);

	NextObj(end) = nullptr;//ɾ����һ��βҪ�ÿմ���
	CentralCache::GetInstance().ReleaseListToSpans(start, size);
}

////��������thread cache
//void* ThreadCache::FetchFromCentralCache(size_t size)
//{
//	//��centralcache��������ռ䣬���ص�ʱ�������������صģ�num������������
//	size_t num = 20;//�Ժ����������ӿ�����ʱ��centralcache��ȡһ������
//
//	//ģ��ȡ�ڴ����Ĵ��룬����ThreadCache���߼�
//	size_t size = (index + 1) * 8;//���������С
//	char* start = (char*)malloc(size*num);//num�Ƕ������
//	char* cur = start;
//	for (size_t i = 0; i < num; ++i)
//	{//����num���ռ�Ҫ����������
//		char* next = cur + size;
//		NextObj(cur) = next;
//
//		cur = next;
//	}
//
//	NextObj(cur) = nullptr;//���һ��λ���ÿ�
//
//	void* head = NextObj(start);
//	void* tail = cur;
//
//	_freeLists[index].PushRange(head, tail);
//
//	return start;
//}


//��������thread cache
void* ThreadCache::FetchFromCentralCache(size_t size)
{
	size_t num = SizeClass::NumMoveSize(size);

	//��CentralCache�л�ȡ�ڴ�
	void* start = nullptr, *end = nullptr;
	size_t actualNum = CentralCache::GetInstance().FetchRangeObj(start, end, num, size);//numҪ��num,actualNumʵ�ʷ��ص�num

	if (actualNum == 1)
	{//ֻ��ȡ����һ����ֱ�ӷ���
		return start;
	}
	else
	{//����һ����ʣ�µĹ�����
		size_t index = SizeClass::ListIndex(size);
		FreeList& list = _freeLists[index];
		list.PushRange(NextObj(start), end, actualNum - 1);

		return start;
	}
}
