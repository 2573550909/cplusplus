//#include <stdio.h>
//#include <stdlib.h>
//
//int main()
//{
//	for (int i = 0; i < 5; ++i)
//	{
//		for (int j = 0; j < 2*i+1; ++j)
//		{
//			printf("*");
//		}
//		printf("\n");
//	}
//
//	for (int i = 0; i < 4; ++i)
//	{
//		for (int j = 7; j >  2 * i; --j)
//		{
//			printf("*");
//		}
//		printf("\n");
//	}
//
//	system("pause");
//	return 0;
//}
#include <iostream>
#include <stdlib.h>
#include <string>
using namespace std;

//class Student//��������
//{
//public:
//	void get_value()//��������Ա����
//	{
//		cin >> num >> name >> sex;
//	}
//
//	//����������ݵĳ�Ա����
//	void display()
//	{
//		cout << "name:" << num << endl;
//		cout << "name:" << name << endl;
//		cout << "sex:" << sex << endl;
//	}
//private: //����˽�г�Ա
//	int num;
//	string name;
//	char sec;
//};

//
////�� public ��ʽ���������� Student1
//class Student1:public Student
//{
//public:
//	void get_value_1() //��������������
//	{
//		cin >> age >> addr;
//	}
//	void display_1()
//	{
//		//�˴��������û����˽�г�Ա
//		//�����������������˽�г�Ա
//		cout << "age:" << age << endl;
//		cout << "address:" << addr << endl;
//	}
//private:
//	int age;
//	string addr;
//};
//
//int main()
//{
//	//����������Student1 �Ķ��� stud
//	Student1 stud;
//
//	//���û���Ĺ��г�Ա����,���������3�����ݳ�Ա��ֵ
//	stud.get_value();
//
//	//����������Ĺ��г�Ա����,�����������������ݳ�Ա��ֵ
//	stud.get_value_1();
//
//	//���û���Ĺ��г�Ա����,���������3�����ݳ�Ա��ֵ
//	stud.display();
//
//	//����������Ĺ��г�Ա����,������������������ݳ�Ա��ֵ
//	stud.display_1();
//
//
//	system("pause");
//	return 0;
//}


//class Student1:private Student
//{
//public:
//	void get_value_1()
//	{
//		//���û���Ĺ��ú����������3������
//		get_value();
//		cin >> age >> addr;//�������������������
//	}
//
//	//���5�����ݳ�Ա��ֵ
//	void display_1()
//	{
//		display();//���û����ó�Ա����,���3�����ݳ�Ա��ֵ
//
//		//����������˽�����ݳ�Ա
//		cout << "age:" << age << endl;
//		cout << "address:" << addr << endl;
//	}
//private:
//	int age;
//	string addr;
//};
//
//int main()
//{
//	//����һ��Student1 ��Ķ��� stud1
//	Student1 stud1;
//
//	//˽�л���Ĺ��г�Ա����������������˽�к���;
//	//stud1.display();
//
//	//display_1������Student1 ��Ĺ��ú���
//	stud1.display_1();
//
//	//��粻�������������˽�г�Ա
//	//stud1.age = 18;
//
//
//	system("pause");
//	return 0;
//}

//
//class Student
//{
//public:
//
//protected:
//	int num;
//	string name;
//	char sec;
//};
//
//class Student1 :protected Student
//{
//public:
//	void get_value1(); //�����๫�ó�Ա����
//	void display1();  //�����๫�ó�Ա����
//private:
//	int age;  //������˽�����ݳ�Ա
//	string addr; //������˽�����ݳ�Ա
//};
//
////���������๫�ó�Ա����
//void Student1::get_value1()
//{
//	cin >> num >> name >> sec;
//	cin >> age >> addr;
//}
//
//void Student1::display1()
//{
//	//���û���ı�����Ա
//	cout << "num:" << num << endl;
//	cout << "name:" << name << endl;
//	cout << "sex:" << sec << endl;
//
//	//�����������˽�г�Ա
//	cout << "age:" << age << endl;
//	cout << "address:" << addr << endl;
//}
//
//int main()
//{
//	Student1 stud1; //stud1 �������� Student1 ��Ķ���
//
//	//������Ĺ��ó�Ա����,��������
//	stud1.get_value1();
//	stud1.display1();
//
//	//stud1.num = 1100; //���Ǵ����
//	system("pause");
//	return 0;
//}


