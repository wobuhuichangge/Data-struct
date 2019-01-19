#define _CRT_SECURE_NO_WARNINGS 1
#pragma once
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
typedef int SDataType;
//���ṹ
typedef struct SListNode
{
	SDataType _data;
	struct SListNode* _pNEXT;
}Node;

//����ṹ
typedef struct SList
{
	Node* _pHead;
}SList;

void SListInit(SList* pl);
// �������� 
void SListDestroy(SList* pl);
// ��������β��ֵΪdata�Ľڵ� 
void SListPushBack(SList* pl, SDataType data);
void SListPopBack(SList* pl);
void SListPushFront(SList* pl, SDataType data);
void SListPopFront(SList* pl);
// ������posλ�ú������Ϊdata�Ľڵ� 
void SListInsertAfter(Node* pos, SDataType data);
// ɾ��������ֵΪdata�Ľڵ� 
void SListErase(SList* pl, Node* pos);
// �������в���ֵΪdata�Ľڵ㣬�ҵ����ظýڵ�ĵ�ַ�����򷵻ؿ� 
Node* SListFind(SList* pl, SDataType data);
// ��ȡ��������Ч�ڵ�ĸ��� 
int SListSize(SList* pl);
// ��������Ƿ�Ϊ�� 
int SListEmpty(SList* pl);
// ��ȡ����ĵ�һ���ڵ� 
Node* SListFront(SList* pl);

// ��ȡ����ĵڶ����ڵ� 
Node* SListBack(SList* pl);

void SListRemove(SList* pl, SDataType data);
void SListRemoveAll(SList* pl, SDataType data);