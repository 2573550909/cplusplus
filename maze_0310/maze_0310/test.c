#include <stdio.h>
#include <stdlib.h>

//#define ADD(x,y) (x+y)

//void test()
//{
//	int i = 0;
//	int *p = (int *)malloc(10 * sizeof(int));
//	if (NULL == p)
//	{
//		exit(EXIT_FAILURE);
//	}
//	for (i = 0; i <= 10; i++)
//	{
//		*(p + i) = i;//��i��10��ʱ��Խ�����
//	}
//	free(p);
//}
//

int main()
{






	//void test()
	//{
	//	int *p = (int *)malloc(100);
	//	if (NULL != p)
	//	{
	//		*p = 20;
	//	}
	//}
	//int main()
	//{
	//	test();
	//	while (1);
	//}



	//int *p = (int *)malloc(100);
	//free(p);
	//free(p);
	//int *p = (int*)malloc(100);
	//free(p);
	//free(p);
	//int *p = (int *)malloc(100);
	//p++;
	//free(p);//p����ָ��̬�ڴ����ʼλ��


	//int a = 10;
	//int *p = &a;
	//free(p);


//  ��̬�ڴ濪��
//	malloc

	//void* malloc(size_t size);
	//����������ڴ�����һ���������õĿռ䣬������ָ�����ռ��ָ�롣
	//������ٳɹ����򷵻�һ��ָ�򿪱ٺÿռ��ָ�롣
	//�������ʧ�ܣ��򷵻�һ��NULLָ�룬���malloc�ķ���ֵһ��Ҫ����顣
	//����ֵ�������� void* ������malloc��������֪�����ٿռ�����ͣ�
	//������ʹ�õ�ʱ��ʹ�����Լ���������
	//������� size Ϊ0��malloc����Ϊ�Ǳ�׼��δ����ģ�ȡ���ڱ�������

	//void free(void* ptr);
	//free���������ͷŶ�̬���ٵ��ڴ档
	//������� ptr ָ��Ŀռ䲻�Ƕ�̬���ٵģ���free��������Ϊ��δ����ġ�
	//������� ptr ��NULLָ�룬����ʲô�¶�������
	//int num = 4;
	//int* ptr = NULL;
	//ptr = (int*)malloc(num * sizeof(int));
	//if (NULL != ptr)//�ж�ptrָ���Ƿ�Ϊ��
	//{
	//	int i = 0;
	//	for (i = 0; i < num; i++)
	//	{
	//		*(ptr + i) = 0;
	//	}
	//}
	//free(ptr);//�ͷ�ptr��ָ��Ķ�̬�ڴ�

	//int*p = NULL;
	//p = realloc(ptr, 1000);
	//if (p != NULL)
	//{
	//	ptr = p;
	//}
	////ҵ����
	//free(ptr);
	//return 0;


//	free
//	calloc
//	realloc
	



	//int aa[3][5] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10,11 };
	////1 2 3 4 5
	////6 7 8 9 10
	//int *ptr1 = (int *)(&aa + 1);
	//int *ptr2 = (int *)(*(aa + 2));
	//printf("%d\n%d\n", *(ptr1 - 1), *(ptr2 ));
 


	//char *a[] = { "work","at","alibaba" };
	//char**pa = a;
	//pa++;
	//pa++;
	//printf("%s\n", *pa);



	//char *c[] = { "ENTER","NEW","POINT","FIRST" };
	//char**cp[] = { c + 3,c + 2,c + 1,c };
	//char***cpp = cp;
	//printf("%s\n", **++cpp);
	//printf("%s\n", *--*++cpp + 3);
	//printf("%s\n", *cpp[-2] + 3);
	//printf("%s\n", cpp[-1][-1] + 1);
	//
	
	//POINT
	//ER
	//ST
	//EW




	//printf("%s", __DATE__);
	//printf("%d", __STDC__);
	//printf("%s", __FILE__);


	system("pause");
	return 0;
}