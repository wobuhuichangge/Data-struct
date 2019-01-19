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
//�������
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
		printf("���ٳɹ�\n");
	}
	
	
}
// β�� 
void SeqListPushBack(PSeqList ps, DataType data)
{
	assert(ps);
	CheckCapacity(ps);
	ps->_array[ps->_size] = data;
	ps->_size++;
}
// βɾ 
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
// ͷ�� 
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
// ͷɾ 
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
// ����λ�ò��� 
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
// ����λ��ɾ�� 
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
// ���data�Ƿ���˳����� 
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
	int ret =SeqListFind(ps, data);
	if (ret == -1)
	{
		printf("˳������޴�Ԫ��\n");
	}
	SeqListErase(ps, ret);
	
}
// �Ƴ�˳���������ֵΪdata��Ԫ�� 
void SeqListRemoveAll(PSeqList ps, DataType data)
{
	assert(ps);
	int ret = SeqListFind(ps, data);
	if (ret == -1)
	{
		printf("˳������޴�Ԫ��\n");
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
// ��ȡ˳�����ЧԪ�ظ��� 
int SeqListSize(PSeqList ps)
{
	assert(ps);
	return ps->_size;
}
// ��ȡ˳�������� 
int SeqListCapacity(PSeqList ps)
{
	assert(ps);
	return ps->_capacity;
}
// ���˳����Ƿ�Ϊ�� 
int SeqListEmpty(PSeqList ps)
{
	assert(ps);
	if (ps->_size == 0)
		return 0;
	return ps->_array;
}
// ��ȡ˳����е�һ��Ԫ�� 
DataType SeqListFront(PSeqList ps)
{
	assert(ps);
	return ps->_array[0];
}
// ��ȡ˳��������һ��Ԫ�� 
DataType SeqListBack(PSeqList ps)
{
	assert(ps);
	return ps->_array[ps->_size - 1];
}
