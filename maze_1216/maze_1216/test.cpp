#include <iostream>
#include <stdlib.h>
#include <string>
#include <map>
#include <set>
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
	multimap<string, string>mp;
	mp["apple"] = "ƻ��";
	mp["peae"] = "��";
	mp["apricot"] = "��";
	mp["grape"] = "����";
	mp["pineapple"] = "����";
	mp["watermelon"] = "����";
	mp["orange"] = "����";
	mp["lemon"] = "����";
	mp["mango"] = "â��";
	printf("%d\n", mp.size());

	for (auto&e : mp) {
		cout << e.first << "--->" << e.second << endl;
	}
	cout << endl;
	mp.erase("pineapple");
	mp["watermelon"] = "����";
	printf("%d\n", mp.size());
	for (auto&e : mp) {
		cout << e.first << "--->" << e.second << endl;
	}
	cout << endl;
	cout << mp.at("apple")<< endl;
	printf("%d\n", mp.size());

	system("pause");
	return 0;
}

#endif

void TestSet(){
	// ������array�е�Ԫ�ع���set
	int array[] = {1,2,3,2,3,4,5};
	multiset<int> s(array, array + sizeof(array) / sizeof(array[0]));
	// �����ӡset�е�Ԫ�أ��Ӵ�ӡ����п��Կ�����set��ȥ��
	for (auto& e : s) {
		cout << e << " ";
	}
	cout << endl;
	// ֱ�Ӱ� value �����ȥ����
	//s.insert(6);
	//s.insert(7);
	//// ʹ�õ����������ӡset�е�Ԫ��
	//for (auto it = s.rbegin(); it != s.rend(); ++it) {
	//	cout << *it << " ";
	//}
	cout << endl;
}

int main() {
	TestSet();
	system("pause");
	return 0;
}
