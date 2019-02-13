#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int c = 0;
void move(char x, int n, char z)
{
	//��n��Բ�̴�����x�ᵽ����z
	
	printf("��%-2d������%d���̴�%c�Ƶ�%c\n", ++c, n, x, z);

}

void hanoi(int n, char x, char y, char z)
{
	if (n == 1)
	{
		move(x, 1, z);
	}
	else
	{
		hanoi(n - 1, x, z, y);
		move(x, n, z);
		hanoi(n - 1, y, x, z);
	}
}

int main()
{
	
	int n = 0;
	printf("����Բ������\n");

	scanf("%d", &n);
	hanoi(n, 'a', 'b', 'c');


	system("pause");
	return 0;
}