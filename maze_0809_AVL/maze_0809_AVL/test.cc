#include <iostream>
#include <stdlib.h>

template<class T>
struct AVLTreeNode{
	AVLTreeNode(const T& data)
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
class BSTree{
	typedef BSTNode<T> Node;
	typedef Node* PNode;
public:
	BSTree() : _pRoot(nullptr)
	{}
	~BSTree();
	
	//�����ڵ��ƽ������С�� -1 ��ʱ��˵�����ʧ�⣬��Ҫ
	//�ҵ���
	void _RotateR(PNode pParent){
		// pSubL: pParent������
		// pSubLR: pParent���ӵ��Һ��ӣ�ע�⣺��
		PNode pSubL = pParent->_pLeft;
		PNode pSubLR = pSubL->_pRight;
		// ��ת���֮��30���Һ�����Ϊ˫�׵�����
		pParent->_pLeft = pSubLR;
		// ���30�����������Һ��Ӵ��ڣ�������˫��
		if (pSubLR) {
			pSubLR->_pParent = pParent;
		}
		// 60 ��Ϊ 30���Һ���
		pSubL->_pRight = pParent;
		// ��Ϊ60�����ǿ�����������ڸ�����˫��ǰ�����ȱ���60��˫��
		PNode pPParent = pParent->_pParent;
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


private:
	PNode _pRoot;
};
