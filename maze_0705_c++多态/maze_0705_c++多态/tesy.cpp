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


class A {};
class B : public A {};
class Person {
public:
	//������󷵻ػ����ָ��
	virtual A* f() { 
		return new A; 
	}
};

class Student : public Person {
public:
	virtual B* f() { 
		return new B;
	}
};

class Perosn {
public:
	virtual ~Perosn() {
		cout << "~Person" << endl;
	}
};

class Student :public Perosn {
public:
	virtual ~Student() {
		//������д�˻�����������������Ի������һ�λ������������
		cout << "~Student" << endl;
	}
};


class Car{
public:
	//��final���εĺ������ܱ��̳�
	virtual void Drive() final {}
};

class Benz :public Car{
public:
	//�޷���д���ຯ���е�Drive
	virtual void Drive() {
		cout << "Benz-����" << endl;
	}
};


class Car {
public:
	virtual void Drive() {}
};

class Benz :public Car {
public:
	//override �������麯���Ƿ���д�˻����ĳ���麯��
	//���û�з�����д��������
	virtual void Drive() override { 
		cout << "Benz-����" << endl;
	}
};


class Car{
public:
	//�������麯������г����ࣨ�ӿ��ࣩ����ʵ����������
	virtual void Drive() = 0;
	//���麯��
};

class Benz :public Car{
public:
	virtual void Drive(){
		cout << "Benz-����" << endl;
	}
};

class BMW :public Car{
public:
	virtual void Drive(){
		cout << "BMW-�ٿ�" << endl;
	}
};

void Test(){
	Car* pBenz = new Benz;
	pBenz->Drive();
	Car* pBMW = new BMW;
	pBMW->Drive();
}


class Base{
public:
	virtual void Func1(){
		cout << "Func1()" << endl;
	}
private:
	int _b = 1;
};

int main() {
	cout << sizeof(Base) << endl;

	Test();
	Perosn* p1 = new Student;
	Perosn* p2 = new Perosn;
	delete p1;
	delete p2;

	Person p1;
	Student t1;

	fun(p1);
	fun(t1); 

	system("pause");
	return 0;
}