#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
//1. ��Ϥ˳���ĸ���
//2. ��Ϥ˳���ķ��ࣿ��̬˳���Ͷ�̬˳��������
//3. ʵ�ֶ�̬˳�������»���������
typedef int DataType;

typedef struct SeqList
{
	DataType* _array; // ����˳�������ЧԪ�ظ��� 
	int _capacity; // �ռ��ܴ�С 
	int _size; // ��ЧԪ�ظ��� 
}	SeqList,*PSeqList;

//��ʼ��˳���
void SeqListInit(PSeqList ps)
{
	assert(ps != NULL);
	ps->_capacity = 10;//����
	//���ٿռ�
	ps->_array = (int*)malloc(sizeof(DataType)*ps->_capacity);
	//sizeΪ��Ч����,�������Ϊ0
	ps->_size = 0;
}

void SeqListDestroy(PSeqList ps)
{
	assert(ps != NULL);
	assert(ps->_array != NULL);	
	free(ps->_array);
	ps->_array = NULL;
	ps->_capacity = 0;
	ps->_size = 0;
}

void SeqListCheck(PSeqList ps)//����
{
	if (ps->_capacity > ps->_size)
	{
		return;
	}

	int newcapacity = 2 * ps->_capacity; 
	DataType* new_array = (int*)malloc(sizeof(DataType)*newcapacity);
	for (int i = 0; i < ps->_size; ++i)
	{
		new_array[i] = ps->_array[i];
	}

	ps->_capacity = newcapacity;
	ps->_array = new_array;
}

// β�� 
void SeqListPushBack(PSeqList ps, DataType data)
{
	SeqListCheck(ps);//����
	ps->_array[ps->_size] = data;
	ps->_size++;
}
// βɾ 
void SeqListPopBack(PSeqList ps)
{
	assert(ps->_size > 0);
	ps->_size--;
}

// ͷ�� 
void SeqListPushFront(PSeqList ps, DataType data)
{
	SeqListCheck(ps);//����
	for (int i = ps->_size-1; i >=0 ; --i)
	{
		ps->_array[i+1] = ps->_array[i];
	}
	ps->_array[0] = data;
	ps->_size++;
}

// ͷɾ 
void SeqListPopFront(PSeqList ps)
{
	if (ps->_array == 0) { return; }

	for (int i = 1; i < ps->_size; ++i)
	{
		ps->_array[i-1] = ps->_array[i];
	}
	ps->_size--;
}

// ����λ�ò��� 
void SeqListInsert(PSeqList ps, int pos, DataType datda)
{
	assert(ps);
	SeqListCheck(ps);//����
	for (int i = ps->_size-1; i > pos-2; --i)
	{
		ps->_array[i+1] = ps->_array[i];
	}
	//2 3 4 5 6 7
	//2 3 4 9 5 6 7
	ps->_array[pos-1] = datda;
	ps->_size++;
}

// ����λ��ɾ�� 
void SeqListErase(PSeqList ps, int pos)
{
	assert(ps);
	for (int i = pos; i < ps->_size; ++i)
	{
		ps->_array[i-1] = ps->_array[i];
	}
	//2347567
	ps->_size--;
}

// ���data�Ƿ���˳����� 
int SeqListFind(PSeqList ps, DataType data)
{
	assert(ps);
	for (int i = 0; i < ps->_size; ++i)
	{
		if (ps->_array[i] == data)
		{
			return 1;
		}
	}
	return 0;
}

// �Ƴ�˳����е�һ��ֵΪdata��Ԫ�� 
void SeqListRemove(PSeqList ps, DataType data)
{
	assert(ps->_array>0);

	for (int i = 0; i < ps->_size; ++i)
	{
		if (ps->_array[i] == data)
		{
			for (int j = i + 1; j < ps->_size; ++j)
			{
				ps->_array[j - 1] = ps->_array[j];
			}
			ps->_size--;
		}
	}
}

// �Ƴ�˳���������ֵΪdata��Ԫ�� 
void SeqListRemoveAll(PSeqList ps, DataType data)
{
	assert(ps);
	int i = 0;
	int j = 0;
	for (; i < ps->_size; ++i)
	{
		if (ps->_array[i] != data)
		{
			ps->_array[j] = ps->_array[i];
			++j;
		}
	}
	ps->_size = j;
}

// ��ȡ˳�����ЧԪ�ظ��� 
int SeqListSize(PSeqList ps)
{
	int size = ps->_size;
	return size;
}

// ��ȡ˳�������� 
int SeqListCapacity(PSeqList ps)
{
	int capacity = ps->_capacity;
	return capacity;
}

// ���˳����Ƿ�Ϊ�� 
int SeqListEmpty(PSeqList ps)
{
	if (ps == NULL)
	{
		return 1;
	}
	return 0;
}

// ��ȡ˳����е�һ��Ԫ�� 
DataType SeqListFront(PSeqList ps)
{
	assert(ps->_size > 0);
	DataType size = ps->_array[0];
	return size;
}

// ��ȡ˳��������һ��Ԫ�� 
DataType SeqListBack(PSeqList ps)
{
	assert(ps);
	DataType a = ps->_array[ps->_size-1];
	return a;
}


//��ӡ˳���Ĵ洢����
void print(SeqList *ps)
{
	for (int i = 0; i < ps->_size; ++i)
	{
		printf("%d ", ps->_array[i]);
	}
	printf("\n");
}

int main()
{
	SeqList ps;//��ʼ�������������һ��ָ�����͵Ļ�������Ҫ��ʼ����
	SeqListInit(&ps);
	SeqListPushFront(&ps, 4);//ͷ��
	SeqListPushFront(&ps, 3);
	SeqListPushFront(&ps, 2);
	SeqListPushFront(&ps, 1);
	SeqListPushBack(&ps, 5);//β��
	SeqListPushBack(&ps, 6);
	SeqListPushBack(&ps, 7);
	SeqListPushBack(&ps, 8);
	print(&ps);			//12345678

	printf("%d\n", SeqListSize(&ps));//��ȡ˳����е���Ч����
	
	printf("%d\n", SeqListCapacity(&ps));// ��ȡ˳�������� 

	if (SeqListEmpty(&ps))// ���˳����Ƿ�Ϊ�� ���Ϊ�շ���1
	{
		printf("˳���Ϊ�գ�\n");
	}
	else { printf("��Ϊ��\n"); }

	
	printf("%d\n",SeqListFront(&ps));//��ȡ˳����е�һ��Ԫ�� 

	printf("%d\n", SeqListBack(&ps));// ��ȡ˳��������һ��Ԫ�� 
	

	SeqListPopBack(&ps);//βɾ
	print(&ps);			//1234567

	SeqListPopFront(&ps);//ͷɾ
	print(&ps);			//234567

	SeqListInsert(&ps, 4, 7);	// ����λ�ò��� 
	print(&ps);//2347567

	SeqListErase(&ps, 1);	// ����λ��ɾ�� 
	print(&ps);//347567

	SeqListErase(&ps, 4);	// ����λ��ɾ�� 
	print(&ps);//34767

	(SeqListFind(&ps, 8) == 1) ? printf("ok\n") : printf("no\n");
	(SeqListFind(&ps, 4) == 1) ? printf("ok\n") : printf("no\n");

	SeqListRemove(&ps, 4);//�Ƴ�˳�����ֵΪdata�ĵ�һ��Ԫ�� 
	print(&ps);
	SeqListRemoveAll(&ps, 7);//�Ƴ�˳���������ֵΪdata��Ԫ�� 
	print(&ps);
	printf("\n");
	SeqListPushBack(&ps, 8);
	SeqListPushBack(&ps, 8);
	SeqListPushBack(&ps, 8);
	SeqListPushBack(&ps, 8);
	SeqListPushBack(&ps, 8);
	SeqListPushBack(&ps, 8);
	SeqListPushBack(&ps, 8);
	SeqListPushBack(&ps, 8);
	SeqListPushBack(&ps, 8);
	SeqListPushBack(&ps, 8);
	SeqListPushBack(&ps, 8);
	print(&ps);//_capacity == 20
	
	SeqListDestroy(&ps);//����˳���
	print(&ps);

	system("pause");
	return 0;
}


//4. ��Ϥ˳������ȱ��