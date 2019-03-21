#define _CRT_SECURE_NO_WARNINGS 1


#pragma once
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<string.h>
#include"栈\栈\Stack.h"


typedef char BTDataType;
typedef struct BTNode
{
	BTDataType data;
	struct BTNode* left;
	struct BTNode* right;
}Node;
Node* BuyNode(BTDataType val);
Node* BTcreat(BTDataType* arr, int size, int* index);
////先序遍历
void PreOrderTree(Node* root);
//
//void PreOrderTreeNor(BTNode* root);
//中序遍历
void InOrderTree(Node* root);
//后序遍历
void PostOrderTree(Node* root);
//二叉树的深度
int MaxDepth(Node* root);
int SizeBtree(Node *Bt);//求总节点的个数
int BalaceBt(Node* root);//检测是否为平衡树
int Leafsize(Node* root);//获取叶子节点的个数
int KsizeBt(Node* root, int k);//求第K层结点个数
Node* FindvalBt(Node* root, BTDataType val);//找值为val的结点，返回它的地址
Node* ParentfindBt(Node* root, BTDataType val);//找一个结点的双亲
////销毁二叉树
void DestroyBinTree(Node* root);
void TEST();

