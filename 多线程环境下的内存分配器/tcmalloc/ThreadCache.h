//#pragma once
//
//#include"Common.h"
//
//class ThreadCache
//{
//public:
//	//�����ڴ���ͷ��ڴ�
//	void* Allocte(size_t size);
//	void Deallocte(void* ptr, size_t size);
//
//	//�����Ļ����ȡ����
//	//����ӿ�����threadcache��û���ڴ棬ȥcentralcache�����룬��ʱҪ��������������������
//	void* FetchFromCentralCache(size_t index);
//	//������������ж��󳬹�һ�����Ⱦ�Ҫ�ͷŸ����Ļ���
//	void ListTooLong(FreeList& freeList, size_t num, size_t size);
//
//private:
//	FreeList _freeLists[NFREELIST];
//
//	//ThreadCache* _next;
//	//int threadid;
//};
//
////ThreadCache* tclist = nullptr;
////�߳�TLS Thread Local Storage
//
////static ThreadCache* pThreadCache = nullptr;//����һ�������������߳�
//_declspec (thread) static ThreadCache* pThreadCache = nullptr;//ʵ��һ����̬��TLS�����̶߳���
////��̬��ȫ�ֱ���

#pragma once

#include "Common.h"

class ThreadCache
{
public:
	// �����ڴ���ͷ��ڴ�
	void* Allocte(size_t size);
	void Deallocte(void* ptr, size_t size);

	// �����Ļ����ȡ����
	void* FetchFromCentralCache(size_t index);

	// ������������ж��󳬹�һ�����Ⱦ�Ҫ�ͷŸ����Ļ���
	void ListTooLong(FreeList& freeList, size_t num, size_t size);
private:
	FreeList _freeLists[NFREELIST];

	//ThreadCache* _next;
	//int threadid;
};

// ThreadCache* tclist = nullptr;
// �߳�TLS Thread Local Storage

_declspec (thread) static ThreadCache* pThreadCache = nullptr;
