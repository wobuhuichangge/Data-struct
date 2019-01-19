#include<stdio.h>
#define MAXSIZE 10
typedef int DataType;
//静态顺序表
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

// 尾插
void SeqListPushBack(PSeqList ps, DataType data)
{
	assert(ps);
	//检查空间
	ps->_array[ps->_size++] = data;
	ps->_size++;
}
//尾删
void SeqListPopBack(PSeqList ps)
{
	assert(ps);
	if (ps->_size <= 0)
	{
		printf("当前顺序表为空，无法删除\n");
		return;
	}
	ps->_size--;

}
// 头插 
void SeqListPushFront(PSeqList ps, DataType data)
{
	assert(ps);
	//检查空间
	for (int i = ps->_size - 1; i >= 0; i--)
	{
		ps->_array[i] = ps->_array[i + 1];
	}
	ps->_array[0] = data;
	ps->_size++;
}
// 头删 
void SeqListPopFront(PSeqList ps)
{
	assert(ps);
	for (int i = 1; i < ps->_size; i++)
	{
		ps->_array[i] = ps->_array[i - 1];
	}
	ps->_size--;
}
// 任意位置插入 
void SeqListInsert(PSeqList ps, int pos, DataType data)
{
	assert(ps);
	//检查空间
	for (int i = ps->_size - 1; i >= pos; i--)
	{
		ps->_array[i] = ps->_array[i + 1];
	}
	ps->_array[pos] = data;
	ps->_size++;
}

// 任意位置删除 
void SeqListErase(PSeqList ps, int pos)
{
	assert(ps);
	for (int i = pos; i < ps->_size; i++)
	{
		ps->_array[i+1] = ps->_array[i];
	}
	ps->_size--;
}
// 检测data释放在顺序表中 
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
// 移除顺序表中第一个值为data的元素 
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

// 移除顺序表中所有值为data的元素 
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


// 获取顺序表有效元素个数 
int SeqListSize(PSeqList ps)
{

}


// 获取顺序表的容量 
int SeqListCapacity(PSeqList ps);

// 检测顺序表是否为空 
int SeqListEmpty(PSeqList ps);

// 获取顺序表中第一个元素 
DataType SeqListFront(PSeqList ps);

// 获取顺序表中最后一个元素 
DataType SeqListBack(PSeqList ps);
////////////////////////////////////// 
// 
void PrintSeqList(PSeqList ps);