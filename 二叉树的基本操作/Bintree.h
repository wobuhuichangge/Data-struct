#define _CRT_SECURE_NO_WARNINGS 1


#pragma once
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<string.h>



typedef char BTDataType;
typedef struct BTNode
{
	BTDataType data;
	struct BTNode* left;
	struct BTNode* right;
}BTNode;
BTNode* BuyNode(BTDataType val);
BTNode* BTcreat(BTDataType* arr, int size, int* index);
////�������
void PreOrderTree(BTNode* root);
//
void PreOrderTreeNor(BTNode* root);
//�������
void InOrderTree(BTNode* root);
void InOrderTreeNor(BTNode* root);
//�������
void PostOrderTree(BTNode* root);
void PostOrderNorTree(BTNode* root);
//�����������
int MaxDepth(BTNode* root);
int SizeBtree(BTNode *Bt);//���ܽڵ�ĸ���
int BalaceBt(BTNode* root);//����Ƿ�Ϊƽ����
int Leafsize(BTNode* root);//��ȡҶ�ӽڵ�ĸ���
int KsizeBt(BTNode* root, int k);//���K�������
BTNode* FindvalBt(BTNode* root, BTDataType val);//��ֵΪval�Ľ�㣬�������ĵ�ַ
void Mirror(BTNode* root);
BTNode* ParentfindBt(BTNode* root, BTDataType val);//��һ������˫��
BTNode* CopyBinTree(BTNode* root);//����������
////���ٶ�����
void DestroyBinTree(BTNode* root);
void LevelOrder(BTNode* root);//�������
void TEST();

