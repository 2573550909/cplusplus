#pragma once
#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include <string.h>
#include<iomanip>
//��дһ������print,��ӡһ��ѧ���ĳɼ�����,
//����������5��ѧ��������,ÿ��ѧ�������ݰ���
//num(ѧ��)		name(����)		score[3](3�ǿεĳɼ�)
//��������������Щ����,����print�����Щ����
const int n = 5;
struct student
{
	int num;
	int score[4];
	string name;
}stu[n];

void information()//�ռ���Ϣ
{
	int i, j;
	for (i = 0; i < n; i++)
	{
		cout << "�������" << i + 1 << "��ѧ���ĳɼ���" << endl;
		cout << "NO.:";
		cin >> stu[i].num;
		cout << "name:";
		cin >> stu[i].name;
		for (j = 0; j < 3; j++)
		{
			cout << "score " << j + 1 << ":";
			cin >> stu[i].score[j];
		}
		cout << endl;
	}
}

void print()//��ӡѧ����Ϣ
{
	student stu[n];
	int i, j;
	cout << "NO.  name  score1  score2  score3" << endl;
	for (i = 0; i < n; i++)
	{
		cout << stu[i].num << "    " << setw(10) << stu[i].name << "       ";
		for (j = 0; j < 3; j++)
		{
			cout << setw(3) << stu[i].score[j] << "      ";
		}
		cout << endl;
	}
}

//======================================================================
//219ҳ��6,7,8,9,10��

//creat�����������
typedef struct Node 
{
	int value;//ֵ
	struct Node* next;
}	Node;

void creat()//����������
{
	Node* a1 = (Node*)malloc(sizeof(int));
	Node* a2 = (Node*)malloc(sizeof(int));
	Node* a3 = (Node*)malloc(sizeof(int));
	Node* a4 = (Node*)malloc(sizeof(int));
	a1->next = a2, a1->value = 1;
	a2->next = a3; a2->value = 1;
	a3->next = a4; a3->value = 1;
	a4->next = NULL;
}

void print_Node(Node*a1)
{
	while (a1 != NULL)
	{
		a1 = a1->next;
		cout << a1->value << endl;
	}
}

void del(Node* a1,Node* a3)//ɾ��a3����Ӧ�Ľ��
{
	Node* p = a1;
	while (a1->next->value != a3->value)
	{
		a1 = a1->next;
	}
	a1->next = a1->next->next;
	free(a3);
}

void insert(Node* a1, int n)//β�����һ�����
{
	Node* m = (Node*)malloc(sizeof(int));
	m->value = n;
	while (a1->next != NULL)
	{
		a1 = a1->next;
	}
	a1->next = m;
	m->next = NULL;
}






