#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct test
{
	int m1;
	char m2;
	float m3;
	union uu
	{
		char u1[5];
		int u2[2];
	}ua;
}myaa;

void change(int* a,int &b,int c)
{
	c = *a;
	b = 30;
	*a = 20;
}

int main()
{
	int a = 10;
	int b = 20;
	int c = 30;
	
	change(&a, b, c);
	printf("%d %d %d", a, b, c);//20 30 30
	//�����Ŀ�����Ǻ������ε���ʽ�����������֣���ֵ����ָ�롢�����ã�
	//���д�ֵ����ı������ֵ����ָ��ʹ����û�ı������ֵ�� 

	//��ֵ������������Ĳ����������ʱ�ռ䣬���������ͻ��ͷſռ䣬
	//��˲���ı��������б�����ֵ��

	//��ָ�뼴���ݵ��ǵ�ַ�����������б����ĵ�ַ���������У�
	//�����������ʱ��������˻�ı�����ֵ��

	//�����õ���������Ǵ��ݵı����ı��������Ҳ��ı������ֵ��
	
	
	
	
	//char c = 'A';
	//if ('0' <= c <= '9')
	//{
	//	printf("YES!");
	//}
	//else
	//{
	//	printf("NO!");
	//}
	
	
	
	//char* p1 = "hello";
	//char* p2 = "world";
	//char* p3 = "a piece of cake";
	//char* str[] = { p1,p2,p3 };
	//printf("%c", *(str[0] + 1));

	////printf("%d", sizeof(struct test));//20
	//char* str[3] = { "stra","strb","strc" };
	//char* p = str[0];
	//int i = 0;
	//while (i < 3)
	//{
	//	printf("%c ", p++);//stra  tra  ra													

	//	i++;
	//}
	//char *str[3] = { "stra","strb","strc" }; ��һ��ָ�����飻 
	//char *p = str[0]��ʵ����pָ���һ���ַ����������ַ�����1��
	//��ָ���ַ�������һ����ĸ������������һ���ַ���


	//int x, y;
	//int count = 0;
	//for (x = 0, y = 0; (y = 123) && (x < 4); x++)
	//{
	//	count++;
	//}
	//printf("%d", count);
	

	system("pause");
	return 0;
}