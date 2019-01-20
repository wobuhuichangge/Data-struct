#include"DList.h"
//双向链表的初始化
void DListInit(Node** pHead)
{
	assert(pHead);
	if (pHead == NULL)
		return;
	 *pHead= (Node*)malloc(sizeof(Node));
	(*pHead)->_data = 0;
	(*pHead)->_Next = *pHead;
	(*pHead)->_Pre = *pHead;
}
// 创建一个新的节点
Node* BuyNode(DLDataType data)
{
	Node* NewNode = (Node*)malloc(sizeof(Node));
	if (NULL == NewNode)
	{
		assert(0);
		return NULL;
	}
	NewNode->_data = data;
	NewNode->_Next = NULL;
	NewNode->_Pre = NULL;
	return NewNode;
}
//双向链表的销毁
void NListDestory(Node** pHead)
{
	assert(pHead);
	Node* pCur = (*pHead)->_Next; 
	Node* tmp =NULL;
	while (pCur!=(*pHead))
	{
		tmp = pCur;
		//free(tmp);
		pCur = pCur->_Next;
		free(tmp);
	}
	free(pCur);
	*pHead = NULL;
	
}
//头插
//先把新节点连接到链表，再破坏链表结构
void NlistPushFront(Node* pHead, DLDataType data)
{
	assert(pHead);
	Node* NewNode = BuyNode(data);
	//链表中没有节点
    if (pHead->_Next == pHead)
	{
		pHead->_Next = NewNode;
		NewNode->_Next = pHead;
		pHead->_Pre = NewNode;
		NewNode->_Pre = pHead;
	}
	else
		//链表中有节点
	{
		NewNode->_Next = pHead->_Next;
		NewNode->_Pre = pHead;
		pHead->_Next->_Pre = NewNode;
		
		pHead->_Next = NewNode;
	}
}
//头删
void NlistPopFront(Node* pHead)
{
	assert(pHead);
	Node* pCur = pHead->_Next;
	if (pHead->_Next == pHead)
		return;//没得删
	pHead->_Next = pHead->_Next->_Next;
	pHead->_Next->_Next->_Pre = pHead;
	free(pCur);
}
//尾插
//先把新节点连接到链表，再破坏链表结构
void NListPushBack(Node* pHead,DLDataType data)
{
	assert(pHead);
	if (pHead == NULL)
		return;
	else
	{
		Node* NewNode = BuyNode(data);
		NewNode->_Next = pHead;
		NewNode->_Pre = pHead->_Pre;
		pHead->_Pre->_Next = NewNode;
		pHead->_Pre = NewNode;
	}

}
//尾删
void NListPopBack(Node* pHead)
{
	assert(pHead);
	if (pHead->_Next == pHead)
		return;//没得删
	else
	{
		Node* pCur = pHead->_Pre;
		pHead->_Pre->_Pre->_Next = pHead;
		pHead->_Pre = pHead->_Pre->_Pre;
		free(pCur);
	}

}
//查找值为data的节点 ，返回该节点的地址，否则返回空
Node* DListFind(Node* pHead, DLDataType data)
{
	assert(pHead);
	Node* pCur = pHead->_Next;
	while (pCur != pHead)
	{
		if (pCur->_data == data)
		{
			return pCur;
		}
		pCur = pCur->_Next;
	}
	return NULL;
}
//在pos位置插入(前插)为data的节点
void DListInsert(Node* pos, DLDataType data)
{
	Node* NewNode = NULL;
	assert(pos);
	if (pos == NULL)
		return;
	else
	{
		Node* NewNode = BuyNode(data);
		NewNode->_Pre = pos->_Pre;
		NewNode->_Next = pos;
		pos->_Pre->_Next = NewNode;
		pos->_Pre = NewNode;
	}
}
//删除pos位置为data的值
void DListErase(Node* pHead, Node* pos)
{
	assert(pHead);
	assert(pos);
	if (pos == NULL)
		return;
	else
	{
		Node* pCur = pos;
		pos->_Next->_Pre = pos->_Pre;
		pos->_Pre->_Next = pos->_Next;
		
		free(pCur);
	}
}
//删除值为data的节点
void DListRemove(Node* pHead, DLDataType data)
{
	assert(pHead);
	//Node* pCur = DListFind(pHead, data);
	if (NULL == DListFind(pHead, data))
		return;//找不到
	else
		DListErase(pHead, DListFind(pHead, data));

}
//删除所有值为data的节点
void DListRemoveAll(Node* pHead, DLDataType data)
{
	assert(pHead);
	while (NULL != DListFind(pHead, data))
	//if (NULL == DListFind(pHead, data))
	//	return;
	//else
	{
		DListErase(pHead, DListFind(pHead, data));
	}
}