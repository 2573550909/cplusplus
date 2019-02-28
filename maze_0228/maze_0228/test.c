#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

//int my_strcat(char* p1, const char* p2)
//{
//	assert(p1 != NULL);
//	assert(p2 != NULL);
//	char* ret = p1;
//	while (*p1)
//	{
//		++p1;
//	}
//	while(*p2)
//	{
//		*p1++ = *p2++;
//	}
//	*p1 = '\0';
//	return* p1;
//}

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
//		int flag = 1;
//		while (*str2 !='\0')
//		{
//			if (*str2 == *str1)
//			{
//				flag = 0;
//				break;
//			}
//			else
//			{
//				++str1;
//				++str2;
//			}
//		}
//		if (1 == flag)
//		{
//			return (char*)str1;
//		}
//		++str1;
//	}
//	return NULL;
//}

char* my_strstr(const char*str1, const char* str2)
{
	assert(str1 != NULL);
	assert(str2 != NULL);
	if (*str2 == '\0')
	{
		return (char*)str1;
	}
	while (*str1 != '\0')
	{
		const char* p1 = str1;
		const char* p2 = str2;
		while (*p2 != '\0')
		{
			if (*p1 != *p2)
			{
				break;
			}
			else
			{
				p1++;
				p2++;
			}		
		}	
		if ('\0' == *p2)
		{
			return (char*)p1;
		}
		++p1;
	}
	return NULL;
}

int main()
{
	//3.ʵ��strstr��str1��str2��; �����ж�str2�Ƿ���str1���Ӵ������ַ�����
	//char* str1 = "hello world";
	//char* str2 = "llo";
	////strstr(str1, str2);
	//printf("%s", strstr(str1, str2));




	//4.ʵ��strchr
	//char *strchr(const char* _Str,char _Val)
	//char *strchr(char* _Str, char _Ch)
	//	ͷ�ļ���#include <string.h>
	//	���ܣ������ַ���_Str���״γ����ַ�_Val��λ��
	//	˵���������״γ���_Val��λ�õ�ָ�룬
	//	���صĵ�ַ�Ǳ������ַ���ָ�뿪ʼ�ĵ�һ����Val��ͬ�ַ���ָ�룬
	//	���Str�в�����Val�򷵻�NULL��
	//	����ֵ���ɹ��򷵻�Ҫ�����ַ���һ�γ��ֵ�λ�ã�ʧ�ܷ���NULL
	char _Str[20] = "abcdefabc";
	char _Val[20] = "bc";





	//5.ʵ��strcmp
	//6.ʵ��memcpy
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