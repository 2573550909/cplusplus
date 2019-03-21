#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

typedef struct Node {
	int value;
	struct Node *next;
}	Node;

//���� (1)ͷɾ��ͷɾ
Node* Reverse(Node *head)
{
	Node* result = NULL;
	Node* cur = head;
	while (cur != NULL)
	{
		Node* next = cur->next;
		//��curͷ�嵽result����
		cur->next = result;
		result = cur;
		cur = next;
	}
}
//����--����ָ��
Node* Reverse2(Node *head)
{
	if (head == NULL)
	{
		return NULL;
	}
	Node* p1 = NULL;
	Node* p2 = head;
	Node* p3 = head->next;
	while (p2 != NULL)
	{
		p2->next = p1;
		p1 = p2;
		p2 = p3;
		if (p3 != NULL)
		{
			p3 = p3->next;
		}
	}
	return p1;
}


//�ϲ�������������
Node *MergeOrderedList(Node *L1, Node* L2)
{
	Node* n1 = L1;
	Node* n2 = L2;
	Node* last = NULL;
	Node* first = NULL;
	while (n1!=NULL && n2!=NULL)
	{
		if (n1->next <= n2->next)
		{
			if (last == NULL)
			{
				first = last = n1;
			}
			else
			{
				last->next = n1;
				last = n1;
			}
			n1 = n1->next;
		}
		else
		{
			if (last == NULL)
			{
				first = last = n2;
			}
			else
			{
				last->next = n2;
				last = n2;
			}
		}
	}
	//n1��n2��һ��Ϊ��
	if (n1 != NULL)
	{
		last->next = n1;
	}
	if (n2 != NULL)
	{
		last->next = n2;
	}
}





int main()
{



	system("pause");
	return 0;
}