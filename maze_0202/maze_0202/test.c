#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void odd_print(int a[], int n)
{
	for (int j = 0; j < n; ++j)
	{
		if (a[j] % 2 != 0)
		{
			printf("%d\n", a[j]);
		}
	}
}

void min_print(int(* p)[4],int n)
{
	for (int i = 0; i <n ; ++i)
	{
		int value = *(*(p + i));//��i�е���Ԫ��
		for (int j = 0; j < 4; ++j)
		{
			if (value > *(*(p + i) + j))
			{
				value = *(*(p + i) + j);//������ǵ�i�еĵ�j��Ԫ��
			}		
		}
		printf("��%d��С������%d\n", i, value);
	}
}

int main()
{
	//int a[10];
	//int* p = a;
	//int i = 0;
	//for (; i < 10; ++i)
	//{
	//	scanf("%d", &a[i]);
	//}
	//odd_print(p, 10);

	//���㲢��ӡÿ������С����
	int arr[3][4] = {0};
	int(* p)[4] ;
	p = &arr[0];
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			scanf("%d", &arr[i][j]);
		}	
	}
	min_print(p, 3);
	








	system("pause");
	return 0;
}