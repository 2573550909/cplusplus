#include <iostream>
#include <stdlib.h>
using namespace std;

//��������д�����麯��ʱ��������麯������ֵ���Ͳ�ͬ��
//
//�����麯�����ػ�������ָ��������ã�
//�������麯����������������ָ���������ʱ����ΪЭ��
//
//���Ǹ���д�����Ǻܹ淶������������ʹ��* /
//
class A {};
class B : public A {};

class Person {
public:
	virtual A* f() { return new A; }
};

class Student : public Person {
public:
	virtual B* f() { return new B; }
};

/*2. ������������д(�������������������������ֲ�ͬ)
����������������Ϊ�麯������ʱ��������������ֻҪ���壬
�����Ƿ��virtual�ؼ��֣�����������������������д��
��Ȼ�����������������������ֲ�ͬ��������Υ������д�Ĺ���
��ʵ��Ȼ������������Ϊ�����������������������������⴦��
�������������������ͳһ�����destructor��
������麯�����̳������������������ɱ����麯������), 
c*/class Person {
public:
	virtual ~Person(){
		cout << "�������������" << endl;
	}
};

class Student : public Person {
	virtual ~Student(){
		cout << "���������������" << endl;
	}
};

class Base {
public:
	virtual void fun1() {
		cout << "Base::fun1()" << endl;
	}
	virtual void fun2() {
		cout << "Base::fun2()" << endl;
	}
	//��������������ַ�ᱻ�Ž��麯������
	//fun3()���ڲ����麯�������麯��û�й�ϵ
	void fun3() {
		cout << "Base::fun3()" << endl;
	}
private:
	int _b = 1;
};

class Drive : public Base {
public:
	//�����fun1()��д�˻����е��麯��fun1()
	//��������ȡ���̳��µ�fun1()
	virtual void fun1() {
		cout << "Drive::fun1()" << endl;
	}
	virtual void fun4() {
		cout << "Drive::fun4()" << endl;
	}

private:
	int d = 2;
};

class Base {
public:
	virtual void func1() { cout << "Base::func1" << endl; }
	virtual void func2() { cout << "Base::func2" << endl; }
private:
	int a;
};

class Derive :public Base {
public:
	virtual void func1() { cout << "Derive::func1" << endl; }
	virtual void func3() { cout << "Derive::func3" << endl; }
	virtual void func4() { cout << "Derive::func4" << endl; }
private:
	int b;
};

typedef void(*VFPTR) ();
void PrintVTable(VFPTR vTable[]){
	 ����ȡ����е��麯��ָ���ӡ�����á����þͿ��Կ���������ĸ�����
	cout << " ����ַ>" << vTable << endl;
	for (int i = 0; vTable[i] != nullptr; ++i){
		printf(" ��%d���麯����ַ :0X%x,->", i, vTable[i]);
		VFPTR f = vTable[i];
		f();
	}
	cout << endl;
}

int main(){
	Base b;
	Derive d;
	VFPTR* vTableb = (VFPTR*)(*(int*)&b);
	PrintVTable(vTableb);
	VFPTR* vTabled = (VFPTR*)(*(int*)&d);
	PrintVTable(vTabled);

	system("pause");
	return 0;
}

int main() {
	
	Base b;
	Derive d;

	Person* p1 = new Person;
	//p2 �����������������
	Person* p2 = new Student;

	delete p1;
	delete p2;

	return 0;
}

class Person {
public:
	//�����õĺ����������麯��
	virtual void buytacket(){
		cout << "ȫ�۹�Ʊ" << endl;
	}
	//��virtual ���εĳ�Ա���������麯��
};

class Student :public Person {
	//������ĺ�������Ի���ĺ���������д
	virtual void buytacket(){	
		cout << "��۹�Ʊ" << endl;
	}
	//����������һ���ͻ�����ȫ��ͬ���麯����֮Ϊ��д
	//��ȫ��ָͬ���ǣ�����ֵ���ͣ��������������б�
};

//���ɶ�̬������֮һ���ǣ�����ͨ�������ָ������õ����麯��
void Func(Person& p) {
	p.buytacket();
}

int main() {
	Person p1;
	Func(p1);

	Student s1;
	Func(s1);

	system("pause");
	return 0;
}