#include <stdio.h>
#include <stdlib.h>
#include <assert.h>


////ͷ��
//void PushFront(Node* head, Node* node)
//{
//	assert(head != NULL);
//	assert(node != NULL);
//
//	node->next = head
//	head = node;
//
//}
//
////β��
//void PushBack(Node* head, Node* node)
//{
//	assert(head != NULL);
//	assert(node != NULL);
//	node->next = NULL;
//	if(head == NULL)
//	{
//		head = node;
//	}
//	else
//	{
//		Node* last = GetLastNode(head);
//		last->next = node;
//	}
//}
//
//
//Node* Reverse(Node* head)
//{
//	Node* cur = head;
//	Node* result = NULL;
//	while (cur != NULL)
//	{
//		Node* next = cur->next;
//
//		cur->next = result;
//		result = cur;
//
//		cur = next;
//	}
//	return result;
//}

//==================================================
//ջ

typedef struct Stack
{
	int array[100];
	int size;
}	Stack;

//����,ѹջ
void StackPush(	Stack *s ,int v)
{
	s->array[s->size++] = v;
}

//ɾ��,����,��ջ
void StackPop(Stack* s)
{
	s->size--;
}

void StackTop()
{

}


//����
void QueneInit(satc)
{

}



int main()
{
	//�����ͷ��/ͷɾ/β��/βɾ		1
	//����							2
	//ɾ���ظ�ϵ���/���Ƹ�������	3



	system("pause");
	return 0;
}
