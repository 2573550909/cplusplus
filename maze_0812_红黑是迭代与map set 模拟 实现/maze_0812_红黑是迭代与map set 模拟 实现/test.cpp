#include <iostream>
using namespace std;

enum Color { RED, BLACK };
// ������ڵ�Ķ���
template<class ValueType>
struct RBTreeNode{
	RBTreeNode(const ValueType& data = ValueType()��Color color = RED)
		: _pLeft(nullptr), _pRight(nullptr), _pParent(nullptr)
		, _data(data), _color(color)
	{}
	RBTreeNode<ValueType>* _pLeft; // �ڵ������
	RBTreeNode<ValueType>* _pRight; // �ڵ���Һ���
	RBTreeNode<ValueType>* _pParent; // �ڵ��˫��(�������Ҫ��ת��
									 //Ϊ��ʵ�ּ򵥸������ֶ�)
	ValueType _data; // �ڵ��ֵ��
	Color _color; // �ڵ����ɫ
};

template<class ValueType>
class RBTree{
	// �ҵ���������һ���ڵ㣬��һ���ڵ�϶������
	void Increasement(){
		//�������������:_pNode�����������ںͲ�����
		// ����������
		if (_pNode->_pRight){
			// ����������С�Ľڵ㣬���������������ڵ�
			_pNode = _pNode->_pRight;
			while (_pNode->_pLeft) {
				_pNode = _pNode->_pLeft;
			}
		}
		else{
			// �����������ڣ����ϲ��ң�ֱ��_pNode != pParent->right
			PNode pParent = _pNode->_pParent;
			while (pParent->_pRight == _pNode){
				_pNode = pParent;
				pParent = _pNode->_pParent;
			}
			// ������������ڵ�û��������
			if (_pNode->_pRight != pParent) {
				_pNode = pParent;
			}
		}
	}
	// ��ȡ������ָ��ڵ��ǰһ���ڵ�
	void Decreasement(){
		//������������ۣ�_pNode ��head��λ�ã�_pNode ���������ڣ�_pNode ������������
		// 1. _pNode ��head��λ�ã�--Ӧ�ý�_pNode���ں���������ڵ��λ��
		if (_pNode->_pParent->_pParent == _pNode 
				&& _pNode->_color == RED){

			_pNode = _pNode->_pRight;
		}
		else if (_pNode->_pLeft) {
			// 2. _pNode������������,���������������Ľڵ㣬
			//    �������������Ҳ�ڵ�
			_pNode = _pNode->_pLeft;
			while (_pNode->_pRight) {
				_pNode = _pNode->_pRight;
			}
		}
	}
	else{
		// _pNode�������������ڣ�ֻ��������
		PNode pParent = _pNode->_pParent;
		while (_pNode == pParent->_pLeft){
			_pNode = pParent;
			pParent = _pNode->_pParent;
		}
		_pNode = pParent;
	}

//����

private:
	PNode& GetRoot() { 
		return _pHead->_pParent;
	}
	// ��ȡ���������С�ڵ㣬�������ڵ�
	PNode LeftMost();
	// ��ȡ����������ڵ㣬�����Ҳ�ڵ�
	PNode RightMost();
private:
	PNode _pHead;
};
#if 0
// ��Ϊ����ʽ�����д洢����<key, value>�ļ�ֵ�ԣ����
// kΪkey�����ͣ�
// ValueType: �����map����Ϊpair<K, V>; �����set����Ϊk
// KeyOfValue: ͨ��value����ȡkey��һ���º�����
template<class K, class ValueType, class KeyOfValue>
class RBTree
{
	typedef RBTreeNode<ValueType> Node;
	typedef Node* PNode;
public:
	typedef RBTreeIterator<ValueType, ValueType*, ValueType&> Iterator;
	
	RBTree();
	~RBTree();
		///////////////////////////////////////////////
		// Iterator
	Iterator Begin() {
		return Iterator(_pHead->_pLeft); 
	}
	Iterator End() { return Iterator(_pHead); }
	//////////////////////////////////////////////////////////////////
	// Modify
	pair<Iterator, bool> Insert(const ValueType& data)
	{
		// ����ڵ㲢���е���
		// �ο�����...
		return make_pair(Iterator(pNewNode), true);
	}
	// ��������еĽڵ����
	void Clear();
	Iterator Find(const K& key);

	/////////////////////
	// capacity
	/////////////////////
	size_t Size()const;
	bool Empty()const;
	// ����
private:
	PNode _pHead;
	size_t _size; // ���������Ч�ڵ�ĸ���

};

#endif
// map ��ģ��ʵ��
namespace bite{
	template<class K, class V>
	class map{
		typedef pair<K, V> ValueType;
		// ���ã���value�е�key��ȡ����
		struct KeyOfValue{
			const K& operator()(const ValueType& v){
				return v.first;
			}
		};
		typedef RBTree<K, ValueType, KeyOfValue> RBTree;
	public:
		typedef typename RBTree::Iterator iterator;
	public:
		map() {}
		/////////////////////////////////////////////
		// Iterator
		iterator begin() { return _t.Begin(); }
		iterator end() { return _t.End(); }
		/////////////////////////////////////////////////
		// Capacity
		size_t size()const { return _t.Size(); }
		bool empty()const { return _t.Empty(); }
		/////////////////////////////////////////////////
		// Acess
		V& operator[](const K& key){
			return (*(_t.Insert(ValueType(key, V()))).first).second;
		}
		const V& operator[](const K& key)const;
		////////////////////////////////////////////////////
		// modify
		pair<iterator, bool> insert(const ValueType& data) {
			return _t.Insert(data);
		}
		void clear() {
			_t.Clear();
		}
		iterator find(const K& key) {
			return _t.Find(key);
		}
	private:
		RBTree _t;
	};
}
