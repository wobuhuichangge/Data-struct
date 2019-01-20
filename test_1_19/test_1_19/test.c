#include"DList.h"
void PrintDList(Node* pHead)
{
	assert(pHead);
	Node* pCur = pHead->_Next;
	while (pCur!= pHead)
	{
		printf("%d ", pCur->_data);
		pCur = pCur->_Next;
	}
	printf("\n");
}
void test()
{
	Node* s = NULL;
	DListInit(&s);
	NlistPushFront(s, 1);
	//NlistPopFront(s);
	//PrintDList(s);
	NlistPushFront(s, 2);
	NlistPushFront(s, 3);
	NlistPushFront(s, 4);
	NlistPushFront(s, 5);
	PrintDList(s);
	//NListPushBack(s, 0);
	//PrintDList(s);
	//NListPopBack(s);
	//NlistPopFront(s);
	//PrintDList(s);
	DListInsert(DListFind(s, 2), 5);
	PrintDList(s);
	//DListErase(s, DListFind(s, 5));
	//PrintDList(s);
	//DListRemove(s, 5);
	DListRemoveAll(s, 5);
	PrintDList(s);
	NListDestory(&s);
}

int main()
{
	test();
	system("pause");
	return 0;
}