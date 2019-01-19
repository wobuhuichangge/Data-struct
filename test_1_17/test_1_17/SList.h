#define _CRT_SECURE_NO_WARNINGS 1
#pragma once
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
typedef int SDataType;
//结点结构
typedef struct SListNode
{
	SDataType _data;
	struct SListNode* _pNEXT;
}Node;

//链表结构
typedef struct SList
{
	Node* _pHead;
}SList;

void SListInit(SList* pl);
// 销毁链表 
void SListDestroy(SList* pl);
// 在链表中尾插值为data的节点 
void SListPushBack(SList* pl, SDataType data);
void SListPopBack(SList* pl);
void SListPushFront(SList* pl, SDataType data);
void SListPopFront(SList* pl);
// 在链表pos位置后插入置为data的节点 
void SListInsertAfter(Node* pos, SDataType data);
// 删除链表中值为data的节点 
void SListErase(SList* pl, Node* pos);
// 在链表中查找值为data的节点，找到返回该节点的地址，否则返回空 
Node* SListFind(SList* pl, SDataType data);
// 获取链表中有效节点的个数 
int SListSize(SList* pl);
// 检测链表是否为空 
int SListEmpty(SList* pl);
// 获取链表的第一个节点 
Node* SListFront(SList* pl);

// 获取链表的第二个节点 
Node* SListBack(SList* pl);

void SListRemove(SList* pl, SDataType data);
void SListRemoveAll(SList* pl, SDataType data);