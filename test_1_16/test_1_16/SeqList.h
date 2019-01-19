#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdio.h>
#include<string.h>
typedef int DataType;

typedef struct SeqList
{
	DataType*_array;
	int _capacity;
	int _size;
}SeqList, *PSeqList;

void SeqListInit(PSeqList ps);
void SeqListDestroy(PSeqList ps);
void SeqListPushBack(PSeqList ps, DataType data);
void SeqListPopBack(PSeqList ps);
void SeqListPushFront(PSeqList ps, DataType data);
void SeqListPopFront(PSeqList ps);
void SeqListInsert(PSeqList ps, int pos, DataType data);
void SeqListErase(PSeqList ps, int pos);
void SeqListRemove(PSeqList ps, DataType data);
void SeqListRemoveAll(PSeqList ps, DataType data);
int SeqListSize(PSeqList ps);
int SeqListCapacity(PSeqList ps);
int SeqListEmpty(PSeqList ps);
DataType SeqListFront(PSeqList ps);
DataType SeqListBack(PSeqList ps);