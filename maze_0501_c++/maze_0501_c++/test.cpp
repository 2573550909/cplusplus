#include <stdlib.h>
#include <iostream>

using namespace std;

//void Swap(int& left, int& right)
//{
//	int tmp = left;
//	left = right;
//	right = tmp;	
//}
//
////����һ����ΪStudent�Ľṹ������
//struct Student
//{
//	int num;
//	char name[20];
//	char sex;
//};
//
////���������ṹ��
//Student student1, student2;
////����������һ����ΪStudent �ṹ�����Ͳ������������ṹ�����
//
//class Student//����һ���࣬����ΪStudent
//{
//	int num;
//	char name[20];
//	char sex;
//	void display()//��Ա����
//	{
//		cout << "num:" << num << endl;
//		cout << "name:" << name << endl;
//		cout << "sex:" << sex << endl;
//	}
//};

//class Time
//{
//public:
//	int hour;
//	int minute;
//	int sec;
//};

//int main()
//{
	//Time t1;//����һ�������

	////��Ϊhour minute sec �ǹ��е�,���Կ��������ⱻ����
	//cin >> t1.hour;
	//cin >> t1.minute;
	//cin >> t1.sec;

	//cout << t1.hour <<":"<< t1.minute <<":"<< t1.sec << endl;

	//int a = 5;
	//int* p = NULL;
	//int& ra = a;
	//Swap(ra, *p);

	/*printf("%d", ra);*/


//	system("pause");
//	return 0;
//}

////����һ��������Time ����
//class Time
//{
//public:
//	//������Ա����
//	void set_time();
//	void show_time();
//private:
//
//	//����˽�б���
//	int hour;
//	int minute;
//	int sec;
//};
//
//int main()
//{
//
//	Time t1;//����һ������
//
//	//���ڳ�Ա�����ǹ��е�,���Կ��Ա�����
//	t1.set_time();
//	t1.show_time();
//
//	Time t2;
//	t2.set_time();
//	t2.show_time();
//
//	system("pause");
//	return 0;
//}
//
////�����Ա���� �ú�������Time
//void Time::set_time()
//{
//	cin >> hour;
//	cin >> minute;
//	cin >> sec;
//}
//
////�����Ա���� �ú�������Time
//void Time::show_time()
//{
//	cout << hour<<":" << minute << ":" << sec << endl;
//}

//class V
//{
//public:
//	void shuru();
//	void calculate_v();
//	void display_v();
//private:
//	float length;
//	float width;
//	float height;
//	float v;
//};

//int main()
//{
//	V v1;
//	v1.shuru();
//	v1.calculate_v();
//	v1.display_v();
//
//	V v2;
//	v2.shuru();
//	v2.calculate_v();
//	v2.display_v();
//
//	V v3;
//	v3.shuru();
//	v3.calculate_v();
//	v3.display_v();
//
//	system("pause");
//	return 0;
//}

//void V::shuru()
//{
//	cin >> length;
//	cin >> width;
//	cin >> height;
//}
//
//void V::calculate_v()
//{
//	float v = height * width * length;
//}
//
//void V::display_v()
//{
//	cout << height * width * length << endl;
//}
//
//////��������������ʱ������ݳ�Ա��ʼ��
////class Time
////{
////	hour = 0;
////	minute = 0;
////	sec = 0;
////};
//
//class Time
//{
//public:
//	Time()
//	{
//		hour = 0;
//		minute = 0;
//		sec = 0;
//	}
//	void set_time();
//	void show_time();
//private:
//	int hour;
//	int minute;
//	int sec;
//};
//
//void Time::set_time()
//{
//	cin >> hour;
//	cin >> minute;
//	cin >> sec;
//}
//
//void Time::show_time()
//{
//	cout << hour << ":" << minute << ":" << sec << endl;
//}

//int main()
//{
//	Time t1;
//	t1.set_time();
//	t1.show_time();
//
//	Time t2;
//
//	t2.show_time();
//
//	system("pause");
//	return 0;
//}
//
//class Time
//{
//public:
//	Time();
//	void set_time();
//	void show_time();
//private:
//	int hour;
//	int minute;
//	int sec;
//};
//���캯��û�з���ֵ
//Time::Time()//���ⶨ�幹�캯�������ҳ�ʼ��
//{
//	hour = 0;
//	minute = 0;
//	sec = 0;
//}
//
//void Time::set_time()
//{
//	cin >> hour;
//	cin >> minute;
//	cin >> sec;
//}
//
//void Time::show_time()
//{
//	cout << hour << ":" << minute << ":" << sec << endl;
//}
//

//int main()
//{
//	Time t1;
//	t1.set_time();
//	t1.show_time();
//
//	system("pause");
//	return 0;
//}
//
//class Box
//{
//public:
//
//	//�����������Ĺ��캯��
//	Box(int, int, int);
//	int volume();
//private:
//	int height;
//	int width;
//	int length;
//};
//
//Box::Box(int h,int w,int l)//���캯���Ĵ���
//{
//	height = h;
//	width = w;
//	length = l;
//}
//
//int Box::volume()
//{
//	return (height*width*length);
//}
//
//int main()
//{
//	//����һ������box1,���Ҹ����ֵ
//	Box box1(12, 25, 40);
//	cout << box1.volume() << endl;
//
//	Box box2(15, 30, 50);
//	cout << box2.volume() << endl;
//
//
//	system("pause");
//	return 0;
//}

//class Box
//{
//public://���������캯����ʱ��ָ��Ĭ��ֵ���������ڶ����ʱ��
//	Box(int h = 10, int w = 10, int len = 10);
//	int volume();
//private:
//	int height;
//	int width;
//	int length;
//};
//
//Box::Box(int h,int w,int len)
//{
//	height = h;
//	width = w;
//	length = len;
//}
//
//int Box::volume()
//{
//	return (height*width*length);
//}

//int main()
//{
//	Box box1;
//	cout << box1.volume() << endl;
//
//	Box box2(5);
//	cout << box2.volume() << endl;
//
//	Box box3(10, 20);
//	cout << box3.volume() << endl;
//
//	system("pause");
//	return 0;
//}
//
class Time
{
public:
	//�����ṹ��Ա����
	Time(int, int, int);

	//�������,������ʽΪ���е�
	int hour;
	int minute;
	int sec;

	//�������г�Ա����
	void get_time();
};

//���캯���Ķ���,
Time::Time(int h, int m, int s)
{
	hour = h;
	minute = m;
	sec = s;
}

//�����Ա��Ա����
void Time::get_time()
{
	cout << hour << ":" << minute << ":" << sec << endl;
}

int main()
{
	Time t1(10, 12, 30);//���� Time ����� t1 ����ʼ��

	int *p1 = &t1.hour;//����ָ���������ݵ�ָ�����p1,

	cout << *p1 << endl;//���p1��ָ�����ݳ�Աt1.hour

	t1.get_time();

	
	Time *p2 = &t1; //����ָ�� Time �����ݵ�ָ����� p2
	p2->get_time();
	
	void(Time::*p3)();//����һ������ָ��p3 
	p3 = &Time::get_time; //ָ�� get_time ����
	(t1.*p3)();

	system("pause");
	return 0;
}