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


//������
void CreateHeap(Heap* root, HPDataType* array, int size, CMP cmp);

//�ڶ��в���ֵΪdata��Ԫ��
void InserHeap(Heap* root, HPDataType data,CMP cmp);
//��ȡ�Ѷ�Ԫ��
HPDataType TopHeap(Heap* root);
//��ȡ����Ԫ�صĸ���
int SizeHeap(Heap* root);
//���һ�����Ƿ�Ϊ�ն�
int EmptyHeap(Heap* root);
////ɾ���Ѷ�Ԫ��
void DeleteHeapFront(Heap* root,CMP cmp);
//�ѵ�����
void DestroyHeap(Heap* root,CMP cmp);





//void AddData(HpDataType ret, heap *hp);//
//oid Addcatacity(heap *hp);
//void Heapafterdelete(Heap * root);//�ѵ����һ��Ԫ�ص�ɾ��
//
//
//
//
//void HeapPrint(Heap *root);//��ӡ����
void TestHeap();