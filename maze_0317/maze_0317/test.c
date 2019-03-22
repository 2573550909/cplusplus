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
//typedef struct SeqList
//{
//	int array[100];	//������100
//	int size;		//˳��������Ч���ݸ���
//					//ͬʱҲ���Ա�ʾ�Ӻ�����һ������λ�õ��±�
//}	SeqList;

typedef int SLDataType;

//��̬˳����ڳ��������ڼ���Զ�̬���������Ĵ�С��
typedef struct SeqList
{
	SLDataType *array;	//ָ����ϵĿռ䣬�������
	int capacity;		//����
	int size;			//��Ч����
}	SeqList;

//����
void SeqListInit(SeqList *pSeqList)
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

void SeqListInit2(SeqList *p)
{
	assert(p != NULL);

	p->capacity = 10;
	p->array = (int*)malloc(sizeof(SLDataType) * 10);
	p->size = 0;
}

//����
void SeqListDestroy(SeqList *pSeqList)
{
	assert(pSeqList != NULL);
	assert(pSeqList->array != NULL);
	
	free(pSeqList->array);
	pSeqList->array = NULL;
	pSeqList->capacity = 0;
	pSeqList->size = 0;
}

void SeqListDestroy2(SeqList *p)
{
	assert(p != NULL);
	free(p->array);
	p->array = NULL;
	p->capacity = 0;
	p->size = 0;
}
//�������ԣ����ⲿ�������� �� �ڲ�������
static void CheckCapacity(SeqList *ps)
{
	//����Ҫ���ݵ����
	if (ps->size <= ps->capacity)
	{
		return;
	}

	//��Ҫ���ݡ���һ�����Ҫ���ݵ�2��
	int newCapacity = ps->capacity * 2;
	SLDataType *newArray =
		(SLDataType *)malloc(sizeof(SLDataType)* newCapacity);
	assert(newArray != NULL);

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

void CheckCapacity2(SeqList *p)
{
	if (p->size < p->capacity)
	{
		return;
	}
	int NewCapacity = p->capacity * 2;
	int *NewArray = (int*)malloc(sizeof(int)*NewCapacity);

	for (int i = 0; i < p->size; ++i)
	{
		NewArray[i] = p->array[i];
	}

	free(p->array);
	p->array = NewArray;
	p->capacity = NewCapacity;
}
//��ɾ���
//β��
void SeqListPushBack(SeqList *pSeqList, SLDataType value)
{
	CheckCapacity(pSeqList);
	pSeqList->array[pSeqList->size] = value;
	pSeqList->size++;
}

void SeqListPushBack2(SeqList *p, SLDataType val)
{
	if (p->size = p->capacity)
	{
		CheckCapacity2(p);
	}

	p->array[p->size] = val;
	p->size++;
}
//ͷ��
void SeqListPushFront(SeqList *pSeqList, SLDataType value)	
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

void SeqListPushFront2(SeqList *p, SLDataType val)
{
	if (p->size = p->capacity)
	{
		CheckCapacity2(p);
	}

	for (int i = p->size; i >0 ; --i)
	{
		p->array[i + 1] = p->array[i];
	}
	p->array[0] = val;
	p->size++;
}
//�����±�pos������
void SeqListPopInsert(SeqList *ps, int pos, SLDataType value)
{
	CheckCapacity(ps);
	//pos[0,size]  i �����ݵ��±�
	for (int i = ps->size - 1; i >= pos; i--)
	{
		ps->array[i + 1] = ps->array[i];
	}

	ps->array[pos] = value;
	ps->size++;
}

//  sd   f   fd	   da    e     l     w
//   0   1   2     3     4     5     6      7
void SeqListPopInsert2(SeqList *p, int pos, SLDataType val)
{
	if (p->size = p->capacity)
	{
		CheckCapacity2(p);
	}
	assert(p != NULL);
	for (int i = p->size - 1; i > pos + 1; --i)
	{
		p->array[i + 1] = p->array[i];
	}

	p->array[pos] = val;
	p->size++;
}

//βɾ
void SeqListPopBack(SeqList *ps)
{
	assert(ps->size > 0);
	ps->size--;
}

void SeqListPopBack2(SeqList *p)
{
	assert(p != NULL);
	assert(p->size >= 0);

	p->size--;
}

//ͷɾ
void SeqListPopFront(SeqList *ps)
{
	assert(ps->size > 0);
	for (int i = 0; i < ps->size - 1; i++)
	{
		ps->array[i] = ps->array[i + 1];
	}
	ps->size--;
}


//  sd   f   fd	   da    e     l     w
//   0   1   2     3     4     5     6      7
void SeqListPopFront2(SeqList *p)
{
	assert(p != NULL);
	assert(p->size > 0);

	for (int i = 1; i < p->size + 1; ++i)
	{
		p->array[i - 1] = p->array[i];
	}

	p->size--;
}

//ɾ��pos�±�����Ӧ��ֵ
void SeqListErase(SeqList *ps, int pos)
{
	assert(ps->size > 0);
	//[0,size-1]

	for (int i = pos + 1; i < ps->size; i++)
	{
		ps->array[i - 1] = ps->array[i];
	}
	ps->size--;
}

//  sd   f   fd	   da    e     l     w
//   0   1   2     3     4     5     6      7
void SeqListErase2(SeqList *p, int pos)
{
	//pos = 3
	assert(p != NULL);

	for (int i = pos + 1; i < p->size ; ++i)
	{
		p->array[i - 1] = p->array[i];
	}
	p ->size--;
}

//����
int SeqListSearch(const SeqList *ps, SLDataType value)
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

int SeqListFind(const SeqList *p, SLDataType val)
{
	assert(p != NULL);

	for (int i= 0;i<p->size;++i)
	{
		if (p->array[i] == val)
		{
			return i;
		}
	}
	return -1;
}
//�޸� pos �±����ڵ�ֵΪ value
void SeqListModify(SeqList *ps, int pos, SLDataType value)
{
	assert(pos >= 0 && pos < ps->size);
	ps->array[pos] = value;
}

void SeqListModify2(SeqList *s, int pos, SLDataType val)
{
	assert(s != NULL);
	assert(pos >= 0 && pos < s->size);
	s->array[pos] = val;
}

//ɾ�������ĵ�һ��value
void SeqListRemove(SeqList *ps, SLDataType value)
{
	int pos = SeqListSearch(ps, value);
	if (pos != -1)
	{
		SeqListErase(ps, pos);
	}
}

int SeqListRemove2(SeqList *p, SLDataType val)
{
	assert(p != NULL);
	for (int i = 0; i < p->size; ++i)
	{
		if (p->array[i] = val)
		{
			for (int j = i + 1; i < p->size + 1; ++j)
			{
				p->array[j - 1] = p->array[j];
			}
			p->size--;
			return 1;
		}
	}
	return 0;
}
//ɾ�����������е�value
void SeqListRemoveAll(SeqList *ps, SLDataType value)
{
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

void SeqListRemoveAll2(SeqList *p, SLDataType val)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < p->size; ++i)
	{
		if (p->array[i] != val)
		{
			p->array[j] = p->array[i];
		}
		++j;
	}
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