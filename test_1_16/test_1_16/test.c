#define _CRT_SECURE_NO_WARNINGS 1
#include"SeqList.h"

void printSeqList(PSeqList ps)
{
	assert(ps);
	if (ps->_size == 0)
		printf("NULL");
	else
	for (int i = 0; i < ps->_size; i++)
	{
		printf("%d ", ps->_array[i]);
	}
	printf("\n");
}
int main()
{
	SeqList s;
	SeqListInit(&s);
	SeqListPushBack(&s, 0);
	SeqListPushBack(&s, 2);
	SeqListPushBack(&s, 1);
	SeqListPushBack(&s, 2);
	SeqListPushBack(&s, 3);
	printSeqList(&s);
	//SeqListPopBack(&s);
	//SeqListPushFront(&s, 4);
	//SeqListPopFront(&s);
	//SeqListInsert(&s, 2, 5);
	//SeqListErase(&s, 2);
	//int ret = SeqListFind(&s, 0);
	//printf("%d \n", ret);
	//SeqListRemove(&s, 2);
	//SeqListRemoveAll(&s, 2);
	//printSeqList(&s);
	//int ret = SeqListSize(&s);
	//int ret = SeqListCapacity(&s);
	//int ret = SeqListEmpty(&s);
	//DataType ret = SeqListFront(&s);
	DataType ret = SeqListBack(&s);
	printf("%d ", ret);
	system("pause");
	return 0;
}