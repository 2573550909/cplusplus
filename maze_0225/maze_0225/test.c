#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

//int my_strlen(const char* str)
//{
//	assert(str != NULL);
//	int count = 0;
//
//	while (*str)
//	{
//		count++;
//		*str++;
//	}
//	return count;
//}

//int my_strlen(char* str)
//{
//	assert(str != NULL);
//	if (*str == '\0')
//	{
//		return 0;
//	}
//	else
//	{
//		return 1 + my_strlen(str + 1);
//	}
//}

//int my_strlen(char* str)//ѭ��ʵ��
//{
//	assert(str != NULL);
//	char* p1 = str;
//	char* p2 = str;
//	while (*p2 != '\0')
//	{
//		*p2++;
//	}
//	int n = p2 - p1;
//	return n;
//}

char my_strcpy(char* p,const char* p1)//p�����ܱ����������Լ�const
{
	assert(p != NULL);
	assert(p1 != NULL);
	char* ret = p;
	while ((*p++ = *p1++) != '\0')
	{
		;
	}
	return *ret;
	//while (*p1)
	//{
	//	*p = *p1;
	//	++p;
	//	++p1;
	//}
	//*p = '\0';//����д�� *p = *p1;
	
}

int main()
{
	//strlen  ��ģ��ʵ��
	//���Ȳ������Ƶ��ַ�

	//char a[] = "aaabbbccc";
	//printf("%d", my_strlen(a));

	//	strcpy ��ֵ�ַ���

	char str1[20] = { 0 };
	my_strcpy(str1, "aaabbbccc");//�Զ��庯��
	printf("%s\n",str1);
	printf("%s",strcpy(str1, "aaabbbccc"));//c���Ա�׼��ĺ���



	//	strcat �����ַ���
	//	strcmp �ж��ַ����Ĵ�С

	//	���������Ƶ��ַ�����������
	//	strncpy
	//	strncat
	//	strncmp
	//	�ַ�������
	//	strstr
	//	strtok
	//	������Ϣ����
	//	strerror
	





	system("pause");
	return 0;
}