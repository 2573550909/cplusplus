#include <iostream>
#include <stdlib.h>
using namespace std;

class A{
public:
	void foo(){
		printf("1");
	}
	virtual void fun(){
		printf("2");
	}
};

class B : public A{
public:
	void foo(){
		printf("3");
	}
	// fun Ϊ�麯��
	void fun(){
		printf("4");
	}
};

int main(void){
	A a;
	B b;
	A *p = &a;
	p->foo(); //1
	p->fun(); //2
	p = &b;
	p->foo(); //1
	p->fun(); //4
	A *ptr = (A *)&b;
	ptr->foo(); //1
	ptr->fun(); //4

	system("pause");
	return 0;
}


#if 0
int main(int argc, char* argv[]){
	A*p1 = new A;
	A*p2 = new B;
	// B*p3 = new A;    //error
	B*p3 = reinterpret_cast<B*> (new A);
	B*p4 = new B;
	// test()
	p1->test();    //A->1
	p2->test();    //A->1
	p3->test();    //A->1
	p4->test();    //A->1
	// func()
	p1->func();    //A->1
	p2->func();    //A->1
	p3->func();    //B->0
	p4->func();    //B->0
	
	//A*p1 = new A;
	//A*p2 = new B;
	//// B*p3 = new A;    //error
	//B*p3 = reinterpret_cast<B*> (new A);
	//B*p4 = new B;

	//// ���������ó�Ա����
	//p1->test();    //A->1
	//// ��̬���� ���Ƚ� val ��Ϊ1
	//p2->test();    //B->1
	//// p3 �����±������Ϊһ�� A��ָ��
	//p3->test();    //A->1

	//p4->test();    //B->1
	////����func()
	//p1->func();    //A->1
	//p2->func();    //B->1
	//// ���� val ����0,Ȼ�����±�����
	//p3->func();    //A->0
	//p4->func();    //B->0

	system("pause");
	return 0;
}

#include <stdio.h>
#include <stdlib.h>

#define N 9
int x[N];

int count = 0;

void dump() {
	int i = 0;
	for (i = 0; i < N; i++) {
		printf("%d", x[i]);
	}
	printf("\n");
}
void swap(int a, int b) {
	int t = x[a];
	x[a] = x[b];
	x[b] = t;
}
void run(int n) {
	int i;
	if (N - 1 == n) {
		dump();
		count++;
		return;
	}
	for (i = n; i < N; i++) {
		swap(n, i);
		run(n + 1);
		swap(n, i);
	}
}

int main() {
	int i;
	for (i = 0; i < N; i++) {
		x[i] = i + 1;
	}
	run(0);
	printf("* Total: %d\n", count);

	system("pause");
	return 0;
}
#endif
