#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>


int num(int n)
{
	if (n == 0)//��Ԫ������ƿ
	{
		return 0;
	}
	if (n == 1)//һԪ����һƿ
	{
		return 1;
		
	}
	//�������������������
	if (n % 2 == 0)
	{
		return n + num(n / 2);
	}
	else//����
	{
		return (n + 1) + num((n / 2) - 1);
	}	
}

char *his_strcpy(char *dest, char *src)
{
	char *ret = dest;
	while (*dest++ = *src++)
	{
		;
	}
	return ret;
}

char *my_strcpy(char *dest, char *src)
{
	char *ret = dest;
	while (*src)
	{
		*dest++ = *src++;
	}
	*dest = '\0';
	return ret;
}

//char *mystrcat(char *dest, char *src)
//{
//	char *destbak = dest;
//	assert(NULL = dest && NULL != src);
//	while ('\0'!= *dest)
//	{
//
//	}
//}

int main()
{
	// һ��������ֻ�����������ǳ���һ�Σ������������ֶ����������Ρ�
	//�ҳ����������֣����ʵ�֡�
	//int arr[] = { 4,8,8,4,5,9,3,5,9,3,15,56 };
	//int count = 0;
	//int sz = sizeof(arr) / sizeof(arr[0]);//12
	//int i = 0;
	//int j = 0;
	//for(i = 0; i < sz; i++)
	//{
	//	count = 0;//ÿ��ִ��ѭ��ʱ��ʼ��Ϊ0
	//	for (j = 0; j < sz ; j++)
	//	{
	//		if (arr[i] == arr[j])
	//		{
	//			count++;
	//		}
	//	}
	//	if (count == 1)
	//	{
	//		printf("%d\n",arr[i]);
	//	}
	//}
	//printf("%d", sz);//12


	//2.����ˮ��1ƿ��ˮ1Ԫ��2����ƿ���Ի�һƿ��ˮ��
	//	��20Ԫ�����Զ�����ˮ��
	//	���ʵ�֡�
	
	//int n = 0;
	//printf("������Ҫ���Ѷ���Ǯ��\n");
	//scanf("%d", &n);
	//printf("%dԪ���Ժ�%dƿ��ˮ����\n", n, 2 * n - 1);//�ҹ��ɣ�nԪ���Ժ�2*n-1ƿ��ˮ
	//printf("%dԪ���Ժ�%dƿ��ˮ����\n", n, num(n));//�����ݹ�


	//	3.ģ��ʵ��strcpy
	//����strcpy�Ĺ����ǣ� ��һ���ַ��������ݸ��Ƶ�����һ���ַ������У������ַ������ս��

	//char a[20];
	//char *p = "bfaslkjfcd";
	//printf("%s\n", my_strcpy(a, p));
	//printf("%s\n", his_strcpy(a, p));


	//	4.ģ��ʵ��strcat
	//strcat�Ĺ����ǣ�
	char array[100] = "hello world !";
	char *p = "abcdef";
	mystrcat(array, p);
	printf("array = %s\n", array);
	printf("hello...\n");






	system("pause");
	return 0;
}