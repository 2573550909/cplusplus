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
//6. ��Ϥѭ�����У�������ѭ����������ж϶�����
//7. ʵ�ֶ��е����»�������
//typedef int * QDataType;
//
//// ��ʽ�ṹ����ʾ���� 
//typedef struct QListNode
//{
//	struct QListNode* _pNext;
//	QDataType _data;
//}QNode;
//
//// ���еĽṹ 
//typedef struct Queue
//{
//	QNode* _front;
//	QNode* _rear;
//}Queue;
//
//// ��ʼ������ 
//void QueueInit(Queue* q);
//
//// ��β����� 
//void QueuePush(Queue* q, QDataType data);
//
//// ��ͷ������ 
//void QueuePop(Queue* q);
//
//// ��ȡ����ͷ��Ԫ�� 
//QDataType QueueFront(Queue* q);
//
//// ��ȡ���ж�βԪ�� 
//QDataType QueueBack(Queue* q);
//
//// ��ȡ��������ЧԪ�ظ��� 
//int QueueSize(Queue* q);
//
//// �������Ƿ�Ϊ�գ����Ϊ�շ��ط�����������ǿշ���0 
//int QueueEmpty(Queue* q);
//
//// ���ٶ��� 
//void QueueDestroy(Queue* q);

//8. �ܽ�ջ�Ͷ��е�����
//9. ջ�Ͷ��в��ֵ�����OJ��Ŀ
//10. ��������ҵд�ɲ���
