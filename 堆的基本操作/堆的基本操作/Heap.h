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
//������
void CreateHeap(Heap* root, HPDataType* array, int size);

//�ڶ��в���ֵΪdata��Ԫ��
void InserHeap(Heap* root, HPDataType data);
//��ȡ�Ѷ�Ԫ��
HPDataType TopHeap(Heap* root);
//��ȡ����Ԫ�صĸ���
int SizeHeap(Heap* root);
//���һ�����Ƿ�Ϊ�ն�
int EmptyHeap(Heap* root);
////ɾ���Ѷ�Ԫ��
void DeleteHeapFront(Heap* root);
//�ѵ�����
void DestroyHeap(Heap* root);





//void AddData(HpDataType ret, heap *hp);//
//oid Addcatacity(heap *hp);
//void Heapafterdelete(Heap * root);//�ѵ����һ��Ԫ�ص�ɾ��
//
//
//
//
//void HeapPrint(Heap *root);//��ӡ����
void TestHeap();