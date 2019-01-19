#include "SList.h"
//链表初始化
void SListInit(SList* pl)
{
	assert(pl);
	pl->_pHead = NULL;
	
}
 //销毁链表 
void SListDestroy(SList* pl)
{
	assert(pl);
	Node* pCur = pl->_pHead;
	Node* pos = NULL;
	while (pCur)
	{
		pos = pCur;
		pCur = pCur->_pNEXT;
		free(pos);
	}
	pl->_pHead = NULL;//防止pl->_pHead 成为野指针！
}
 
Node* BuySListNode(SDataType data)
{
	Node* pNode = (Node*)malloc(sizeof(Node));
	if (pNode == NULL)
	{
		return NULL;
	}
	pNode->_data = data;
	pNode->_pNEXT = NULL;
	return pNode;
}
// 在链表中尾插值为data的节点
void SListPushBack(SList* pl, SDataType data)
{
	Node* pNewNode = NULL;
	Node* pCur = pl->_pHead;
	assert(pl);
	pNewNode = BuySListNode(data);
	if (pl->_pHead == NULL)
	{
		pl->_pHead = pNewNode;
		
	}
	else if (pl->_pHead->_pNEXT == NULL)
	{
		pl->_pHead->_pNEXT = pNewNode;
	}
	else
	{
		while (pCur->_pNEXT != NULL)
		{
			
			pCur = pCur->_pNEXT;
		}
		pCur->_pNEXT = pNewNode;
	}
	
}



// 删除链表最后一个节点 
void SListPopBack(SList* pl)
{

	assert(pl);
	Node* pCur = pl->_pHead;
	if (pl->_pHead == NULL)
		return;
	else if (pl->_pHead->_pNEXT == NULL)
	{
		free(pCur);
		pl->_pHead = NULL;
	}
	else  
	{
		while (pCur->_pNEXT->_pNEXT)
		{
			pCur = pCur->_pNEXT;
		}
		free(pCur->_pNEXT);
		pCur->_pNEXT = NULL;
	}
}
// 在链表第一个元素前插入值为data的节点 
void SListPushFront(SList* pl, SDataType data)
{
	Node* pNewNode = NULL;
	assert(pl);
	Node* pCur = pl->_pHead;
	pNewNode = BuySListNode(data);
	if (pl->_pHead == NULL)
	{
		pl->_pHead = pNewNode;
	}
	else

		pl->_pHead = pNewNode;
	    pNewNode->_pNEXT = pCur;

}

// 删除链表中第一个节点 
void SListPopFront(SList* pl)
{
	assert(pl);
	if (pl->_pHead == NULL)
	{
		return;
	}
	else if (pl->_pHead->_pNEXT == NULL)
	{
		free(pl->_pHead);
		pl->_pHead = NULL;
	}
	else
	{
		Node* pCur = pl->_pHead->_pNEXT;
		free(pl->_pHead);
		pl->_pHead = pCur;
	}
}

// 在链表中查找值为data的节点，找到返回该节点的地址，否则返回空 
Node* SListFind(SList* pl, SDataType data)
{
	assert(pl);
	Node* pCur = pl->_pHead;
	while (pCur)
	{
		if (pCur->_data == data)
		{
			return pCur;
		}
		pCur = pCur->_pNEXT;
	}
	return NULL;
}

// 在链表pos位置后插入置为data的节点 
void SListInsertAfter(Node* pos, SDataType data)
{
	Node* pNewNode = NULL;
	assert(pos);
	pNewNode = BuySListNode(data);
	if (pos == NULL)
		return;
	else
	{
		pNewNode->_pNEXT = pos->_pNEXT;
		pos->_pNEXT= pNewNode;
	}
}

// 删除链表中值为data的节点 
void SListErase(SList* pl, Node* pos)
{
	assert(pl);
	assert(pos);
	Node* pCur = pl->_pHead;
	if (pl->_pHead == NULL)
		return;
	else if (pCur == pos)
	{
		pl->_pHead = pos->_pNEXT;
		free(pos);
		pos = NULL;
	}
	else
	{
		while (pCur)
		{
			if (pCur->_pNEXT == pos)
			{
				break;
			}
			pCur = pCur->_pNEXT;
		}
		pCur->_pNEXT = pos->_pNEXT;
		free(pos);
	}
	
	/*pCur = pos->_pNEXT->_pNEXT;
	free(pos->_pNEXT);
	pos->_pNEXT = pCur;*/
}


// 获取链表中有效节点的个数 
int SListSize(SList* pl)
{
	assert(pl);
	int count = 0;
	Node* pCur = pl->_pHead;
	while (pCur)
	{
		count++;
		pCur = pCur->_pNEXT;
	}
	return count;
}
// 检测链表是否为空 
int SListEmpty(SList* pl)
{
	assert(pl);
	if (pl->_pHead == NULL)
	{
		return 1;
	}
	else
		return 0;
}
// 获取链表的第一个节点 
Node* SListFront(SList* pl)
{
	return pl->_pHead;
}

// 获取链表的第二个节点 
Node* SListBack(SList* pl)
{
	return pl->_pHead->_pNEXT;
}
void SListRemove(SList* pl, SDataType data)
{
	assert(pl);
	SListErase(pl, SListFind(pl, data));
}
void SListRemoveAll(SList* pl, SDataType data)
{
	assert(pl);
	int count = 0;
	Node* pCur = pl->_pHead;
	while (pCur)
	{
		if (pCur->_data == data)
		{
			count++;

		}
		pCur = pCur->_pNEXT;
	}
	while (count--)
	{
		SListRemove(pl, data);
	}

}