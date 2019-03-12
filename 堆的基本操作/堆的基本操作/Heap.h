#define _CRT_SECURE_NO_WARNINGS 1
#pragma once
#include <stdio.h>
#include<assert.h>
#include<malloc.h>
#include<stdlib.h>

typedef int HPDataType;
typedef struct Heap
{
	HPDataType* _array;
	int _capacity;
	int _size;
}Heap;
//创建堆
void CreateHeap(Heap* root, HPDataType* array, int size);

//在堆中插入值为data的元素
void InserHeap(Heap* root, HPDataType data);
//获取堆顶元素
HPDataType TopHeap(Heap* root);
//获取堆中元素的个数
int SizeHeap(Heap* root);
//检测一个堆是否为空堆
int EmptyHeap(Heap* root);
////删除堆顶元素
void DeleteHeapFront(Heap* root);
//堆的销毁
void DestroyHeap(Heap* root);





//void AddData(HpDataType ret, heap *hp);//
//oid Addcatacity(heap *hp);
//void Heapafterdelete(Heap * root);//堆的最后一个元素的删除
//
//
//
//
//void HeapPrint(Heap *root);//打印函数
void TestHeap();