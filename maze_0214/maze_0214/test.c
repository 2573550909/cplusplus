#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>


void move(char x, int n, char y)
{
	int c = 0;
	printf("��%d�Σ�����%d�����Ӵ�%c�Ƶ�%c\n",++c,n,x,y);
}

void hannuota(int n, char x, char y, char z)
{
	//����y��x�ϵ��Ƶ�z��
	if (n == 1)
	{
		move(x, 1, z);
	}
	else
	{
		hannuota(n - 1, x, z, y);
		move(x, n, z);
		hannuota(n - 1, y, x, z);
	}

}


int main()
{
	printf("����Ҫת�Ƶ���������\n");
	int n = 0;
	scanf("%d", &n);
	hannuota(n, 'a', 'b', 'c');

	//fputc()�ĺ���һ����ʽ��ch = fputc(ch,fp);
	//�ú����������ǰ�һ���ַ�д�������ļ��У�fp��ָ����ļ���
	//����ch��Ҫ������ַ��������ַ��������ַ�������
	//fp���ļ�ָ������������������ɹ��Ļ��򷵻�ֵ����������ַ�
	//�������ʧ�ܷ���EOF
	//FILE* fp;
	//char ch;
	//char filename[50]; 
	//printf("please input filename:\n");
	//scanf("%d", filename);
	//fp = fopen(filename, "w");
	//if (fp == NULL)
	//{
	//	printf("cannot open file\n");
	//	exit(0);
	//}
	//ch = getchar();
	//ch = getchar();
	//while (ch != '#')
	//{
	//	fputc(ch, fp);
	//	ch = getchar();
	//}

	//fclose(fp);
	















	system("pause");
	return 0;
}