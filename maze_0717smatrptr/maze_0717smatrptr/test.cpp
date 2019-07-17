#include "SmartPtr.h"

#if 1
void Test() {
	UniquPtr<int> p1(new int);
	*p1 = 10;

	SmartPtr<int>p1(new int);
	*p1 = 10;
	cout << *p1 << endl;

	SmartPtr<int> sparray(new Date);
	sparray->_year = 2019;
}

void Test1() {
	auto_ptr<Date> ap(new Date);
	auto_ptr<Date> app(ap);

	//��Դ������ת�ƣ�����ap��Ϊ�˿�
	ap->_year = 10;
	app->_month = 20;
}


void TestSmartptr() {
	SmartPtr<int>s1(new int);
	SmartPtr<int>s2(s1);

	
	SmartPtr<Date> sparray(new Date);
	sparray->_year = 2019;
	sparray->_month = 7;
	sparray->_days = 17;
	// shared_ptrͨ�����ü���֧������ָ�����Ŀ���
	shared_ptr<Date> sp(new Date);
	shared_ptr<Date> copy(sp);
	cout << "ref count:" << sp.use_count() << endl;
	cout << "ref count:" << copy.use_count() << endl;
}

void TestSharedPtr() {

	SharedPtr<int>sp1(new int(10));
	SharedPtr<int>sp3(new int(10));
	SharedPtr<int>sp2(new int);
	sp2 = sp1;

	//SharedPtr<int> sp1(new int(10));
	//SharedPtr<int> sp2(sp1);
	//*sp2 = 20;
	//cout << sp1.UseCount() << endl;
	//cout << sp2.UseCount() << endl;
	//SharedPtr<int> sp3(new int(10));
	//sp2 = sp3;
	//cout << sp1.UseCount() << endl;
	//cout << sp2.UseCount() << endl;
	//cout << sp3.UseCount() << endl;
	//sp1 = sp3;
	//cout << sp1.UseCount() << endl;
	//cout << sp2.UseCount() << endl;
	//cout << sp3.UseCount() << endl;
}


void SharePtrFunc(shared_ptr<Date>& sp, size_t n){
	cout << sp.get() << endl;
	for (size_t i = 0; i < n; ++i){
		// ��������ָ�뿽����++������
		//����ָ��������--�������������̰߳�ȫ�ġ�
		shared_ptr<Date> copy(sp);
		// ��������ָ����ʹ������Դ�������̰߳�ȫ�ġ�
		//�������ǿ�����Щֵ�����߳�++��2n�Σ�������
		//�տ����Ľ������һ���Ǽ���2n
		copy->_year++;
		copy->_month++;
		copy->_days++;
	}
}

int main() {

	shared_ptr<Date> p(new Date);
	cout << p.get() << endl;
	const size_t n = 100;
	thread t1(SharePtrFunc, p, n);
	thread t2(SharePtrFunc, p, n);
	t1.join();
	t2.join();
	cout << p->_year << endl;
	cout << p->_month << endl;
	cout << p->_days << endl;

	system("pause");
	return 0;
}
#endif

struct ListNode{
	int _data;
	shared_ptr<ListNode> _prev;
	shared_ptr<ListNode> _next;
	~ListNode() {
		cout << "~ListNode()" << endl;
	}
};

int main() {

	shared_ptr<ListNode> node1(new ListNode);
	shared_ptr<ListNode> node2(new ListNode);
	cout << node1.use_count() << endl;
	cout << node2.use_count() << endl;
	node1->_next = node2;
	node2->_prev = node1;
	cout << node1.use_count() << endl;
	cout << node2.use_count() << endl;

	return 0;
}
