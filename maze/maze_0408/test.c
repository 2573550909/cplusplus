#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct ListNode
{
	int val;
	ListNode* next;
}	ListNode;


////A   a1 a2 c1 c2 c3
////B   b1 b2 b3 c1 c2 c3
//ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) 
//{
//	if (headA == NULL || headB == NULL)
//	{
//		return NULL;
//	}
//	ListNode* pA = headA, *pB = headB;
//	//�������һ��������pA��pB��һ�ε���β����������һ����ı�ͷ,
//	//���ڶ������������pA��pB�ཻ�ͷ��ؽ���, ���ཻ������null==null
//	while (pA != pB) {
//		pA = pA == NULL ? headB : pA->next;
//		pB = pB == NULL ? headA : pB->next;
//	}
//	return pA;
//}
//
//ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
//{
//	if (headA == NULL || headB == NULL)
//	{
//		return NULL;
//	}
//	ListNode* pA = headA, *pB = headB;
//	//�������һ��������pA��pB��һ�ε���β����������һ����ı�ͷ,
//	//���ڶ������������pA��pB�ཻ�ͷ��ؽ���, ���ཻ������null==null
//
//	while (pA != pB)
//	{
//		if (pA == NULL)
//		{
//			pA = headB;
//		}
//		else
//		{
//			pA = pA->next;
//		}
//		if (pB == NULL)
//		{
//			pB = headA;
//		}
//		else
//		{
//			pB = pB->next;
//		}
//	}
//	return pA;
//}
//
//bool hasCycle(ListNode *head)
//{
//	if (head == NULL)
//	{
//		return false;
//	}
//	ListNode* fast = head;
//	ListNode* slow = head;
//
//	while (fast != slow)
//	{
//		fast = fast->next->next;
//		slow = slow->next;
//	}
//	return true;
//}
//bool hasCycle(ListNode *head)
//{
//	if (head == NULL || head->next == NULL)
//	{
//		return false;
//	}
//	ListNode* fast = head->next;
//	ListNode* slow = head;
//
//	while (fast != slow)
//	{
//		if (fast == NULL || slow == NULL)
//		{
//			return false;
//		}
//		slow = slow->next;
//		if (fast->next == NULL)
//		{
//			return false;
//		}
//		fast = fast->next->next;
//	}
//	return true;
//}

ListNode *detectCycle(ListNode *head)
{
	if (head == NULL || head->next == NULL)
	{
		return NULL;
	}
	ListNode* A = head;
	ListNode* B = head;
	int count = 0;
	while (A != B)
	{
		++count;
		if (A == NULL || B == NULL)
		{
			return false;
		}
		B = B->next;
		if (A->next == NULL)
		{
			return false;
		}
		A = A->next->next;
	}


	return true;
}
ListNode* detectCycle(ListNode* head)
{
	if (head == NULL || head->next == NULL) {return NULL;}
	ListNode* slow = head;
	ListNode* fast = head;
	while (fast != NULL && fast->next != NULL) {
		fast = fast->next->next;
		slow = slow.next;
		if (slow == fast)//you huan 
		{
			slow = head;
			while (slow != fast)
			{
				slow = slow.next;
				fast = fast.next;
			}
			return slow;
		}
	}
	return null;
}

ListNode* detectCycle(ListNode* head)
{
	if (head == NULL || head->next == NULL)
	{
		return NULL;
	}
	ListNode* fast = head;
	ListNode* slow = head;
	ListNode* p = head;
	while (fast != NULL && fast->next!=NULL)
	{
		fast = fast->next->next;
		slow = slow->next;
		//����л��Ļ�
		if (fast == slow)
		{
			while (fast != p)
			{
				fast = fast->next;
				p = p->next;
			}
			return p;
		}
	}
	return NULL;
}


int main()
{



	systema("pause");
	return 0;
}