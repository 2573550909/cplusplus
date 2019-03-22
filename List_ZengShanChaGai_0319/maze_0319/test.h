#pragma once
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

typedef int SListDataType;

//����Ĳ�������Ľṹ�壬����������һ���ڵ�Ľṹ��
typedef struct ListNode
{
	SListDataType value;	//�����ֵ
	struct ListNode *next;  //������һ���ĵ�ַ
}	Node;

typedef struct SList
{
	Node *first;//Node *head;
}	SList;

//��ʼ��
void SListInit(SList *s)
{
	assert(s != NULL);
	s->first = NULL;
}

void SListInit2(SList *s)
{
	assert(s != NULL);
	s->first = NULL;
}

void Test()
{
	SList list;
	SListInit(&list);
}

//ͷ��
void SListPushFront(SList *s, SListDataType v)
{
	Node *node = (Node *)malloc(sizeof(Node));
	node->value = v;
	node->next = s->first;
	s->first = node;
}


void SListPushFront2(SList *p, SListDataType v)
{
	assert(p != NULL);
	Node * node = (Node*)malloc(sizeof(Node));
	node->value = v;
	node->next = p->first;
	p ->first = node;

	if (p->first == NULL)
	{
		p->first = node;
	}
}
//β��
void SListPushBack(SList *s, SListDataType v)
{
	Node *node = (Node*)malloc(sizeof(Node));
	node->value = v;
	node->next = NULL;

	if (s->first == NULL)
	{
		s->first = node;
		return;
	}

	//������������һ�����
	Node* cur = s->first;
	while (cur->next != NULL)
	{
		cur = cur->next;
	}
	cur->next = node;
}


void SListPushBack2(SList *p, SListDataType v)
{
	assert(p != NULL);
	Node* node = (Node*)malloc(sizeof(Node));
	node->next = NULL;

	if (p->first == NULL)
	{
		p->first = node;
	}

	Node* cur = p->first;
	while (cur != NULL)
	{
		cur = cur->next;
	}
	cur->next = node;
}
//ͷɾ
void SListPopFront(SList *s)
{
	assert(s != NULL);		 //����û������
	assert(s->first != NULL);//����û�н��
	Node *next = s->first->next;
	free(s->first);
	s->first = next;
}

void SListPopFront(SList *p)
{
	assert(p != NULL);
	if (p->first == NULL)
	{
		return;
	}

	if (p->first->next == NULL)
	{
		free(p->first);
		return;
	}

	Node* cur = p->first->next;
	free(p->first);
	p->first = cur;
}

//βɾ
void SListPopBack3(SList *s)
{
	assert(s != NULL);
	assert(s->first != NULL);

	if (s->first->next == NULL)//������ֻ��һ�����
	{
		free(s->first);
		s->first = NULL;
		return;
	}

	// 1 -> 5 -> 6 -> 2 -> 4 -> NULL
	// 1    2    3    4    5    6  
	Node *cur = s->first;
	for (; cur->next->next != NULL;cur = cur->next)
	{
		;
	}
	//cur ���ǵ����ڶ������
	//cur->next->next = NULL
	free(cur->next);
	cur->next = NULL;
}

//βɾ
void SListPopBack2(SList *s)
{
	//ֻ��һ�����
	if (s->first->next == NULL)
	{
		free(s->first);
		s->first = NULL;
	}

	//����һ�����
	else
	{
		Node* cur = s->first;
		while (cur->next->next != NULL)
		{
			cur = cur->next;
		}
		free(cur->next);
		cur->next = NULL;
	}
}

void SListPopBack(SList *p)
{
	assert(p != NULL);
	if (p->first == NULL)
	{
		return;
	}

	Node* cur = p->first;
	while (cur->next->next != NULL)
	{
		cur = cur->next;
	}
	free(cur->next);
	cur->next = NULL;
}

//��ת����
//   1  ->  5  ->  4  ->  6  ->  8  ->  9  -> NULL
//           ->              cur
//       ->          node
//   1  <-  5  <-  4  <-  6  <-  8  <-  9  <- node

struct ListNode* reverseList2(struct ListNode * head)
{
	assert(head != NULL);


}
//1.��������cur��㣬ʵ�ʸ��ĵĵط�һ����cur ��ǰ����㣻
//2.������һ��������������


//����
Node* SListFind(SList *s, SListDataType v)
{
	for (Node *cur = s->first; cur != NULL; cur = cur->next)
	{
		if (cur->value == v)
		{
			return cur;
		}
	}
	return NULL;
}

Node* SListSearch(SList *s, SListDataType val)
{
	assert(s != NULL);

	Node* cur = s->first;
	while (cur->next != NULL)
	{
		if (cur->value == val)
		{
			return cur;
		}
		cur = cur->next;
	}
	return NULL;
}
//��pos�ĺ������һ����㣬pos һ���������еĽ��
void SListInsertAfter(SList *s , Node* pos,SListDataType v)
{
	Node *node = (Node*)malloc(sizeof(Node));
	node->value = v;
	node->next = pos->next;
	pos->next = node;
}

void SeqListInsertAfter2(SList *p, Node* pos, SListDataType val)
{
	assert(p != NULL);
	assert(pos != NULL);

	Node* node = (Node*)malloc(sizeof(Node));
	node->value = val;
	node->next = pos->next;
	pos->next = node;
}
//pos һ���������еĽ�㣬���� pos ������������һ�����
//ɾ�� pos ����Ľ��
void SListEraseAfter(SList *s, Node *pos)
{
	Node *next = pos->next;//����һ�����
	pos->next = pos->next->next;
	free(next);
}

void SListEraseAfter2(SList *p, Node *pos)
{
	assert(p != NULL);
	assert(pos != NULL);
	//  1 -> 2 -> 3 -> 4 -> 5 -> 6 -> NULL
	Node* cur = pos->next;
	pos->next = pos->next->next;
	free(cur);
}
//������������
void SListDestroy(SList *s)
{
	Node *next;
	for (Node* cur = s->first; cur != NULL; cur = next)
	{
		next = cur->next;
		free(cur);
	}
	s->first = NULL;
}

void SListDestroy2(SList *p)
{
	assert(p != NULL);
	Node* cur = p->first;
	Node* s;
	while (cur != NULL)
	{
		s = cur->next;
		free(cur);
		cur = s;
	}
}
// ��ת��������������ָ��ķ��������з�ת
// ��ת����
//   NULL -> 1  ->  5  ->  4  ->  6  ->  8  ->  9  -> NULL
//   NULL <- 1  <-  5  ->  4  ->  6  ->  8  <-  9  -> NULL
//                                             pre 
//	                                                  cur   
//                                                    next
Node * Reverse(Node *head)
{
	Node *prev = NULL;
	Node *cur = head;

	while (cur != NULL)
	{
		Node *next = cur->next;

		cur->next = prev;
		prev = cur;
		cur = next;
	}
	return prev;
}

struct ListNode* reverseList(struct ListNode * head)
{
	struct ListNode *newHead = NULL;
	struct ListNode *cur = head;
	while (cur != NULL)
	{
		struct ListNode* node = cur;
		cur = cur->next;

		//��node ���뵽������ newHead
		node->next = newHead;
		newHead = node;
	}
	return newHead;
}

//ɾ��v����Ӧ�Ľ��
void SListRemove(SList *s, SListDataType v)
{
	if (s->first == NULL)
	{
		//����Ϊ��
		return;
	}

	if (s->first->value == v)
	{
		//v���ǵ�һ���������
		Node *next = s->first->next;
		free(s->first);
		s->first = next;
		return;
	}
	Node *cur = s->first;
	while (cur->next != NULL)
	{
		if (cur->next->value == v)
		{
			Node *next = cur->next->next;
			free(cur->next);
			cur->next = next;
			return;
		}
		cur = cur->next;
	}
}

//ɾ��v��Ӧ�����н��
struct ListNode* removeElements(struct ListNode* head, int val)
{
	if (head == NULL)
	{
		return NULL;
	}

	//�Ȳ��ܵ�һ���������
	struct ListNode* cur = head;
	while (cur->next != NULL)
	{
		if (cur->next->value == val)
		{
			struct ListNode* next = cur->next->next;
			free(cur->next);
			cur->next = next;
		}
		cur = cur->next;
	}

	if(head->value == val)
	{
		Node* newHead = head->next;
		free(head);
		return newHead;
	}
	return head;
}


