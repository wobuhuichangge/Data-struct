#include"Bintree.h"

#include"Stack.h"
#include"����\����\Queue.h"

BTNode* BuyNode(BTDataType val)
{
	BTNode* ret = NULL;
	ret = (BTNode*)malloc(sizeof(BTNode));
	if (NULL == ret)
		assert(0);
	ret->data = val;
	ret->left = NULL;
	ret->right = NULL;
	return ret;
}
//����������  
//����ǰ�����ԭ��
BTNode* BTcreat(BTDataType* arr, int size, int* index)
{
	BTNode* root = NULL;
	assert(arr);
	assert(index);
	while (*index < size && arr[*index] != '#'&& arr[*index] != '\0')//array[*index] != '\0'
	{
		root = BuyNode(arr[*index]);
		++(*index);
		root->left = BTcreat(arr, size, index);
		++(*index);
		root->right = BTcreat(arr, size, index);
	}
	return root;
}
//�������
//void LevelOrder(BTNode* root)
//{
//	Queue q;
//	if (NULL == root)
//		return;
//	QueueInit(&q);
//	QueuePush(&q, root);
//	while (!QueueEmpty(&q))
//	{
//		BTNode* pCur = QueueFront(&q);
//		printf("%c ", pCur->data);
//		if (pCur->left)
//			QueuePush(&q, pCur->left);
//		if (pCur->right)
//			QueuePush(&q, pCur->right);
//		QueuePop(&q);
//	}
//	QueueDestory(&q);
//	printf("\n");
//}
//�������NLR
//�ݹ�
//void PreOrderTree(BTNode* root)
//{
//	
//	if (root)
//	{
//		printf("%c ", root->data);
//		PreOrderTree(root->left);
//		PreOrderTree(root->right);
//	}
//		
//}
//ǰ��ǵݹ�
//void PreOrderTreeNor(BTNode* root)
//{
//	Stack s;
//	BTNode* pCur = root;
//	
//	StackInit(&s);
//	if (NULL == root)
//		return;
//	StackPush(&s, pCur);
//	while (StackEmpty(&s)!= 0)
//	{
//
//		pCur = StackTop(&s);
//		StackPop(&s);
//		printf("%c ", pCur->data);
//
//		if (pCur->right)
//			StackPush(&s, pCur->right);
//			
//		
//		if (pCur->left)
//			StackPush(&s, pCur->left);
//		
//		
//	}
//	StackDestroy(&s);
//	printf("\n");
//}
//�������LNR
void InOrderTree(BTNode* root)
{

	if (NULL == root)
		return;
	InOrderTree(root->left);
	printf("%c ", root->data);
	InOrderTree(root->right);
	
}
//����ǵݹ����
void InOrderTreeNor(BTNode* root)
{
	Stack s;
	if (root == NULL)
		return;
	
	StackInit(&s);
	BTNode* pCur = root;
	
	while (pCur  || StackEmpty(&s)!= 0)//ջ�շ���0�����ط�0Ϊ����
	{
		while (pCur)
		{
			StackPush(&s, pCur);
			pCur = pCur->left;
		}
		pCur = StackTop(&s);
		printf("%c ", pCur->data);
		StackPop(&s);

		pCur = pCur->right;
	}
}
//�������
void PostOrderTree(BTNode* root)
{
	
	if (NULL == root)
		return;
	PostOrderTree(root->left);
	PostOrderTree(root->right);
	printf("%c ", root->data);
	
}
//void PostOrderNorTree(BTNode* root)
//{
//	Stack s;
//	BTNode* pCur = root;
//	BTNode* pre = NULL;
//	if (NULL == root)
//		return;
//	StackInit(&s);
//	while (pCur || StackEmpty(&s) != 0)
//	{
//		while (pCur)
//		{
//			StackPush(&s, pCur);
//			pCur = pCur->left; 
//		}
//		pCur = StackTop(&s);
//		pre = pCur;
//		if (pCur->right == NULL && pre->right !=pCur)
//		{
//			printf("%c ", pCur->data);
//			
//			StackPop(&s);
//		}
//		
//		else
//			pre = pCur;
//			pCur = pCur->right;
//	}
//
//}
void PostOrderNorTree(BTNode* root)
{
	Stack s1;
	Stack s2;
	BTNode* pCur = root;
	StackInit(&s1);
	StackInit(&s2);
	StackPush(&s1, root);
	while (StackEmpty(&s1) != 0)
	{
		pCur = StackTop(&s1);
		StackPop(&s1);
		StackPush(&s2, pCur);
		if (pCur->left)
		{
			StackPush(&s1, pCur->left);
		}
		if (pCur->right)
		{
			StackPush(&s1, pCur->right);
		}

	}
	while (StackEmpty(&s2) != 0)
	{
		pCur = StackTop(&s2);
		StackPop(&s2);
		printf("%c ", pCur->data);
	}
	StackDestroy(&s1);
	StackDestroy(&s2);
	
}

//�����������
int MaxDepth(BTNode* root)
{
	//assert(root);
	if (NULL == root)
		return 0;
	if (root->left == NULL && root->right == NULL)//������
		return 1;
	return MaxDepth(root->left) > MaxDepth(root->right) ? MaxDepth(root->left) + 1 : MaxDepth(root->right) + 1;
}

int SizeBtree(BTNode* root)//���ܽڵ�ĸ���
{
	//assert(root);
	if (NULL == root)
		return 0;
	return 1 + SizeBtree(root->left) + SizeBtree(root->right);
}
int BalaceBt(BTNode* root)//����Ƿ�Ϊƽ����
{
	//assert(root);
	if (NULL == root || (root->left == NULL &&root->right == NULL))
		return 1;
	if (BalaceBt(root->left) && BalaceBt(root->right) && abs(MaxDepth(root->left) - MaxDepth(root->right)))
		return 1;
	return 0;
}
int Leafsize(BTNode* root)//��ȡҶ�ӽڵ�ĸ���
{
	//assert(root);
	if (NULL == root)
		return 0;
	if (root->left == NULL&&root->right == NULL)
		return 1;
	return Leafsize(root->left) + Leafsize(root->right);
}
int KsizeBt(BTNode* root, int k)//���K�������
{
	//assert(root);
	if (NULL == root||k<1)
		return 0;
	if (k ==  1)
		return 1;
	return KsizeBt(root->left, k - 1) + KsizeBt(root->right, k - 1);
}
//��ֵΪval�Ľ�㣬�������ĵ�ַ
BTNode* FindvalBt(BTNode* root, BTDataType val)
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
BTNode* ParentfindBt(BTNode* root, BTDataType val)//��һ������˫��
{
	BTNode* ret = NULL;
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
//���ٶ�����
void DestroyBinTree(BTNode* root)
{
	
	//assert(root);
	if (NULL == (root))
		return;
	DestroyBinTree(root->left);
	DestroyBinTree(root->right);
	free(root);
	root = NULL;
}
void Swap(BTNode** left, BTNode** right)
{
	BTNode* temp = NULL;
	temp = *left;
	*left = *right;
	*right = temp;
}
void Mirror(BTNode* root)
{
	if (root)
	{
		Swap(&(root->left), &(root->right));
		Mirror(root->left);
		Mirror(root->right);
	}
	return;
}
BTNode* CopyBinTree(BTNode* root)//����������
{
	BTNode* pNewNode = NULL;
	if (root)
	{
		pNewNode = BuyNode(root->data);
		pNewNode->left = CopyBinTree(root->left);
		pNewNode->right = CopyBinTree(root->right);
	}
	return pNewNode;
}
void TEST()
{
	BTNode* bt = NULL;
	BTNode* ret1 = NULL;
	BTDataType arr[] = "ABD###CE##F";
	BTNode* pNewNode = NULL;
	int index = 0; 
	bt = BTcreat(arr, (sizeof(arr) / sizeof(arr[0])), &index);
	//printf("ǰ�������\n");
	//PreOrderTree(bt);
	//printf("\n");
	//printf("ǰ��ǵݹ������\n");
	//PreOrderTreeNor(bt);
	//printf("\n");
	printf("���������\n");
	InOrderTree(bt);
	printf("\n");
	printf("����ǵݹ������\n");
	InOrderTreeNor(bt);
	printf("\n");

	printf("���������\n");
	PostOrderTree(bt);
	printf("\n");
	printf("����ǵݹ������\n");
	PostOrderNorTree(bt);
	printf("\n");
	//LevelOrder(bt);
	//printf("\n");
	//Mirror(bt);
	//pNewNode = CopyBinTree(bt);
	//MaxDepth(bt);
	//printf("�����������: %d \n", MaxDepth(bt));
	//printf("�������Ľ�����: %d \n", SizeBtree(bt));
	//printf("�������Ƿ�Ϊƽ����: %d \n", BalaceBt(bt));
	//printf("������Ҷ�ӽ��ĸ���: %d \n", Leafsize(bt));
	//printf("��������K����ĸ���: %d \n", KsizeBt(bt,2));
	//ret1 = FindvalBt(bt, 'G');
	//printf("%d\n", ret1);
	//ret1 = ParentfindBt(bt, 'D');
	//printf("%d\n", ret1);
	DestroyBinTree(bt);
	printf("���ٳɹ� \n");

}






 