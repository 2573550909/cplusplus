#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct ListNode
{
	int val;
	ListNode* next;
}	ListNode;

//����һ������ͷ��� head �ķǿյ���������������м��㡣
//����������м��㣬�򷵻صڶ����м��㡣
ListNode* middleNode(ListNode* head)
{
	ListNode* fast = head;
	ListNode* low = head;

	while (fast != NULL && (fast->next != NULL))
	{
		low = low->next;
		fast = fast->next->next;
	}
	return low;
}
//���������������������k�����
ListNode* middleNode(ListNode* head) 
{
	int i = 1;
	ListNode* flag = head;
	while (flag->next != NULL) 
	{
		i++;
		flag = flag->next;
	}
	i >>= 1;
	for (int j = 0; j < i; j++)
	{
		head = head->next;
	}
	return head;
}

ListNode* FindKthToTail(ListNode* pListHead, unsigned int k)
{
	ListNode* p = pListHead;
	ListNode* q = pListHead;

	int i = 1;
	for (; q!= NULL; ++i)
	{
		q = q->next;
	}

	int j = 0;
	while (j < i - k)
	{
		p = p->next;
		++j;
	}
	return p;
}

////���������������������k�����
ListNode* FindKthToTail(ListNode* pListHead, unsigned int k)
{
	if (pListHead == NULL)
	{
		return NULL;
	}
	if (k == 0)
	{
		return NULL;
	}

	ListNode* p1 = pListHead;
	ListNode* p2 = pListHead;
	int count = 0;

	while (p1!= NULL)
	{
		++count;
		p1 = p1->next;
	}

	for (int i = 0; i < count - k; ++i)
	{
		p2 = p2->next;
	}
	return p2;
}


//���������������������k�����
ListNode* FindKthToTail(ListNode* pListHead, unsigned int k)
{
	if (pListHead == NULL || k == 0)
	{
		return NULL;
	}

	ListNode* pTail = pListHead;
	ListNode* pHead = pListHead;

	for (int i = 1; i < k; ++i)
	{
		if (pHead->next != NULL)
		{
			pHead = pHead->next;
		}
		else
		{
			return NULL;
		}
	}

	while (pHead->next != NULL)
	{
		pHead = pHead->next; 
		pTail = pTail->next;
	}   
	return pTail;
}

//��������������ϲ�Ϊһ���µ������������ء�
//��������ͨ��ƴ�Ӹ�����������������нڵ���ɵġ�
//���룺1->2->4, 1->3->4
//�����1->1->2->3->4->4
ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
{
	if (l1 == NULL) { return l2; }
	if (l2 == NULL) { return l1; }
	ListNode* first = NULL;
	ListNode* last = NULL;

	while (l1 != NULL && l2 != NULL)
	{
		if (l1->val <= l2->val)
		{
			if (last == NULL)
			{
				first = last = l1;
			}
			else
			{
				last->next = l1;
				last = l1;
			}
			l1 = l1->next;
		}
		else
		{
			if (last == NULL)
			{
				first = last = l2;
			}
			else
			{
				last->next = l2;
				last = l2;
			}
			l2 = l2->next;
		}
	}
	if (l1 != NULL)
	{
		last->next = l1;
	}
	if (l2 != NULL)
	{
		last->next = l2;
	}
	return first;
}


ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
{
	if (l1 == NULL) { return l2; }
	if (l2 == NULL) { return l1; }

	ListNode *n1 = l1, *n2 = l2;
	ListNode *first = NULL;	// �ϲ��������ĵ�һ�����
	ListNode *last = NULL;	// �ϲ������������һ�����
	while (n1 != NULL && n2 != NULL)
	{
		if (n1->val <= n2->val)
		{
			if (last == NULL)
			{
				// �������������û�н�㣬��β���������
				// �������һ�����
				first = last = n1;
			}
			else
			{
				// ��ԭ�����һ������ next = n1
				last->next = n1;
				// n1 ����µ����һ�����
				last = n1;
			}

			n1 = n1->next;
		}
		else
		{
			if (last == NULL)
			{
				// �������������û�н�㣬��β���������
				// �������һ�����
				first = last = n2;
			}
			else
			{
				// ��ԭ�����һ������ next = n2
				last->next = n2;
				// n1 ����µ����һ�����
				last = n2;
			}

			n2 = n2->next;
		}
	}

	// n1 ���� n2 ��һ��Ϊ NULL
	// һ����������н�㶼��������
	// ��ʣ������������ last ��߾Ϳ�����
	if (n1 != NULL) {
		last->next = n1;
	}

	if (n2 != NULL) {
		last->next = n2;
	}

	return first;
}

//���룺1->2->4, 1->3->4
//�����1->1->2->3->4->4
ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) 
{
	if (l1 == NULL) { return l2; }
	if (l2 == NULL) { return l1; }
	ListNode* n1 = l1;
	ListNode* n2 = l2;
	ListNode* newlist = NULL;
	ListNode* first = NULL;


	if (n1->next < n2->next)
	{
		first = newlist = n1;
		n1 = n1->next;
	}
	else
	{
		first = newlist = n2;
		n2 = n2->next;
	}

	while (n1 != NULL && n2 != NULL)
	{
		if (n1->next <= n2->next)
		{
			newlist->next = n1;
			newlist = n1;

			n1 = n1->next;
		}
		else
		{
			newlist->next = n2;
			newlist = n2;

			n2 = n2->next;
		}
	}
	if (n1 == NULL)
	{
		newlist->next = n2;
	}
	if (n2 == NULL)
	{
		newlist->next = n1;
	}

	return first;
}

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
{
	if (l1 == NULL)
	{
		return l2;
	}
	if (l2 == NULL)
	{
		return l1;
	}
	ListNode* mergeHead = NULL;
	if (l1->val <= l2->val)
	{
		mergeHead = l1;
		mergeHead->next = mergeTwoLists(l1->next, l2);
	}
	else 
	{
		mergeHead = l2;
		mergeHead->next = mergeTwoLists(l2->next, l1);
	}
	return mergeHead;
}


int main()
{



	system("pause");
	return 0;
}
