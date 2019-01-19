#include"SeqList.h"



void SeqListInit(PSeqList ps)
{
	assert(ps);
	ps->_array = (DataType*)malloc(sizeof(DataType)* 3);
	if (ps->_array == NULL)
	{
		assert(0);
		return;
	}
	else
	{
		ps->_capacity = 3;
		ps->_size = 0;
	}
	
}
//检查容量
void CheckCapacity(SeqList* ps)
{
	assert(ps);
	if (ps->_size == ps->_capacity)
	{
		int Newcapacity = ps->_capacity * 2;
		DataType* tmp = (DataType*)malloc(sizeof(DataType) * Newcapacity);
		if (tmp == NULL)
		{
			assert(0);
			return;
		}
		else
		{
			memcpy(tmp, ps->_array, ps->_size*sizeof(DataType));
			free(ps->_array);
			ps->_capacity = Newcapacity;
			ps->_array = tmp;

		}
	}
}
void SeqListDestroy(PSeqList ps)
{
	assert(ps);
	if (ps->_size)
	{
		free(ps->_array);
		ps->_array = NULL;
		ps->_capacity = 0;
		ps->_size = 0;
		printf("销毁成功\n");
	}
	
	
}
// 尾插 
void SeqListPushBack(PSeqList ps, DataType data)
{
	assert(ps);
	CheckCapacity(ps);
	ps->_array[ps->_size] = data;
	ps->_size++;
}
// 尾删 
void SeqListPopBack(PSeqList ps)
{
	assert(ps);
	if (ps->_size == 0)
		return;
	else
	{
		ps->_size--;
	}
	
	
}
// 头插 
void SeqListPushFront(PSeqList ps, DataType data)
{
	assert(ps);
	CheckCapacity(ps);
	for (int i = ps->_size - 1; i >= 0; i--)
	{
		ps->_array[i+1] = ps->_array[i];
		
	}
	ps->_array[0] = data;
	ps->_size++;
	
}
// 头删 
void SeqListPopFront(PSeqList ps)
{
	assert(ps);
	if (ps->_size == 0)
		return;
	for (int i = 1; i < ps->_size; i++)
	{
		ps->_array[i - 1] = ps->_array[i];
	}
	ps->_size--;
}
// 任意位置插入 
void SeqListInsert(PSeqList ps, int pos, DataType data)
{
	assert(ps);
	CheckCapacity(ps);
	for (int i = ps->_size - 1; i >= pos; i--)
	{
		ps->_array[i+1] = ps->_array[i];
	}
	ps->_array[pos] = data;
	ps->_size++;
}
// 任意位置删除 
void SeqListErase(PSeqList ps, int pos)
{
	assert(ps);
	if (ps->_size == 0)
		return;
	for (int i = pos; i < ps->_size; i++)
	{
		ps->_array[i] = ps->_array[i+1];
	}
	ps->_size--;
}
// 检测data是否在顺序表中 
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
	int ret =SeqListFind(ps, data);
	if (ret == -1)
	{
		printf("顺序表中无此元素\n");
	}
	SeqListErase(ps, ret);
	
}
// 移除顺序表中所有值为data的元素 
void SeqListRemoveAll(PSeqList ps, DataType data)
{
	assert(ps);
	int ret = SeqListFind(ps, data);
	if (ret == -1)
	{
		printf("顺序表中无此元素\n");
	}
	else
	for (int i = 0; i < ps->_size - 1; i++)
	{
		if (ps->_array[i] == data)
		{
			SeqListErase(ps, i);
		}
	}
	
}
// 获取顺序表有效元素个数 
int SeqListSize(PSeqList ps)
{
	assert(ps);
	return ps->_size;
}
// 获取顺序表的容量 
int SeqListCapacity(PSeqList ps)
{
	assert(ps);
	return ps->_capacity;
}
// 检测顺序表是否为空 
int SeqListEmpty(PSeqList ps)
{
	assert(ps);
	if (ps->_size == 0)
		return 0;
	return ps->_array;
}
// 获取顺序表中第一个元素 
DataType SeqListFront(PSeqList ps)
{
	assert(ps);
	return ps->_array[0];
}
// 获取顺序表中最后一个元素 
DataType SeqListBack(PSeqList ps)
{
	assert(ps);
	return ps->_array[ps->_size - 1];
}
