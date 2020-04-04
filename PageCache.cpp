#include"PageCache.h"

Span* PageCache::_NewSpan(size_t numpage)
{
	if (!_spanLists[numpage].Empty())
	{
		Span* span = _spanLists[numpage].Begin();
		_spanLists[numpage].PopFront();
		return span;
	}
	for (size_t i = numpage; i < MAX_PAGES; ++i)
	{
		if (!_spanLists[i].Empty())
		{
			//���ѵĹ���
			Span* span = _spanLists[i].Begin();
			_spanLists[i].PopFront();

			Span* splitspan = new Span;

			//Ϊ��ӳ������ı�,һ���еñȽ��٣����е�ҳ����splitspan�ı���ӳ���ϵ��û���ߵ�ҳ����
			/*splitspan->_pageid = span->_pageid + numpage;
			splitspan->_pagesize = span->_pagesize - numpage;

			span->_pagesize = numpage;

			_spanLists[splitspan->_pagesize].PushFront(splitspan);*/

			splitspan->_pageid = span->_pageid + span->_pagesize - numpage;
			splitspan->_pagesize = numpage;
			for (PAGE_ID i = 0; (size_t)i < numpage; ++i)
			{
				_idSpanMap[splitspan->_pageid + i] = splitspan;
			}

			span->_pagesize -= numpage;

			_spanLists[span->_pagesize].PushFront(span);

			return splitspan;

		}
	}

	void* ptr = SystemAlloc(MAX_PAGES - 1);

	Span* bigspan = new Span;
	bigspan->_pageid = (PAGE_ID)ptr >> PAGE_SHIFT;
	bigspan->_pagesize = MAX_PAGES - 1;

	for (PAGE_ID i = 0; i < bigspan->_pagesize; ++i)
	{//����mapӳ��
		//_idSpanMap.insert(std::make_pair(bigspan->_pageid + i, bigspan));
		_idSpanMap[bigspan->_pageid + i] = bigspan;
	}
	//�������δ���ĸ��ã��ٵ�һ���Լ���ţ��
	_spanLists[bigspan->_pagesize].PushFront(bigspan);

	return _NewSpan(numpage);

}

Span* PageCache::NewSpan(size_t numpage)
{
	_mtx.lock();
	Span* span = _NewSpan(numpage);
	_mtx.unlock();

	return span;

}

void PageCache::ReleaseSpanToPageCache(Span* span)
{
	//ҳ�ĺϲ�
	while (1)
	{
		PAGE_ID prevPageId = span->_pageid - 1;
		auto pit = _idSpanMap.find(prevPageId);//������[]
		//ǰ���ҳ������
		if (pit == _idSpanMap.end())
		{
			break;
		}

		//˵��ǰһ��ҳ����ʹ���У����ܺϲ�
		Span* prevSpan = pit->second;
		if (prevSpan->_use_count != 0)
		{
			break;
		}

		//�ϲ�

		//����ϲ�������128ҳ��span���ǾͲ�Ҫ�ϲ�
		if (span->_pagesize + prevSpan->_pagesize >= MAX_PAGES)
		{
			break;
		}

		span->_pageid = prevSpan->_pageid;
		span->_pagesize += prevSpan->_pagesize;
		//mapҲҪ����
		for (PAGE_ID i = 0; i < prevSpan->_pagesize; ++i)
		{
			_idSpanMap[prevSpan->_pageid + i] = span;
		}

		_spanLists[prevSpan->_pagesize].Erase(prevSpan);//��ֹҰָ�룬�ϲ����Ҫ�ѽ�С��span��ԭ���ҵĵط�ɾ��
		delete prevSpan;
	}

	//���ϲ�
	while (1)
	{
		PAGE_ID nextPageId = span->_pageid + span->_pagesize;
		auto nextIt = _idSpanMap.find(nextPageId);
		if (nextIt == _idSpanMap.end())
		{
			break;
		}

		Span* nextSpan = nextIt->second;
		if (nextSpan->_use_count != 0)
		{
			break;
		}
		//����ϲ�������128ҳ��span���ǾͲ�Ҫ�ϲ�
		if (span->_pagesize + nextSpan->_pagesize >= MAX_PAGES)
		{
			break;
		}
		span->_pagesize += nextSpan->_pagesize;
		for (PAGE_ID i = 0; i < nextSpan->_pagesize; ++i)
		{
			_idSpanMap[nextSpan->_pageid + i] = span;
		}

		_spanLists[nextSpan->_pagesize].Erase(nextSpan);//��ֹҰָ��
		delete nextSpan;
	}

	_spanLists[span->_pagesize].PushFront(span);
}

Span *PageCache::GetIdToSpan(PAGE_ID id)
{
	//std::map<PAGE_ID, Span*>::iterator it = _idSpanMap.find(id);
	auto it = _idSpanMap.find(id);
	if (it != _idSpanMap.end())
	{
		return it->second;
	}
	else
	{
		return nullptr;
	}
}