#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>


//char* my_strstr(const char*str1, const char* str2)
//{
//	assert(str1 != NULL);
//	assert(str2 != NULL);
//	if (*str2 == '\0')
//	{
//		return (char*)str1;
//	}
//
//	while (*str1 != '\0')
//	{
//		const char* p1 = str1;
//		const char* p2 = str2;
//		while (*p2)
//		{
//			if (*p2 != *p1)
//			{
//				++p1;
//			}
//		}
//
//
//	}
//	return NULL;
//}

//char* my_strstr(const char*str1, const char* str2)
//{
//	assert(str1 != NULL);
//	assert(str2 != NULL);
//	if (*str2 == '\0')
//	{
//		return (char*)str1;
//	}
//	while (*str1 != '\0')
//	{
//		const char* p1 = str1;
//		const char* p2 = str2;
//		while (*p2 != '\0')
//		{
//			if (*p1 != *p2)
//			{
//				break;
//			}
//			else
//			{
//				p1++;
//				p2++;
//			}
//		}
//		if ('\0' == *p2)
//		{
//			return (char*)str1;
//		}
//		++str1;
//	}
//	return NULL;
//}

//int my_strncmp(const char* str1, const char* str2, int n)
//{
//	assert(str1 != NULL);
//	assert(str2 != NULL);
//	int m = 1;		
//	while ((*str1 != '\0')&&(*str2 != '\0')&& (m<=n-1))
//	{
//		if (*str1 < *str2)
//		{
//			return -1;
//		}
//		else if (*str1 > *str2)
//		{
//			return 1;
//		}
//		else
//		{
//			++str1;
//			++str2;
//			m++;
//		}
//	}
//
//	if (*str1 < *str2)
//	{
//		return -1;
//	}
//	else if (*str1 > *str2)
//	{
//		return 1;
//	}
//	else
//	{
//		return 0;
//	}
//}

//int my_strcmp(const char* str1,const char* str2)
//{
//	assert(str1 != NULL);
//	assert(str2 != NULL);
//	while (*str1 != '\0' && *str2 != '\0')
//	{
//		if (*str1 > *str2)
//		{
//			return 1;
//		}
//		else if (*str1 < *str2)
//		{
//			return -1;
//		}
//		else
//		{
//			++str1;
//			++str2;
//		}
//	}
//	//�����str1����str2����βʹѭ���������������һ���ж�
//	if (*str1 < *str2)
//	{
//		return -1;
//	}
//	else if (*str1 > *str2)
//	{
//		return 1;
//	}
//	else
//	{
//		return 0;
//	}
//}

//int my_strchr()
//{
//	
//}

//char* my_strchr(const char* str1, const char str2)
//{
//	assert(str1 != NULL);
//	while (*str1 != '\0'&& *str1 !=(char) str2)
//	{
//		++str1;
//	}
//	if (*str1 == (char)str2)
//	{
//		return (char*)str1;
//	}
//	return NULL;
//}



int main()
{
	//char* str1 = "hello world";
	//char* str2 = "llo";
	//printf("%s", my_strstr(str1, str2));

	//4.ʵ��strchr
	//char *strchr(const char* _Str,char _Val)
	//char *strchr(char* _Str, char _Ch)
	//	ͷ�ļ���#include <string.h>
	//	���ܣ������ַ���_Str���״γ����ַ�_Val��λ��
	//	˵���������״γ���_Val��λ�õ�ָ�룬
	//	���صĵ�ַ�Ǳ������ַ���ָ�뿪ʼ�ĵ�һ����Val��ͬ�ַ���ָ�룬
	//	���Str�в�����Val�򷵻�NULL��
	//	����ֵ���ɹ��򷵻�Ҫ�����ַ���һ�γ��ֵ�λ�ã�ʧ�ܷ���NULL
	//char str1[20] = "abcdecfabc";
	//char str2 = 'c';
	//char* ret = strchr(str1, str2);
	//printf("%s", ret);


	////5.ʵ��strcmp
	//char str1[10] = "aaabbbaa";
	//char str2[10] = "aaabbbab";
	//int ret = my_strncmp(str1, str2, 8);
	////int n = my_strcmp(a, b);3
	//if (ret == 0)
	//{
	//	printf("��ȣ�\n");
	//}
	//else if(ret>0)
	//{
	//	printf("str1>str2\n");
	//}
	//else
	//{
	//	printf("str1<str2!\n");
	//}
	//

	//6.ʵ��memcpy
	//�ڴ濽�������������ǣ���Դ�ڴ��ַ����ʼλ�ÿ�ʼ�������ɸ��ֽڵ�Ŀ���ڴ��ַ��

	//void* memcpy(void* dest, const void* src, size_t n);
	////��Դsrc��ָ���ڴ��ַ����ʼλ�ÿ�ʼ����n���ֽڵ�Ŀ��dest��ָ���ڴ��ַ����ʼλ����
	//char* src = "aaabbbcccddd";
	//char* dest = NULL;
	//int n = 6;
	//char* ret = memcpy(dest,src,6);
	//printf("%s", ret);



	//7.ʵ��memmove

	//���Ȳ������Ƶ��ַ�������
	//	strcpy ����/����
	//	strcat �Ĺ����ǣ���������char���͵��ַ���
	//char a[20] = "abc";
	//char b[20] = "def";
	//my_strcat(a, b);
	////strcat(a, b);
	////printf("%s\n", strcat(a, b));
	//printf("%s\n", a);
	//printf("%d", sizeof(a));



	system("pause");
	return 0;
}