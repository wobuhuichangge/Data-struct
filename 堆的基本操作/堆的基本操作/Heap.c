#include"Heap.h"
#include<string.h>
void Swap(HPDataType* left, HPDataType* right)
{
	HPDataType temp = 0;
	temp = *left;
	*left = *right;
	*right = temp;
}
void AdjustDown(Heap* root, int size)
{
	assert(root);
	int parent = 0;
	int child = parent*2 + 1;
	if (NULL == root)
		return;
	while (child < size)
	{
		//�����Һ����н�С�ĺ���
		if (child + 1 < size && root->_array[child] > root->_array[child + 1])
		{
			child += 1;
		}
		//���˫���Ƿ��������
		if (root->_array[child] < root->_array[parent])
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
void Adjust(Heap* root, int size)
{
	assert(root);
	//�ҵ�����һ����Ҷ�ӽڵ�
	int parent = (size - 2) / 2;
	int child = 2 * parent + 1;
	while (parent)
	{
		//�����Һ����н�С�ĺ���
		if (child + 1 < size &&root->_array[child] > root->_array[child + 1])
		{
			child += 1;
		}
		//���˫���Ƿ��������
		if (root->_array[child] < root->_array[parent])
		{
			Swap(&(root->_array[child]), &(root->_array[parent]));
			parent -= 1;
			child = parent * 2 + 1;
		}
	}
	AdjustDown(root, size);
}
//������
void CreateHeap(Heap* root, HPDataType array[10], int size)
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

	Adjust(root, size);
}
void Adjustup(Heap* root)
{
	assert(root);
	if (NULL == root)
		return;
	int child = root->_size - 1;
	int parent = (child - 1) / 2;
	while (parent > 0)
	{
		if (root->_array[child] < root->_array[parent])
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
void InserHeap(Heap* root, HPDataType data)
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
	Adjustup(root);
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
void DeleteHeapFront(Heap* root)
{
	int i = 0;
	assert(root);
	if (root->_size == 0)
		return;
	//�����Ѷ�Ԫ�غ����һ��Ԫ��
	Swap(&(root->_array[0]), &(root->_array[root->_size - 1]));
	root->_size -= 1;
	AdjustDown(root,root->_size);
}
//�ѵ�����
void DestroyHeap(Heap* root)
{
	assert(root);
	if (NULL == root)
		return;
	while (root->_size)
	{
		DeleteHeapFront(root);

	}
	root->_array = NULL;
	printf("���ٳɹ�\n");
}

void TestHeap()
{
	Heap hp;
	HPDataType i = 0;
	HPDataType array[10] = { 5, 4, 2, 7, 6, 1, 8, 3, 9, 0 };
	CreateHeap(&hp, array, 10);
	//InserHeap(&hp, 2);
	//DeleteHeapFront(&hp);
	i = TopHeap(&hp);
	int a = SizeHeap(&hp);
	int b = EmptyHeap(&hp);
	DestroyHeap(&hp);
}