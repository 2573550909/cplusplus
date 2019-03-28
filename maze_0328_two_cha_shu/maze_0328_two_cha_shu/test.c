#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct Node
{
	int value;
	struct Node* left;
	struct Node* right;
}	Node;

void PreorderTraversal(Node* root)
{
	//root == NULL;����
	if (root == NULL)
	{
		return;
	}

	printf("%d", root->value);
	//if (root->left != NULL)
	//{
	//	PreorderTraversal(root->left);
	//}

	//if (root->right!= NULL)
	//{
	//	PreorderTraversal(root->right);
	//}
	PreorderTraversal(root->left);
	PreorderTraversal(root->right);
}

void Inorder(Node* root)
{
	//������  ��  ������
	if (root == NULL)
	{
		return;
	}

	Inorder(root->left);

	printf("%d", root->value);

	Inorder(root->right);
}


void Postorder2(Node* root)
{
	//������ ������   ��  
	if (root == NULL)
	{
		return;
	}

	Postorder2(root->left);

	Postorder2(root->right);

	printf("%d", root->value);

}

//��������
int Size(Node* root)
{

}

//���Ƶķ�ʽ����Ҷ�ӽ�����
int LeaftSize(Node* root)
{
	if (root == NULL)
	{
		return 0;
	}
	if (root->left == NULL && root->right == NULL)
	{
		return 1;
	}

	int left = LeaftSize(root->left);
	int right = LeaftSize(root->right);
	return left + right;

}

int GetHeight(Node* root)
{
	if (root == NULL)
	{
		return 0;
	}

	if (root->left == NULL && root->right == NULL)
	{ 
		return 1;
	}

	int left = GetHeight(root->left);
	int right = GetHeight(root->right);

	if (left > right)
	{
		return left + 1;
	}
	else
	{
		return right + 1;
	}

}

//���K�������
int GetKlevel(Node* root, int k)
{
	if (root == NULL)
	{
		return 0;
	}

	if (k == 1)//����ǰ��root!=NULL
	{
		return 1;
	}

	int left = GetKlevel(root->left,k-1);
	int right = GetKlevel(root->right ,k - 1);

	return left + right;
}

//������������е�value�����ظ�
//���������value��v�Ľ�㣬����v���ڵĽ���ַ�����򷵻�NULL
//����˳��	1.�����	2.������	3.������
Node* Find(Node* root, int v)
{
	if (root == NULL)
	{
		return NULL;
	}

	if (root->value == v)
	{
		return root;
	}
	
	Node* result = Find(root->left, v);
	if (result != NULL)
	{
		//�������ҵ���
		return result;
	}

	result = Find(root->right, v);
	if(result!=NULL)
	{
		return result;
	}
	else
	{
		return NULL;
	}
}

//bool isMirror(struct TreeNode* p, struct TreeNode* q)
//{
//	if (p == NULL && q == NULL)
//	{
//		return true;
//	}
//
//	if (p == NULL || q == NULL)
//	{
//		return false;
//	}
//
//	return p->val == q->val
//		&& isMirror(p->left, q->right)
//		&& isMirror(p->right, q->left);
//}
//
//bool isSynmetric(struct TreeNode* root)
//{
//	if (root == NULL)
//	{
//		return true;
//	}
//}

void  

int main()
{

	//1.�����������return

	//ǰ��A B C D F I E G H
	//��: B A D I F C G E H 
	//��: B I F D G H E C A



	//�ڵ�Ķȣ�һ���ڵ㺬�е������ĸ�����Ϊ�ýڵ�Ķȣ� ����ͼ��A��Ϊ6
	
	//Ҷ�ڵ���ն˽ڵ㣺��Ϊ0�Ľڵ��ΪҶ�ڵ㣻 ����ͼ��B��C��H��I...�Ƚڵ�ΪҶ�ڵ�
	
	//���ն˽ڵ���֧�ڵ㣺�Ȳ�Ϊ0�Ľڵ㣻 ����ͼ��D��E��F��G...�Ƚڵ�Ϊ��֧�ڵ�
	
	//˫�׽ڵ�򸸽ڵ㣺��һ���ڵ㺬���ӽڵ㣬������ڵ��Ϊ���ӽڵ�ĸ��ڵ㣻 
	//					����ͼ��A��B�ĸ��ڵ�
	
	//���ӽڵ���ӽڵ㣺һ���ڵ㺬�е������ĸ��ڵ��Ϊ�ýڵ���ӽڵ㣻 
	//					����ͼ��B��A�ĺ��ӽڵ�

	//�ֵܽڵ㣺������ͬ���ڵ�Ľڵ㻥��Ϊ�ֵܽڵ㣻 ����ͼ��B��C���ֵܽڵ�
	
	//���Ķȣ�һ�����У����Ľڵ�Ķȳ�Ϊ���Ķȣ� ����ͼ�����Ķ�Ϊ6
	
	//�ڵ�Ĳ�Σ��Ӹ���ʼ�����𣬸�Ϊ��1�㣬�����ӽڵ�Ϊ��2�㣬�Դ����ƣ�
	
	//���ĸ߶Ȼ���ȣ����нڵ������Σ� ����ͼ�����ĸ߶�Ϊ4
	
	//���ֵܽڵ㣺˫����ͬһ��Ľڵ㻥Ϊ���ֵܣ�����ͼ��H��I��Ϊ���ֵܽڵ�
	
	//�ڵ�����ȣ��Ӹ����ýڵ�������֧�ϵ����нڵ㣻����ͼ��A�����нڵ������
	
	//�����ĳ�ڵ�Ϊ������������һ�ڵ㶼��Ϊ�ýڵ�����
	//		����ͼ�����нڵ㶼��A������
	
	//ɭ�֣���m��m >= 0���û����ཻ�����ļ��ϳ�Ϊɭ�֣�


	system("pause");
	return 0;
}