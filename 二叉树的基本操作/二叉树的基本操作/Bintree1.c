#include"Bintree.h"





Node* BuyNode(BTDataType val)
{
	Node* ret = NULL;
	ret = (Node*)malloc(sizeof(Node));
	if (NULL == ret)
		assert(0);
	ret->data = val;
	ret->left = NULL;
	ret->right = NULL;
	return ret;
}
//创建二叉树  
//利用前序遍历原理
Node* BTcreat(BTDataType* arr, int size, int* index)
{
	Node* root = NULL;
	assert(arr);
	assert(index);
	while (*index < size && arr[*index] != '#' && arr[*index] != '\0')
	{
		root = BuyNode(arr[*index]);
		++(*index);
		root->left = BTcreat(arr, size, index);
		++(*index);
		root->right = BTcreat(arr, size, index);
	}
	return root;
}
//遍历
//先序遍历NLR
//递归
void PreOrderTree(Node* root)
{
	
	if (root)
	{
		printf("%c ", root->data);
		PreOrderTree(root->left);
		PreOrderTree(root->right);
	}
	
	
}
非递归
void PreOrderTreeNor(Node* root)
{
	Stack s;
	char ret;
	char tmp;
	Node* pCur = root;
	StackInit(&s);
	assert(root);
	if (NULL == root)
		return;
	StackPush(&s, root->data);
	while (StackEmpty(&s)!= 0)
	{

		ret = StackTop(&s);
		StackPop(&s);
		printf("%c ", ret);

		if (pCur->right)
			StackPush(&s, pCur->right->data);
			
		
		if (pCur->left)
			StackPush(&s, pCur->left->data);
		tmp = StackTop(&s);
		pCur = FindvalBt(root,tmp);
	}
}
//中序遍历LNR
void InOrderTree(Node* root)
{

	if (NULL == root)
		return;
	InOrderTree(root->left);
	printf("%c ", root->data);
	InOrderTree(root->right);
	
}
//后序遍历
void PostOrderTree(Node* root)
{
	
	if (NULL == root)
		return;
	PostOrderTree(root->left);
	PostOrderTree(root->right);
	printf("%c ", root->data);
	
}
////层序遍历
////void 
//二叉树的深度
int MaxDepth(Node* root)
{
	//assert(root);
	if (NULL == root)
		return 0;
	if (root->left == NULL && root->right == NULL)//多余吗？
		return 1;
	return MaxDepth(root->left) > MaxDepth(root->right) ? MaxDepth(root->left) + 1 : MaxDepth(root->right) + 1;
}

int SizeBtree(Node* root)//求总节点的个数
{
	//assert(root);
	if (NULL == root)
		return 0;
	return 1 + SizeBtree(root->left) + SizeBtree(root->right);
}
int BalaceBt(Node* root)//检测是否为平衡树
{
	//assert(root);
	if (NULL == root || (root->left == NULL &&root->right == NULL))
		return 1;
	if (BalaceBt(root->left) && BalaceBt(root->right) && abs(MaxDepth(root->left) - MaxDepth(root->right)))
		return 1;
	return 0;
}
int Leafsize(Node* root)//获取叶子节点的个数
{
	//assert(root);
	if (NULL == root)
		return 0;
	if (root->left == NULL&&root->right == NULL)
		return 1;
	return Leafsize(root->left) + Leafsize(root->right);
}
int KsizeBt(Node* root, int k)//求第K层结点个数
{
	//assert(root);
	if (NULL == root||k<1)
		return 0;
	if (k = 1)
		return 1;
	return KsizeBt(root->left, k - 1) + KsizeBt(root->right, k - 1);
}
//找值为val的结点，返回它的地址
Node* FindvalBt(Node* root, BTDataType val)
{
	//assert(root);
	if (NULL == root)
		return NULL;
	if (root->data == val)
		return root;
	if (FindvalBt(root->left,val) != NULL)
		return root->left;
	return FindvalBt(root->right, val);
}
Node* ParentfindBt(Node* root, BTDataType val)//找一个结点的双亲
{
	Node* ret = NULL;
	//assert(root);
	if (root == NULL||root->data == val)
		return NULL;
	if (root->left->data == val||root->right->data == val)
		return root;
	ret = ParentfindBt(root->left, val);
	if (NULL == ret)
		ret = ParentfindBt(root->right, val);
	return ret;
}
//销毁二叉树
void DestroyBinTree(Node* root)
{
	
	//assert(root);
	if (NULL == (root))
		return;
	DestroyBinTree(root->left);
	DestroyBinTree(root->right);
	free(root);
	root = NULL;
}

void TEST()
{
	Node* bt = NULL;
	Node* ret1 = NULL;
	BTDataType arr[] = "ABD###CE##F";

	int index = 0; 
	bt = BTcreat(arr, (sizeof(arr) / sizeof(arr[0])), &index);
	printf("前序遍历：\n");
	PreOrderTree(bt);
	printf("\n");
	printf("前序非递归遍历：\n");
	PreOrderTreeNor(bt);
	printf("\n");
	printf("中序遍历：\n");
	InOrderTree(bt);
	printf("\n");
	printf("后序遍历：\n");
	PostOrderTree(bt);
	printf("\n");

	//MaxDepth(bt);
	//printf("二叉树的深度: %d \n", MaxDepth(bt));
	//printf("二叉树的结点个数: %d \n", SizeBtree(bt));
	//printf("二叉树是否为平衡树: %d \n", BalaceBt(bt));
	//printf("二叉树叶子结点的个数: %d \n", Leafsize(bt));
	//printf("二叉树第K层结点的个数: %d \n", KsizeBt(bt,2));
	//ret1 = FindvalBt(bt, 'G');
	//printf("%d\n", ret1);
	//ret1 = ParentfindBt(bt, 'D');
	//printf("%d\n", ret1);
	DestroyBinTree(bt);
	printf("销毁成功 \n");

}

