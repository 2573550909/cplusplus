#include <iostream>
#include <stdlib.h>
#include <string>
#include <iomanip>
using namespace std;

//struct Student 
//{
//	string name[10];
//	float score[2];
//	int num;
//}stu;

//
//void score_low()
//{
//	cout << "�����ǳɼ����ϸ��ѧ����Ϣ"<<endl;
//	for (int i = 0; i < 3; ++i)
//	{
//		if (score[i] < 60)
//		{
//			cout << stu.name[i] << " "<<stu.score<< " "<< stu.num << endl;
//		}
//	}
//}

int main()
{
	//string name[10];
	//int num[10];
	//float score[10];
	//for (int i = 0; i < 10; ++i)
	//{
	//	cout  <<"�����"<<i+1<<"��ѧ����������ѧ�š��ɼ�:" <<endl;
	//	cin >> name[i] >> num[i] >> score[i] ;
	//}
	//cout << "�����ǳɼ����ϸ��ѧ����Ϣ��" << endl;
	//for (int j = 0; j < 10; ++j)
	//{
	//	if (score[j] < 60)
	//	{
	//		cout << "����:"<<name[j] << setw(8) << "ѧ�ţ�" << num[j] << setw(8) << "�ɼ���" << score[j] << endl;
	//	}
	//}
	int i = 0;
	cout << setw(-18) << "maze" <<i + 1 << setw(-14) << endl;
	cout << setw(-18) << "mafdsgze" << i + 2 << setw(-14) << endl;
	cout << setw(-18) << "mafssdfsfze" << i + 3 << setw(-14)<< endl;
	system("pause");
	return 0;
}