#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <assert.h>

typedef struct infor											
{
	//ͨѶ¼������Ϣ	
	char name[256];
	char num[256];
}	infor;

typedef struct member
{
	infor *mem;
	int size;//��Ч����
	int capacity;//����
}	member,*pMember;

void Menu();//�˵�
void Init(member *m);//��ʼ��ͨѶ¼
void Insert(member *m);//�����ϵ��
void Delete(member *m);//ɾ����ϵ��
void Display(member *m);//��ʾ��ϵ��
void Find(member *m);//������ϵ��
void Modify(member *m);//�޸���ϵ��
void Clear(member *m);//�����ϵ��

