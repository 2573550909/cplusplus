//#include <iostream>
//#include <stdlib.h>
//#include <string>
//using namespace std;
//
////��һ����,4��ѧ��,5�ſ�,��:
//struct student

//{
//	string name[100];//����
//	float score1[100];//����;
//	int num[100];//ѧ��
//}	S;
//
//struct xiaobiao
//{
//	int i;		//��
//}	course;
//
////1.��һ�ſε�ƽ����?
//void average(float students_score[4][5])
//{
//	float average = 0;
//	float sum = 0;
//	float s = 0;
//	int i = 0;
//	for (int j = 0; j < 5; ++j)
//	{
//		s = students_score[i][j];
//		sum = s + sum;
//	}
//	average = sum / 5;
//	cout << "��һ�����Ե�ƽ���ɼ�Ϊ" << average << endl;
//}
//
////2.�ҳ��������Ͽγ̲������ͬѧ,
////	������ǵ�ѧ���Լ�ȫ���γ̳ɼ���ƽ���ɼ�
//void sucess_2_bujige(float students_score[4][5])
//{
//	int j = 0;
//	int i = 0;
//	for (i = 0; i < 4; ++i)
//	{
//		int count = 0;
//		for (int j = 0; j < 5; ++j)
//		{
//			if (students_score[i][j] < 60)
//			{
//				++count;
//			}
//		}
//		if (count > 2)
//		{
//			float s = 0;
//			float sum = 0;
//			cout << "��" << i+1 << "��" << "ͬѧ��" << count
//				<< "�ſγ̲�����" << endl;
//			cout << "����:"<<" " << S.name[i] << "ѧ�ţ�" << S.num[i]<<"  " ;
//			for (int l = 0; l < 5; ++l)
//			{
//				s = students_score[i][l];
//				sum = sum + s;
//				cout<<" "<<students_score[i][l]<< " ";
//			}
//			cout << "ƽ���ɼ��ǣ�" << sum/5 << endl;
//		}
//	}
//}
//
////3.�ҳ�ƽ���ɼ���90�����ϻ�ȫ���γ���85�����ϵ�ͬѧ
//void excllent90_or85(float students_score[4][5])
//{
//	float sum = 0;
//	int i = 0;
//	int j = 0;
//	float s = 0;
//	float average = 0;
//	for (i = 0; i < 4; ++i)
//	{
//		int count = 0;
//		for (j = 0; j < 5; ++j)
//		{
//			if (students_score[i][j]>85)
//			{
//				++count;
//			}
//			s = students_score[i][j] ;
//			sum = s + sum;
//		}
//		average = sum / 5;
//		if (average > 90 &&  count == 5)
//		{
//			cout<<S.name[i]<<"ѧ��ƽ���ɼ���90�����ϻ�ÿ�ſ���85����"<<endl;
//		}
//	}
//}
//
//void all_students_info(float students_score[4][5])
//{
//	for (int i = 0; i < 4; ++i)
//	{
//		cout << "�������" << i + 1 << "��ѧ��������,ѧ��" << endl;
//		cin >> S.name[i] >> S.num[i];
//	}
//	for (int j = 0; j < 4; ++j)
//	{
//		cout << "��" << j + 1 << "��ѧ����������:"
//			<< S.name[j]<<"   "<< "ѧ����:" << S.num[j]<<"  " ;
//		
//		for (int l = 0; l < 5; ++l)
//		{
//			cout << "  " << students_score[j][l] << "  ";
//		}
//		cout << endl;
//	}
//}
//
//int main()
//{
//	//�ȶԳɼ����г�ʼ��
//	float students_score[4][5] = 
//	{
//		{40,30,60,70,80},
//		{50,20,10,80,90},
//		{60,70,80,90,99},
//		{86,87,88,89,95}
//	};
//
//	all_students_info(students_score);
//	cout << endl;
//
//	//1.��һ�ſε�ƽ����?
//	average(students_score);
//	cout << endl;
//	//2.�ҳ��������Ͽγ̲������ͬѧ,
//	//  ������ǵ�ѧ���Լ�ȫ���γ̳ɼ���ƽ���ɼ�
//	sucess_2_bujige(students_score);
//	cout << endl;
//	//3.�ҳ�ƽ���ɼ���90�����ϻ�ȫ���γ���85�����ϵ�ͬѧ
//	excllent90_or85(students_score);
//
//	system("pause");
//	return 0;
//}