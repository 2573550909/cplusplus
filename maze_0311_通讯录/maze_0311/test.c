#define _CRT_SECURE_NO_WARNINGS
#include "test.h"

int main()
{
	member m;
	Init(&m);

	typedef void(*T)(member *m);
	T menu[] = { Insert,Delete,Display,Find,Modify,Clear };
	int choice = 0;
	Menu();
	printf("\n�����������Ҫ������ѡ��!\n");
	while (1)
	{
		scanf("%d", &choice);
		if (choice == 0)
		{
			printf("�ټ���\n");
			system("pause");
			return 0;
		}

		if (choice < 0 || choice>7)
		{
			printf("����������������!!\n");
			continue;
		}
		else 
		{
			menu[choice - 1](&m);
			printf("�����������Ҫ������ѡ�\n");
			Menu();
		}
	}

	system("pasuse");
	return 0;
}

void Menu()
{
	printf("************\n");
	printf("1.�����ϵ��\n");
	printf("2.ɾ����ϵ��\n");
	printf("3.��ʾ��ϵ��\n");
	printf("4.������ϵ��\n");
	printf("5.�޸���ϵ��\n");
	printf("6.�����ϵ��\n");
	printf("0.�˳�\n");
	printf("************\n");
}

void Init(member *m)//��ʼ����ϵ��
{
	int sz = m->size = 0;
	int cap = m->capacity = 100;
	
	m->mem = (infor*)malloc(sizeof(infor*)*cap);
	if (m->mem == NULL){return;}
}

void Insert(member* m)//�����ϵ��
{
	if (m == NULL){return;}

	infor *p = m;
	printf("��,�����µ���ϵ�˵�����\n");
	scanf("%s", p->name);

	printf("������ϵ�绰����\n");
	scanf("%s", p->num);

	printf("��ӳɹ���\n");
	m->size++;
}

void Delete(member *m)//ɾ����ϵ��
{
	if (m == NULL) {return;}
	
	int serial_number = 1;
	printf("������Ҫɾ����ϵ�˵ı�ţ�");
	while (1)
	{
		scanf("%d", &serial_number);
		if ((serial_number < 0) || (serial_number >= m->mem_index))
		{
			printf("��������\n");
			continue;
		}
		else { break; }
	}
	
	//���Ҫɾ�������һ������ֱ���±�--
	if(serial_number== m->mem_index-1)
	{
		--m->mem_index;
	}
	else//��������һ��Ԫ�ظ�ֵ��Ҫɾ����Ԫ������±�--
	{
		m->mem[serial_number] = m->mem[m->mem_index - 1];
		--m->mem_index;
	}
	printf("ɾ����ϵ�˳ɹ���\n");
}

//��ʾ��ϵ��
void Display(member *m)
{
	if(m == NULL){return;}
	
	for (int i = 0; i < m->mem_index; ++i)
	{
		printf("��ţ�%d.������%s\t�绰��%s\n",
			i+1, m ->mem[i].name, m->mem[i].num);
	}
}

void Find(member *m)//������ϵ��
{
	if (m == NULL)
	{
		return;
	}

	int index = 0;
	while (1)
	{
		printf("��������Ҫ���ҵ���ϵ�˵ı�ţ�\n");
		scanf("%d", &index);
		if (index<0 || index>m->mem_index - 1)
		{
			printf("��������\n���������룺\n");
			continue;
		}
		break;
	}
	printf("���ҳɹ���\n");
	printf("%d.������%s\t�绰��%s\n", 
		index, m->mem[index-1].name, m->mem[index-1].num);
}

void Modify(member *m)//�޸���ϵ��
{
	if (m == NULL)
	{
		return;
	}
	int index;
	int type;

	printf("��������Ҫ�޸ĵ���ϵ�˵ı�ţ�");
	scanf("%d", &index);
	if (index < 0 || index >( m->mem_index - 1))
	{
		printf("��������!");
		return;
	}
	infor *p = &m->mem[index-1];
	printf("1.����\n");
	printf("2.�绰\n");
	printf("��������Ҫ�޸ĵ�����");
	scanf("%d", &type);
	if (type < 1 || type>2)
	{
		printf("��������");
		return;
	}
	if (type == 1)
	{
		char new_name[256] = { 0 };
		printf("��������ϵ�˵�������");
		scanf("%s", new_name);
		strcpy(p->name, new_name);
	}
	else
	{
		char new_num[256] = { 0 };
		printf("������Ҫ�޸ĵ���ϵ�˵ĵ绰��");
		scanf("%s", new_num);
		strcpy(p->num, new_num);
	}
	printf("�޸ĳɹ���");
}

void Clear(member *m)//���ͨѶ¼
{
	if (m == NULL)
	{
		return;
	}
	m->mem_index = 0;
	printf("ͨѶ¼�Ѿ���գ�");
}
