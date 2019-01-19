#include "SList.h"
//�����ʼ��
void SListInit(SList* pl)
{
	assert(pl);
	pl->_pHead = NULL;
	
}
 //�������� 
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
	pl->_pHead = NULL;//��ֹpl->_pHead ��ΪҰָ�룡
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
// ��������β��ֵΪdata�Ľڵ�
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



// ɾ���������һ���ڵ� 
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
// �������һ��Ԫ��ǰ����ֵΪdata�Ľڵ� 
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

// ɾ�������е�һ���ڵ� 
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

// �������в���ֵΪdata�Ľڵ㣬�ҵ����ظýڵ�ĵ�ַ�����򷵻ؿ� 
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

// ������posλ�ú������Ϊdata�Ľڵ� 
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

// ɾ��������ֵΪdata�Ľڵ� 
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


// ��ȡ��������Ч�ڵ�ĸ��� 
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
// ��������Ƿ�Ϊ�� 
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
// ��ȡ����ĵ�һ���ڵ� 
Node* SListFront(SList* pl)
{
	return pl->_pHead;
}

// ��ȡ����ĵڶ����ڵ� 
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