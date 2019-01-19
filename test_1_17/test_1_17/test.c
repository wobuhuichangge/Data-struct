#include "SList.h"
void printfSList(SList* pl)
{
	assert(pl);
	Node* pCur = pl->_pHead;
	while (pCur)
	{

		printf("%d---> ", pCur->_data);
		pCur = pCur->_pNEXT;
	}
		printf("null\n");
		
	

}
void test1()
{
	SList s;
	SListInit(&s);


	SListPushBack(&s, 1);
	SListPushBack(&s, 2);
	SListPushBack(&s, 3);
	SListPushBack(&s, 2);
	SListPushBack(&s, 2);
	SListPushBack(&s, 4);
	/*printfSList(&s);
	SListPopBack(&s);*/
	/*printfSList(&s);
	SListPushFront(&s, 0);
	printfSList(&s);
	SListPopFront(&s);*/
	printfSList(&s);
	//SListFind(&s, 2);
	//SListInsertAfter(SListFind(&s, 2), 0);
	//printfSList(&s);
	//printf("%p\n", SListFind(&s, 1));
	/*SListErase(&s, SListFind(&s, 1));
	printfSList(&s);*/

	/*SListSize(&s);
	SListEmpty(&s);
	SListFront(&s);
	SListBack(&s);*/
	//SListRemove(&s, 2);
	SListRemoveAll(&s, 2);
	printfSList(&s);
	SListDestroy(&s);
}


int main()
{
	test1();
	system("pause");
	return 0;
}