#include "Queue.h"

void QueueInit(Queue* pq)
{
	assert(pq);
	pq->_front = NULL;
	pq->_rear = NULL;
	
}
void QueueDestory(Queue* pq)
{
	assert(pq);
	free(pq);
	pq->_front = NULL;
	pq->_rear = NULL;
}

QueueNode* BuyQueueNode(QUDataType x)
{
	QueueNode* NewNode = (QueueNode*)malloc(sizeof(QueueNode));
	if (NULL == NewNode)
	{
		assert(0);
	}
	NewNode->_data = x;
	NewNode->_next = NULL;
	return NewNode;
}
//入队列
void QueuePush(Queue* pq, QUDataType x)
{
	assert(pq);
	if (NULL == pq->_front)
	{
		pq->_front = pq->_rear = BuyQueueNode(x);
		return;
	}
	pq->_rear->_next = BuyQueueNode(x);
	pq->_rear = pq->_rear->_next;
}
//出队列
void QueuePop(Queue* pq)
{
	assert(pq);
	QueueNode* tmp = NULL;
	if (NULL == pq->_front)
	{
		return;//没有元素
	}
	if (pq->_front == pq->_rear)
	{
		pq->_rear = NULL;
		pq->_front = NULL;
		return;
	}
	tmp = pq->_front;
	pq->_front = pq->_front->_next;
	free(tmp);
}
QUDataType QueueFront(Queue* pq)
{
	assert(pq);
	return pq->_front->_data;
}
QUDataType QueueBack(Queue* pq)
{
	assert(pq);
	return pq->_rear->_data;
}
int QueueEmpty(Queue* pq)
{
	return NULL == pq->_front;
}
int QueueSize(Queue* pq)
{
	int count = 0;
	QueueNode* pCur;
	assert(pq);
	pCur = pq->_front;
	while (pCur)
	{
		pCur = pCur->_next;
		count++;
	}
	return count;
}
