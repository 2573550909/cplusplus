//�洢ͼ����Ϣ
typedef struct book
{
	char num[10];//�����
	char name[15];//����
	int price;//�۸�
	char author[15];//����
	char pub[20];//������
	int number;//����
};

//��Ա��Ϣ
typedef struct Member
{
	char mnum[10];//��Ա��
	char mname[15];//��Ա����
	char tel[15];//��Ա�ֻ���
};

typedef struct borrow
{
	char mnum[10];//��Ա��
	char mname[15];//��Ա����
	char num[10];//���
	char name[15];//����
};

//ͼ����Ϣ����Ľ��ṹ
typedef struct node
{
	struct book data;
	struct node* next;
}	Node,*Link;

//�����Ա��Ϣ��������ṹ
typedef struct mnode
{
	struct Member inf;
	struct mnode *next;
}	Mnode,*Mlink;

//���������Ϣ����Ľ��ṹ
typedef struct bnode
{
	struct borrow binf;
	struct bnode* next;
}	Bnode,*Blink;

void MainMenu();
int Ide,Key;
Link I;
Mlink m;
Blink b;



