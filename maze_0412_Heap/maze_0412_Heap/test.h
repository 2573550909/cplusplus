#pragma once
#include <stdlib.h>
#include <assert.h>
typedef int DataType;
typedef struct Heap
{
	DataType* array;
	int capacity;
	int size;
}	Heap;

void AdjustDown(int* array, int parent, int size);
//����
void checkcapacity(Heap* hp)
{
	if (hp->capacity > hp->size){return;}

	int newcapacity = hp->capacity * 2;
	DataType* newarray = 
		(int*)malloc(sizeof(DataType)*newcapacity);

	for (int i = 0; i < hp->size; ++i)
	{
		newarray[i] = hp->array[i];
	}

	free(hp->array);
	hp->array = newarray;
	hp->capacity = newcapacity;
}

//�ѵĳ�ʼ��
void InitHeap(Heap* hp, DataType* a, int len)
{
	assert(hp && a);
	hp->array = (DataType*)malloc(sizeof(DataType)*len);
	assert(hp->array);

	hp->capacity = len;
	for (int i = 0; i < len; ++i)
	{
		hp->array[i] = a[i];
	}
	hp->size = len;
	int parent = (len-2)>>1;
	for (; parent >= 0; --parent)
	{
		AdjustDown(hp->array, parent,len);
	}
}

void AdjustUp(int* array, int size, int child)
{
	int parent = (child - 1) >> 1;
	while (child)
	{
		if (array[child] < array[parent])
		{
			Swap(&array[parent], &array[child]);
			child = parent;
			parent = (child - 1) >> 1;
		}
		else { return; }
	}
}

// ����в���ֵΪdata��Ԫ�� 
void InsertHeap(Heap* hp, DataType data)
{
	assert(hp);
	checkcapacity(hp);
	hp->array[hp->size++] = data;
	AdjustUp(hp->array, hp->size, hp->size - 1);

}

void Swap(DataType* left, DataType* right)
{
	int tmp = *left;
	*left = *right;
	*right = tmp;
}

//��Ԫ�� ���µ���
void AdjustDown(int* array,int parent,int size)
{
	int child = parent * 2 + 1;

	while (child < size)//������ӵĴ���
	{
		if (child + 1 < size && array[child + 1] < array[child])
		{
			++child;//�Һ��ӵĴ���
		}

		if (array[parent] > array[child])
		{
			Swap(&array[parent], &array[child]);
			parent = child;
			child = 2 * parent + 1;
		}
		else { return; }
	}
}

// ɾ���Ѷ�Ԫ�� 
void EraseHeap(Heap* hp)
{
	assert(hp->size > 0);
	Swap(&hp->array[0],&hp->array[hp->size-1]);
	hp->size--;
	AdjustDown(hp->array, hp->array[hp->size - 1],hp->size);
}

// ��ȡ������ЧԪ�ظ��� 
int SizeHeap(Heap* hp)
{
	int num = hp->size;
	return num;
}

// �����Ƿ�Ϊ�� 
int EmptyHeap(Heap* hp)
{
	if (hp->size == 0)
	{
		return 1;
	}
	else {return 0;}
}

// ��ȡ�Ѷ�Ԫ�� 
DataType TopHeap(Heap* hp)
{
	assert(hp->size > 0);
	return hp->array[0];
}

// ���ٶ� 
void DestroyHeap(Heap* hp)
{
	free(hp->array);
	hp->array = NULL;
	hp->size = 0;
	hp->capacity = 0;
}
