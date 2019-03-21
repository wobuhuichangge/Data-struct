#define _CRT_SECURE_NO_WARNINGS 1


#pragma once
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<string.h>
#include"ջ\ջ\Stack.h"


typedef char BTDataType;
typedef struct BTNode
{
	BTDataType data;
	struct BTNode* left;
	struct BTNode* right;
}Node;
Node* BuyNode(BTDataType val);
Node* BTcreat(BTDataType* arr, int size, int* index);
////�������
void PreOrderTree(Node* root);
//
//void PreOrderTreeNor(BTNode* root);
//�������
void InOrderTree(Node* root);
//�������
void PostOrderTree(Node* root);
//�����������
int MaxDepth(Node* root);
int SizeBtree(Node *Bt);//���ܽڵ�ĸ���
int BalaceBt(Node* root);//����Ƿ�Ϊƽ����
int Leafsize(Node* root);//��ȡҶ�ӽڵ�ĸ���
int KsizeBt(Node* root, int k);//���K�������
Node* FindvalBt(Node* root, BTDataType val);//��ֵΪval�Ľ�㣬�������ĵ�ַ
Node* ParentfindBt(Node* root, BTDataType val);//��һ������˫��
////���ٶ�����
void DestroyBinTree(Node* root);
void TEST();

