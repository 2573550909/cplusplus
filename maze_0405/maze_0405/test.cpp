#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct ListNode
{
	int val;
	struct ListNode *next;	
}	ListNode;

ListNode* partition(ListNode* pHead, int x)
{
	ListNode* cur = pHead;
	ListNode* last_small = NULL;
	ListNode* last_big = NULL;
	ListNode* first_small = NULL;
	ListNode* first_big = NULL;
	while (cur != NULL)
	{
		if (cur->val < x)//x=5 
		{
			if (last_small == NULL)
			{
				first_small = last_small = cur;
			}
			else
			{
				last_small->next = cur;
				last_small = cur;
			}
		}
		else
		{
			if (last_big == NULL)
			{
				first_big = last_big = cur;
			}
			else
			{
				last_big->next = cur;
				last_big = cur;
			}
		}
		cur = cur->next;
	}
	if (last_big != NULL)
	{
		last_big->next = NULL;
	}
	if (last_small != NULL)
	{
		last_small->next = first_big;
	}
	else
	{
		first_small = first_big;
	}
	return first_small;
}
	
void print(ListNode* a1)
{
	ListNode* cur = a1;
	while (cur != NULL)
	{
		printf("%d->", cur->val);
		cur = cur->next;
	}
	printf("NULL");
	printf("\n");
}

//��һ������������У������ظ��Ľ�㣬��ɾ�����������ظ��Ľ�㣬
//�ظ��Ľ�㲻��������������ͷָ�롣
//���磬����1->2->3->3->4->4->5 �����Ϊ 1->2->5
ListNode* deleteDuplication(ListNode* pHead)
{
	if (pHead == NULL)
	{
		return NULL;
	}
	ListNode* fake = (ListNode*)malloc(sizeof(ListNode));
	fake->next = pHead;

	ListNode* pre = fake;
	ListNode* p1 = pHead;
	ListNode* p2 = pHead->next;
	while (p2 != NULL)
	{
		if (p1->val != p2->val)
		{
			pre = p1;
			p1 = p2;
			p2 = p2->next;
		}
		else
		{
			while (p2 != NULL && p2->val == p1->val)
			{
				p2 = p2->next;
			}
			pre->next = p2;
			p1 = p2;
			if (p2 != NULL)
			{
				p2 = p2->next;
			}
		}
	}
	pHead = fake->next;
	free(fake);
	return pHead;
}

ListNode* deleteDuplication2(ListNode* pHead)
{ 
	//��ֹ����
	if (pHead == NULL)
	{
		return NULL;
	}
	if (pHead != NULL && pHead->next == NULL)
	{
		return pHead;
	}

	ListNode* current;
	if (pHead->next->val == pHead->val)
	{
		current = pHead->next->next;
		while (current != NULL && current->val == pHead->val)
		{
			current = current->next;
		}
		return deleteDuplication(current); 
	}
	else
	{
		current = pHead->next;
		pHead->next = deleteDuplication(current);
		return pHead; 
	}
}


//����һ�����������һ��ʱ�临�Ӷ�ΪO(n), ����ռ临�Ӷ�ΪO(1)���㷨��
//�ж����Ƿ�Ϊ���Ľṹ��
//����һ�������ͷָ��A���뷵��һ��boolֵ���������Ƿ�Ϊ���Ľṹ��
//��֤������С�ڵ���900��
//����������  1->2->2->1  ���أ�true
class PalindromeList {
public:
	bool chkPalindrome(ListNode* A) {
		if (A == NULL)
		{
			return false;
		}
		if (A->next == NULL)
		{
			return true;
		}

		ListNode* pHead = A;
		ListNode* fast = pHead;
		ListNode* slow = pHead;
		ListNode* pp;
		pp->next = A;

		//Ŀ����ʹ:��ָ���ߵ��е����һ����λ����
		//1->2->3->4->4->3->2->1->NULL
		while (fast != NULL && fast->next !=NULL)
		{
			fast = fast->next->next;
			slow = slow->next;
			pp = pp->next;
		}
		//��ʱfast��NULL��low�ڵڶ���4��λ����

		//Ȼ��4->3->2->1->NULL  ��ת����ָ��ָ��1  
		//�õ���������1->2->3->4
		ListNode* cur = slow->next;
		ListNode* p = cur->next;
		while (cur != NULL)
		{
			cur->next = pp;
			pp = cur;
			cur = p;
			p = p->next;
		}

		while (cur->next != pHead)
		{
			if (cur->val != pHead->val)
			{
				return false;
			}
			cur = cur->next;
			pHead = pHead->next;
		}
		return true;
	}
};
int main()
{
	ListNode* a1 = (ListNode*)malloc(sizeof(ListNode));
	ListNode* a2 = (ListNode*)malloc(sizeof(ListNode));
	ListNode* a3 = (ListNode*)malloc(sizeof(ListNode));
	ListNode* a4 = (ListNode*)malloc(sizeof(ListNode));
	ListNode* a5 = (ListNode*)malloc(sizeof(ListNode));
	ListNode* a6 = (ListNode*)malloc(sizeof(ListNode));
	ListNode* a7 = (ListNode*)malloc(sizeof(ListNode));
	a1->next = a2; a2->next = a3; a3->next = a4; 
	a4->next = a5;a5->next = a6; a6->next = a7; 
	//1->2->5->7->3->9->4
	a1->val = 1; a2->val = 2; a3->val = 3; a4->val = 3;
	a5->val = 4;a6->val = 4; a7->val = 5; a7->next = NULL;

	print(a1);
	deleteDuplication2(a1);
	print(a1);

	system("pause");
	return 0;
}
