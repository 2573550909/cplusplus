#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

//void find_one_finger(int* arr)
//{
//	//arr[] = {1,9,2,8,3,6,4,5,3,6,7,7,2,8,1,9}; 
//	int* p1 = arr;		//pָ��arr�ĵ�һ��Ԫ��1
//	int* p2 = arr + 1;	//pָ��arr�ڶ���Ԫ��1
//	while (*p1 != '\0')
//	{
//		*p2 = arr;//��ʼ��p2��ָ��ָ��
//		while (*p2 != '\0')
//		{
//			++p2;
//			if (*p1 == *p2)
//			{
//				continue;//printf("%d�ظ�����\n", *p1);
//			}			
//		}
//		printf("%dֻ����һ��\n", *p1);
//		*++p1;
//	}
//}

void find_num(int arr[], int sz, int *num1, int*num2)
{
	//������ж�����Ԫ���Ƿ����
	assert(arr);
	int ret = 0;
	int i = 0;
	int pos = 0;
	int tmp = 0;
	*num1 = 0;
	*num2 = 0;
	for (i = 0; i < sz; i++)
	{
		ret = ret ^ arr[i];
	}
	tmp = ret;
	while (ret)
	{
		if ((ret & 1) == 1)
		{
			break;
		}
		ret = ret >> 1;//����ret = ret/2
		++pos;
	}
	for (i = 0; i < sz; i++)
	{
		if ((arr[i] >> pos) & 1)
		{
			*num1 ^= arr[i];
		}
	}
	*num2 = *num1^tmp;

}

void sort(int arr[], int n)//ð�����򷨣���С����
{
	int i, j;
	for (i = 0; i < n - 1; i++)
	{
		for (j = 0; j < n - i - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				int tmp;
				tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
		}
	}
}

void func(int arr[], int n, int *num1, int *num2)
{
	int tmp = 0;
	for (int i = 0; i < n; i += 2)
	{
		if (arr[i] == arr[i + 1])
		{
			continue;
		}
		else
		{
			if (tmp == 0)
			{
				*num1 = arr[i];
				i = i + 1;
			}
			else if (tmp == 1)
			{
				*num2 = arr[i];
				i = i + 1;
			}
			tmp++;
		}
	}
}

int main()
{
	//1.һ��������ֻ�����������ǳ���һ�Σ�
	//	�����������ֶ����������Ρ�
	//	�ҳ����������֣����ʵ�֡�

	//int arr[] = { 1,2,3,10,1,2,3,14 };
	//int sz = sizeof(arr) / sizeof(arr[0]);
	//int num1 = 0;
	//int num2 = 0;
	//find_num(arr, sz, &num1, &num2);
	//printf("%d\n%d\n", num1, num2);
	//printf("%d\n", sz);//�������������м���Ԫ��

	
	//int a[10] = { 1,4,5,8,56,4,8,5,7,1 };//56,7
	//int a[10] = { 1,8,5,3,14,4,1,3,5,8 };
	//sort(a, 10);
	//int num1, num2;
	//
	//for (int i = 0; i < 10; i++)
	//{
	//	printf("%d ", a[i]);
	//}
	//printf("\n");
	//func(a, 10, &num1, &num2);
	//printf("%d %d", num1, num2);

	//	2.����ˮ��1ƿ��ˮ1Ԫ��2����ƿ���Ի�һƿ��ˮ��
	//	��20Ԫ�����Զ�����ˮ��
	//	���ʵ�֡�	
	
	//	3.ģ��ʵ��strcpy
	//	4.ģ��ʵ��strcat

	

	system("pause");
	return 0;
}