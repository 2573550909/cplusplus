#include <iostream>
#include<string>
#include<algorithm>
using namespace std;

int main()
{
	string s, table = "0123456789ABCDEF";
	int m, n;
	cin >> m >> n;
	bool flag = false;
	 ����Ǹ�������ת�������������һ��
	if (m < 0)
	{
		m = 0 - m;
		flag = true;
	}
	 �����ƻ���ɶ�Ӧ���ַ���ӵ�s
	while (m)
	{
		s += table[m%n];
		m /= n;
	}
	if (flag)
		s += '-';
	reverse(s.begin(), s.end());
	cout << s << endl;
	return 0;
}


#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;

class Test
{
public:
	Test()
		: _data(0)
	{
		cout << "Test():" << this << endl;
	}
	~Test()
	{
		cout << "~Test():" << this << endl;
	}
private:
	int _data;
};

void Test1()
{
	 ���뵥��Test���͵Ŀռ�
	Test* p1 = (Test*)malloc(sizeof(Test));
	free(p1);
	 ����10��Test���͵Ŀռ�
	Test* p2 = (Test*)malloc(sizeof(Test) * 10);
	free(p2);
}

void Test2()
{
	 ���뵥��Test���͵Ķ���
	Test* p1 = new Test;
	delete p1;
	 ����10��Test���͵Ķ���
	Test* p2 = new Test[10];
	delete[] p2;
}

5. new��delete��ʵ��ԭ��
5.1 ��������
�����������������͵Ŀռ䣬new��malloc��delete��free�������ƣ���ͬ�ĵط��ǣ�new / delete�����
�ͷŵ��ǵ���Ԫ�صĿռ䣬new[]��delete[]������������ռ䣬����new������ռ�ʧ��ʱ�����쳣��
malloc�᷵��NULL��
5.2 �Զ�������
new��ԭ��
1. ����operator new��������ռ�
2. ������Ŀռ���ִ�й��캯������ɶ���Ĺ���
delete��ԭ��
1. �ڿռ���ִ��������������ɶ�������Դ��������
class List
{
public:
	List()
	{
		_head = new ListNode;
		_head->_next = _head;
		_head->_prev = _head;
	}
	~List()
	{
		ListNode* cur = _head->_next;
		while (cur != _head)
		{
			ListNode* next = cur->_next;
			delete cur;
			cur = next;
		}
		delete _head;
		_head = nullptr;
	}
private:
	ListNode* _head;
};
int main()
{
	List l;
	return 0;
}
class Test
{
public:
	Test()
		: _data(0)
	{
		cout << "Test():" << this << endl;
	}
	~Test()
	{
		cout << "~Test():" << this << endl;
	}
private:
	int _data;
};
void Test()
{
	 pt����ָ���ֻ��������Test������ͬ��С��һ�οռ䣬����������һ��������Ϊ���캯��û��ִ��
	Test* pt = (Test*)malloc(sizeof(Test));
	new(pt) Test; // ע�⣺���Test��Ĺ��캯���в���ʱ���˴���Ҫ����
}

template<typename T,class T2 >
void Swap(T& left, T2& right)
{
	T2 temp = left;
	left = right;
	right = temp;
}

int main()
{
	int a[5] = { 1,3,5,7,9 };
	
	int *p = (int *)(&a + 1);

	printf("%d, %d", *(a + 1),*(p - 1));

	
	int a = 10;
	int b = 20;
	double c = 30.1;

	Swap(a, c);
	cout << a << " " << b << endl;

	int a = 10;
	int b = 20;
	Swap(1,2.0);
	cout << a << " " << b << endl;

	Test1();
	Test2();

	int* p1 = (int*)malloc(sizeof(int) * 10);
	free(p1);

	char* p2 = new char;
	delete p2;


	int* p1 = new int;
	int* p2 = new int(10);
	int* p3 = new int[3];
	int* p4 = new int;
	cout << "p1:" << p1 << endl;
	cout << "p2:" << p2 << endl;
	cout << "p3:" << p3 << endl;
	cout << "p4:" << p4 << endl;
	cout << endl;
	delete p1;
	delete p2;
	delete[] p3;
	delete p4;

	system("pause");
	return 0;
}
template <class M>
void Swap(M& a, M& b)
{
	int temp = a;
	a = b;
	b = temp;
}


template<class T>
class / typename ûɶ����  
T Add(T left, T right)
{
	cout << typeid(T).name() << endl;
	return left + right;
}


int main()
{
	Add(10, 20);


	int a = 10;
	int b = 20;
	Swap(a,b);

	system("pause");
	return 0;
}

#include <iostream>
#include <stdlib.h>
#include <assert.h>
using namespace std;

typedef int T;
template<class T>

class SeqList
{
public:
	SeqList(size_t capacity = 10)
		:_array (new T [capacity])
		,_capacity(capacity)
		,_size(0)
	{}

	void PushBack(const T& data);
	void PopBack()
	{
		--_size;
	}

	size_t Size()const
	{
		return _size;
	}

	size_t Capacity()const
	{
		return _capacity;
	}

	bool Empty()const
	{
		return _size == 0;
	}

	[] :�±����������
	T& operator[](size_t index)
	{
		assert(index < _size);
		return _array[index];
	}

	const T& operator[](size_t index)const
	{
		assert(index < _size);
		return _array[index];
	}

	~SeqList()
	{
		if (_array)
		{
			delete[] _array;
			_array = nullptr;
			_capacity = 0;
			_size = 0;
		}
	}
protected:
	T* _array;
	size_t _capacity;
	size_t _size;
};

template<class T>
SeqList ����һ���࣬��һ��ģ�� SeqList<int>������
void SeqList<T>::PushBack(const T& data)
{
	CheckCapacity
	_array[_size++] = data;
}

int main()
{
	�������Ϊ SeqList<int>::SeqList<int>
	SeqList<int> s1;	
	s1.PushBack(1); 
	s1.PushBack(2); 
	s1.PushBack(3);
	cout << s1[0] << endl;

	�������Ϊ SeqList<int>::SeqList<int>
	SeqList<double> s2;

	system("pause");
	return 0;
}