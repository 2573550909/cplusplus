#include "test.h"

//1. ��Ϥ�ѵĸ����Լ�����
//2. �ܽ����ݽṹ�ж����ڴ����������
//3. ʵ�ֶѵ����²���
//4. �ú���ָ��Զѽ�����չ��ʹ�û�������Ҫȥ������ѻ���С��

int main()
{
	Heap hp;
	int a[] = { 15,16,47,78,65,41,23,65,52,85 };
	int len = sizeof(a) / sizeof(a[0]);
	InitHeap(&hp, a, len);
	//AdjustDown(&hp, a[0], len);

	system("pause");
	return 0;
}