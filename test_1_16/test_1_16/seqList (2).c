#include<stdio.h>
#define MAXSIZE 10
typedef int DataType;
//��̬˳���
struct SeqList
{
	DataType array[MAXSIZE];
	int size;
};
//typedef struct SeqList SeqList;
typedef struct SeqList
{
	DataType *_array;
	int _size;
	int _capacity;
}SeqList, *PSeqList;

//void SeqListInit(PSeqList ps)
//{
//	ps->_array = NULL;
//	ps->_capacity = 0;
//	ps->_size = 0;
//}
//void SeqListDestroy(PSeqList ps)
//{
//
//}

// β��
void SeqListPushBack(PSeqList ps, DataType data)
{
	assert(ps);
	//���ռ�
	ps->_array[ps->_size++] = data;
	ps->_size++;
}
//βɾ
void SeqListPopBack(PSeqList ps)
{
	assert(ps);
	if (ps->_size <= 0)
	{
		printf("��ǰ˳���Ϊ�գ��޷�ɾ��\n");
		return;
	}
	ps->_size--;

}
// ͷ�� 
void SeqListPushFront(PSeqList ps, DataType data)
{
	assert(ps);
	//���ռ�
	for (int i = ps->_size - 1; i >= 0; i--)
	{
		ps->_array[i] = ps->_array[i + 1];
	}
	ps->_array[0] = data;
	ps->_size++;
}
// ͷɾ 
void SeqListPopFront(PSeqList ps)
{
	assert(ps);
	for (int i = 1; i < ps->_size; i++)
	{
		ps->_array[i] = ps->_array[i - 1];
	}
	ps->_size--;
}
// ����λ�ò��� 
void SeqListInsert(PSeqList ps, int pos, DataType data)
{
	assert(ps);
	//���ռ�
	for (int i = ps->_size - 1; i >= pos; i--)
	{
		ps->_array[i] = ps->_array[i + 1];
	}
	ps->_array[pos] = data;
	ps->_size++;
}

// ����λ��ɾ�� 
void SeqListErase(PSeqList ps, int pos)
{
	assert(ps);
	for (int i = pos; i < ps->_size; i++)
	{
		ps->_array[i+1] = ps->_array[i];
	}
	ps->_size--;
}
// ���data�ͷ���˳����� 
int SeqListFind(PSeqList ps, DataType data)
{
	assert(ps);
	for (int i = 0; i < ps->_size - 1; i++)
	{
		if (ps->_array[i] == data)
		{
			return i;
		}
	}
	return -1;
}
// �Ƴ�˳����е�һ��ֵΪdata��Ԫ�� 
void SeqListRemove(PSeqList ps, DataType data)
{
	assert(ps);
	for (int i = 0; i < ps->_size - 1; i++)
	{
		if (ps->_array[i] == data)
		{
			SeqListErase(ps, i);
			return;
		}
	}
	return -1;
}

// �Ƴ�˳���������ֵΪdata��Ԫ�� 
void SeqListRemoveAll(PSeqList ps, DataType data)
{
	assert(ps);
	for (int i = 0; i < ps->_size - 1; i++)
	{
		if (ps->_array[i] == data)
		{
			SeqListErase(ps, i);
			ps->_size--;
		}
	}
	return -1;
}


// ��ȡ˳�����ЧԪ�ظ��� 
int SeqListSize(PSeqList ps)
{

}


// ��ȡ˳�������� 
int SeqListCapacity(PSeqList ps);

// ���˳����Ƿ�Ϊ�� 
int SeqListEmpty(PSeqList ps);

// ��ȡ˳����е�һ��Ԫ�� 
DataType SeqListFront(PSeqList ps);

// ��ȡ˳��������һ��Ԫ�� 
DataType SeqListBack(PSeqList ps);
////////////////////////////////////// 
// 
void PrintSeqList(PSeqList ps);