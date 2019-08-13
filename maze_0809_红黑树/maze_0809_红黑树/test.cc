#include <iostream>
#include <stdlib.h>
using namespace std;

//˼����Ϊʲô��������·������������·��������

// �ڵ����ɫ
enum Color { RED, BLACK };
// ������ڵ�Ķ���
template<class T>
struct RBTreeNode{
	RBTreeNode(const T& data = T(),Color color = RED)
		: _pLeft(nullptr)
		, _pRight(nullptr)
		, _pParent(nullptr)
		, _data(data)
		, _color(color)
	{}

	RBTreeNode<T>* _pLeft; // �ڵ������
	RBTreeNode<T>* _pRight; // �ڵ���Һ���
	// �ڵ��˫��(�������Ҫ��ת��
	//Ϊ��ʵ�ּ򵥸������ֶ�)
	RBTreeNode<T>* _pParent; 

	T _data; // �ڵ��ֵ��
	Color _color; // �ڵ����ɫ
};

template<class T>
class RBTree{
	//����
	typedef RBTreeNode<T> Node;
	RBTree() {
		_pHead = new Node;
		_pHead->_pLeft = _pHead;
		_pHead->_pRight = _pHead;
	}

	bool Insert(const T& data){
		Node* pRoot = GetRoot();
		if (nullptr == pRoot){
			pRoot = new Node(data, BLACK);
			// ����˫��Ϊͷ�ڵ�
			pRoot->_pParent = _pHead;
			_pHead->_pLeft = pRoot;
			_pHead->_pRight = pRoot;
			return true;
		}
		else {
			// 1. ���ն�������������ʽ�����½ڵ�
			Node* cur = pRoot;
			Node* parent = nullptr;
			while (cur) {
				parent = cur;
				if (data > pRoot->_data) {
					cur = cur->_pRight;
				}
				else if (data < pRoot->_data��{
					cur = cur->_pLeft;
					}
				else {
					return false;
				}
			}
			//��ʱ cur ����Ҫ�����λ�ã����ĸ��ڵ���parent
			cur = new Node(data);
				if (data > parent->_data) {
					parent->_pRight = cur;
				}
				else {
					parent->_pLeft = cur;
				}
			cur->_pParent = parent;

			// 2. ����½ڵ����󣬺�����������Ƿ��쵽�ƻ���
			// ������ֱ���˳�������Ժ����������ת��ɫ����
			// ����Υ������3
			while (parent != _pHead && RED == parent->_color) {
				Node* granderFather = parent->_pParent;
				if (parent == granderFather->_pLeft) {
					Node* uncle = granderFather->_pRight;
					// ���1������ڵ���� ��Ϊ��
					if (uncle && uncle->_color == RED) {
						parent->_color = BLACK;
						uncle->_color = BLACK;
						granderFather->_color = RED;
						cur = granderFather;
						parent = cur->_pParent;
					}
					else {
						// �����
						if (cur = parent->_pRight) {
							RoteteLeft(parent);
							swap(parent, cur);
						}
						//�����
						parent->_color = BLACK;
						granderFather->_color = RED;
						RotateRight(granderFather);
					}
				}
				else {
					Node* uncle = granderFather->_pLeft;
					if (uncle && uncle->_color == RED) {
						parent->_color = BLACK;
						uncle->_color = BLACK;
						granderFather->_color = RED;
						cur = granderFather;
						parent = cur->_pParent;
					}
					else {
						if (cur == parent->_pLeft) {
							RotateRight(parent);
							swap(parent, cur);
						}
						parent->_color = BLACK;
						granderFather->_color = RED;
						RotateLeft(granderFather);
					}
				}

			}
			// ���ڵ����ɫ���ܱ��޸ģ�����Ļغ�ɫ
			pRoot->_color = BLACK;
			_pHead->_pLeft = LeftMost();
			_pHead->_pRight = RightMost();
			return true;
		}
	}
	
	
private:
	Node*& GetRoot() {
		return _pHead->_pParent;
	}
	// ��ȡ���������С�ڵ㣬�������ڵ�
	Node* LeftMost() {
		Node* cur = GetRoot();
		if (cur == nullptr) {
			return;
		}
		while (cur->_pLeft) {
			cur = cur->_pLeft;
		}
		return cur;
	}
	// ��ȡ����������ڵ㣬�����Ҳ�ڵ�
	Node* RightMost() {
		Node* cur = GetRoot();
		if (cur == nullptr) {
			return;
		}
		while (cur->_pLeft) {
			cur = cur->_pLeft;
		}
		return cur;
	}

	//////////////////////////////////////
	//�������
	/////////////////////////////////////
	//1. ÿ����㲻�Ǻ�ɫ���Ǻ�ɫ
	//2. ���ڵ��Ǻ�ɫ��
	//3. ���һ���ڵ��Ǻ�ɫ�ģ��������������ӽ���Ǻ�ɫ��
	//4. ����ÿ����㣬�Ӹý�㵽�����к��Ҷ���ļ�·���ϣ�
	//   ��������ͬ��Ŀ�ĺ�ɫ���
	//5. ÿ��Ҷ�ӽ�㶼�Ǻ�ɫ��(�˴���Ҷ�ӽ��ָ���ǿս��)
	bool IsValidRBTree(){
		PNode pRoot = GetRoot();
		// ����Ҳ�Ǻ����
		if (nullptr == pRoot) {
			return true;
		}
		// �����ڵ��Ƿ��������
		if (BLACK != pRoot->_color){
			cout << "Υ����������ʶ������ڵ����Ϊ��ɫ" << endl;
			return false;
		}
		// ��ȡ����һ��·���к�ɫ�ڵ�ĸ���
		size_t blackCount = 0;
		PNode pCur = pRoot;
		while (pCur){
			if (BLACK == pCur->_color) {
				blackCount++;
			}
			pCur = pCur->_pLeft;
		}
		// ����Ƿ��������������ʣ�k������¼·���к�ɫ�ڵ�ĸ���
		size_t k = 0;
		return _IsValidRBTree(pRoot, k, blackCount);
	}

	bool _IsValidRBTree(PNode pRoot, size_t k, const size_t blackCount){
		//�ߵ�null֮���ж�k��black�Ƿ����
		if (nullptr == pRoot){
			if (k != blackCount){
				cout << "Υ�������ģ�ÿ��·���к�ɫ�ڵ�ĸ���������ͬ" << endl;
				return false;
			}
			return true;
		}
		// ͳ�ƺ�ɫ�ڵ�ĸ���
		if (BLACK == pRoot->_color){
			k++;
		}
		// ��⵱ǰ�ڵ�����˫���Ƿ�Ϊ��ɫ
		PNode pParent = pRoot->_pParent;
		if (pParent && RED == pParent->_color && RED == pRoot->_color){
			cout << "Υ����������û������һ��ĺ�ɫ�ڵ�" << endl;
			return false;
		}
		return _IsValidRBTree(pRoot->_pLeft, k, blackCount) &&
			_IsValidRBTree(pRoot->_pRight, k, blackCount);
	}
	
private:
	Node* _pHead;
};