//#include <iostream>
//#include <stdlib.h>
//#include <string>
//
//using namespace std;
//
//struct Student 
//{
//	string name[100];//����
//	float score[100];//����
//	int num[100];//ѧ��
//}	stu;
//
//
//void print_score_low()//��ӡ��Ϣ
//{
//	cout << "�����ǳɼ����ϸ��ѧ����Ϣ"<<endl;
//	for (int i = 0; i < 10; ++i)
//	{
//		if (stu.score[i] < 60)
//		{
//			cout << "����:"<<stu.name[i] <<"����:"
//				<<stu.score[i]<<"ѧ��:"<< stu.num[i] << endl;
//		}
//	}
//}
//
//void get_information()//��ȡ��Ϣ
//{
//
//	for (int i = 0; i < 10; ++i)
//	{
//		cout << "�������"<<i+1<<"��ѧ��������,ѧ��,�ɼ�" <<endl;
//		cin >> stu.name[i] >> stu.num[i] >> stu.score[i];
//	}
//}
//
//int main()
//{
//	//����ɼ�
//	get_information();
//
//	//��ӡ�ɼ�
//	print_score_low();
//
//
//
//
////==============================================
//	//��ӡ�ɼ����ϸ��ѧ��
//
//	//string name[10];
//	//int num[10];
//	//float score[10];
//	//for (int i = 0; i < 10; ++i)
//	//{
//	//	cout  <<"�����"<<i+1<<"��ѧ����������ѧ�š��ɼ�:" <<endl;
//	//	cin >> name[i] >> num[i] >> score[i] ;
//	//}
//	//cout << "�����ǳɼ����ϸ��ѧ����Ϣ��" << endl;
//	//for (int j = 0; j < 10; ++j)
//	//{
//	//	if (score[j] < 60)
//	//	{
//	//		cout << "����:"<<name[j]  << "ѧ�ţ�"
//	//			<< num[j]  << "�ɼ���" << score[j] << endl;
//	//	}
//	//}
//	//int i = 0;
//	//cout << setw(-18) << "maze" <<i + 1 << setw(-14) << endl;
//	//cout << setw(-18) << "mafdsgze" << i + 2 << setw(-14) << endl;
//	//cout << setw(-18) << "mafssdfsfze" << i + 3 << setw(-14)<< endl;
//	system("pause");
//	return 0;
//}