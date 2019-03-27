#include <stdio.h>
#include <stdlib.h>
#include <assert.h>


////ͷ��
//void PushFront(Node* head, Node* node)
//{
//	node->next = head;
//	head = node;
//}


//static Node* GetLastNode(Node * head)
//{
//	Node* last = head;
//	while (last->next != NULL)
//	{
//		last = last->next;
//	}
//	return last;
//}
//
////β��
//void PushBack(Node* head, Node* node)
//{
//	node->next = NULL;
//	if (head == NULL)
//	{
//		head = node;
//	}
//	else
//	{
//		Node* last = GetLastNode(head);
//		last->next = node;
//	}
//}

//Node* Reverse(Node* head)
//{
//	Node* cur = head;//��������
//	Node* result = NULL;//�������
//
//	while (cur != NULL)
//	{
//		Node* p = cur->next;
//
//		cur->next = result;
//		result = cur;
//
//		cur = p;
//	}
//	return result;
//}

//=================================================================//

//ջ�Ͷ���
//��̬˳���
typedef struct Stack
{
	int array[100];
	int size;//���ݸ������±�
}	Stack;

//��ʼ��
void StackInit(Stack *s)
{
	s->size = 0;
}

//����
void StackDestroy(Stack *s)
{
	s->size = 0;
}

//����,ѹջ
void StackPush(Stack* s,int v)
{
	s->array[s->size++] = v;
}

//ɾ��,��������ջ
void StackPop(Stack* s)
{
	s->size--;
}

//����ջ��Ԫ�أ�����Ҫɾ��ջ��Ԫ��
int StackPop(Stack* s)
{
	return s->array[s->size - 1];
}

//����ջ��Ԫ�ظ���
int StackTop(Stack* s)
{
	return s->size;
}

//����ջ���Ƿ��ǿ�ջ������0��ʾ���ǿգ����ط�0��ʾ�ǿ�
int StackEmpty(Stack* s)
{
	return !(s->size);
}

//==================================================================
//����

typedef struct Node
{
	int value;
	struct Node* next;
}	Node;

typedef struct Queue
{
	Node* head;//����ĵ�һ�����
	Node* last;//��������һ�����
}	Queue;

void QueueInit(Queue *q)
{
	q->head = q->last = NULL;
}

void QueueDestroy(Queue *q)
{
	Node* cur, *next;
	for (cur = q->head; cur != NULL; cur = next)
	{
		next = cur->next;
		free(cur);
	}
	q->head = q->last = NULL;
}


void QueuePush(Queue *q, int v)
{
	Node* node = (Node*)malloc(sizeof(Node));
	node->value = v;
	node->next = NULL;
	if (q->head == NULL)
	{
		q->head = node;
		q->last = node;
	}
	else
	{
		q->last->next = node;
		q->last = node;
	}
}

//ɾ��
void QueuePop(Queue *q)
{
	Node* second = q->head->next;
	free(q->head);
	q->head = second;
	// last��Ҫ���

	//��Ϊ��������ֻ��һ����㣬
	if(q->head == NULL)
	{
		q->last = NULL;
	}
}

int QueueFront(Queue* q)
{
	return q->head->value;
}

int QueueSize(Queue* q)
{
	int size = 0;
	for (Node* c = q->head; c != NULL; c = c->next)
	{
		size++;
	}
	return size;
}

int QueueEmpty(Queue *q)
{
	if (q->head == NULL)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
//=============================================================
//������1.

int main()
{


	system("pause");
	return 0;
}