#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

int main()
{
	int count = 0;
	int find = 0;
	int arr[] = { 1,3,5,6,23,34,54,56,76,87,89,91,92,93,95,99 };
	printf("Ҫ�ҵ�������%d\n",find);
	int left = 0;
	int right = sizeof(arr) / sizeof(arr[0]);
	
	while (left < right)
	{
		++count;//����,����һ�����˶��ٴ�
		int mid = (left + right) / 2;

		if (arr[mid] < find)
		{
			left = mid + 1;
		}

		if (arr[mid] > find)
		{
			right = mid - 1;
		}

		if (arr[mid] == find)
		{
			printf("�ҵ���!!�����±���%d\n", mid);
			break;
		}
	}

	if (left == right)
	{
		printf("û�ҵ�\n");
	}

	printf("һ������ %d ��\n", count);

	//char ch = getchar();
	//printf("%c\n", ch);

	//printf("%d\n", getchar());

	//char ch = _getch();
	//printf("%c\n", ch);

	system("pause");
	return 0;
}
