#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//�����ķ���ֵ��ʾ�ַ����з�֮�����зֵĸ���
int Split(char* input,const char* split_char,char* output[])
{
	int output_index = 0;
	char* p = strtok(input, split_char);
	while (p != NULL)
	{
		output[output_index] = p;
		++output_index;
		p = strtok(NULL, split_char);
	}
	return output_index;
}

int main()
{

	char str[1024] = "aaa bbb ccc ddd";
	char* result[10] = { 0 };

	int n = Split(str, " ",result);
	for (int i = 0; i < n; ++i)
	{
		printf("%s\n", result[i]);
	}
	//strtokʹ��ע�����
	//1.strtok���ƻ�ԭ�����ַ���
	//	���磺char str[1024] = "aaa bbb ccc ddd";//��ȷ�Ķ���
	//		  char* str = "aaa bbb ccc ddd";//����Ķ���
	//2.strtok�ڲ��и�static��������¼�ϴ��зֵ�λ��
	//  ������һ���������������̲߳���ȫ��
	//3.strtok����ֵ����ǿ�ָ��˵���з����
	//4.����ж���ָ�����ڣ��ᱻ����һ��

	//char* p = strtok(str, " ");
	//while (p != NULL)
	//{
	//	printf("%s\n", p);
	//	p = strtok(NULL, " ");
	//}

	//char str[1024] = "aaa bbb ccc ddd";
	//char* p = strtok(str, " ");
	//while (p != NULL)
	//{
	//	printf("%s\n", p);
	//	p = strtok(NULL, " ");
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

	//  1��int(*p)[4]; ------ptrΪָ��4��Ԫ�ص�һά���������ָ���������ָ�룩
	//	2��int *p[4]; ------ - ����ָ������p������4��ָ���������ݵ�ָ��Ԫ����ɣ������飩
	//	3��int(*)[4]; --------ʵ���Ͽ��Կ�����һ���������͡�Ҳ���ǵ�һ����int(*p)[4]; ��



	system("pause");
	return 0;
}
