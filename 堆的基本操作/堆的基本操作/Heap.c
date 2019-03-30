#include"Heap.h"
#include<string.h>
//大堆
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
		//找左右孩子中较小的孩子
		//if (child + 1 < size && root->_array[child] > root->_array[child + 1])
		if (child + 1 < size && cmp(root->_array[child + 1], root->_array[child]))
		{
			child += 1;
		}
		//检查双亲是否满足情况
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
//把双亲的子树调整为堆的结构 （小堆）
void Adjust(Heap* root, int size, CMP cmp)
{
	assert(root);
	//找倒数第一个非叶子节点
	int parent = (size - 2) / 2;
	int child = 2 * parent + 1;
	while (parent)
	{
		//找左右孩子中较小的孩子
		//if (child + 1 < size &&root->_array[child] > root->_array[child + 1])
		if (child + 1 < size &&cmp(root->_array[child+1] , root->_array[child ]))

		{
			child += 1;
		}
		//检查双亲是否满足情况
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
//创建堆
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
//在堆中插入值为data的元素
void InserHeap(Heap* root, HPDataType data, CMP cmp)
{
	
	assert(root);
	//是否能插入
	if (root->_size == root->_capacity)
	{
		//满了 进行扩容
		Addcatacity(root);
	}
	//没满
	root->_array[root->_size] = data;
	root->_size++;
	Adjustup(root,cmp);
}
//获取堆顶元素
HPDataType TopHeap(Heap* root)
{
	assert(root);
	if (NULL == root)
		return -1;
	return root->_array[0];
}
////获取堆中元素的个数
int SizeHeap(Heap* root)
{
	assert(root);
	return root->_size;
}
////检测一个堆是否为空堆
int EmptyHeap(Heap* root)
{
	assert(root);
	return (root->_size == 0);
}
//删除堆顶元素
void DeleteHeapFront(Heap* root, CMP cmp)
{
	int i = 0;
	assert(root);
	if (root->_size == 0)
		return;
	//交换堆顶元素和最后一个元素
	Swap(&(root->_array[0]), &(root->_array[root->_size - 1]));
	root->_size -= 1;
	AdjustDown(root, root->_size,cmp);
}
//堆的销毁
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
	printf("销毁成功\n");
}

//堆排序   大堆排升序。小堆排降序
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
//打印函数
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
	printf("最大的3个数：");
	for (i = 0; i < K; i++)
	{
		printf("%d ", root->_array[i]);
	}
	printf("\n");
}
//前K个最大元素 

//1 先用N个元素中前K个元素创建一个堆   最大对应小堆，最小对应大堆
//2.用剩余的N-k个元素不断与堆顶元素进行比较，替换调整。
//(N-k)logK
//求最大的3个元素
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
	
//	//HeapSort(&hp, 10, Less);//小堆排降，大堆排升序；
//	//HeapPrint(&hp);
//	//InserHeap(&hp, 2,Less);
//	//DeleteHeapFront(&hp,Less);
//	//i = TopHeap(&hp);
//	//int a = SizeHeap(&hp);
//	//int b = EmptyHeap(&hp);
	//DestroyHeap(&hp);
}
