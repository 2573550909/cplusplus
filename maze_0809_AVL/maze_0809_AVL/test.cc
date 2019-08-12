#include <iostream>
#include <stdlib.h>
using namespace std;


template<class T>
struct AVLTreeNode{
	AVLTreeNode(const T& data = T())
		: _pLeft(nullptr), _pRight(nullptr), _pParent(nullptr)
		, _data(data)
		, _bf(0)//ƽ������
	{}

	AVLTreeNode<T>* _pLeft; // �ýڵ������
	AVLTreeNode<T>* _pRight; // �ýڵ���Һ���
	AVLTreeNode<T>* _pParent; // �ýڵ��˫��
	T _data;
	int _bf; // �ýڵ��ƽ������
};

template<class T>
class AVLTree{
	typedef AVLTreeNode<T> Node;
public:
	AVLTree() : _pRoot(nullptr)
	{}
	bool Insert(const T& _pRoot) {
		if (nullptr == _pRoot) {
			_pRoot = new Node(data);
			return true;
		}
		//�ǿ�
		Node* pCur = _pRoot;
		Node* pParent = nullptr;
		while (pCur) {
			pParent = pCur;
			if (data < pCur->_data){
				pCur = pCur->_pLeft;
			}
			else if (data > pCur->_data) {
				pCur = pCur->_pRight;
			}
			else {
				return false;
			}
		}
		//�����½ڵ�
		pCur = new Node(data);
		if (data < pParent->_data) {
			pParent->_pLeft = pCur;
		}else {
			pParent->_pRight = pCur;
		}

		//���ƽ������
		if (pCur == pParent->_pLeft) {
			pParent->_bf--;
		}else {
			pParent->_bf++;
		}

		//���ܵ��� parent �ڵ��ƽ�����Ӳ����� AVL��������
		while (pParent) {
			if (pParent->_bf == 0) {
				return true;
			}
			else if (-1 == pParent->_bf || 1 == pParent->_bf) {
				pCur = pParent;
				pParent = pCur->_pParent;
			}
			else {
				//˫�׵�ƽ�����Ӳ����� AVL ��������
				//˫�׵Ľڵ��ƽ������Ϊ 2 ���� -2
				//��Ҫ�� ��˫��Ϊ���Ķ�����������ת����
				if (pParent->_bf == 2) {
					//��������
					if (1 == pCur->_bf) {
						_RotateL(pParent);
					}
					else {
						//˫��
						_RotateRL(pParent);
					}
				}
				else {
					//��������
					if (-1 == pCur->_bf) {
						_RotateR(pParent);
					}
					else {
						//˫��
						_RotateLR(pParent);
					}
				}
			}
			break;
		}
		return true;
	}

	////////////////////////////////////////////
	//���ƽ����
	////////////////////////////////////////////
	//�������
	int _Height(Node* pRoot){
		if (root == NULL){
			return 0;
		}
		if (root->left == NULL && root->right == NULL){
			return 1;
		}
		int left = GetHeight(root->left);
		int right = GetHeight(root->right);
		if (left > right){
			return left + 1;
		}else{
			return right + 1;
		}
	}

	//�ж��Ƿ�ƽ��
	bool _IsBalanceTree(Node* pRoot){
		// ����Ҳ��AVL��
		if (nullptr == pRoot) {
			return true;
		}
		// ����pRoot�ڵ��ƽ�����ӣ���pRoot���������ĸ߶Ȳ�
		int leftHeight = _Height(pRoot->_pLeft);
		int rightHeight = _Height(pRoot->_pRight);
		int diff = rightHeight - leftHeight;
		// ����������ƽ��������pRoot��ƽ�����Ӳ���ȣ�����
		// pRootƽ�����ӵľ���ֵ����1����һ������AVL��
		if (diff != pRoot->_bf || (diff > 1 || diff < -1))
			return false;
		// pRoot��������������AVL���������һ����AVL��
		return _IsBalanceTree(pRoot->_pLeft) 
			&& _IsBalanceTree(pRoot->_pRight);
	}
	//////////////////////////////////////////////////////

	void InOrder() {
		_InOrder(_pRoot);
	}

protected:

	void _InOrder(Node* pRoot) {
		if (pRoot) {
			_InOrder(pRoot->_pLeft);
			cout << pRoot->_data << " ";
			_InOrder(pRoot->_pRight);
		}
	}

	//�����ڵ��ƽ������С�� -1 ��ʱ��˵�����ʧ�⣬��Ҫ
	//�ҵ���
	void _RotateRight1(Node* pParent){
		// pSubL: pParent������
		// pSubLR: pParent���ӵ��Һ��ӣ�ע�⣺��
		Node* pSubL = pParent->_pLeft;
		Node* pSubLR = pSubL->_pRight;
		// ��ת���֮��30���Һ�����Ϊ˫�׵�����
		pParent->_pLeft = pSubLR;
		// ���30�����������Һ��Ӵ��ڣ�������˫��
		if (pSubLR) {
			pSubLR->_pParent = pParent;
		}
		// 60 ��Ϊ 30���Һ���
		pSubL->_pRight = pParent;
		// ��Ϊ60�����ǿ�����������ڸ�����˫��ǰ�����ȱ���60��˫��
		Node* pPParent = pParent->_pParent;
		// ����60��˫��
		pParent->_pParent = pSubL;
		// ����30��˫��
		pSubL->_pParent = pPParent;
		// ���60�Ǹ��ڵ㣬����ָ����ڵ��ָ��
		if (NULL == pPParent){
			_pRoot = pSubL;
			pSubL->_pParent = NULL;
		}
		else{
			// ���60����������������˫�׵���������Ҳ������������
			if (pPParent->_pLeft == pParent) {
				pPParent->_pLeft = pSubL;
			}
			else {
				pPParent->_pRight = pSubL;
			}
		}
		// ���ݵ�����Ľṹ���²��ֽڵ��ƽ������
		pParent->_bf = pSubL->_bf = 0;
	}

	void _RotateR(Node* pParent) {
		Node* pSubL = pParent->_pLeft;
		Node* pSubLR = pSubL->_pRight;
		
		//���º���ָ����
		pParent->_pLeft = pSubL;
		if (pSubLR) {
			pSubLR->_pParent = pParent;
		}

		pSubL->_pRight = pParent;
		//����˫��ָ����
		Node* pPParent = pParent->_pParent;
		pParent->_pParent = pSubL;
		pSubL->_pParent = pPParent;
		if (nullptr == pPParent) {
			_pRoot = pSubL;
		}
		//ʹ���ڵ� pParentָ�� pSubL
		else {
			if (pParent == pPParent->_pLeft) {
				pPParent->_pLeft = pSubL;
			}
			else {
				pPParent->_pRight = pSubL;
			}
		}
	}

	//����
	void _RotateL(Node* pParent) {
		Node* pSubR = pParent->_pRight;
		Node* pSubRL = pSubR->_pLeft;
		
		pParent->_pRight = pSubRL;
		if (pSubRL) {
			pSubRL->_pParent = pParent;
		}

		pSubR->_pLeft = pParent;
		Node* pPParent = pParent->_pParent;
		pSubR->_pParent = pPParent;
		pParent->_pParent = pSubR;

		if (pPParent == nullptr){
			_pRoot = pParent;
		}
		else {
			if (pParent = pPParent->_pLeft) {
				pPParent->_pLeft = pSubR;
			}
			else {
				pPParent->_pRight = pSubR;
			}
		}
		pParent->_bf = pSubR->_bf = 0;
	}

	void _RotateRL(Node* pParent) {
		_RotateR(pParent->_pRight);
		_RotateL(pParent);
	}

	void _RotateLR(Node* pParent) {
		_RotateL(pParent->_pLeft);
		_RotateR(pParent);
	}
private:
	Node* _pRoot;
};

void TestAVLTree() {
	int array[] = { 16,3,6,45,32,5,76,23,54,67,98 };
	AVLTree<int> t;
	for (auto e : array) {
		t.Insert(e);
	}
	t.InOrder();
}

int main() {

	TestAVLTree();
	system("pause");
	return 0;
}
