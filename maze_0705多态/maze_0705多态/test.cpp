#include <iostream>
#include <stdlib.h>
using namespace std;

class Person {
public:
	virtual void BuyTicket() {
		cout << "��Ʊ-ȫ��" << endl;
	}
};

class Student : public Person {
public:
	virtual void BuyTicket() {
		cout << "��Ʊ-���" << endl;
	}
};

void fun(Person& p) {
	p.BuyTicket();
}

int main() {
	Person p1;
	Student t1;

	fun(p1);
	fun(t1);

	return 0;
}
