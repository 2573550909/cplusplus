#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

//typedef struct SeqList
//{
//	int* array;		//����ָ����ϵĿռ�ĵ�ַ
//	int capacity;	//���������
//	int size;		//��Ч���ݵĸ���
//}SeqList;

//��̬˳�����С�̶��������ڼ�����ģ�
typedef struct SeqList
{
	int array[100];	//������100
	int size;		//˳��������Ч���ݸ���
					//ͬʱҲ���Ա�ʾ�Ӻ�����һ������λ�õ��±�
}	SeqList;

typedef int SLDataType;

//��̬˳����ڳ��������ڼ���Զ�̬���������Ĵ�С��
typedef struct SeqList
{
	SLDataType *array;	//ָ����ϵĿռ䣬�������
	int capacity;		//����
	int size;			//��Ч����
}	SeqList;

void SeqListInit(SeqList *pSeqList)//����
{
	//��������������һ�������ĵ�ַ
	//�����ĵ�ַ�϶�����NULL
	assert(pSeqList != NULL);

	//���ٿռ䣬����������size
	pSeqList->capacity = 10;
	pSeqList->array = 
		(int*)malloc(sizeof(SLDataType)*pSeqList->capacity);
	//assert(pSeqList->array != NULL);
	pSeqList->size = 0;
}

void SeqListDestroy(SeqList *pSeqList)//����
{
	assert(pSeqList != NULL);
	assert(pSeqList->array != NULL);
	free(pSeqList->array);

	pSeqList->array = NULL;
	pSeqList->capacity = 0;
	pSeqList->size = 0;
}

//�������ԣ����ⲿ�������� �� �ڲ�������
static void CheckCapacity(SeqList *ps)
{
	//����Ҫ���ݵ����
	if (ps->size < ps->capacity)
	{
		return;
	}

	//��Ҫ���ݡ���һ�����Ҫ���ݵ�2��
	int newCapacity = ps->capacity * 2;
	SLDataType *newArray =
		(SLDataType *)malloc(sizeof(SLDataType)* newCapacity);
	asset(newArray != NULL);

	//���
	for (int i = 0; i < ps->size; ++i)
	{
		newArray[i] = ps->array[i];
	}

	//�ͷ�ԭ���Ŀռ䣬���¿ռ�
	free(ps->array);
	ps->array = newArray;
	ps->capacity = newCapacity;
}

//��ɾ���
void SeqListPushBack(SeqList *pSeqList, SLDataType value)//β��
{
	CheckCapacity(pSeqList);
	pSeqList->array[pSeqList->size] = value;
	pSeqList->size++;
}

void SeqListPushFront(SeqList *pSeqList, SLDataType value)	//ͷ��
{
	CheckCapacity(pSeqList);
	//i �ǿռ���±�
	for (int i = pSeqList->size; i >= 1; --i)
	{
		pSeqList->array[i] = pSeqList->array[i-1];
	}

	pSeqList->array[0] = value;
	pSeqList->size++;
}

void SeqListPopInsert(SeqList *ps, int pos, SLDataType value)
{//�����±�pos������
	CheckCapacity(ps);
	//pos[0,size]  i �����ݵ��±�
	for (int i = ps->size - 1; i >= pos; i--)
	{
		ps->array[i + 1] = ps->array[i];
	}

	ps->array[pos] = value;
	ps->size++;
}

void SeqListPopBack(SeqList *ps)
{//βɾ
	assert(ps->size > 0);
	ps->size--;
}

void SeqListPopFront(SeqList *ps)
{//ͷɾ
	assert(ps->size > 0);
	for (int i = 0; i < ps->size - 1; i++)
	{
		ps->array[i] = ps->array[i + 1];
	}
	ps->size--;
}

void SeqListErase(SeqList *ps, int pos)
{//ɾ��pos�±�����Ӧ��ֵ
	assert(ps->size > 0);
	//[0,size-1]

	for (int i = pos + 1; i < ps->size; i++)
	{
		ps->array[i - 1] = ps->array[i];
	}
	ps->size--;
}

int SeqListSearch(const SeqList *ps, SLDataType value)//����
{
	for (int i = 0; i < ps->size; ++i)
	{
		if (ps->array[i] == value)
		{
			return i;
		}
	}
	return -1;
}

void SeqListModify(SeqList *ps, int pos, SLDataType value)
{
	//�޸� pos �±����ڵ�ֵΪ value
	assert(pos >= 0 && pos < ps->size);
	ps->array[pos] = value;
}

void SeqListRemove(SeqList *ps, SLDataType value)
{
	//ɾ�������ĵ�һ��value
	int pos = SeqListSearch(ps, value);
	if (pos != -1)
	{
		SeqListErase(ps, pos);
	}
}


void SeqListRemoveAll(SeqList *ps, SLDataType value)
{
	//ɾ�����������е�value
	int i = 0; 
	int j = 0;
	for (; i < ps->size; ++i)
	{
		if (ps->array[i] != value)
		{
			ps->array[j] = ps->array[i];
			j++;
		}
	}
	ps->size = j;
}


int main()
{
	//���Ա�L��n����ͬ����������Ԫ�ع��ɵ��������У���n==0��Ϊ�ձ�
	//����������֪�����ȵģ����ҹ̶���
	//�����Ա��г��˵�һ�������һ��������Ԫ�ض��н���һ��ǰ���ͺ���
	//���磺An��ǰ����n-1,������n+1�����������Ԫ�أ�

	system("pause");
	return 0;
}