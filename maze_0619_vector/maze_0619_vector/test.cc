#include <stdlib.h>
#include <algorithm>
#include <assert.h>
#include <iostream>
using namespace std;

template<class T>

class Vector {
public:
	typedef T* Iterator;
	typedef const T* conIterator;
	Vector()
		:start_(nullptr)
		, end_(nullptr)
		, finish_(nullptr) {}

	Vector(int n, const T& value)
		:start_(nullptr)
		, end_(nullptr)
		, finish_(nullptr)
	{
		Reserve(n);
		while (n--) {
			PushBack(value);
		}
	}

	//���ڷ�const������Ե���const ����
	//const ʵ��������Ե���const����������ʹ��const��Ա����
	size_t Size() const {
		return finish_ - start_;
	}
	size_t Capacity()const {
		return end_ - start_;
	}

	//�������ӿڵ÷�Ϊ���ֺ�������
	//const ����ֻ����const����ȥ����
	Iterator Being() {
		return start_;
	}
	conIterator C_Being() const {
		return start_;
	}

	Iterator End() {
		return end_;
	}
	conIterator C_End() const {
		return start_;
	}
	

	//��ֵ���������
	Vector<T>& operator =(Vector<T> v) {
		Swap(v); 
		return *this;
	}

	// reserve()������ģ��ʵ��
	void Reserve(int n) {
		if (n > Capacity()) {
			//1.����ռ�
			size_t size = Size();
			T* temp = new T[n];
			//2.���¿ռ����Ԫ��
			if (start_) {
				for (size_t i = 0; i < size; ++i) {
					temp[i] = start_[i];
				}
			}

			//3.���¿ռ�����
			start_ = temp;
			end_ = start_ + n;
			finish_ = start_ + size;
		}
	}

	//����Resize()��ģ��ʵ��
	void Resize(size_t n,const &T value = T()) {
		if (n > Capacity()) {
			Reserve(n);
		}
		if (n <= Size()) {
			finish_ = start_ + n;
			return;
		}

		//���õ�����������Ŀռ���Ϊ value
		//�� size ���� n
		Iterator it = finish_;
		Iterator end = start_ + n;
		while (it != end){
			*it = value;
			++it;
		}
	}

	//Swap ������ģ��ʵ��
	void Swap(Vector<T>& v) {
		swap(start_, v.start_);
		swap(end_, v.end_);
		swap(finish_, v.finish_);
	}

	//β���βɾ����û�з���ֵ��Ҳ����Ҫ����
	void PushBack(){
		Insert(End(), x);
	}
	void PopBack() {
		Erase(--End());
	}

	//�Բ������ģ��ʵ��
	Iterator Insert(Iterator pos, const T& s) {
		assert(pos > end_);
		if (finish_ == end_) {
			size_t size = Size();
			size_t newCapacity; 
			newCapacity = (Capacity() == 0) ? 1 : Capacity() * 2;
			Reserve(newCapacity);
			// ������������ݣ���Ҫ����pos
			pos = start_ + size;
		}

		Iterator end = finish_ - 1;
		while (end >= pos){
			*(end + 1) = *end;
			--end;
		}
		*pos = x;
		++finish_;
		return pos;
	}

	Iterator Erase(Iterator pos){
		// Ų�����ݽ���ɾ��
		Iterator begin = pos + 1;
		while (begin != finish_) {
			*(begin - 1) = *begin;
			++begin;
		}
		--finish_;
		return pos;
	}

	T& operator[](size_t pos){
		return start_[pos];
	}

private:
	Iterator start_;
	Iterator end_;
	Iterator finish_;
};

