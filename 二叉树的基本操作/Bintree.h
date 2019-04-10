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
////先序遍历
void PreOrderTree(BTNode* root);
//
void PreOrderTreeNor(BTNode* root);
//中序遍历
void InOrderTree(BTNode* root);
void InOrderTreeNor(BTNode* root);
//后序遍历
void PostOrderTree(BTNode* root);
void PostOrderNorTree(BTNode* root);
//二叉树的深度
int MaxDepth(BTNode* root);
int SizeBtree(BTNode *Bt);//求总节点的个数
int BalaceBt(BTNode* root);//检测是否为平衡树
int Leafsize(BTNode* root);//获取叶子节点的个数
int KsizeBt(BTNode* root, int k);//求第K层结点个数
BTNode* FindvalBt(BTNode* root, BTDataType val);//找值为val的结点，返回它的地址
void Mirror(BTNode* root);
BTNode* ParentfindBt(BTNode* root, BTDataType val);//找一个结点的双亲
BTNode* CopyBinTree(BTNode* root);//拷贝二叉树
////销毁二叉树
void DestroyBinTree(BTNode* root);
void LevelOrder(BTNode* root);//层序遍历
void TEST();

