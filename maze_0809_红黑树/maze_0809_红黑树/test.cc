#include <iostream>
#include <stdlib.h>
using namespace std;

// �ڵ����ɫ
enum Color { RED, BLACK };
// ������ڵ�Ķ���
template<class ValueType>
struct RBTreeNode{
	RBTreeNode(const ValueType& data = ValueType(),Color color = RED)
		: _pLeft(nullptr)
		, _pRight(nullptr)
		, _pParent(nullptr)
		, _data(data)
		, _color(color)
	{}

	RBTreeNode<ValueType>* _pLeft; // �ڵ������
	RBTreeNode<ValueType>* _pRight; // �ڵ���Һ���
	// �ڵ��˫��(�������Ҫ��ת��
	//Ϊ��ʵ�ּ򵥸������ֶ�)
	RBTreeNode<ValueType>* _pParent; 

	ValueType _data; // �ڵ��ֵ��
	Color _color; // �ڵ����ɫ
};

template<class ValueType>
class RBTree{
	//����
	typedef RBTreeNode<ValueType> Node;

	bool Insert(const ValueType& data){
		Node* pRoot = GetRoot();
		if (nullptr == pRoot){
			pRoot = new Node(data, BLACK);
			// ����˫��Ϊͷ�ڵ�
			pRoot->_pParent = _pHead;
			_pHead->_pParent = pRoot;
		}
		else{
			// 1. ���ն�������������ʽ�����½ڵ�
			Node* cur = pRoot;
			Node* parent = nullptr;
			while (cur) {
				parent = cur;
				if (data > pRoot->_data) {
					cur = cur->_pRight;
				}
				else if(data < pRoot->_data��{
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
			else if (data < parent->_data) {
				parent->_pLeft = cur;
			}
			else {
				return true;
			}
			// 2. ����½ڵ����󣬺�����������Ƿ��쵽�ƻ���
			// ������ֱ���˳�������Ժ����������ת��ɫ����
			IsValidRBTree();
		}
		// ���ڵ����ɫ���ܱ��޸ģ�����Ļغ�ɫ
		pRoot->_color = BLACK;
		_pHead->_pLeft = LeftMost();
		_pHead->_pRight = RightMost();
		return true;
	}
	
	
private:
	PNode& GetRoot() {
		return _pHead->_pParent;
	}
	// ��ȡ���������С�ڵ㣬�������ڵ�
	PNode LeftMost() {
		PNode cur = GetRoot();
		if (cur == nullptr) {
			return;
		}
		while (cur->_pLeft) {
			cur = cur->_pLeft;
		}
		return cur;
	}
	// ��ȡ����������ڵ㣬�����Ҳ�ڵ�
	PNode RightMost() {
		PNode cur = GetRoot();
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