#pragma once
#include <iostream>
#include <stdlib.h>
#include <string>

using namespace std;

struct Student
{
	string name[100];//����
	float score[100];//����
	int num[100];//ѧ��
}	stu;


void print_score_low()//��ӡ��Ϣ
{
	cout << "�����ǳɼ����ϸ��ѧ����Ϣ" << endl;
	for (int i = 0; i < 10; ++i)
	{
		if (stu.score[i] < 60)
		{
			cout << "����:" << stu.name[i] << "����:"
				<< stu.score[i] << "ѧ��:" << stu.num[i] << endl;
		}
	}
}

void get_information()//��ȡ��Ϣ
{

	for (int i = 0; i < 10; ++i)
	{
		cout << "�������" << i + 1 << "��ѧ��������,ѧ��,�ɼ�" << endl;
		cin >> stu.name[i] >> stu.num[i] >> stu.score[i];
	}
}

