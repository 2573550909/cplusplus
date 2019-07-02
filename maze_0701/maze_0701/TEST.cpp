#include <iostream>
#include <stdlib.h>
#include <string>
using namespace std;

class Person {
public:
	void Print() {
		cout << "name" << _name << endl;
		cout << "age" << _age << endl;
	}
protected:
	string _name = "Jack";
private:
	int _age = 18;
};

class Student :public Person {
protected:
	int _num = 100;
};

class Teacher :public Person {
protected:
	int _Tnum;
};

class Person {
protected:
	string _name;
	string _gender;
	int _age;
};

class Student :public Person {
public:
	int _id;
};

class Person {
protected:
	string _name = "Jack";
	int _num = 11;
};

class Student :public Person {
public:
	void Print() {
		cout << "����" << _name << endl;
		�������Person���ʵ���Student
		���������������
		cout << "ʡ��֤��" <<Person::_num << endl;
		cout << "ѧ��" << _num << endl;
	}
protected:
	int _num = 99;
};

class A {
public:
	void Fun() {
		cout << "Fun()" << endl;
	}
};

class B :public A {
public:
	void Fun(int i) {
		A::Fun();
		cout << "Fun(int i)" << i << endl;
	}
};

class Person {
public:
	Person(const char* name = "Jack")
		:_name(name) {
		cout << "���ǻ���Ĺ��캯��" << endl;
	}

	Person(const Person& s)
		: _name(s._name)
	{
		cout << "���ǻ���Ŀ������캯��" << endl;
	}

	Person operator=(const	Person s) {
		cout << "���ǻ���ĸ�ֵ��������" << endl;
		if (this != &s) {
			_name = s._name;
		}
		return *this;
	}

	~Person() {
		cout << "���ǻ������������" << endl;
	}

protected:
	string _name;
};

class Student : public Person{
public:
	Student(const char* name, int num)
		: Person(name)
		, _num(num)
	{
		cout << "����������Ĺ��캯��"<< endl;
	}

	Student(const Student& s)
		: Person(s)
		, _num(s._num)
	{
		cout << "����������Ŀ������캯��" << endl;
	}

	Student& operator = (const Student& s){
		cout << "����������ĸ�ֵ����������" << endl;
		if (this != &s){
			Person::operator =(s);
			_num = s._num;
		}
		return *this;
	}

	~Student(){
		cout << "���������������" << endl;
	}
protected:
	int _num; //ѧ��
};

void Test(){
	Student s1("jack", 18);
	���ǻ���Ĺ��캯��
	����������Ĺ��캯��
	Student s2(s1);
		���ǻ���Ŀ������캯��
		����������Ŀ������캯��
	Student s3("rose", 17);
		���ǻ���Ĺ��캯��
		����������Ĺ��캯��
	s1 = s3;
		����������ĸ�ֵ����������
		���ǻ���Ŀ������캯��
		���ǻ���ĸ�ֵ��������
		���ǻ���Ŀ������캯��
		���ǻ������������
		���ǻ������������
	cout << endl;
		���������������
		���ǻ������������
		���������������
		���ǻ������������
		���������������
		���ǻ������������
}

class NonInherit
{
public:
	static NonInherit GetInstance()
	{
		return NonInherit();
	}
private:
	NonInherit()
	{}
};

class A :public NonInherit {

};
 
 C++11�������µĹؼ���final��ֹ�̳�
class NonInherit final
{};

int main() {
	Test();
	B b1;
	b1.Fun(10);

	Student s1;
	s1.Print();

	�������ǿ��Ը������ָ�룬���ö���ֵ��

	Student s1;
	Person p1 = s1;
	Person* p2 = &s1;
	Person& p3 = s1;


	Student s1;
		
	Teacher t1;
	cout << sizeof(class Teacher) << endl;
	cout << sizeof(class Student) << endl;

	s1.Print();
	t1.Print();
	
	system("pause");
	return 0;
}