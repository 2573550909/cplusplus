#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
//#define NULL '#'
//1. ��Ϥ���ĸ����Լ���ظ���
//2. �˽����Ĵ洢��ʽ�Լ�������
//3. �˽�����Ӧ�ó���
//4. ��Ϥ�������Ļ��������Լ�����
//5. ��Ϥ������������ȫ��������������������
//6. ��Ϥ�������ľ�̬�洢����ʽ�洢
//7. ʵ����ʽ���ݽṹ�����»���������
typedef char BTDataType;

typedef struct BTNode
{
	struct BTNode* _pLeft;
	struct BTNode* _pRight;
	BTDataType _data;
}	BTNode;



// 1. ���������� 
BTNode* CreateBinTree(BTDataType* array, int size)
{
	if (size == 0 || array[0] == '#')
	{
		return NULL;
	}
	//'A', 'B', '#', 'D', '#', '#', 'C', '#', '#'
	BTNode* root = (BTNode*)malloc(sizeof(BTNode));
	root->_data = array[0];

	BTDataType l = CreateBinTree(array + 1, size - 1);



}

// ���������� 
BTNode* CopyBinTree(BTNode* pRoot);

// ���ٶ����� 
void DestroyBinTree(BTNode** pRoot)
{
	if (*pRoot == NULL || pRoot == NULL)
	{
		return;
	}
	free(pRoot);
	DestroyBinTree(*(pRoot->_pLeft));

}
// �����������ֱ�����ʽ 
//ǰ������ݹ�
void PreOrder(BTNode* pRoot)
{
	if (pRoot->_data == '#')
	{
		printf("# ");
		return;
	}

	printf("%c ", pRoot->_data);
	PreOrder(pRoot->_pLeft);
	PreOrder(pRoot->_pRight);
}

void PreOrderNor(BTNode* pRoot);


//�������������--�ݹ�
void InOrder(BTNode* pRoot)
{
	if (pRoot->_data == '#')
	{
		printf("# ");
		return;
	}

	InOrder(pRoot->_pLeft);
	printf("%c ", pRoot->_data);
 	InOrder(pRoot->_pRight)	;
}
void InOrderNor(BTNode* pRoot);


//�������������
void PostOrder(BTNode* pRoot)
{
	if (pRoot->_data == '#')
	{
		printf("# ");
		return;
	}

	PostOrder(pRoot->_pLeft);
	PostOrder(pRoot->_pRight);
	printf("%c ", pRoot->_data);
}

void PostOrderNor(BTNode* pRoot);
void LevelOrder(BTNode* pRoot);

// ��ȡ�������нڵ�ĸ��� 
int GetNodeCount(BTNode* pRoot);

// ��������ĸ߶� 
int Height(BTNode* pRoot);

// ���������Ƿ�ƽ��O(N^2) 
int IsBalanceTree(BTNode* pRoot);
// ���������Ƿ�ƽ��O(N) 
int IsBalanceTree_P(BTNode* pRoot, int* height);

// ��ȡ��������Ҷ�ӽڵ�ĸ��� 
int GetLeafNodeCount(BTNode* pRoot);

// ��ȡ��������K��ڵ�ĸ��� 
int GetKLevelNodeCount(BTNode* pRoot, int K);

// ��ȡ��������ĳ���ڵ��˫�׽ڵ� 
BTNode* GetNodeParent(BTNode* pRoot, BTNode* pNode);

// ��������ľ��� 
void Mirror(BTNode* pRoot);








//8. ��ɶ��������ֵ�����OJ��Ŀ
//9. ����������д����(���Էֳɶ������д)

