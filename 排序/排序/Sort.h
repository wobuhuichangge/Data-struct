#define _CRT_SECURE_NO_WARNINGS 1
#pragma once
#include"Stack.h"
#include"Heap.h"

void InsertSort(int* array, int size);
void ShellSort(int* array, int size);
void SelectSort(int* array, int size);
void SelectSortOP(int* array, int size);
void _HeapSort(int* array, int size,CMP cmp);
void BubbleSort(int* array, int size);
void QuickSort(int* array, int left, int right);
void QuickSortOp(int* array, int left, int right);

void QuickSortNor(int* array, int left, int right);




void PrintfSort(int * array, int size);
void TEST();