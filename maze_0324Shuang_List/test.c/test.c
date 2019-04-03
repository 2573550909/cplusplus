#include <stdio.h>
#include<stdlib.h>
#include <assert.h>
#include <string.h>

typedef struct DNode
{
	int value;
	struct DNode *prev;//qian
	struct DNode *next;//hou
}	DNode;

//��ʼ��
void DListInit(DNode **node)
{
	//����ͷ���
	DNode* head = (DNode*)malloc(sizeof(DNode));
	head->next = head;
	head->prev = head;

	*node = head;
}

//ͷ��
void DListPushFront(DNode* head, int v)
{
	DNode* node = (DNode*)malloc(sizeof(DNode));
	node->value = v;

	node->next = head->next;
	node->prev = head;
	head->next->prev = node;
	head->next = node;
}

//β��
void DListPushBack(DNode* head,int v)
{
	DNode* node = (DNode*)malloc(sizeof(DNode));
	node->value = v;

	node->prev = head->prev;
	node->next = head;
	head->prev->next = node;
	head->prev = node;
}

//��ָ��λ�õĺ������
void DListInsertAfter(DNode* head, DNode* pos, int v)
{
	DNode* node = (DNode*)malloc(sizeof(DNode));
	node->value = v;

	node->prev = pos;
	node->next = pos->next;
	pos->next->prev = node;
	pos->next = node;
}

//��ָ��λ�õ�ǰ�����
void DListInsertBefore(DNode* head, DNode* pos, int v)
{
	DNode* node = (DNode*)malloc(sizeof(DNode));
	node->value = v;

	node->prev = pos->prev;
	node->next = pos;
	pos->prev->next = node;
	pos->prev = node;
}


//ͷɾ
void DListDelectFront(DNode*s)
{
	assert(s != NULL);
	DNode* node = s->next;
	s->next = s->next->next;
	free(node);
}

//βɾ
void DListDeleteBack(DNode*head)
{
	assert(head != NULL);
	DNode* node = head->prev;

	head->prev = head->prev->prev;
	free(node);
}

//��ָ��pos��λ�ú���ɾ��head
void DList_Delete_Pop_After(DNode* head, DNode* pos)
{
	assert(head != NULL);
	assert(pos != NULL);

	DNode* node = pos->next;
	pos->next = pos->next->next;
	pos->next->next->prev = pos;
	free(node);
}

//��ָ��pos��λ��ǰ��ɾ��head
void DList_Delete_Pop_Before(DNode*head, DNode* pos)
{
	assert(head != NULL);
	assert(pos != NULL);
	
	DNode* node = pos->prev;
	pos->prev = pos->prev->prev;
	pos->prev->prev->next = pos;
	free(node);
}


int main()
{

	DNode* p;
	DListInit(&p);
	
	//ͷ��
	DListPushFront(p, 10);
	DListPushFront(p, 20);
	DListPushFront(p, 30);
	DListPushFront(p, 40);
	//β��
	DListPushBack(p, 50);
	DListPushBack(p, 60);
	DListPushBack(p, 70);
	DListPushBack(p, 80);
	
	//��ָ��λ�õĺ������
	//void DListInsertAfter(p, DNode* pos, int v)

	////��ָ��λ�õ�ǰ�����
	//void DListInsertBefore(DNode* head, DNode* pos, int v)

	////ͷɾ
	//void DListDelectFront(DNode*s)

	////βɾ
	//void DListDeleteBack(DNode*head)

	////��ָ��pos��λ�ú���ɾ��head
	//void DList_Delete_Pop_After(DNode* head, DNode* pos)

	////��ָ��pos��λ��ǰ��ɾ��head
	//void DList_Delete_Pop_Before(DNode*head, DNode* pos)
	
	system("pause");
	return 0;
}