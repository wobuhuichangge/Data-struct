
#include"Sort.h"
#include<assert.h>
#include<stdlib.h>
#include<stdio.h>
#include"Stack.h"


void Swap1(int* a, int* b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void InsertSort(int* array, int size)//排升序
{
	assert(array);
	int i = 0;
	int j = 0;
	int key = 0;
	for (i = 1; i < size; i++)
	{
		key = array[i];
		j = i - 1;
		while (j >= 0&&key<array[j])
		{
			array[j + 1] = array[j];
			j--;
		}
		array[j + 1] = key;
	}
}
void ShellSort(int* array, int size)
{
	assert(array);
	int gap = size / 3 - 1;
	int i = 0;
	while (gap > 0)
	{
		for (i = 0; i < size; i++)
		{
			if (i + gap <size &&array[i]>array[i + gap])
				Swap1(&array[i], &array[i + gap]);
		}
		gap -= 1;
	}
}
void SelectSort(int* array, int size)
{
	assert(array);
	int max = 0;
	int i = 0;
	int j = 0;
	//趟数
	for (i = 0; i < size - 1; i++)
	{
		max = 0;

		for (j = 1; j < size - i; j++)
		{
			if (array[j]>array[max])
				max = j;
		}
		//若最大元素不是这组中的最后一个元素
		if (max != j - 1)
			Swap1(&array[j - 1], &array[max]);
	}
}
void SelectSortOP(int* array, int size)
{
	int max;
	int min;
	int i = 0;
	int left = 0;
	int right = size - 1;
	while (left < right)//控制趟数
	{
		max = left;
		min = left;
		for (i = left; i <= right; i++)
		{
			if (array[i]>array[max])
				max = i;
			if (array[i] < array[min])
				min = i;
		}

		if (max != right)
			Swap1(&array[max], &array[right]);
		//if (min == right)//如果最右边的是最小值
			min = max;
		if (min != left)
			Swap1(&array[min], &array[left]);
		++left;
		--right;
	}
}
//void _HeapSort(int* array, int size,CMP cmp)
//{
//	int i = 0;
//	assert(array);
//	Heap hp;
//	CreateHeap(&hp, array, size, cmp);
//	HeapPrint(&hp);
//	HeapSort(&hp, size, cmp);
//	HeapPrint(&hp);
//}
void BubbleSort(int* array, int size)
{
	assert(array);
	int i = 0;
	int j = 0;
	for (i = 0; i < size ; i++)
	{
		for (j = 0; j < size - 1 - i; j++)
		{
			if (array[j]>array[j + 1])
				Swap1(&array[j], &array[j + 1]);
		}
	}
}
void BubbleSortOP(int* array, int size)
{
	assert(array);
	int i = 0;
	int j = 0;
	int tmp = 0;
	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size - 1 - i; j++)
		{
			if (array[j]>array[j + 1])
			{
				tmp = 1;
				Swap1(&array[j], &array[j + 1]);
			}
		}
		if (tmp == 0)
			break;
	}
}



int PartSort(int* array, int left, int right)
{
	int key = array[right-1];
	int end = right - 1;
	int begin = left;
	while (begin < end)
	{
		while (begin < end && array[begin] <= key)
		{
			++begin;
		}
		while (begin < end && array[end] >= key)
		{
			--end;
		}
		if (begin < end)
			Swap1(&(array[begin]), &(array[end]));
	}
	Swap1(&(array[begin]), &(array[right -1]));
	return begin;
}
//挖坑
int PartSort1(int* array, int left, int right)
{
	int end = right - 1;
	int key = array[end];//
	while (left < end)
	{
		while (left < end&&array[left] <= key)
		{
			++left;
		}
		array[end] = array[left];
		while (left < end&&array[end] >= key)
		{
			--end;
		}
		array[left] = array[end];
	}
	array[end] = key;
	return end;
}

int PartSort2(int* array, int left, int right)
{
	int end = right - 1;
	int key = array[end];
	
	int pCur = left;
	int prev = pCur - 1;
	while (pCur < end)
	{
		if (array[pCur] < key && ++prev != pCur)
		{
			Swap1(&(array[pCur]), &(array[prev]));
		}
		pCur++;
	}
	if (++prev != right - 1)
		Swap1(&array[prev], &array[right - 1]);
	return prev;
}
int GetIndexOfMid(int* array, int left, int right)
{
	int mid = left + (right - left) / 2;
	if (array[left] > array[right])
	{
		if (array[mid] > array[left])
			return left;
		else if (array[mid] < array[right])
			return right;
		else
			return mid;

	}
	else
	{
		if (array[mid]>array[right])
			return right;
		else if (array[mid] < array[left])
			return left;
		else
			return mid;
	}
}
int PartSort3(int* array, int left, int right)
{
	
	int end = right - 1;
	int begin = left;
	int index = GetIndexOfMid(array, left, end);
	Swap1(&array[index], &array[right - 1]);
	int key = array[right - 1];
	while (begin < end)
	{
		while (begin < end && array[begin] <= key)
		{
			++begin;
		}
		while (begin < end && array[end] >= key)
		{
			--end;
		}
		if (begin < end)
			Swap1(&(array[begin]), &(array[end]));
	}
	Swap1(&(array[begin]), &(array[right - 1]));
	return begin;
}


//void QuickSort(int* array, int left, int right)
//{
//	int pos;
//	if (right-left>1)
//	{
//		pos = PartSort2(array, left, right);
//		QuickSort(array, left, pos);
//		QuickSort(array, pos + 1, right);
//	}
//}
void QuickSortOp(int* array, int left, int right)
{
	int pos = 0;
	//if (right - left < 16)
	//	InsertSort(array, right - left);
	//else
	if (right - left >1)
	{
		pos = PartSort3(array, left, right);
		QuickSortOp(array, left, pos);
		QuickSortOp(array, pos + 1, right);
	}
}

////非递归快速排序
//void QuickSortNor(int* array, int left,int right)
//{
//	Stack s;
//	StackInit(&s);
//	StackPush(&s, left);
//	StackPush(&s, right);
//	while (StackEmpty(&s) != 0)
//	{
//		int right = StackTop(&s);
//		StackPop(&s);
//		int left = StackTop(&s);
//		StackPop(&s);
//		int pos = PartSort(array, left, right);
//		if (pos>left)
//		{
//			StackPush(&s, left);
//			StackPush(&s, pos );
//		}
//		if ((pos+1) < right)
//		{
//			StackPush(&s, pos+1);
//			StackPush(&s, right);
//		}
//	}
//}



void PrintfSort(int * array, int size)
{
	int i = 0;
	for (i = 0; i < size; i++)
	{
		printf("%d ", array[i]);
	}
	printf("\n");
}
void TEST()
{
	int array[10] = { 8,7, 2, 9, 4, 6,0, 1, 3 ,5};
	int size = sizeof(array) / sizeof(array[0]);
	//InsertSort(array, size);
	//PrintfSort(array, size);
	//ShellSort(array, size);
	//PrintfSort(array, size);
	//SelectSort(array, size);
	//PrintfSort(array, size);
	//SelectSortOP(array, size);
	//QuickSort(array, 0, size);
	QuickSortOp(array, 0, size);
	//QuickSortNor(array, 0, size);
	PrintfSort(array, size);
	/*_HeapSort(array, size, Less);*/
}