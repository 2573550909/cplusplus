#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
//struct Node
//{
//	int data;
//	struct Node* next;
//};

//int increment( a2)
//{
//	return a2 + 1;
//}

//int increment(a2);
//int negate(a1);

//enum Liquid
//{
//	OUNCE = 1,
//	CUP = 8,
//	PINT = 16,
//	QUART = 32,
//	GALLON = 128,
//};
//
//enum Liquid jar;

int func()
{
	static int counter = 1;
	return ++counter;
}

int main()
{




	//int answer;
	//answer = func() - func() * func();
	//printf("%d\n", answer);

	//printf("%f", (float)(25 / 10));
	//�����ͣ�2.000000


	//int a, b, c;
	//printf("�����������ε������ߣ�");
	//scanf("%d %d %d", &a, &b, &c);
	//if (a == b == c)
	//{
	//	printf("�ȱ������Σ�");
	//	system("pause");
	//	return;
	//}

	//if ((a+b)>c && (a+c)>b && (b+c)>a)//�����γ�������
	//{
	//	if (a == c || a == b || b == c)
	//	{
	//		printf("���������Σ�");
	//	}
	//	else
	//	{
	//		printf("��ͨ�����Σ�");
	//	}
	//}
	//else
	//{
	//	printf("����ĳ�������");
	//}
	//int num = 0;
	//int ch = 0;
	//while ((ch = getchar()) != EOF)
	//{
	//	//num = ch + num;
	//	putchar(ch);
	//}
	//int a = getchar();
	//printf("%d", a-58);
	//for (int i = 0; i < a; ++i)
	//{
	//	printf("*\n");
	//}

	//int checksum = 0;
	//char ch;
	//while ((ch = getchar())!= EOF)
	//{
	//	checksum = checksum + ch;
	//	putchar(ch);
	//}
	//printf("%d\n", checksum);



	//jar = QUART;
	//printf("%d\n", jar);
	//jar = jar + PINT;
	//printf("%d\n", jar);



	////��֤�������Ƿ�ɶԳ��֣�
	//int count = 0;
	//char ch;
	//while ((ch = getchar()) != EOF)
	//{
	//	if (ch == '{')
	//	{
	//		++count;
	//	}
	//	if (ch == '}')
	//	{
	//		--count;
	//	}
	//}
	//if (count == 0)
	//{
	//	printf("{}�ɶԳ��֣�");
	//}
	//else if(count >0)
	//{
	//	printf("'}'ȱʧ��");
	//}
	//else
	//{
	//	printf("'{' ȱʧ��");
	//}


	//int a = 10;
	//int b = 0;
	//int c = -10;
	//increment(10);
	//increment(0);
	//increment(-10);
	//negate(10);
	//negate(0);
	//negate(-10);
	//printf("increment(10):%d\n", increment(10));
	//printf("increment(0):%d\n", increment(0));
	//printf("increment(-10):%d\n", increment(-10));
	//printf("negate(10):%d\n", negate(10));
	//printf("negate(0):%d\n", negate(0));
	//printf("negate(-10):%d\n", negate(-10));

	//int x, y;
	//x = 0;
	//while (x < 10)
	//{
	//	y = x * x;
	//	printf("%d\t%d\n", x, y);
	//	x = x + 1;
	//}

	//int	xy;
	

	//int a = '\x0123';
	//printf("%x", a);




	//int i = 0;
	//char ch;
	//char* arr[3];
	//while ((ch = getchar()) != EOF)
	//{	
	//	arr[i] = ch;
	//	if (ch == '\n')
	//	{
	//		++i;
	//	}
	//	if (i == 3)
	//	{
	//		break;
	//	}
	//}
	//for (int j = 0; j < i; ++j)
	//{	
	//	printf("%s\n", *arr[i]);
	//	
	//}

	//char* arr[4] = { 0 };
	//char ch;
	//int j = 0;
	//
	//while (ch = getchar() != EOF)
	//{
	//	arr[j] = ch;
	//	if (ch == '\n')
	//	{
	//		++j;
	//	}
	//}
	//for (int i = 0; i < 4; ++i)
	//{		
	//	printf("%s\n", arr[i]);
	//}


	//char* arr = '\0';
	//arr = getchar();
	//putchar(*arr);

	//printf("%s", arr);

	//char ch;
	//int line = 0;
	//int at_beginning = 1;
	//while ((ch = getchar())!= EOF)
	//{
	//	if (at_beginning == 1)
	//	{
	//		at_beginning = 0;
	//		line ++;
	//		printf("��%d�� ", line);
	//	}

	//	//��ӡ�ַ�����β�н��м��
	//	putchar(ch);
	//	if (ch == '\n')
	//	{
	//		at_beginning = 1;
	//	}
	//}


	//char input[1000];
	//char output[1000];

	//int max = 0;
	//int num = 0;
	//printf("���������ݣ���'CRRL+Z'������\n");

	//while ((gets(input)) != NULL )
	//{
	//	num =  strlen(input);

	//	if (num > max)
	//	{
	//		max = num;
	//		strcpy(output, input);
	//	}
	//}
	//printf("%d ,%s", max, output);
	////printf("%d", sizeof(struct Node));//8


	system("pause");
	return 0;
}