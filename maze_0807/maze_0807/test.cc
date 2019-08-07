#include <iostream>
#include <stdlib.h>
using namespace std;

#if 1
void Test()
{
	int i = 1;
	// ��ʽ����ת��
	double d = i;
	printf("%d, %.2f\n", i, d);

	int* p = &i;
	// ��ʾ��ǿ������ת��
	int address = (int)p;
	printf("%x, %d\n", p, address);
}

int main() {
	Test();

	system("pause");
	return 0;
}
int main()
{
	double d = 12.34;
	int a = static_cast<int>(d);
	cout << a << endl;

	system("pause");
	return 0;
}

typedef void(*FUNC)();
int DoSomething(int i){
	cout << "DoSomething" << endl;
	return 0;
}

void Test(){
	// reinterpret_cast���Ա��� ��FUNC�Ķ��巽ʽȥ����DoSomething����
	// ���Էǳ���BUG������ת������ָ��Ĵ����ǲ�����ֲ�ģ����Բ�����������
	// C++����֤���еĺ���ָ�붼��һ����ʹ�ã�
	// ������������ʱ�������ȷ���Ľ��
	FUNC f = reinterpret_cast<FUNC>(DoSomething);
	f();
}

int main() {
	Test();
	
}

void Test(){
	const int a = 2;
	int* p = const_cast<int*>(&a);
	*p = 3;
	cout << a << endl;
	cout << *p << endl;
}

int main() {
	Test();

	system("pause");
	return	0;
}

class A{
public:
	virtual void f() {}
};

class B : public A
{};

void fun(A* pa){
	// dynamic_cast���ȼ���Ƿ���ת���ɹ����ܳɹ���ת���������򷵻�
	B* pb1 = static_cast<B*>(pa);
	B* pb2 = dynamic_cast<B*>(pa);
	cout << "pb1:" << pb1 << endl;
	cout << "pb2:" << pb2 << endl;
}

int main(){
	A a;
	B b;
	fun(&a);
	fun(&b);
	return 0;
}

class A{
public:
	explicit A(int a){
		cout << "A(int a)" << endl;
	}
	A(const A& a){
		cout << "A(const A& a)" << endl;
	}
private:
	int _a;
};

int main(){
	A a1(1);
	// ��ʽת��-> A tmp(1); A a2(tmp);
	//A a2 = 1;
	return 0;
}
#include <set>
void TestSet(){
	int array[] = { 2, 1, 3, 9, 6, 0, 5, 8, 4, 7 };
	// ע�⣺multiset�ڵײ�ʵ�ʴ洢����<int, int>�ļ�ֵ��
	multiset<int> s(array, array + sizeof(array) / sizeof(array[0]));
	for (auto& e : s) {
		cout << e << " ";
	}
	cout << endl;
}

int main() {
	TestSet();

	system("pause");
	return 0;
}

//ͳ��ǰ k ����Ƶ����
#include <vector>
#include <map>
#include <set>
class Solution {
public:
	class Compare{
	public:
		// ��set�н�������ʱ�ıȽϹ���
		bool operator()(const pair<string, int>& left,
			const pair<string, int>& right){
			return left.second > right.second;
		}
	};
	vector<string> topKFrequent(vector<string>& words, int k){
		// ��<���ʣ����ʳ��ִ���>������ֵ�ԣ�
		//Ȼ��vector�еĵ��ʷŽ�ȥ��ͳ��ÿ�����ʳ��ֵĴ���
		map<string, int> m;
		for (size_t i = 0; i < words.size(); ++i) {
			++(m[words[i]]);
		}
		// �����ʰ�������ִ����������򣬳�����ͬ�����ĵ��ʼ�����һ��
		multiset<pair<string, int>, Compare> ms(m.begin(), m.end());
		// ����ͬ�����ĵ��ʷ���set�У�Ȼ���ٷŵ�vector��
		set<string> s;
		size_t count = 0; // ͳ����ͬ�������ʵĸ���
		size_t leftCount = k;
		vector<string> ret;
		for (auto& e : ms){
			if (!s.empty()){
				// ��ͬ�����ĵ����Ѿ�ȫ���ŵ�set��
				if (count != e.second){
					if (s.size() < leftCount){
						ret.insert(ret.end(), s.begin(), s.end());
						leftCount -= s.size();
						s.clear();
					}else{
						break;
					}
				}
			}
			count = e.second;
			s.insert(e.first);
		}
		for (auto& e : s){
			if (0 == leftCount) {
				break;
			}
			ret.push_back(e);
			leftCount--;
		}
		return ret;
	}
};
#endif

template<class T>
struct BSTNode{
	BSTNode(const T& data = T())
		: _pLeft(nullptr)
		, _pRight(nullptr)
		, _data(data)
	{}

	BSTNode<T>* _pLeft;
	BSTNode<T>* _pRight;
	T _data;
};

template<class T>
class BSTree{
	typedef BSTNode<T> Node;
	typedef Node* PNode;
public:
	BSTree() : _pRoot(nullptr)
	{}

	//����
	~BSTree() {
		if (_pRoot == nullptr) {
			return;
		}
		void Destroy(PNode _pRoot) {
			if (_pRoot->_pLeft) {
				Destroy(_pRoot->_pLeft);
			}
			if (_pRoot->_pRight) {
				Destroy(_pRoot->_pRight);
			}
			delete _pRoot;
			_pRoot = nullptr;
		}
	}

	// ���ݶ��������������ʲ��ң��ҵ�ֵΪdata�Ľڵ��ڶ����������е�λ��
	PNode Find(const T& data) {
		if (data == *_pRoot) {
			return _pRoot;
		}
		else if (data > *_pRoot) {
			_pRoot = _pRoot->_pRight;
			Find(data);
		}
		else {
			_pRoot = _pRoot->_pLeft;
			Find(data);
		}
		return false;
	}

	bool Insert(const T& data){
		// �����Ϊ�գ�ֱ�Ӳ���
		if (nullptr == _pRoot){
			_pRoot = new Node(data);
			return true;
		}
		// ���ն��������������ʲ���data�����еĲ���λ��
		PNode pCur = _pRoot;
		// ��¼pCur��˫�ף���Ϊ��Ԫ�����ղ�����pCur˫�����Һ��ӵ�λ��
		PNode pParent = nullptr;
		while (pCur){
			pParent = pCur;
			if (data < pCur->_data) {
				pCur = pCur->_pLeft;
			}
			else if (data > pCur->_data) {
				pCur = pCur->_pRight;
			}
			else {
				// Ԫ���Ѿ������д���
				return false;
			}
		}
		// ����Ԫ��
		pCur = new Node(data);
		if (data < pParent->_data) {
			pParent->_pLeft = pCur;
		}else {
			pParent->_pRight = pCur;
		}
		return true;
	}

	bool Erase(const T& data){
		// �����Ϊ�գ�ɾ��ʧ��
		if (nullptr == _pRoot) {
			return false;
		}
		// ������data�����е�λ��
		PNode pCur = _pRoot;
		PNode pParent = nullptr;
		while (pCur){
			if (data == pCur->_data) {
				break;
			}
			else if (data < pCur->_data){
				pParent = pCur;
				pCur = pCur->_pLeft;
			}else{
				pParent = pCur;
				pCur = pCur->_pRight;
			}
		}
		// data���ڶ����������У��޷�ɾ��
		if (nullptr == pCur) {
			return false;
		}
		if (nullptr == pCur->_pRight){
			// ��ǰ�ڵ�ֻ�����ӻ�������Ϊ��---��ֱ��ɾ��
			if (pCur->_pLeft) {
				pParent->_pLeft = pCur->_pLeft;
				delete pCur;
				Cur = nullptr;
			}
			else {
				delete pCur;
				Cur = nullptr;
			}
		}
		else if (pCur->_pRight && pCur->_pLeft == nullptr){
			// ��ǰ�ڵ�ֻ���Һ���---��ֱ��ɾ��
			pParent->_pRight = pCur->_pRight;
			delete pCur;
			Cur = nullptr;
		}
		else{
			// ��ǰ�ڵ����Һ��Ӷ����ڣ�ֱ��ɾ������ɾ������
			//����������������һ�������㣬���磺
			// �����������е����ڵ㣬�������������Ҳ�Ľڵ㣬
			//������������������С�Ľڵ㣬������������С�Ľڵ�
			// ����ڵ��ҵ��󣬽�����ڵ��е�ֵ������ɾ���ڵ㣬
			//ת����ɾ������ڵ�
		}
		return true;
	}

	void InOrder();
private:
	PNode _pRoot;
};
