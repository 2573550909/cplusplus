#include <iostream>
#include <stdlib.h>
using namespace std;

#if 0
class B {
public:
	B() {
		cout << "�����˹��캯��" << endl;
	}
private:
	~B() {
		cout << "��������������" << endl;
	}
};

class A{
public:
	A() {
		cout << "�����˹��캯��" << endl;
	}
	void destory() {
		delete this;
	}
private:
	~A() {
		cout << "��������������" << endl;
	}
};

#endif

class A{
protected:
	A() {
		cout << "�����˹��캯��" << endl;
	}
	~A() {
		cout << "��������������" << endl;
	}
public:
	static A* create(){
		return new A();
	}
	void destory(){
		delete this;
	}
};

int main() {
	A a;
	a.create();
	a.destory();

	system("pause");
	return 0;
}