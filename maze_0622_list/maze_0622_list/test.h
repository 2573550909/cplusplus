#pragma once
#include <iostream>
#include <stdlib.h>
#include <assert.h>
using namespace std;

//��һ�������з�װ
class Node {
public:
	Node* _next;
	Node* _pre;
	int _data;
};

//˫���ѭ������
class SList {
public:
	SList() {
		_head->_pre = nullptr;
		_head->_next = nullptr;
	}
	~SList() {

	}
	//β��
	void SListPushBack(int data) {
		Node* node;
		node->_data = data;

		//ֻ����ͷ���
		if (_head->_next == nullptr) {
			node->_pre = _head;
			node->_next = nullptr;
			_head->_next = node;
		}

		//�ҵ����һ�����
		Node* cur = _head->_next;
		while (cur->_next != nullptr) {
			cur = cur->_next;
		}
		//���в���
		cur->_next = nullptr;
		cur->_pre = cur;
		cur->_next = node;
	}
	//βɾ
	void SListPopBack() {
		if (_head->_next == nullptr) {
			_head = nullptr;
		}

		//�ҵ������ڶ������
		Node* cur = _head->_next;
		while (cur->_next->_next == nullptr) {
			cur = cur->_next;
		}
		Node* node = cur->_next;
		node->_pre = nullptr;
		cur->_next = nullptr;
	}
	//ͷ��
	void SListPushFront(int data) {
		//�ȹ���һ�����
		Node* node;
		node->_data = data;
		//���ֻ��ͷ��� 
		if (_head->_next == nullptr) {
			node->_next = nullptr;
			node->_pre = _head;
			_head->_next = node;
		}
		//������һ�����
		node->_next = _head->_next;
		node->_pre = _head;
		_head->_next->_pre = node;
		_head->_next = node;
	}
	//ͷɾ
	void SListPopFront() {
		assert(_head->_next == nullptr);
		if (_head->_next->_next == nullptr) {
			_head->_next->_pre = nullptr;
			_head->_next = nullptr;
		}

		//�������������
		Node* node = _head->_next->_next;
		Node* cur = _head->_next;
		_head->_next = node;
		node->_pre = _head;
		cur->_next = cur->_pre = nullptr;
	}

	//�� pos ���ǰ�����
	void SListInsertFront(Node* pos,int data) {
		Node* node;
		node->_data = data;
		
		node->_next = pos;
		node->_pre = pos->_pre;
		pos->_pre->_next = node;
		pos->_pre = node;
	}
	//�� pos ���������
	void SListInsertAfter(Node* pos, int data) {
		Node* node;
		node->_data = data;

		node->_pre = pos;
		node->_next = pos->_next;
		pos->_next->_pre = node;
		pos->_next = node;
	}

	//ɾ�� pos ���
	void SListErase(Node* pos) {
		//ֻ��ͷ���
		if (pos->_next = nullptr) {
			return;
		}

		pos->_pre->_next = pos->_next;
		pos->_next->_pre = pos->_pre;
		pos->_next = pos->_pre = nullptr;
	}

	//���ҽ��
	int SListFind(int data) {
		Node* node = _head->_next;
		while (node != nullptr) {
			if (node->_data == data) {
				return data;
			}
			node = node->_next;
		}
		return 0;
	}
	//ɾ��v����Ӧ�Ľ��
	void SListEraseV(int data) {
		Node* node = _head->_next;
		while (node != nullptr) {
			if (node->_data == data) {
				SListErase(node);
			}
			node = node->_next;
		}
	}

	void Print() {
		Node* node = _head->_next;
		while (node != nullptr) {
			cout << node->_data;
		}
		cout << endl;
	}
private:
	Node* _head;
};
