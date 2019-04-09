#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct ListNode 
{
	int val;
	struct ListNode* next;
}	ListNode;

//��д���룬�Ը���ֵxΪ��׼������ָ�������֣�
//����С��x�Ľ�����ڴ��ڻ����x�Ľ��֮ǰ
//����һ�������ͷָ�� ListNode* pHead��
//�뷵���������к�������ͷָ�롣ע�⣺�ָ��Ժ󱣳�ԭ��������˳�򲻱䡣
// 1->2->5->7->3->9->4    int x = 5


//ListNode* partition(ListNode* pHead, int x)
//{
//	ListNode* cur = pHead;
//	ListNode* last_small = NULL;
//	ListNode* last_big = NULL;
//	ListNode* first_small = NULL;
//	ListNode* first_big = NULL;
//	
//	while (cur != NULL)
//	{
//		if (cur->val < x)//x=5 
//		{
//			if (last_small == NULL)
//			{
//				first_small = last_small = cur;
//			}
//			else
//			{
//				last_small->next = cur;
//				last_small = cur;
//			}
//		}
//		else
//		{
//			if (last_big == NULL)
//			{
//				first_big = last_big = cur;
//			}
//			else
//			{
//				last_big->next = cur;
//				last_big = cur;
//			}
//		}
//		cur = cur->next;
//	}
//
//	if (last_big != NULL)
//	{
//		last_big->next = NULL;
//	}
//	if (last_small != NULL)
//	{
//		last_small->next = first_big;
//	}
//	else
//	{
//		first_small= first_big;
//	}
//	return first_small;
//}
//
////// 1->2->5->7->3->9->4    int x = 5
////ListNode* partition(ListNode* pHead, int x)
////{        
////	ListNode* beforeStart=NULL;
////	ListNode* beforeEnd=NULL;
////	ListNode* afterstart = NULL;
////	ListNode *afterEnd = NULL;
////	ListNode* headval;
////	while(pHead)
////	{            
////		headval=pHead->next;
////		if(pHead->val<x) 
////		{                
////			if (beforeEnd == NULL)
////			{
////				beforeEnd = beforeStart = pHead;
////			}
////			else
////			{                    
////				beforeEnd->next=pHead;
////				beforeEnd=pHead;
////			}            
////		}           
////		else
////		{                
////			if(afterstart==NULL)
////			{                    
////				afterstart = afterEnd = pHead;
////			}                
////			else
////			{                    
////				afterEnd->next=pHead;
////				afterEnd=pHead;
////			}            
////		}            
////		pHead=headval;
////	}        
////	if (afterEnd)
////	{
////		afterEnd->next = NULL;
////	}
////	if (beforeEnd != NULL)
////	{
////		beforeEnd->next = afterstart;
////	}
////	else
////	{
////		beforeStart = afterstart;
////	}
////	return beforeStart;
////}
//
//void print(ListNode* p)
//{
//	while (p != NULL)
//	{
//		printf("%d->", p->val);
//		p = p->next;
//	}
//	printf("NULL\n");
//}

////��һ������������У������ظ��Ľ�㣬
////��ɾ�����������ظ��Ľ�㣬�ظ��Ľ�㲻��������������ͷָ�롣
////���磬����1->2->3->3->4->4->5 �����Ϊ 1->2->5
//ListNode* deleteDuplication(ListNode* pHead)
//{
//	ListNode* cur = pHead;
//	ListNode* res = pHead + 1;
//	while (res != NULL)
//	{
//		if (cur->val == res->val)
//		{
//
//
//
//		}
//		cur = cur->next;
//		res = res->next;
//	}
//
//
//
//
//}

////��һ������������У������ظ��Ľ�㣬
////��ɾ�����������ظ��Ľ�㣬�ظ��Ľ�㲻��������������ͷָ�롣
////���磬����1->2->3->3->4->4->5 �����Ϊ 1->2->5
ListNode* deleteDuplication(ListNode* pHead)
{
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
			return deleteDuplication(current);
		}
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
//���������� 1->2->2->1
//���أ�true
chkPalindrome(ListNode* A)
{
	
}

Node* buildTree2(char postorder[], char inorder[], int size)
{

}

int main()
{
	////1->2->5->7->3->9->4    int x = 5
	//ListNode* a1 = (ListNode*)malloc(sizeof(ListNode));
	//ListNode* a2 = (ListNode*)malloc(sizeof(ListNode));
	//ListNode* a3 = (ListNode*)malloc(sizeof(ListNode));
	//ListNode* a4 = (ListNode*)malloc(sizeof(ListNode));
	//ListNode* a5 = (ListNode*)malloc(sizeof(ListNode));
	//ListNode* a6 = (ListNode*)malloc(sizeof(ListNode));
	//ListNode* a7 = (ListNode*)malloc(sizeof(ListNode));
	//a1->next = a2, a1->val = 1;
	//a2->next = a3, a2->val = 2;
	//a3->next = a4, a3->val = 5;
	//a4->next = a5, a4->val = 7;
	//a5->next = a6, a5->val = 3;
	//a6->next = a7, a6->val = 9;
	//a7->next = NULL, a7->val = 4;

	////1->2->5->7->3->9->4    int x = 5
	//print(a1);
	//ListNode* p1 = partition(a1, 5);

	//while (p1)
	//{
	//	printf("%d->", p1->val);
	//	p1 = p1->next;
	//}
	//printf("NULL");
	////1->2->3->4->5->7->9
	//printf("\n");




	system("pause");
	return 0;
}