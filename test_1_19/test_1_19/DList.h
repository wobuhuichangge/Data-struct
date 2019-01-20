#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<assert.h>
typedef int DLDataType;
typedef struct DListNode
{
	DLDataType _data;
	struct DListNode* _Next;
	struct DListNode* _Pre;
}Node;

void DListInit(Node** pHead);

void NListDestory(Node** pHead);
void NlistPushFront(Node* pHead, DLDataType data);

void NlistPopFront(Node* pHead);

void NListPushBack(Node* pHead,DLDataType data);

void NListPopBack(Node* pHead);
Node* DListFind(Node* pHead, DLDataType data);
void DListInsert(Node* pos, DLDataType data);
void DListErase(Node* pHead, Node* pos);
void DListRemoveAll(Node* pHead, DLDataType data);

void DListRemove(Node* pHead, DLDataType data);



