#pragma once
#include<iostream>
#include <stdlib.h>
#include <string>
#include <stdio.h>
using namespace std;

//����һ���ַ���,�������ֺͷ������ַ� a123x456__17960?302tab5876
//�����е�����������Ϊһ���������δ�ŵ�һά����a��
//����:123����a[0],456����a[1]ͳ�ƹ��ж��ٸ�����,���������Щ��

void isfinger()
{
	char b[100] = "a123x456__17960?302tab5876";
	int q = 0;
	char *p = b;
	char a[100];
	int num = 0;
	
	for(;*p!='\0';++p)
	{
		if (*p > '0' && *p <= '9')
		{
			q = (*p) - '0';
			p++;
			while (*p >= '0'&& *p <= '9')
			{
				q = (q) * 10 + (*p) - '0';
				p++;
			}
			++num;
			cout << "a[" << num - 1 << "]=" << q << endl;
			//printf("a[%d] = %d\n",num-1, q);
		}
	}
	//printf("����%d������\n", num);
	cout << "����"<<num<<"������" << endl;
}

