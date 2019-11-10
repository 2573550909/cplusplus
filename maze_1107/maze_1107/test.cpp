#include <iostream>
#include <stdlib.h>
#include <typeinfo>
#include <memory>
using namespace std;

template <class T>
class Shared_ptr {
public:
	// ���캯���ĳ�ʼ��
	Shared_ptr(T* str = nullptr)
		:_ptr(ptr)
		,_pRefCount(new int(1))
		,_pMutex(new mutex)
	{}
	~Shared_ptr() {
		Replease();
	}

	// ����һ������
	void AddRefCount() {
		_pMutex.lock();
		++(*_pRefCount);
		_pMutex.unlock();
	}
private:
	void Replease() {
		bool deleteflag = false;
		_pMutex.lock();
		if (--(*pRefCount)== 0) {
			delete _ptr;
			delete _pRefCount;
			deleteflag = true;
		}
		_pMutex.unlock();

		if (deleteflag == true) {
			delete _pMutex;
		}
	}
private:
	mutex* _pMutex 
	int* _pRefCount; // ���ü���
	T* _ptr; // ָ�������Դ��ָ��
};

#if 0
//class A {
//public:
//	A() {
//		printf("A���캯��\n");
//	}
//	void display() {
//		fei_display();
//		printf("���Ƿ� const ����\n");
//	}
//	const void fei_display()const {
//		display();
//		printf("���� const ����\n");
//	}
//	~A() {
//		printf("ϴ������ʡũ��\n");
//	}
//
//
//private:
//	int a;
//};
//

class Base {
};

class Derived :public Base {
};

int main() {

	Base b;
	Derived d = static_cast<Derived>(b);
	cout << typeid(b).name() << endl;
	cout << typeid(d).name() << endl;
		

	//double a = 12.34;
	//int b = static_cast<int>(a);
	//printf("%d\n", b);

	//int i = 1;
	//double j = i;
	//printf("%f\n", j);

	//int* p = &i;
	//int address = (int)p;
	//printf("%x, %d\n", p, address);

	system("pause");
	return 0;
}
class A {
public:
	virtual void f() {}
};
class B : public A
{};

void fun(A* pa) {
	// dynamic_cast���ȼ���Ƿ���ת���ɹ���
	// �ܳɹ���ת���������򷵻�0
	cout << "pa" <<' '<< typeid(pa).name()<<pa << endl;

	B* pb1 = static_cast<B*>(pa);
	B* pb2 = dynamic_cast<B*>(pa);
	//pa   class A*  00AFFE00
	//pb1  class B*  00AFFE00
	//pb2  class B*  00000000 

	//pa   class A*  00AFFDF4
	//pb1  class B*  00AFFDF4
	//pb2  class B*  00AFFDF4
	cout << "pb1" <<' '<<typeid(pb1).name()<<' '<< pb1 << endl;
	cout << "pb2" <<' '<<typeid(pb2).name()<<' '<< pb2 << endl;
}

int main() {
	A a;
	B b;
	fun(&a);
	fun(&b);

	system("pause");
	return 0;
}

int main() {
	int a = 0;
	double d = reinterpret_cast<double*>(a);


	system("pause");
	return 0;
}
#endif

