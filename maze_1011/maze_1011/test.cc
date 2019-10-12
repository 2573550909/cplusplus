#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdlib.h>
#include <string>
using namespace std;

char* Strcpy(char* pStrDest,const char* pStrSrc) {
	//�����³�����ж�
	if (pStrDest == nullptr || pStrSrc == nullptr) {
		return nullptr;
	}
	char* add = pStrDest;
	while ((*pStrDest = *pStrSrc) != '\0') {
		++pStrDest;
		++pStrSrc;
	}
	return add;
}

void GetMemory(char** p,int num) {
	if (num <= 0) {
		printf("������ڴ�̫С��\n");
	}
	*p = (char*)malloc(num);
	if (*p == nullptr) {
		return;
	}
}

void test() {
	char* str = nullptr;
	GetMemory(&str, 100);
	strcpy(str, "hello");
	free(str);
	printf("%s",str);
}

void Test() {
	char*str = (char*)malloc(100);
	strcpy(str, "hello");
	free(str);
}

void swap1(int *p1, int* p2) {
	int *p = p1;
	int *n = p2;
	*p1 = *p;
	p2 = p;
}

void swap2(int& p1, int& p2) {
	int p = p1;
	p1 = p2;
	p2 = p;
}

void isfloatequal(float n1, float n2) {
	const float EPSINON = 0.00001;
	int x = n1 - n2;
	if ((x <= EPSINON)&&(x>=-EPSINON)) {
		printf("�����ж����������\n");
	}
	else {
		printf("����\n");
	}
}

int main() {
	isfloatequal(0.0000001,0.00000002);
	isfloatequal(0.0001,1);
	isfloatequal(100,100.0000001);

	system("pause");
	return 0;
}

#if 0
union temp{
	int a;
	char b;
}temp;

int main(){
	int a = 0x12345;

	if (*(char*)&a == 0x45) {
		cout << "С��ģʽ" << endl;
	}
	else {
		cout << "���ģʽ" << endl;
	}

	system("pause");
	return 0;
}
#endif	