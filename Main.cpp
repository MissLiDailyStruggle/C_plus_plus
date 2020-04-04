#include"ThreadCache.h"

#include<vector>

//void UnitThreadCache()
//{
//	ThreadCache tc;
//	vector<void*> v;
//	for (size_t i = 0; i < 21; i++)
//	{
//		v.push_back(tc.Allocte(7));
//	}
// 
//	for (size_t i = 0; i < 21; i++)
//	{
//		printf("[%d]->%p\n", i, v[i]);
//	}
//
//	for (auto ptr : v)
//	{
//		tc.Deallocte(ptr, 7);
//	}
//}

void UnitTestSizeClass()
{
	// ������10%���ҵ�����Ƭ�˷�
	// [1,128] 8byte���� freelist[0,16)
	// [129,1024] 16byte���� freelist[16,72)
	// [1025,8*1024] 128byte���� freelist[72,128)
	// [8*1024+1,64*1024] 512byte���� freelist[128,184)
	cout << SizeClass::RoundUp(1) << endl;
	cout << SizeClass::RoundUp(127) << endl;
	cout << endl;

	cout << SizeClass::RoundUp(129) << endl;
	cout << SizeClass::RoundUp(1023) << endl;
	cout << endl;

	cout << SizeClass::RoundUp(1025) << endl;
	cout << SizeClass::RoundUp(8 * 1024 - 1) << endl;
	cout << endl;

	cout << SizeClass::RoundUp(8 * 1024 + 1) << endl;
	cout << SizeClass::RoundUp(64 * 1024 - 1) << endl;
	cout << endl << endl;

	cout << SizeClass::ListIndex(1) << endl;
	cout << SizeClass::ListIndex(128) << endl;
	cout << endl;

	cout << SizeClass::ListIndex(129) << endl;
	cout << SizeClass::ListIndex(1023) << endl;
	cout << endl;

	cout << SizeClass::ListIndex(1025) << endl;
	cout << SizeClass::ListIndex(8 * 1024 - 1) << endl;
	cout << endl;

	cout << SizeClass::ListIndex(8 * 1024 + 1) << endl;
	cout << SizeClass::ListIndex(64 * 1024 - 1) << endl;
	cout << endl << endl;
}

void UnitTestSystemAlloc()
{
	void* ptr1 = SystemAlloc(1);//ҳ����ʼ��ַ
	void* ptr2 = SystemAlloc(1);

	PAGE_ID id1 = (PAGE_ID)ptr1 >> PAGE_SHIFT;//��ַ��ҳ��
	void* ptrshift1 = (void*)(id1 << PAGE_SHIFT);//ҳ�Ż�ԭ��ַ

	PAGE_ID id2 = (PAGE_ID)ptr2 >> PAGE_SHIFT;//��ַ��ҳ��
	void* ptrshift2 = (void*)(id2 << PAGE_SHIFT);//ҳ�Ż�ԭ��ַ

	char* obj1 = (char*)ptr1;//��֤ͨ����ҳ�����ַ��������ҳ��
	char* obj2 = (char*)ptr1 + 8;
	char* obj3 = (char*)ptr1 + 16;
	PAGE_ID idd1 = (PAGE_ID)obj1 >> PAGE_SHIFT;
	PAGE_ID idd2 = (PAGE_ID)obj2 >> PAGE_SHIFT;
	PAGE_ID idd3 = (PAGE_ID)obj3 >> PAGE_SHIFT;
}

void UnitThreadCache()
{
	/*ThreadCache tc;
	void* ptr1 = tc.Allocte(6);
	void* ptr2 = tc.Allocte(6);
	void* ptr3 = tc.Allocte(6);*/

	ThreadCache tc;
	std::vector<void*> v;
	size_t size = 7;
	for (size_t i = 0; i < SizeClass::NumMoveSize(size); ++i)
	{
		v.push_back(tc.Allocte(size));
	}
	v.push_back(tc.Allocte(size));

	for (size_t i = 0; i < v.size(); i++)
	{
		printf("[%d]->%p\n", i, v[i]);
	}

	for (auto ptr : v)
	{
		tc.Deallocte(ptr, 7);
	}

	//v.clear();
	//v.push_back(tc.Allocte(size));
}

#include"ConcurrentMalloc.h"

void func1()
{
	//static int j = 0;
	//for (size_t i = 0; i < n; ++i)
	//{
	//	cout << i << endl;
	//	++j;
	//}
	//cout << "j:" << j << endl;

	ThreadCache tc;
	std::vector<void*> v;
	size_t size = 7;
	for (size_t i = 0; i < 512; ++i)
	{
		v.push_back(ConcurrentMalloc(size));
	}

	v.push_back(ConcurrentMalloc(size));

	for (size_t i = 0; i < v.size(); i++)
	{
		//printf("[%d]->%p\n", i, v[i]);
	}

	for (auto ptr : v)
	{
		ConcurrentFree(ptr);
	}
}

#include"Common.h"

void func2(size_t n)
{
	ThreadCache tc;
	std::vector<void*> v;
	size_t size = 7;
	for (size_t i = 0; i < SizeClass::NumMoveSize(size) + 1; ++i)
	{
		v.push_back(tc.Allocte(7));
	}

	for (size_t i = 0; i < 21; i++)
	{
		//printf("[%d]->%p\n", i, v[i]);
	}

	for (auto ptr : v)
	{
		tc.Deallocte(ptr, 7);
	}
}

/*
//����ģʽ
class Singleton
{
public:
static Singleton& GetInstance()
{
static Singleton inst;
return inst;
}
private:
Singleton()
{}

//��ס�������죬��ȻҲ����Ƶ���ģʽ�Ĺ���
//Singleton(const Singleton&) = delete;//�����������
Singleton(const Singleton&);//��������ֻ����������
};
*/

//int main()
//{
//	//Singleton::GetInstance();
//	//Singleton copy(Singleton::GetInstance());
//
//	//UnitThreadCache();
//	//UnitTestSizeClass();
//	//UnitTestSystemAlloc();
//
//	//UnitThreadCache();
//
//	//������������Դ��ʱ����һ���������
//	//std::thread t1(func1, 100);
//	//std::thread t2(func1, 100);
//
//	////cout << "���̵߳ȴ�" << endl;
//	//t1.join();
//	//t2.join();
//
//	/*
//	void* ptr1 = ConcurrentMalloc(1);
//	void* ptr2 = ConcurrentMalloc(65 << PAGE_SHIFT);
//	void* ptr3 = ConcurrentMalloc(129 << PAGE_SHIFT);
//
//	ConcurrentFree(ptr1);
//	ConcurrentFree(ptr2);
//	ConcurrentFree(ptr3);
//	*/
//
//	func1();
//
//	system("pause");
//	return 0;
//}