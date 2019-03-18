#define _CRT_SECURE_NO_WARNINGS
#include "test.h"

int main()
{
	member m;
	Init(&m);

	typedef void(*T)(member *m);
	T menu[] = { Insert,Delete,Display,Find,Modify,Clear};
	int choice = 0;
	Menu();
	printf("\n�����������Ҫ������ѡ��!\n");
	scanf("%d", &choice);

	while (1)
	{
		if (choice == 0)
		{
			printf("�ټ���\n");
			system("pause");
			break;
		}
		menu[choice - 1](&m);
		printf("\n�����������Ҫ������ѡ��!\n");
		scanf("%d", &choice);
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
	if (m == NULL)
	{
		return;
	}
	m->mem_index = 1;
}

void Insert(member* m)//�����ϵ��
{
	if (m == NULL)
	{
		return;
	}

	infor *p = &(m->mem[m->mem_index]);
	printf("��,�����µ���ϵ�˵�����\n");
	scanf("%s", p->name);

	printf("������ϵ�绰����\n");
	scanf("%s", p->num);

	++(m->mem_index);//�±��1
	printf("��ӳɹ���\n");
	Menu();
}

void Delete(member *m)//ɾ����ϵ��
{
	if (m == NULL)
	{
		return;
	}
	int serial_number = 1;

	printf("������Ҫɾ����ϵ�˵ı�ţ�");
	scanf("%d", &serial_number);
	if ((serial_number < 0) || (serial_number >= m->mem_index))
	{
		printf("��������");
		return;
	}
	if(serial_number== m->mem_index-1)
	{
		--m->mem_index;
		printf("ɾ���ɹ���");
		return;
	}
	m->mem[serial_number] = m->mem[m->mem_index - 1];
	--m->mem_index;
	printf("ɾ����ϵ�˳ɹ���");
}

void Display(member *m)//��ʾ��ϵ��
{
	if(m==NULL)
	{
		return;
	}
	for (int i = 1; i < m->mem_index; ++i)
	{
		printf("%d.������%s\t�绰��%s\n",
			i, m ->mem[i].name, m->mem[i].num);
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
	printf("%d.������%s\t�绰��%s\n", 
		index, m->mem[index].name, m->mem[index].num);
	printf("���ҳɹ���\n");
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
	infor *p = &m->mem[index];
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
