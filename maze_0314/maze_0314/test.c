#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

//////����������һ�������ַ������г��ֵ��ַ�
//char* find_char(char const* source, char const* chars)
//{
//	assert(source != NULL);
//	assert(chars != NULL);
//	
//	char* pchars = (char*)chars;//XRCQEF// ����ʼ����: ��ͬ�ġ�const���޶���
//
//	while (*pchars!= '\0')
//	{
//		char* psource = (char*)source;//ABCDEF	����ʼ����: ��ͬ�ġ�const���޶���
//		while (*psource != '\0')
//		{
//			if (*psource != *pchars)
//			{
//				++psource;
//			}
//			else
//			{
//				return psource;//��return��:��char *���롰char���ļ�Ӽ���ͬ
//			}
//		}
//		pchars++;
//	}
//	return 0;
//}//��find_char��: �������еĿؼ�·��������ֵ

//int del_substr(char* str, char const *substr)
//{
//	assert(str != NULL);
//	assert(substr != NULL);
//
//	while (*str != '\0')
//	{
//		char* psubstr = (char*)substr;//CDE//ACD
//		char* pstr = (char*)str;//ABCDEFGH
//		while (*psubstr != '\0')
//		{
//			if (*psubstr != *pstr)
//			{
//				break;
//			}
//			else
//			{
//				++pstr;
//				++psubstr;
//			}
//		}
//		if (*psubstr == '\0')
//		{
//			char* p1 = str - 3;
//			while()
//			{
//				*p1 = *pstr;
//
//			}
//		}
//		++str;
//	}
//
//	return 0;
//}
//
////ɾ��һ���ַ�����
//int del_substr(char* str, char const *substr)
//{
//	// str : ABCDEFGH		substr: CDE
//	int flag = 0;
//	char* stringStr = str;
//	char* stringResult = NULL;
//	char const *stringSubstr = substr;
//
//	while (*stringStr!= '\0')
//	{
//		if (*stringStr == *stringSubstr)
//		{
//			flag++;
//			stringResult = stringStr;
//			*stringStr++;
//			*stringSubstr++;
//		}
//		else
//		{
//			stringStr++;
//			stringSubstr = substr;
//		}
//
//		if (*(stringSubstr) == '\0')
//		{
//			while (*stringResult)
//			{
//				*(stringResult - flag) = *(++stringResult);
//			}
//			return 1;
//		}
//	}
//	return 0;
//}
//
int del_substr(char *str, char const *substr)
{
	char *stringStr = NULL;
	char *stringResult = NULL;
	char const *stringSubstr = NULL;
	int flag = 0;
	int flagTrue = 0;//�ж��Ƿ���ȹ�
	if (str == NULL || substr == NULL)
	{
		return 0;
	}
	stringStr = str;
	stringSubstr = substr;
	while (*stringStr != '\0')
	{
		while (*stringSubstr != '\0')
		{
			if (*stringStr == *stringSubstr)
			{
				stringResult = stringStr;
				flag++;
				flagTrue = 1;
				*stringStr++;
				*stringSubstr++;
				continue;
			}
			else
			{
				flag = 0;
				break;
			}
		}

		if (*(stringSubstr) == '\0')
		{
			while (*stringResult)
			{

				*(stringResult - flag) = *(++stringResult);
			}
			return 1;
		}

		if (flagTrue == 1)
		{
			break;
		}
		else
		{
			stringStr++;
		}
	}
	return flag;
}

int main()
{
	char str1[] = "ABCDEFGHJKL";
	char str2[] = "CDEFGHJ";
	char str3[] = "ACD";
	int n = del_substr(str1, str2);
	printf("%d\n%s\n", n, str1);

	//char s1[] = "ABCDEF";
	//char s2[] = "BC";
	//int p = del_substr(s1, s2);
	//printf("%d\n%s\n", p, s1);
	

	////�������򷨣�
	int arr[10] = { 0,15,-45,23,45,78,52,49,-12,36 };
	int len = sizeof(arr) / sizeof(arr[0]);
	int k,t;
	for (int i = 0; i < len - 1; ++i)
	{
		k = i;
		for (int j = i + 1; j < len; ++j)
		{
			if (arr[j] < arr[k])
			{
				k = j;
			}
		}
		t = arr[k];
		arr[k] = arr[i];
		arr[i] = t;
	}
	for (int i = 0; i < len; i++)
	{
		printf("%d  ", arr[i]);
	}
	
	//char ch[] = "abc";
	//if (strcmp(ch,"abc") == 0)
	//{
	//	printf("ok!");
	//}
	//else
	//{
	//	printf("no!");
	//}

	//char arr[100] = { 0 };
	//for (char i = 0; i < 4; ++i)
	//{
	//	scanf("%c", &arr[i]);
	//}
	//printf("%s", arr);
	//char str1[] = "ABGDEF";//����ʼ����: �ӡ�char *������int *�������Ͳ�����
	//char str2[] = "XRCQef"; //��printf��: ��ʽ�ַ�����%c����Ҫ���͡�int���Ĳ�����
	//						//���ɱ���� 1 ӵ�������͡�int *��
	//char* p = find_char(str1, str2);
	//printf("%c", *p);
	//

	//char str[] = "This is a sample string";
	//char keys[] = "aeiouh";
	//printf("%s\n", str);
	//char *pch = strpbrk(str, keys);
	
	//while (pch != NULL)
	//{
	//	printf("%c", *pch);//iiaaei
	//	pch = strpbrk(pch + 1, keys);
	//}
	
	//getchar();
	//int *p = NULL;
	//printf("%d", sizeof(p));
	//printf("%d", sizeof(int));
	



	system("pause");
	return 0;
}
