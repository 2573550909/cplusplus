#include <iostream>
#include <stdlib.h>
#include <string>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <functional> // greater�㷨��ͷ�ļ�
#include <list>
using namespace std;

#if 1
// insert/erase���µĵ�����ʧЧ
int main(){
	int a[] = { 1, 2, 3, 4 };
	vector<int> v(a, a + sizeof(a) / sizeof(int));
	// ʹ��find����3����λ�õ�iterator
	vector<int>::iterator pos = find(v.begin(), v.end(), 3);
	// ɾ��posλ�õ����ݣ�����pos������ʧЧ��
	v.erase(pos);
	cout << *pos << endl; // �˴��ᵼ�·Ƿ�����
	// ��posλ�ò������ݣ�����pos������ʧЧ��
	// insert�ᵼ�µ�����ʧЧ������Ϊinsert��
	// �ܻᵼ�����ݣ����ݺ�pos��ָ��ԭ���Ŀռ䣬��ԭ���Ŀռ��Ѿ��ͷ��ˡ�
	pos = find(v.begin(), v.end(), 3);
	v.insert(pos, 30);
	cout << *pos << endl; // �˴��ᵼ�·Ƿ�����

	system("pause");
	return 0;
}

int main(){
	int a[] = { 1, 2, 3, 4 };
	vector<int> v(a, a + sizeof(a) / sizeof(int));
	// ʵ��ɾ��v�е�����ż��
	// ����ĳ����������������ż����erase����itʧЧ
	// ��ʧЧ�ĵ���������++it���ᵼ�³������
	vector<int>::iterator it = v.begin();
	while (it != v.end()){
		if (*it % 2 == 0) {
			v.erase(it);
		}
		++it;
	}
	//�޸ĳ��� Ϊ���棺
	//erase�᷵��ɾ��λ�õ���һ��λ��
	vector<int>::iterator it = v.begin();
	while (it != v.end()){
		if (*it % 2 == 0) {
			it = v.erase(it);
		}
		else {
			++it;
		}
	}
	return 0;
}

int main() {
	cout << "hello";
	return 0;
}

int main() {
	string str1 = "hello maze";
	string str2 = str1;
	printf("%p\n", str1.c_str());
	printf("%p\n", str2.c_str());
	str1[0] = 'W';
	str2[0] = 'W';
	printf("%p\n", str1.c_str());
	printf("%p\n", str2.c_str());

	system("pause");
	return 0;
}

char *mystrcpy(char *str, const char *ptr){
	char *temp = str;
	while ((*str++ = *ptr++) != '\0');
	return temp;
}



char* mystrcpy(char* s1, const char *s2) {
	int len = strlen(s2);
	char* tmp = s1;
	while (len--) {
		*s1++ = *s2++;
	}
	*s1 = '\0';
	return tmp;
}

void test() {
	char str1[] = "heheheheh";
	char str2[] = "maze";
	printf("%s\n",mystrcpy(str1, str2));
}

int mystrlen(char* s) {
	int count = 0;
	while (*(s++) != '\0') {
		++count;
	}
	return count;
}

int mystrlen_nor(char* s) {
	if (*s == '\0') {
		return 0;
	}
	return 1 + mystrlen(s + 1);
}
void test() {
	char str1[] = "heheh";
	int len = mystrlen(str1);
	printf("%d\n", len);
	printf("%d\n", mystrlen_nor(str1));
}

void test() {
	
}

int main() {
	test();
	system("pause");
	return 0;
}

int main(){
	int array[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
	list<int> l(array, array + sizeof(array) / sizeof(array[0]));
	// ʹ���������������list�е�Ԫ��
	for (list<int>::iterator it = l.begin(); it != l.end(); ++it)
		cout << *it << " ";
	cout << endl;
	// ʹ�÷�������������ӡlist�е�Ԫ��
	for (list<int>::reverse_iterator it = l.rbegin(); it != l.rend(); ++it)
		cout << *it << " ";
	cout << endl;
	// cosnt�����������
	auto cit = l.cbegin();
	cout << typeid(cit).name() << endl;
	//*cit = 10; ���д������ʧ�ܣ���ΪcitΪconst_iterator���͵ĵ�����

	system("pause");
	return 0;
}
void PrintDeque(const std::deque<int>& d){
	for (const auto& e : d) {
		cout << e << " ";
	}
	cout << endl;
}

void TestDeque2(){
	int array[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
	std::deque<int> d(array, array + sizeof(array) / sizeof(array[0]));
	// ���������������ӡdeque�е�Ԫ��
	for (auto it = d.cbegin(); it != d.cend(); ++it) {
		cout << *it << " ";
	}
	cout << endl;
	auto cit = d.cbegin();
	//*it = 100; ����������ʧ�ܣ�itΪconst��������
	// ��ָ��ռ�Ԫ��ֵ�����޸�
	// ���÷�������������ӡdeque�е�Ԫ��
	for (auto it = d.crbegin(); it != d.crend(); ++it) {
		cout << *it << " ";
	}
	cout << endl;
}

void TestDeque3(){
	// �б�ʽ��ʼ����C++11�﷨
	deque<int> d1{ 3,4,5 };
	// ��deque��β������5��ͷ������1������ӡ
	d1.push_back(6);
	d1.push_front(2);
	PrintDeque(d1);
	cout << d1.size() << endl;
	cout << d1.front() << endl;
	cout << d1.back() << endl;
	// ��deque��β������6��ͷ������0
	// ע�⣺�������������Ԫ�أ�
	// emplace_back��push_back emplace_front��push_front��Ч����ͬ
	// ������Զ�������Ԫ��
	// emplace_back/emplace_front��Ч�ʸ��ߣ�
	// ����������ֱ����β������ͷ������Ԫ��
	// push_back/push_front��Ч�ʵͣ��ò���ʱ�Ƚ�Ԫ�ع���ã�
	// Ȼ�󿽱���β����ͷ��
	d1.emplace_back(7);
	d1.emplace_front(1);
	PrintDeque(d1);
	// ��deque��beginλ�ò���Ԫ��0
	d1.insert(d1.begin(), 0);
	PrintDeque(d1);
	// ɾ��deque�ײ���β��Ԫ��
	d1.pop_front();
	d1.pop_back();
	d1.erase(d1.begin());
	PrintDeque(d1);
	// ��deque�е�Ԫ�����
	d1.clear();
	cout << d1.size() << endl;
}
// ���⣺���Ҫ��deque�е�Ԫ�ؽ����������µ�Ч�ʸ���
void TestDequeSort(){
	int array[] = { 5, 2, 1, 9, 6, 3, 8, 7, 4, 0 };
	deque<int> d(array, array + sizeof(array) / sizeof(array[0]));
	PrintDeque(d);
	// ���ñ�׼���е��㷨��deque�е�Ԫ�ؽ�����������
	sort(d.begin(), d.end());
	PrintDeque(d);
}
/*
������deque�����������Ч���Ƿǳ��͵ģ�
����deque����ʱ����Ҫ��ζ�deque�е�Ԫ�ؽ������������
��deque�е�Ԫ���������ʱЧ�ʱȽϵͣ�
������Ϊdeque�ײ�Ŀռ䲻������
���Ҫ���������������ĳ�οռ��Ĭ�ϻ��ײ�ʱ��
����Ҫ������һ�λ���ǰһ�οռ��λ�ã�����deque��Ч�ʱȽϵ��¡�
*/
int main() {
	TestDeque2();

	system("pause");
	return 0;
}
void TestPriorityQueue(){
	// Ĭ������£��������Ǵ�ѣ���ײ㰴��С�ںűȽ�
	vector<int> v{ 3,2,7,6,0,4,1,9,8,5 };
	priority_queue<int> q1;
	for (auto& e : v) {
		q1.push(e);
	}
	cout << q1.top() << endl;
	// ���Ҫ����С�ѣ���������ģ���������greater�ȽϷ�ʽ
	priority_queue<int, vector<int>, greater<int>> q2(v.begin(), v.end());
	cout << q2.top() << endl;
}

int main() {
	TestPriorityQueue();

	system("pause");
	return 0;
}
#endif
template<class T, class Con = deque<T>>
class Stack
{
public:
	Stack() {}
	void Push(const T& x) { _c.push_back(x); }
	void Pop() { _c.pop_back(); }
	T& Top() { return _c.back(); }
	const T& Top()const { return _c.back(); }
	size_t Size()const { return _c.size(); }
	bool Empty()const { return _c.empty(); }
private:
	Con _c;
};
template<class T, class Con = deque<T>>
class Queue
{
public:
	Queue() {}
	void Push(const T& x) { _c.push_back(x); }
	void Pop() { _c.pop_front(); }
	T& Back() { return _c.back(); }
	const T& Back()const { return _c.back(); }
	T& Front() { return _c.front(); }
	const T& Front()const { return _c.front(); }
	size_t Size()const { return _c.size(); }
	bool Empty()const { return _c.empty(); }
private:
	Con _c;
};
