#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <memory.h>
#include <assert.h>

//struct {
//	char name[40];
//	int age;
//} person, person_copy;

//int my_strlen(const char* str)
//{
//	int count = 0;
//	//������ǿ�ָ����ʼ�ճ���,��while���������ǿ�ָ���ʱ�򲻽���ѭ����
//	while (*str)	{
//		count++;
//		str++;
//	}
//	return count;
//}
//
//int my_strlen(const char* str)
//{
//	if (*str == '\0')
//	{
//		return 0;
//	}
//	else
//	{
//		return (1 + my_strlen(str + 1));
//	}
//}
//
//int my_strlen(char* s)
//{
//	char* p = s;
//	while (*p != '\0')
//	{
//		p++;
//	}
//	return p - s;
//	//����p��s��һ��ָ�룬����������Ҫ��ȥs���ܼ��㳤�ȣ�
//}

//char *my_strcpy(char* dest, const char* src)
//{
//	char* ret = dest;
//	assert(dest != NULL);
// 	assert(src != NULL);
//	while ((*dest++ = *src++))
//	{
//		;
//	}
//	return ret;
//}
//
//char *my_strcat(char* dest, const char* src)
//{
//	char *ret = dest;
//	assert(dest != NULL);
//	assert(src != NULL);
//	while (*dest)
//	{
//		dest++;
//	}
//	while ((*dest++ = *src++))
//	{
//		;
//	}
//	return ret;
//}

char *my_strstr(const char* str1, const char* str2)
{
	assert(str1);
	assert(str2);
	char* cp = (char*)str1;
	char* substr = (char *)str2;
	char* s1 = NULL;
	if (*str2 == '\0')
	{
		return NULL;
	}
	while (*cp)
	{
		s1 = cp;
		substr = str2;
		while (*s1 && *substr && (*s1 == *substr))
		{
			s1++;
			substr++;
		}
		if (*substr == '\0')
		{
			return cp;
		}
		cp++;
	}
}
int main()
{
	char* str1 = "ma ze is a boy";
	char* str2 = "is";
	char* a = my_strstr(str1, str2);
	printf("%s",a);

	//char arr[20] = "aaaaa";
	//const char str[10] = "bbbbbb";

	//char* a = my_strcat(arr , str);

	//char* a = my_strcpy(arr,str);

	//printf("%s\n", a);
	
	//char* arr = "dasjkhs";
	//int n = my_strlen(arr);
	//printf("%d\n", n);

	//char buffer1[] = "DWgaOtP12df0";
	//char buffer2[] = "DWGAOTP12DF0";
	//int n;
	////printf("%d", sizeof(buffer1));13
	//n = memcmp(buffer1, buffer2, sizeof(buffer1));
	//if (n > 0)
	//{
	//	printf("'%s' is greater than '%s'.\n", buffer1, buffer2);
	//}
	//else if (n < 0)
	//{
	//	printf("'%s' is less than '%s'.\n", buffer1, buffer2);
	//}
	//else
	//{
	//	printf("'%s' is the same as '%s'.\n", buffer1, buffer2);
	//}


	//char str[] = "memmove can be very useful......";
	//memmove(str + 20, str + 15, 11);
	//puts(str);
	//memmove can be very very useful.


	//char myname[] = "Pierre de Fermat";
	////using memcpy to copy string: 
	//memcpy(person.name, myname, strlen(myname) + 1);
	//person.age = 46;
	////using memcpy to copy structure: 
	//memcpy(&person_copy, &person, sizeof(person));
	//printf("person_copy: %s, %d \n", person_copy.name, person_copy.age);

	//person_copy: Pierre de Fermat, 46


	//int i = 0;
	//char str[] = "Test String.\n";
	//char c;
	//while (str[i])
	//{
	//	c = str[i];
	//	if (isupper(c))
	//	{
	//		c = tolower(c);
	//	}
	//	putchar(c);
	//	i++;
	//}

	//fopen()
	//FILE * pFile;
	//pFile = fopen("unexist.ent", "r");
	//if (pFile == NULL)
	//	printf("Error opening file unexist.ent: %s\n", strerror(errno));
	//errno: Last error number
	
	//Error opening file unexist.ent: No such file or directory

	//char* p = "zhangpengwei@bitedu.tech";
	//const char* sep = ".@";
	//char arr[30];
	//char* str = NULL;
	//strcpy(arr, p);//�����ݿ���һ�ݣ�����arr���������
	//for (str = strtok(arr, sep); str != NULL; str = strtok(NULL, sep))
	//{
	//	printf("%s\n", str);
	//}
		
	//char str[] = "- This, a sample string.";
	//char * pch;
	//printf("Splitting string \"%s\" into tokens:\n", str);
	//pch = strtok(str, " ,.-");
	//while (pch != NULL)
	//{
	//	printf("%s\n", pch);
	//	pch = strtok(NULL, " ,.-");
	//}

	//printf("%s\n", pch);

	//char * strtok(char * str, const char * sep);
	//��һ������ָ��һ���ַ�������������0�����߶����sep�ַ�����һ��
	//���߶���ָ����ָ�ı�ǡ�
	//strtok�����ҵ�str�е���һ����ǣ��������� \0 ��β��
	//����һ��ָ�������ǵ�ָ�롣��ע��strtok������
	//�ı䱻�������ַ�����������ʹ��strtok�����зֵ��ַ���
	//һ�㶼����ʱ���������ݲ��ҿ��޸ġ���
	//strtok�����ĵ�һ��������Ϊ NULL ���������ҵ�str�е�һ����ǣ�
	//strtok���������������ַ����е�λ�á�
	//strtok�����ĵ�һ������Ϊ NULL ����������ͬһ���ַ����б������λ�ÿ�ʼ��
	//������һ����ǡ�
	//����ַ����в����ڸ���ı�ǣ��򷵻� NULL ָ�롣
	//strerror
	//���ش����룬����Ӧ�Ĵ�����Ϣ��

	//char s1[10] = "ab c";
	//const char s2[10] = "ABC";
	//printf("s1 = %s\ns2 = %s\n", s1, s2);
	//strncpy(s1, s2,3);
	//printf("s1 = %s\ns2 = %s\n", s1, s2);
	//
	//s1 = ab c
	//s2 = ABC
	//s1 = ABCc
	//s2 = ABC

	//char str[] = "This is a simple string";
	//char * pch;
	//pch = strstr(str, "simple");
	//strncpy(pch, "sample", 8);
	//puts(pch);

	system("pause");
	return 0;
}