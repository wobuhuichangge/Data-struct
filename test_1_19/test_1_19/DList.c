#include"DList.h"
//˫������ĳ�ʼ��
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
// ����һ���µĽڵ�
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
//˫�����������
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
//ͷ��
//�Ȱ��½ڵ����ӵ��������ƻ�����ṹ
void NlistPushFront(Node* pHead, DLDataType data)
{
	assert(pHead);
	Node* NewNode = BuyNode(data);
	//������û�нڵ�
    if (pHead->_Next == pHead)
	{
		pHead->_Next = NewNode;
		NewNode->_Next = pHead;
		pHead->_Pre = NewNode;
		NewNode->_Pre = pHead;
	}
	else
		//�������нڵ�
	{
		NewNode->_Next = pHead->_Next;
		NewNode->_Pre = pHead;
		pHead->_Next->_Pre = NewNode;
		
		pHead->_Next = NewNode;
	}
}
//ͷɾ
void NlistPopFront(Node* pHead)
{
	assert(pHead);
	Node* pCur = pHead->_Next;
	if (pHead->_Next == pHead)
		return;//û��ɾ
	pHead->_Next = pHead->_Next->_Next;
	pHead->_Next->_Next->_Pre = pHead;
	free(pCur);
}
//β��
//�Ȱ��½ڵ����ӵ��������ƻ�����ṹ
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
//βɾ
void NListPopBack(Node* pHead)
{
	assert(pHead);
	if (pHead->_Next == pHead)
		return;//û��ɾ
	else
	{
		Node* pCur = pHead->_Pre;
		pHead->_Pre->_Pre->_Next = pHead;
		pHead->_Pre = pHead->_Pre->_Pre;
		free(pCur);
	}

}
//����ֵΪdata�Ľڵ� �����ظýڵ�ĵ�ַ�����򷵻ؿ�
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
//��posλ�ò���(ǰ��)Ϊdata�Ľڵ�
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
//ɾ��posλ��Ϊdata��ֵ
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
//ɾ��ֵΪdata�Ľڵ�
void DListRemove(Node* pHead, DLDataType data)
{
	assert(pHead);
	//Node* pCur = DListFind(pHead, data);
	if (NULL == DListFind(pHead, data))
		return;//�Ҳ���
	else
		DListErase(pHead, DListFind(pHead, data));

}
//ɾ������ֵΪdata�Ľڵ�
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