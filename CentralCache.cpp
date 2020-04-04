#include"CentralCache.h"

//��spanlist����page cache��ȡһ��span�����ȴ�spanlist�л�ȡ
//��ȡ����span������FetchRangeObj��PopRangeһ�θ�threadCache
Span* CentralCache::GetOneSpan(size_t size)
{
	//��ȡһ���ж����Span
	size_t index = SizeClass::ListIndex(size);//�����±�
	//ͨ���±����SpanList,�ҵ���Ӧ��Span
	SpanList& spanlist = _spanLists[index];
	Span* it = spanlist.Begin();
	while (it != spanlist.End())
	{
		if (!it->_freelist.Empty())
		{
			//�ҵ�ֱ��ȡ
			return it;//��ǰSpan
		}
		else
		{
			it = it->_next;
		}
	}

	//û��Span����PageCache��ȡ
	size_t numpage = SizeClass::NumMovePage(size);
	Span* span = PageCache::GetInstance().NewSpan(numpage);
	//��span�����гɶ�Ӧ��С�ҵ�span��freelist��

	char* start = (char*)(span->_pageid << 12);
	char* end = start + (span->_pagesize << 12);
	while (start < end)
	{
		char* obj = start;
		start += size;

		span->_freelist.Push(obj);
	}
	span->_objSize = size;
	spanlist.PushBack(span);

	return span;
}

size_t CentralCache::FetchRangeObj(void*& start, void*& end, size_t num, size_t size)//num�Ƕ�����,size���ֽ���
{
	size_t index = SizeClass::ListIndex(size);
	SpanList& spanlist = _spanLists[index];
	spanlist.Lock();

	Span* span = GetOneSpan(size);//����Ĵ��뱣֤�����õ������кõĶ���
	FreeList& freelist = span->_freelist;
	size_t actualNum = freelist.PopRange(start, end, num);
	span->_use_count += actualNum;

	spanlist.Unlock();

	return actualNum;
}

void CentralCache::ReleaseListToSpans(void * start, size_t size)
{
	size_t index = SizeClass::ListIndex(size);
	SpanList& spanlist = _spanLists[index];
	spanlist.Lock();

	//�����һ��map<ptr, span*>,Ҫ���Ķ����ָ��ֱ��ӳ��Ҫ����span
	//���Ż���map<pageid, span*>,����֪��������������ĸ�span��ֱ�Ӹ���ҳ�������Ӧspan,����֪�����span���ĸ�list�����ĸ��ط���ֱ�Ӹ���ָ��ҵ�list��
	while (start)
	{
		void* next = NextObj(start);//ע��next����ǰ���棬����ͷ����Ҳ���ԭ�е�next
		PAGE_ID id = (PAGE_ID)start >> PAGE_SHIFT;
		Span* span = PageCache::GetInstance().GetIdToSpan(id);
		span->_freelist.Push(start);
		span->_use_count--;

		//��ʾ��ǰspan�г�ȥ�Ķ���ȫ�����أ����Խ�span����page cache�����кϲ��������ڴ���Ƭ����
		if (span->_use_count == 0)
		{
			size_t index = SizeClass::ListIndex(span->_objSize);
			_spanLists[index].Erase(span);
			span->_freelist.Clear();//��ֹ�й����ڴ������ٹ�һ��
			PageCache::GetInstance().ReleaseSpanToPageCache(span);
		}
		start = next;
	}

	spanlist.Unlock();
}
