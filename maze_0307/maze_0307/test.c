#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//int check_sys()
//{
//	int i = 1;
//	//printf("%p\n", &i);//00D3F768
//	//return (*(char *)&i);
//
//	printf("0x%x\n",(*(char *)&i + 0));
//	printf("0x%x\n", (*(char *)&i + 1));
//}
//unsigned char i = 0;

int main()
{	
	
	
	
	
	//int n = 9;
	//float *pFloat = (float *)&n;
	////printf("n��ֵΪ��%d\n", n);	//n��ֵΪ��9
	////printf("*pFloat��ֵΪ��%f\n", *pFloat);	//*pFloat��ֵΪ��0.000000
	//*pFloat = 9.0;//ָ��ָ�����仯
	//printf("num��ֵΪ��%d\n", n);	//num��ֵΪ��1091567616
	////printf("*pFloat��ֵΪ��%f\n", *pFloat);	//*pFloat��ֵΪ��9.000000


	//for (i = 0; i <= 255; i++)
	//{
	//	printf("hello wolrd\n");
	//}
	//

	//short num = 32767;
	//short int a = num + 1;
	//printf("%d\n", a);


	//char a[1000];
	//int i;
	//for (i = 0; i < 1000; i++)
	//{
	//	a[i] = -1 - i;
	//}
	//printf("%d", strlen(a));


	//int a;
	//char a[1000];
	//char a2[1000];
	//char a3[1000];
	//char a4[1000];
	//char a5[1000];
	//printf("%d\n", strlen(a));
	//printf("%d\n", strlen(a2));
	//printf("%d\n", strlen(a3));
	//printf("%d\n", strlen(a4));
	//printf("%d\n", strlen(a5));
	//printf("%d\n", strlen(b));

	//int i;
	//for (i = 0; i < 1000; i++)
	//{
	//	a[i] = -1 - i;
	//}
	//int count = 0;
	//while(*a)
	//{
	//	a++;
	//	count++;
	//}
	//printf("%d\n", count);

	//printf("%d\n", sizeof(a));

	//unsigned int i;
	//for (i = 9; i >= 0; i--)
	//{
	//	printf("%u\n", i);
	//}

	//int i = -20;
	//unsigned int j = 10;
	//printf("%d\n", i + j);

	//char a = 127;//(-128) ~ 127;
	//printf("%u", a);

	
	//char a = -1;
	//signed char b = -1;
	//unsigned char c = -1;//��Ϊ������unsigned���޷��ţ� ���Ի���һ������
	//printf("a=%d,b=%d,c=%d", a, b, c);


	//check_sys();
	//int i_num = 0x12345678;
	//printf("[0]:0x%x\n", *((char*)&i_num + 0));	//[0] : 0x78
	//printf("[1]:0x%x\n", *((char*)&i_num + 1));	//[1] : 0x56
	//printf("[2]:0x%x\n", *((char*)&i_num + 2));	//[2] : 0x34
	//printf("[3]:0x%x\n", *((char*)&i_num + 3));	//[3] : 0x12

	//i_num = htonl(i_num);
	//printf("[0]:0x%x\n", *((char*)&i_num + 0));	//[0] : 0x78
	//printf("[1]:0x%x\n", *((char*)&i_num + 1));	//[1] : 0x56
	//printf("[2]:0x%x\n", *((char*)&i_num + 2));	//[2] : 0x34
	//printf("[3]:0x%x\n", *((char*)&i_num + 3));	//[3] : 0x12


	////С��
	//int ret = check_sys();
	//if (ret == 1)
	//{
	//	printf("С��\n");
	//}
	//else
	//{
	//	printf("���\n");
	//}


	//ԭ�� ֱ�ӽ������ư�������������ʽ����ɶ����ƾͿ��ԡ�
	//���� ��ԭ��ķ���λ���䣬����λ���ΰ�λȡ���Ϳ��Եõ��ˡ�
	//���� ���� + 1�͵õ����롣 ������ԭ���������붼��ͬ
	

	////Sn = a + aa + aaa + aaaa + aaaaa = ?
	//int i = 0;
	//int n = 0;
	//printf("����������ĸ���\n���ֵ�����:\n");
	//scanf("%d %d", n, i);

	//for (int j = 0; j < n; ++j)
	//{
	//	for (int i = 0;i<j;++i)
	//	{
	//		
	//	}

	//}



	////�����������������
	//int a = 0;
	//int b = 0;
	//printf("��������������a��b\n");
	//scanf("%d %d", &a, &b);
	//if (a < b)
	//{
	//	int t = 0;
	//	t = a;
	//	a = b;
	//	b = t;
	//}
	//if (a%b == 0)
	//{
	//	printf("%d��%d���������Ϊ��%d\n", a, b, b);
	//	system("pause");
	//	return 0;
	//}
	//int i = b;
	//for (; i > 0; i--)
	//{
	//	if (a%i == 0 && b%i == 0)
	//	{
	//		printf("a��b���������Ϊ%d\n", i);
	//		break;
	//	}
	//}


	system("pause");
	return 0;
}