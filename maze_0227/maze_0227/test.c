#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

//void* memcpy(void* dest, const void* src, size_t n);����ԭ��
//			ָ��Ŀ���ڴ�ָ�룬ָ��Դ�ڴ��ָ�룬�����ֽ���
//����һ��Ŀ���ڴ�����ָ��dest
//
//void* my_memcpy(void* dest, const void* src, size_t n)
//{
//	//������һ���ж�
//	//if (dest == NULL || src == NULL || n > 0)
//	//{
//	//	fprintf(stderr, "error\n");
//	//	return NULL;
//	//}
//	//�����ڶ����ж�
//	assert(dest != NULL);//�����жϸ�ָ���Ƿ��ǿ�ָ��
//	assert(src != NULL);//��Ϊ��ָ�벻�ܽ�����
//	void* result = dest;//���Ҳ���Բ�д
//	//ѭ������ֱ����n��ֵ
//	while (--n)
//	{
//		*(char*)dest = *(char*)src;//ǿ������ת����nΪ�ֽڸ���
//		dest = (char*)dest + 1;
//		src = (char*)src + 1;
//	}
//	return result;//����resultָ��Ŀ��ռ����ʼ��ַ
//} 
//void* show(int* arr2, int* arr1, int sz)
//{
//	int i = 0;
//	for (i = 0; i < sz; ++i)
//	{
//		printf("%d ", arr2[i]);
//	}
//	printf("\n");
//}

void* my_memmove(void* dest, const void* src, int n)
{
	assert(dest != NULL);
	assert(src != NULL);
	char* pdest = (char*)dest;//ǿ������ת��
	const char* psrc = (const char*)src;//ǿ������ת��
	int count = 0;
	//��������´�ͷ����ʼ����
	if (pdest < psrc )
	{
		count = 1;
		while (n--)
		{
			*pdest = *psrc;
		}
	}
	else//�������ڴ渲��ʱ����β����ʼ��ǰ����
	{
		count = 2;
		while (n--)
		{
			*(pdest + n) = *(psrc + n);
		}
	}
	printf("%d\n", count);
	return dest;
}


int main()
{
	//memmove
	int i = 0;
	char arr1[15] = { 0 };
	char arr[10] = { 1,2,3,4,5,6,7,8,9,10};
	int sz = sizeof(arr) / sizeof(arr[0]);
	my_memmove(arr1, arr , sz);
	for (i = 0; i < sz; ++i)
	{
		printf("%d ", arr1[i]);
	}
	printf("\n");





	//memcpy��Դ�ڴ��ַ����ʼλ�ÿ�ʼ�������ɸ��ֽڵ�Ŀ���ڴ��ַ
	//char arr1[20] = "hello world";
	//char arr2[20];
	//int sz = sizeof(arr1) / sizeof(arr1[0]);
	//memcpy(arr2, arr1,sz );
	//printf("%s", arr2);
	//char arr1[11] = { 1,2,3,4,5,6,7,8,9,10};
	//char arr2[11] = { 0 };
	//char sz = sizeof(arr1) / sizeof(arr1[0]);
	//my_memcpy(arr2, arr1, sz);
	//for (int i = 0; i < sz-1; ++i)
	//{
	//	printf("%d ", arr2[i]);
	//}
	//printf("\n");
	//
	//show(&arr2, &arr1, sz);
	//printf("%d", sz);//20

	//for (int i = 0; i < sz; ++i)
	//{
	//	printf("%d ", arr2[i]);
	//}







	//memset
	//memcmp





	//char str1[20];
	//char str2[20];
	//strcpy(str1, "To be ");//���Ƶ�str1
	//strcpy(str2, "or not to be");//ͬ��
	//strncat(str1, str2, 6);//��str2��ǰ6���ַ������ӵ�str1����ȥ,���ҷ���str1
	//puts(str1);//���str1



	system("pause");
	return 0;
}