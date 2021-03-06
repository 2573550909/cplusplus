#include <iostream>
#include <stdlib.h>
using namespace std;

//思考：为什么红黑树的最长路径不会大于最短路径的两倍

// 节点的颜色
enum Color { RED, BLACK };
// 红黑树节点的定义
template<class T>
struct RBTreeNode{
	RBTreeNode(const T& data = T(),Color color = RED)
		: _pLeft(nullptr)
		, _pRight(nullptr)
		, _pParent(nullptr)
		, _data(data)
		, _color(color)
	{}

	RBTreeNode<T>* _pLeft; // 节点的左孩子
	RBTreeNode<T>* _pRight; // 节点的右孩子
	// 节点的双亲(红黑树需要旋转，
	//为了实现简单给出该字段)
	RBTreeNode<T>* _pParent; 

	T _data; // 节点的值域
	Color _color; // 节点的颜色
};

template<class T>
class RBTree{
	//……
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
			// 根的双亲为头节点
			pRoot->_pParent = _pHead;
			_pHead->_pLeft = pRoot;
			_pHead->_pRight = pRoot;
			return true;
		}
		else {
			// 1. 按照二叉搜索的树方式插入新节点
			Node* cur = pRoot;
			Node* parent = nullptr;
			while (cur) {
				parent = cur;
				if (data > pRoot->_data) {
					cur = cur->_pRight;
				}
				else if (data < pRoot->_data）{
					cur = cur->_pLeft;
					}
				else {
					return false;
				}
			}
			//此时 cur 就是要插入的位置，他的父节点是parent
			cur = new Node(data);
				if (data > parent->_data) {
					parent->_pRight = cur;
				}
				else {
					parent->_pLeft = cur;
				}
			cur->_pParent = parent;

			// 2. 检测新节点插入后，红黑树的性质是否造到破坏，
			// 若满足直接退出，否则对红黑树进行旋转着色处理
			// 可能违反性质3
			while (parent != _pHead && RED == parent->_color) {
				Node* granderFather = parent->_pParent;
				if (parent == granderFather->_pLeft) {
					Node* uncle = granderFather->_pRight;
					// 情况1：叔叔节点存在 且为红
					if (uncle && uncle->_color == RED) {
						parent->_color = BLACK;
						uncle->_color = BLACK;
						granderFather->_color = RED;
						cur = granderFather;
						parent = cur->_pParent;
					}
					else {
						// 情况三
						if (cur = parent->_pRight) {
							RoteteLeft(parent);
							swap(parent, cur);
						}
						//情况二
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
			// 根节点的颜色可能被修改，将其改回黑色
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
	// 获取红黑树中最小节点，即最左侧节点
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
	// 获取红黑树中最大节点，即最右侧节点
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
	//检测红黑树
	/////////////////////////////////////
	//1. 每个结点不是红色就是黑色
	//2. 根节点是黑色的
	//3. 如果一个节点是红色的，则它的两个孩子结点是黑色的
	//4. 对于每个结点，从该结点到其所有后代叶结点的简单路径上，
	//   均包含相同数目的黑色结点
	//5. 每个叶子结点都是黑色的(此处的叶子结点指的是空结点)
	bool IsValidRBTree(){
		PNode pRoot = GetRoot();
		// 空树也是红黑树
		if (nullptr == pRoot) {
			return true;
		}
		// 检测根节点是否满足情况
		if (BLACK != pRoot->_color){
			cout << "违反红黑树性质二：根节点必须为黑色" << endl;
			return false;
		}
		// 获取任意一条路径中黑色节点的个数
		size_t blackCount = 0;
		PNode pCur = pRoot;
		while (pCur){
			if (BLACK == pCur->_color) {
				blackCount++;
			}
			pCur = pCur->_pLeft;
		}
		// 检测是否满足红黑树的性质，k用来记录路径中黑色节点的个数
		size_t k = 0;
		return _IsValidRBTree(pRoot, k, blackCount);
	}

	bool _IsValidRBTree(PNode pRoot, size_t k, const size_t blackCount){
		//走到null之后，判断k和black是否相等
		if (nullptr == pRoot){
			if (k != blackCount){
				cout << "违反性质四：每条路径中黑色节点的个数必须相同" << endl;
				return false;
			}
			return true;
		}
		// 统计黑色节点的个数
		if (BLACK == pRoot->_color){
			k++;
		}
		// 检测当前节点与其双亲是否都为红色
		PNode pParent = pRoot->_pParent;
		if (pParent && RED == pParent->_color && RED == pRoot->_color){
			cout << "违反性质三：没有连在一起的红色节点" << endl;
			return false;
		}
		return _IsValidRBTree(pRoot->_pLeft, k, blackCount) &&
			_IsValidRBTree(pRoot->_pRight, k, blackCount);
	}
	
private:
	Node* _pHead;
};