#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//struct S
//{
//	int date[1000];
//	int num;
//};
//
//struct S s = { {1,2,3,4},1000 };
//
////�ṹ�崫��
//void print1(struct S s)
//{
//	printf("%d\n", s.num);
//}
//
////�ṹ���ַ����
//void print2(struct S* ps)
//{
//	printf("%d\n", ps->num);
//}
//
//struct A   //��СΪ8
//{
//	int _a : 2;
//	int _b : 5;
//	int _c : 10;
//	int _d : 20;
//
//};

int main()
{	

	//union Un1     //8
	//{
	//	char c[5];
	//	int i;
	//};
	//
	//union Un2     //16
	//{
	//	short c[7];
	//	int i;
	//};

	//printf("%d\n", sizeof(union Un1));
	//printf("%d\n", sizeof(union Un2));

	//printf("%d", sizeof(struct A));//8
	//print1(s); //1000
	//print2(&s);//1000
	//�ṹ�崫�ε�ʱ��ѡ�񴫵�ַ����Ҫ���ṹ�壬������̫�����Ӷ���ĳɱ���

	
	//32λ����ϵͳ��intռ4�ֽڣ�charռ1�ֽڣ�doubleռ8�ֽڣ�floatռ4�ֽ�
	//64λ����ϵͳ��intռ  �ֽڣ�char ռ�ֽڣ�doubleռ �ֽڣ�floatռ �ֽ�

	//struct str
	//{
	//	char c1;
	//	int i ;
	//	char c2;
	//};
	//printf("%d", sizeof(struct str));//12

	//struct str
	//{
	//	char c1;
	//	char c2;
	//	int i;
	//};
	//printf("%d", sizeof(struct str));//8

	//struct str
	//{
	//	double d;
	//	char i;
	//	int a;
	//};
	//printf("%d", sizeof(struct str));//16



	system("pause");
	return 0;
}