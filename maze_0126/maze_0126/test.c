#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	//strcat ��һ���ַ�������ǰһ���ַ����ĺ��棬
	//��ɾ��ǰһ�����ַ���������\0��,�����ϡ�\0��   

	//strncat(str1, str2, 6)
	//6��������ǣ���str2�����м����ַ�������ȥ

	//strcpy ��һ���ַ�������ǰһ���ַ�����
	//strncpy 

	//strcmp ��int* str1,int* str2��
	//������ַ����ıȽϣ����ǰ����򷵻����������򷵻ظ�����0

	//strncmp(int* str1,int* str2,size_num)
	//����Ĳ�����ֻ�Ƚ�num���ַ������ں�����ַ������Ƚ�
	//���磺strncmp("shd1","shd23",3)������Ϊ0����Ϊֻ��ǰ�����ַ�

	//strlen ���ַ�����ʵ�ʳ��ȣ������㡮\0���ĳ���
	//strlwr ��д��ĸת��ΪСд��ĸ�����಻�䡣
	//strupr Сд��ĸת��Ϊ��д��ĸ�����಻�䡣

	//strstr(char* str1, char* str2)
	//����ָ����str1�е�һ�γ���str2��ָ�룬
	//�����str1��û��str2���򷵻�һ����ָ�롣

	//int str1[] = { 'd','s','e','r','d','g' };
	//int str2[] = { 'd','f','s','a','f','g','s' };
	//if (strncmp(str1, str2, 2) > 0)//   <0
	//{
	//	printf("ok��");
	//}
	//else
	//{
	//	printf("no��");
	//}

	//char str1[20];
	//char str2[20];
	//strcpy(str1, "To be a ");
	//strcpy(str2, "or not to be");
	//strncat(str1, str2, 6);
	//puts(str1);

	//printf("%s", str1);


	//char str[][5] = { "R2D2" , "RxPO" , "R2A6" };
	//int n = 0;
	//puts("Looking for R2 astromech droids...");
	//for (n = 0; n < 3; n++)
	//{
	//	if (strncmp(str[n], "Rxxx", 2) == 0)
	//	{
	//		printf("found %s\n", str[n]);
	//	}
	//}
	//char str[] = "This is a simple string";
	//char* pch;
	//pch = strstr(str, "simple");
	//int arr = strncpy(pch, "sample", 6);
	////puts(str);
	////puts(pch);
	////printf("%s", strncpy(pch, "sample", 6));
	//printf("%s", arr);

	//char str1[30] = { "thissmaze" };
	//char str2[20] = {"mynameismaze"};

	//int arr[] = { strncpy(str1, str2, 5) };

	//puts(str1);
	//printf("%s\n", str2);
	//printf("%s\n", str1);
	//printf("%s", arr);
	
	//char str[] = "This is a simple string";
	//char pc[20] = { 0 };
	////pch = strstr(str, "simple");
	//strncpy(pc, str, 6);
	////puts(str);
	//printf("\n");
	//printf("%s",pc);

	//char name[] = "Chinanet";
	//char dest[20] = { 0 };

	//strncpy(dest, name, 10);

	//printf("%s", dest);

	system("pause");
	return 0;
}