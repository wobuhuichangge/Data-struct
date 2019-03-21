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
//����������  
//����ǰ�����ԭ��
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
//����
//�������NLR
//�ݹ�
void PreOrderTree(Node* root)
{
	
	if (root)
	{
		printf("%c ", root->data);
		PreOrderTree(root->left);
		PreOrderTree(root->right);
	}
	
	
}
�ǵݹ�
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
//�������LNR
void InOrderTree(Node* root)
{

	if (NULL == root)
		return;
	InOrderTree(root->left);
	printf("%c ", root->data);
	InOrderTree(root->right);
	
}
//�������
void PostOrderTree(Node* root)
{
	
	if (NULL == root)
		return;
	PostOrderTree(root->left);
	PostOrderTree(root->right);
	printf("%c ", root->data);
	
}
////�������
////void 
//�����������
int MaxDepth(Node* root)
{
	//assert(root);
	if (NULL == root)
		return 0;
	if (root->left == NULL && root->right == NULL)//������
		return 1;
	return MaxDepth(root->left) > MaxDepth(root->right) ? MaxDepth(root->left) + 1 : MaxDepth(root->right) + 1;
}

int SizeBtree(Node* root)//���ܽڵ�ĸ���
{
	//assert(root);
	if (NULL == root)
		return 0;
	return 1 + SizeBtree(root->left) + SizeBtree(root->right);
}
int BalaceBt(Node* root)//����Ƿ�Ϊƽ����
{
	//assert(root);
	if (NULL == root || (root->left == NULL &&root->right == NULL))
		return 1;
	if (BalaceBt(root->left) && BalaceBt(root->right) && abs(MaxDepth(root->left) - MaxDepth(root->right)))
		return 1;
	return 0;
}
int Leafsize(Node* root)//��ȡҶ�ӽڵ�ĸ���
{
	//assert(root);
	if (NULL == root)
		return 0;
	if (root->left == NULL&&root->right == NULL)
		return 1;
	return Leafsize(root->left) + Leafsize(root->right);
}
int KsizeBt(Node* root, int k)//���K�������
{
	//assert(root);
	if (NULL == root||k<1)
		return 0;
	if (k = 1)
		return 1;
	return KsizeBt(root->left, k - 1) + KsizeBt(root->right, k - 1);
}
//��ֵΪval�Ľ�㣬�������ĵ�ַ
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
Node* ParentfindBt(Node* root, BTDataType val)//��һ������˫��
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
//���ٶ�����
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
	printf("ǰ�������\n");
	PreOrderTree(bt);
	printf("\n");
	printf("ǰ��ǵݹ������\n");
	PreOrderTreeNor(bt);
	printf("\n");
	printf("���������\n");
	InOrderTree(bt);
	printf("\n");
	printf("���������\n");
	PostOrderTree(bt);
	printf("\n");

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

