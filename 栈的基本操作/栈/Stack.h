#define _CRT_SECURE_NO_WARNINGS 1
#pragma once
#include<stdio.h>
#include<assert.h>
#include<malloc.h>
#include<stdlib.h>
#include<string.h>
typedef int SDataType;
typedef struct Stack
{
	SDataType* _array;
	int _capacity;
	int _pos;
}Stack;

void StackInit(Stack* ps);
void StackPush(Stack* ps,SDataType data);
void StackPop(Stack* ps);
int StackEmpty(Stack* ps);
SDataType StackTop(Stack* ps);
void StackDestroy(Stack* ps);