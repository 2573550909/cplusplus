#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int Max(int a, int b)
{
	return (a > b) ? a : b;
	//if(a>b)
	//{
	//	return a;
	//}
	//else
	//{
	//	return b;
	//}
}

void exchange(int* a, int* b)
{
	int tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
}

int main()
{
	////1. дһ�����������ж�һ�����ǲ���������
	//int n = 0;
	//scanf("%d", &n);
	//if (n == 1)
	//{
	//	printf("1��������");
	//}
	//if (n == 2)
	//{
	//	printf("2������");
	//}

	//for (int i = 2; i < n; ++i)
	//{
	//	if (n % i == 0)
	//	{
	//		printf("%d��������\n",n);
	//		break;
	//	}
	//	else
	//	{
	//		printf("%d������\n",n);
	//		break;
	//	}
	//}



	////2. дһ�������ж�һ���ǲ������ꡣ

	//int year = 0;
	//scanf("%d", &year);
	//if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
	//{
	//	printf("%d������", year);
	//}
	//else
	//{
	//	printf("%d��������",year);
	//}


	//3. дһ��������ʵ��һ��������������Ķ��ֲ��ҡ�


	//4. дһ��������ÿ����һ������������ͻὫnum��ֵ����1��






	//int a = 10;
	//int b = 20;
	//exchange(&a,&b);
	//printf("a = %d\nb = %d\n", a, b);

	//int a = 0;
	//int b = 0;
	//scanf("%d %d", &a, &b);
	//int c= Max(a, b);
	//printf("%d", c);

	////1. ���� n�Ľ׳�
	//int n = 0;
	//printf("��������Ҫ���������");
	//scanf("%d", &n);
	//int i = 1;
	//int sum = 1;
	//for (; i <= n; ++i)
	//{
	//	sum = sum * i; 
	//}
	//printf("%d", sum);


	////2. ���� 1!+ 2!+ 3!+ ���� + 10!
	//int n = 3;
	//int sum = 1;
	//int num = 1;
	//int s = 0;
	//for (int num = 0; num < n ; ++num)
	//{
	//	sum = 1;
	//	for (int i = 1; i < num + 2; ++i)
	//	{
	//		sum = sum * i;
	//	}
	//	s = s + sum;
	//}
	//printf("%d\n", s);


	//3. ��һ�����������в��Ҿ����ĳ������n��
	//��дint binsearch(int x, int v[], int n); ���ܣ���v[0] <= v[1]
	//	<= v[2] <= ��. <= v[n - 1]�������в���x.


	system("pause");
	return 0;
}