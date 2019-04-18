#pragma once
//1. ��Ϥջ�ĸ����Լ�����

//		��0������һ����������޵����Ա���Ϊ��2��
//		��1����ˮͰ�ʶ���һ�����Ƚ����������ȳ�	
//		��2��ջ���ǿ��Բ�����һ�ˣ�ջ�ײ��ɲ�����
//		pushѹ�룬top����
//		ջ���м������ã���ջ�Ĳ�����ɾ�������У�����Ҫ�ı�ջ��ָ��
//		
//2. ���ݽṹ��ջ�������ջ��ʲô��ͬ��
//@1���ݽṹ��ջ���������ݵ�һ���ֶλ����Ƿ�������������������ݺ͵�ַ��
//@2�ڴ��е�ջ����ȷ�д��ڵ�����ṹ����������Ų�ͬ���ݵ��ڴ�ռ䣻
//				��ϵͳ�Զ�������ͷŵģ��ɸߵ�ַ��͵�ַ��չ�����ݻ���
//				��һ���������ڴ������Ƕ����ݽṹջ�����ֶε�ʵ�֣�
//		һ����˵��ջ��ŵ��ǳ�����ջ�з���ֲ������ռ�

//3. ʵ��ջ�����½ӿڣ�
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int SDataType;
typedef struct Stack
{
	SDataType* _array;
	int _capacity;
	int _top; // ���ջ��λ�� 
}Stack;

// ��ʼ��ջ 
void StackInit(Stack* ps)
{
	assert(ps);
	ps->_capacity = 10;
	ps->_top = 0;
	ps->_array = 
		(SDataType*)malloc(sizeof(SDataType)*ps->_capacity);
}

// ��ջ 
void StackPush(Stack* ps, SDataType data)
{
	assert(ps);

	ps->_array[ps->_top++] = data;
}

// ��ջ 
void StackPop(Stack* ps)
{
	assert(ps);
	ps->_array[ps->_top--];
	
}

// ��ȡջ��Ԫ�� 
SDataType StackTop(Stack* ps)
{
	SDataType a = ps->_array[ps->_top-1];
	return a;
}

// ��ȡջ����ЧԪ�ظ��� 
int StackSize(Stack* ps)
{
	assert(ps);
	int count = 0;
	for (int i = 0; i < ps->_top; ++i)
	{
		++count;
	}
	return count;
}

// ���ջ�Ƿ�Ϊ�գ����Ϊ�շ��ط������������Ϊ�շ���0 
int StackEmpty(Stack* ps)
{
	assert(ps);
	if (ps->_top == 0)
	{
		return 1;
	}
	else{return 0;}
}

// ����ջ 
void StackDestroy(Stack* ps)
{
	assert(ps);
	if (ps->_array == NULL){return;}
	ps->_capacity = 0;
	ps->_top = 0;
	free(ps->_array);
	ps->_array = NULL;
	ps = NULL;
}

void print(Stack *ps)
{
	assert(ps);
	for (int i = 0; i < ps->_top; ++i)
	{
		printf("%d ", ps->_array[i]);
	}
	printf("\n");
}

void Test()
{
	Stack s;
	StackInit(&s);

	//ѹջ
	StackPush(&s, 1);
	StackPush(&s, 2);
	StackPush(&s, 3);
	StackPush(&s, 4);
	StackPush(&s, 5);
	StackPush(&s, 6);
	StackPush(&s, 7);
	StackPush(&s, 8);
	print(&s);
	if (StackEmpty(&s) == 0) 
	{ 
		printf("��Ϊ��!");
	}
	else { printf("Ϊ�գ�"); }
	printf("\n");
	
	StackPop(&s);// ��ջ 
	//StackPop(&s);
	//StackPop(&s);
	//StackPop(&s);
	print(&s);

	//��ȡջ��Ԫ�� 
	printf("%d\n", StackTop(&s));

	//��ȡջ����ЧԪ�ظ��� 
	printf("%d\n", StackSize(&s));

	// ����ջ 
	StackDestroy(&s);
	
	// ���ջ�Ƿ�Ϊ�գ����Ϊ�շ��ط������������Ϊ�շ���0 
	if (StackEmpty(&s) == 0)
	{
		printf("��Ϊ��!");
	}
	else { printf("Ϊ�գ�"); }

}

//4. ջ��Ӧ�ã�����ƥ�䡢�沨�����ʽ��ջ��ݹ�
//5. ��Ϥ���еĸ����Լ�����
//		һ����������Ա�---ֻ������ǰ�ˣ���ͷ��ɾ������ˣ���β������
//													---�����Ƶ����Ա�

//6. ��Ϥѭ�����У�������ѭ����������ж϶�����
//	˳����нṹ����Ҫ��̬��̬����һ���������ڴ�ռ䣬��������ָ�����
//  ---һ��ָ��ָ���ͷ��һ��ָ���β
// ˳��������������
	//��1�����磺������Ϊ��ʱ��������������������󣬳������������ת�Ƶ�����--��������
	//��2�������磺��������ʱ�������޷����в���--����ջ��������Ŀռ��������--Ҫ������������
	//��3�������磺������Ӻͳ��Ӳ����У�ͷָ��ֻ�����������±�ɾ���Ŀռ��޷����ã�
	//			 ������ʵ�ʸ���ԶԶС�������ռ��ģʱ��Ҳ��������βָ���Ѿ���Խ�����ռ�
	//			 ���Ͻ����������Ӳ���--
//ѭ������
//	���ã�  Ϊ��ʹ�Ѿ�ɾ���Ķ��пռ��ظ�ʹ��
//	�����ǣ����۲������ɾ��������һ������ָ�볬����������Ķ��пռ䣬
//	     	������ָ����Ƭ�����ռ����ʼλ��

//������Ϊ�յ�ʱ��rear=front
//������ȫռ��ʱ��rear=front
//���Ϊ���������������ѭ��������ֻ����MAXsize-1��Ԫ�أ���ѭ������ֻʣ��
//һ����ʱ������ˣ�����п������ǣ�front=rear,�������������ǣ�front=(rear+1)%MaxSIZE

//�ж�ѭ���������ķ�����
//��1������һ����������
//��2������һ��Ԫ�ؿռ䣬������ǿ�βָ���Ƿ�͵���ͷָ�룬�����������
//��3����һ����������¼������Ԫ�ص�������ֻҪ����Ԫ�ص��������ռ���Ƕ�������


//7. ʵ�ֶ��е����»�������
//typedef int * int ;

// ��ʽ�ṹ����ʾ���� 
typedef struct QListNode
{
	struct QListNode* _pNext;
	int  _data;
}	QNode;

// ���еĽṹ 
typedef struct Queue
{
	QNode* _front;
	QNode* _rear;
}	Queue;

// ��ʼ������ 
void QueueInit(Queue* q)
{
	q->_front = q->_rear = NULL;
}

// ��β����� 
void QueuePush(Queue* q, int  data)
{
	QNode* node = (QNode*)malloc(sizeof(QNode));

	node->_data = data;
	node->_pNext = NULL;
	if (q->_front == NULL)
	{
		q->_front = node;
		q->_rear = node;
	}
	else
	{
		q->_rear->_pNext = node;
		q->_rear = node;
	}
}

// ��ͷ������ 
void QueuePop(Queue* q)
{
	QNode* second = q->_front->_pNext;
	free(q->_front);
	q->_front = second;

	if (q->_front == NULL)
	{
		q->_rear = NULL;
	}
}

// ��ȡ����ͷ��Ԫ�� 
int  QueueFront(Queue* q)
{
	if (q->_front == NULL)
	{
		return 0;
	}

	return q->_front->_data;
}

// ��ȡ���ж�βԪ�� 
int  QueueBack(Queue* q)
{
	if (q->_rear == NULL)
	{
		return 0;
	}

	return q->_rear->_data;
}

// ��ȡ��������ЧԪ�ظ��� 
int QueueSize(Queue* q)
{
	if (q->_front == NULL || q->_rear == NULL)
	{
		return 0;
	}
	int size = 0;
	for (QNode* cur = q->_front; cur != NULL; cur = cur->_pNext)
	{
		++size;
	}
	return size;
}

// �������Ƿ�Ϊ�գ����Ϊ�շ��ط�����������ǿշ���0 
int QueueEmpty(Queue* q)
{
	if (q->_front == NULL)
	{
		return 1;
	}
	else { return 0; }
}

// ���ٶ��� 
void QueueDestroy(Queue* q)
{
	QNode* cur = q->_front;
	QNode* next;
	for (; cur != NULL; cur = next)
	{
		next = cur->_pNext;
		free(cur);
	}
	q->_front = q->_rear = NULL;
}

void print1(Queue *m ,int num)
{
	QNode* cur = m->_front;
	for (; cur!=NULL;cur = cur->_pNext)
	{
		printf("%d ", cur->_data);
	}
	printf("\n");
}

void Test1()
{

	Queue m;
	QueueInit(&m);

	QueuePush(&m, 1);
	QueuePush(&m, 2);
	QueuePush(&m, 3);
	QueuePush(&m, 4);
	QueuePush(&m, 5);
	QueuePush(&m, 6);
	
	int num = QueueSize(&m);
	printf("�����ﹲ��%d��Ԫ��\n", num);
	printf("�ֱ��ǣ�");
	print1(&m,num);

	QueuePop(&m);
	print1(&m, num);
	
	printf("%d\n",QueueFront(&m));

	printf("%d\n", QueueBack(&m));

	if (QueueEmpty(&m))
	{
		printf("�����ǿյ�!\n");
	}
	else { printf("��Ϊ��!\n"); }
	
	QueueDestroy(&m);
	if (QueueEmpty(&m))
	{
		printf("�����ǿյ�!\n");
	}
	else { printf("��Ϊ�գ�\n"); }
}


//8. �ܽ�ջ�Ͷ��е�����
//��ͬ�㣺
//��1���������Ƚ��ȳ���ջ���Ƚ������
//��2��������ֻ���ڱ�ĺ�˲��룬��ǰ��ɾ������ջ��ֻ����һ�˽��в���ɾ����
//��3���������ݵ��ٶȲ�ͬ������ջֻ����һ��ȡ�����ݣ���������ȷ���ľ�Ҫ����
//	 ����ջ�������ڱ������ݵ�ʱ��Ҫ������ʱ�ռ䣬���������ڱ���ǰ��һ���ԣ�
//	 
//	 �����ǻ��ڵ�ַָ����б��������ҿ��Դ�ͷ������β��������������ͬʱ����
//	 ����Ҫ������ʱ�ռ䣬
//��ͬ�㣺
//��1���������޵����Ա�

//9. ջ�Ͷ��в��ֵ�����OJ��Ŀ
//10. ��������ҵд�ɲ���
