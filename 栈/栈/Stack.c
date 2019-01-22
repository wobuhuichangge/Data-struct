
#include "Stack.h"
void StackInit(Stack* ps)
{
	assert(ps);
	ps->_array = (SDataType*)malloc(sizeof(SDataType)* 3);
	ps->_capacity = 3;
	ps->_pos = 0;
}

void _Checkcapacity(Stack* ps)
{
	if (ps->_capacity == ps->_pos)
	{
		int Newcap = ps->_capacity * 2;
		SDataType* temp = (SDataType*)malloc(sizeof(SDataType)*Newcap);
		if (NULL == temp)
		{
			assert(0);
			return;
		}
		memcpy(temp, ps->_array, ps->_pos*(sizeof(SDataType)));
		free(ps->_array);
		ps->_array = temp;
		ps->_capacity = Newcap;
	}
}
void StackPush(Stack* ps,SDataType data)
{
	assert(ps);
	_Checkcapacity(ps);
	ps->_array[ps->_pos] = data;
	ps->_pos++;
}
void StackPop(Stack* ps)
{
	assert(ps);
	ps->_pos--;
}

void StackDestory(Stack* ps)
{
	assert(ps);
	
	ps->_capacity = 0;
	ps->_pos = 0;
	free(ps->_array);
	ps->_array = NULL;
}