#pragma once
#include <iostream>
#include <stdlib.h>
#include <assert.h>
using namespace std;
namespace List
{
	class SeqList {
	public:
		//��ʼ��,���캯��
		SeqList()
			:_array(new int(_last))
		{
			_start = 0;
			_last = 0;
			_end = 20;
		}
		//����
		~SeqList() {
			delete[] _array;
			_array = nullptr;
			_end = 0;
			_last = 0;
		}
		//���
		void SeqListCheck() {
			//��Ҫ����
			if (_end == _last) {
				int* new_array = new int(_end);
				_end += 10;

				delete[] _array;
				_array = new_array;
			}
		}
		//β��
		void SeqListPushBack(int data) {
			SeqListCheck();
			++_last = data;
		}
		//βɾ
		void SeqListPopBack() {
			--_last;
		}
		//ͷɾ
		void SeqListPopFront() {
			for (int i = 0; i < _last + 1; ++i) {
				_array[i] = _array[i + 1];
			}
			--_last;
		}
		//ͷ��
		void SeqListPushFront(int data) {
			for (int i = _last - 1; i >= 0; --i) {
				_array[i + 1] = _array[i];
			}
			_array[0] = data;
		}
		//�� pos λ��ǰ����
		void SeqListInsert(int pos, int data) {
			for (int i = _last - 1; i >= pos; --i) {
				_array[i + 1] = _array[i];
			}
			_array[pos] = data;
			++_last;
		}
		//����λ�õ�ɾ��
		void SeqListErase(int pos) {
			for (int i = pos + 1; i < _last; ++i) {
				_array[i - 1] = _array[i];
			}
			--_last;
		}
		//�Ƴ�ָ����Ԫ��
		void SeqListRemove(int pos) {
			for (int i = 0; i < _last; ++i) {
				if (_array[i] == pos) {
					SeqListErase(i);
				}
			}
		}
		//���Ԫ���Ƿ��ڱ���
		bool SeqListFind(int data) {
			for (int i = 0; i < _last; ++i) {
				if (_array[i] == data) {
					return true;
				}
			}
			return false;
		}
		//��ȡԪ�ظ���
		int SeqListSize() {
			return _last;
		}
		//��ȡ����
		int SeqListCapacity() {
			return _end;
		}
		//�ж��Ƿ��ǿ�
		bool SeqListEmpty() {
			if (_start == 0) {
				return true;
			}
			return false;
		}
		//��ȡ��һ��Ԫ��
		int SeqListFirst() {
			return _start;
		}
		//��ȡ���һ��Ԫ��
		int SeqListlast() {
			return _last;
		}
		//��ӡ���е�����
		void SeqListPrint() {
			for (int i = 0; i < _last; ++i) {
				cout << _array[i] << endl;
			}
			cout << endl;
		}
	private:
		int* _array;
		int _start;
		int _end;
		int _last;
	};
}
