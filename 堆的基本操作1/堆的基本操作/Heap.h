#define _CRT_SECURE_NO_WARNINGS 1
#pragma once
#include <stdio.h>
#include<assert.h>
#include<malloc.h>
#include<stdlib.h>

typedef int HPDataType;
typedef int (*CMP) (HPDataType left, HPDataType right);
typedef struct Heap
{
	HPDataType* _array;
	int _capacity;
	int _size;
	CMP _cmp;
}Heap;
int Greater(HPDataType left, HPDataType right);
int Less(HPDataType left, HPDataType right);


//创建堆
void CreateHeap(Heap* root, HPDataType* array, int size, CMP cmp);

//在堆中插入值为data的元素
void InserHeap(Heap* root, HPDataType data,CMP cmp);
//获取堆顶元素
HPDataType TopHeap(Heap* root);
//获取堆中元素的个数
int SizeHeap(Heap* root);
//检测一个堆是否为空堆
int EmptyHeap(Heap* root);
////删除堆顶元素
void DeleteHeapFront(Heap* root,CMP cmp);
//堆的销毁
void DestroyHeap(Heap* root,CMP cmp);





//void AddData(HpDataType ret, heap *hp);//
//oid Addcatacity(heap *hp);
//void Heapafterdelete(Heap * root);//堆的最后一个元素的删除
//
//
//
//
//void HeapPrint(Heap *root);//打印函数
void TestHeap();