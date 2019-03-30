#include"Heap.h"
#include<string.h>
//���
int Greater(HPDataType left, HPDataType right)
{
	return left > right? 1:0;
}
int Less(HPDataType left, HPDataType right)
{
	return left < right ? 1 : 0;
}
void Swap(HPDataType* left, HPDataType* right)
{
	HPDataType temp = 0;
	temp = *left;
	*left = *right;
	*right = temp;
}
void AdjustDown(Heap* root, int size, CMP cmp)
{
	assert(root);
	int parent = 0;
	int child = parent*2 + 1;
	if (NULL == root)
		return;
	while (child < size)
	{
		//�����Һ����н�С�ĺ���
		//if (child + 1 < size && root->_array[child] > root->_array[child + 1])
		if (child + 1 < size && cmp(root->_array[child + 1], root->_array[child]))
		{
			child += 1;
		}
		//���˫���Ƿ��������
		//if (root->_array[child] < root->_array[parent])
		if (cmp(root->_array[child], root->_array[parent]))
		{
			Swap(&(root->_array[child]), &(root->_array[parent]));
			parent = child;
			child = parent * 2 + 1;
		}
		else
			return;
	}
}
//��˫�׵���������Ϊ�ѵĽṹ ��С�ѣ�
void Adjust(Heap* root, int size, CMP cmp)
{
	assert(root);
	//�ҵ�����һ����Ҷ�ӽڵ�
	int parent = (size - 2) / 2;
	int child = 2 * parent + 1;
	while (parent)
	{
		//�����Һ����н�С�ĺ���
		//if (child + 1 < size &&root->_array[child] > root->_array[child + 1])
		if (child + 1 < size &&cmp(root->_array[child+1] , root->_array[child ]))

		{
			child += 1;
		}
		//���˫���Ƿ��������
		if (cmp(root->_array[child] , root->_array[parent]))
		{
			Swap(&(root->_array[child]), &(root->_array[parent]));
			/*parent -= 1;
			child = parent * 2 + 1;*/
		}
		parent -= 1;
		child = parent * 2 + 1;
	}
	AdjustDown(root, size,cmp);
}
//������
void CreateHeap(Heap* root, HPDataType array[10], int size, CMP cmp)
{
	int i = 0;
	if (NULL == root)
		return;
	root->_array = (HPDataType*)malloc(sizeof(HPDataType)*size);
	if (root->_array == NULL)
		assert(0);
	memcpy(root->_array, array, sizeof(HPDataType)*size);
	root->_capacity = size;
	root->_size = size;

	Adjust(root, size,cmp);
}
void Adjustup(Heap* root, CMP cmp)
{
	assert(root);
	if (NULL == root)
		return;
	int child = root->_size - 1;
	int parent = (child - 1) / 2;
	while (parent > 0)
	{
		if (cmp(root->_array[child] , root->_array[parent]))
		{
			Swap(&(root->_array[child]), &(root->_array[parent]));
			child = parent;
			parent = (child - 1) / 2;
		}
	}
}
void Addcatacity(Heap* root)
{
	HPDataType* p = NULL;
	assert(root);
	p = (HPDataType*)realloc(root->_array, sizeof(HPDataType)*root->_size + 3);
	if (NULL == p)
		return;
	root->_array = p;
	root->_capacity = root->_size + 3;
}
//�ڶ��в���ֵΪdata��Ԫ��
void InserHeap(Heap* root, HPDataType data, CMP cmp)
{
	
	assert(root);
	//�Ƿ��ܲ���
	if (root->_size == root->_capacity)
	{
		//���� ��������
		Addcatacity(root);
	}
	//û��
	root->_array[root->_size] = data;
	root->_size++;
	Adjustup(root,cmp);
}
//��ȡ�Ѷ�Ԫ��
HPDataType TopHeap(Heap* root)
{
	assert(root);
	if (NULL == root)
		return -1;
	return root->_array[0];
}
////��ȡ����Ԫ�صĸ���
int SizeHeap(Heap* root)
{
	assert(root);
	return root->_size;
}
////���һ�����Ƿ�Ϊ�ն�
int EmptyHeap(Heap* root)
{
	assert(root);
	return (root->_size == 0);
}
//ɾ���Ѷ�Ԫ��
void DeleteHeapFront(Heap* root, CMP cmp)
{
	int i = 0;
	assert(root);
	if (root->_size == 0)
		return;
	//�����Ѷ�Ԫ�غ����һ��Ԫ��
	Swap(&(root->_array[0]), &(root->_array[root->_size - 1]));
	root->_size -= 1;
	AdjustDown(root, root->_size,cmp);
}
//�ѵ�����
void DestroyHeap(Heap* root)
{
	/*assert(root);
	if (NULL == root)
		return;
	while (root->_size)
	{
		DeleteHeapFront(root,cmp);

	}
	root->_array = NULL;*/
	if (root->_array)
	{
		free(root->_array);
		root->_capacity = 0;
		root->_size = 0;
	}
	printf("���ٳɹ�\n");
}

//������   ���������С���Ž���
void HeapSort(Heap* root, int size, CMP cmp)
{
	int i = 0;
	assert(root);
	if (NULL == root)
		return;
	for (i = size - 1; i > 0; i--)
	{
		Swap(&(root->_array[0]), &(root->_array[i]));
		AdjustDown(root, i, cmp);
	}

}
//��ӡ����
void HeapPrint(Heap *root)
{	
	int i = 0;
	assert(root);
	if (NULL == root)
		return;
	for (i = 0; i < root->_size; i++)
	{
		printf("%d ", root->_array[i]);
	}
	printf("\n");
}
void PrintTok(Heap* root, int K)
{
	int i = 0;
	assert(root);
	if (NULL == root)
		return;
	printf("����3������");
	for (i = 0; i < K; i++)
	{
		printf("%d ", root->_array[i]);
	}
	printf("\n");
}
//ǰK�����Ԫ�� 

//1 ����N��Ԫ����ǰK��Ԫ�ش���һ����   ����ӦС�ѣ���С��Ӧ���
//2.��ʣ���N-k��Ԫ�ز�����Ѷ�Ԫ�ؽ��бȽϣ��滻������
//(N-k)logK
//������3��Ԫ��
void TopK(HPDataType* arr, int size, CMP cmp, int K)
{
	Heap hp1;
	CreateHeap(&hp1, arr, K, Less);
	for (int i = 3; i < size - 1; i++)
	{
		if (arr[i]>hp1._array[0])
		{
			Swap(&arr[i], &(hp1._array[0]));
			AdjustDown(&hp1, K, Less);
		}
	}
	PrintTok(&hp1, K);

	DestroyHeap(&hp1);
	return;

}
void TestHeap()
{
	Heap hp;
	/*HPDataType i = 0;
	HPDataType array[10] = { 5, 4, 2, 7, 6, 1, 8, 3, 9, 0 };
	CreateHeap(&hp, array, 10,Less);*/
	HPDataType array1[10] = { 5, 4, 2, 7, 6, 1, 8, 3, 9, 0 };
//	HeapPrint(&hp);
	TopK(array1, 10, Less, 3);
	
//	//HeapSort(&hp, 10, Less);//С���Ž������������
//	//HeapPrint(&hp);
//	//InserHeap(&hp, 2,Less);
//	//DeleteHeapFront(&hp,Less);
//	//i = TopHeap(&hp);
//	//int a = SizeHeap(&hp);
//	//int b = EmptyHeap(&hp);
	//DestroyHeap(&hp);
}
