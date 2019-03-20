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

//β��
void SListPushBack2(SList *s, SListDataType v)
{
	Node* node = (Node*)malloc(sizeof(Node));
	node->value = v;
	node->next = NULL;


	//������һ����㶼û�У���һ��������NULL
	//s->first
	if (s->first == NULL)
	{
		s->first = node;
	}
	else
	{
		Node *cur = s->first;
		while (cur->next != NULL)
		{
			cur = cur->next;
		}
		cur->next = node;
	}
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

//βɾ
void SListPopBack(SList *s)
{
	assert(s != NULL);
	assert(s->first != NULL);

	if (s->first->next == NULL)//������ֻ��һ�����
	{
		free(s->first);
		s->first = NULL;
		return;
	}

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

//��ת����
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

//β��
void PushBack2(SList *s, SListDataType v)
{
	Node *node = (Node *)malloc(sizeof(Node));
	node->value = v;
	node->next = NULL;
	if (s->first == NULL)
	{
		s->first = node;
	}
	else
	{
		//�����һ�����
		Node *p;
		p = s->first;
		while (p->next != NULL)
		{
			p = p->next;
		}
		p->next = node;
	}
}

//βɾ
void PopBack2(SList *s)
{
	//û�н�㣬ֱ��assert
	//ֻ��һ�����
	//����һ���������
	if (s->first->next == NULL)
	{
		free(s->first);
		s->first = NULL;
	}
	else
	{
		//ɾ�����һ����㣬�ҵ������ڶ������
		Node *p = s->first;
		while (p->next->next != NULL)
		{
			p = p->next;
		}

		free(p->next);
		p->next = NULL;
	}
}

//1.��������cur��㣬ʵ�ʸ��ĵĵط�һ����cur ��ǰ����㣻
//2.������һ��������������

/*
һ�ַ�����1->2->3->NULL
		  () ->1->2->3->NULL

	Node *fake_node = malloc(sizeof(Node));
	fack_node->next = first;

//������Ҫ�Ĳ�����������ʵ�Ľ�㶼��ǰ�����
	free(fake_node);

*/

//����
Node *SListFind(SList *s, SListDataType v)
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

//��pos�ĺ������һ����㣬pos һ���������еĽ��
void SListInsertAfter(SList *s , Node* pos,SListDataType v)
{
	Node *node = (Node*)malloc(sizeof(Node));
	node->value = v;
	node->next = pos->next;
	pos->next = node;
}

//pos һ���������еĽ�㣬����pos ������������һ�����
void SListEraseAfter(SList *s, Node *pos)
{
	Node *next = pos->next;//����һ�����
	pos->next = pos->next->next;
	free(next);
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

// ��ת��������������ָ��ķ��������з�ת
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
		else
		{
			cur = cur->next;
		}
	}
	if (head->value == val)
	{
		Node* newHead = head->next;
		free(head);
		return newHead;
	}
	else
	{
		return head;
	}
}


