#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

#if 1
struct Goods{
	string _name;
	double _price;
};

struct Compare{
	bool operator()(const Goods& gl, const Goods& gr){
		return gl._price <= gr._price;
	}
};

int main() {
	Goods gds[] = 
	{ 
		{ "ƻ��", 2.1 }, { "�ཻ", 3 }, 
		{ "����", 2.2 }, {"����", 1.5}
	};
	sort(gds, gds + sizeof(gds) / sizeof(gds[0]), 
		[](const Goods& l, const Goods& r){
		return l._price <= r._price;
	});
	for (int i = 0; i < sizeof(gds) / sizeof(gds[0]);++i) {
		cout << gds[i]._name <<" "<< gds[i]._price << endl;
	}
	cout << endl;

	Goods gds[] = 
	{ 
		{ "ƻ��", 2.1 }, { "�㽶", 3 },
		{ "����", 2.2 }, {"����", 1.5} 
	};
	sort(gds, gds + sizeof(gds) / sizeof(gds[0]), Compare());

	for (auto&e : gds) {
		cout << e._price<<' ';
		cout << e._name << endl;
	}
	cout << endl;

	int a[10] = { 1,4,5,2,7,8,0,6,3,9 };
	std::sort(a, a+sizeof(a) / sizeof(a[0]),less<int>());
	for (auto& e : a) {
		cout << e << ' ';
	}
	cout << endl;


	system("pause");
	return 0;
}
int main() {
	int a = 10;
	int &b = a;

	int a = 10;
	int &&b = a + 1;
	cout << b << endl;

	system("pause");
	return 0;
}

int main(){
	cout << "-------������������ֵ--------" << endl;
	int a = 5;
	int &add_a = a;

	cout << "   a  =" << a << "    " << "    &a = " << &a << endl;
	cout << "add_a =" << add_a << "    " << "&add_a = " << &add_a << endl;

	cout << "-------������������ֵ--------" << endl;
	int b = 10;
	int &&add_b = b + 1;
	cout << "   b  =" << b << "    " << "    &b = " << &b << endl;
	cout << "add_b =" << add_b << "    " << "&add_b = " << &add_b << endl;
	add_b++;
	cout << "add_b++ =" << add_b << "    " << "&add_b++ = " << &add_b << endl;
	cout << "-----------------------" << endl;

	system("pause");
	return 0;
}

class Person{
public:
	Person(string name, char* sex, int age)
		: _name(name)
		, _sex(sex)
		, _age(age)
	{}
	Person(const Person& p)
		: _name(p._name)
		, _sex(p._sex)
		, _age(p._age)
	{}
#if 0
	Person(Person&& p)
		: _name(p._name)
		, _sex(p._sex)
		, _age(p._age)
	{}
#else
	Person(Person&& p)
		: _name(move(p._name))
		, _sex(move(p._sex))
		, _age(p._age)
	{}
#endif
private:
	string _name;
	string _sex;
	int _age;
};

Person GetTempPerson(){
	Person p("prety", "male", 18);
	return p;
}

int main() {
	Person p(GetTempPerson());

	system("pause");
	return 0;
}
class String{
public:
	// ���캯��
	String(const char* str = "") {
		if (str == nullptr) {
			str = "";
		}
		_str = new char[strlen(str) + 1];
		strcpy(_str, str);
	}
	String(const String& str) {
		_str = new char[strlen(str._str) + 1];
		strcpy(_str, str._str);
	}

	// ��ֵ���������
	String& operator=(const String& str) {
		if (this != &str) {
			char* temp = new char[strlen(str._str) + 1];
			strcpy(temp, str._str);
			delete[]_str;
			_str = temp;
		}
		return *this;
	}

	//�ƶ����캯��
	String(String&& s) : _str(s._str){
		s._str = nullptr;
	}

	// ��������
	~String() {
		if (_str) {
			delete[]_str;
			_str = nullptr;
		}
	}

private:
	char* _str;

};

int main(){
	String s1("hello world");
	/*C++11�У�std::move()����λ�� ͷ�ļ��У�����������־����Ի��ԣ�
		�����������κζ�����Ψһ�Ĺ��ܾ��ǣ���һ����ֵǿ��ת��Ϊ��ֵ���ã�
		ͨ����ֵ����ʹ�ø�ֵ��ʵ���ƶ����塣
		ע�⣺��ת������ֵ�����������ڲ�û����������ֵ��ת�����ı䣬
		��std::moveת������ֵ����lvalue���ᱻ���١�*/
	String s2(move(s1));

	String s3(s2);

	system("pause");
	return 0;
}

int main() {
	int a = 10;
	// int&& ra; // ����ʧ�ܣ�û�н��г�ʼ��
	int&& ra = a; // ����ʧ�ܣ�a��һ����ֵ
	// ra����������10�ı���
	//const int&& ra = 10;
	cout << ra << endl;

	system("pause");
	return 0;
}

class String {
public:
	// ���캯��
	String(const char* str = "") {
		if (str == nullptr) {
			str = "";
		}
		_str = new char[strlen(str) + 1];
		strcpy(_str, str);
	}
	String(const String& str) {
		_str = new char[strlen(str._str) + 1];
		strcpy(_str, str._str);
	}

	// ��ֵ���������
	String& operator=(const String& str) {
		if (this != &str) {
			char* temp = new char[strlen(str._str) + 1];
			strcpy(temp, str._str);
			delete[]_str;
			_str = temp;
		}
		return *this;
	}
	// ��������
	~String() {
		if (_str) {
			delete[]_str;
			_str = nullptr;
		}
	}

private:
	char* _str;
};

String GetString(const char* pStr) {
	return String(pStr);
}

int main() {
	// ��һ����������ȡ����
	// �ӳ������������������
	String&& s = GetString("hello");
	
	system("pause");
	return 0;
}
#endif