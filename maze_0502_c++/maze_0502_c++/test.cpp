#include <iostream>
#include <stdlib.h>

using namespace std;

//class Time
//{
//public:
//	//�������캯��,Ĭ�ϲ���
//	Time(int, int, int);
//	int hour;
//	int minute;
//	int sec;
//};
//
////���幹�캯��
//Time::Time(int h, int m, int s)
//{
//	hour = h;
//	minute = m;
//	sec = s;
//}
//
////�����õķ�ʽ����
//void fun(Time &t)
//{
//	t.hour = 18;
//}
//
//int main()
//{
//	Time t1(10, 13, 56);
//	fun(t1);
//	cout << t1.hour << endl;
//
//
//	system("pause");
//	return 0;
//}

//class Time
//{
//public:
//	Time(int, int, int);
//	int hour;
//	int minute;
//	int sec;
//};
//
//Time::Time(int h, int m, int s)
//{
//	hour = h;
//	minute = m;
//	sec = s;
//}
//
//void fun(Time &t)
//{
//	t.hour = 18;
//}
//
//int main()
//{
//	Time t1(10, 36, 56);
//	fun(t1);
//	cout << t1.hour << endl;
//
//
//	system("pause");
//	return 0;
//}

//class Box
//{
//public:
//	Box(int, int);
//	int volume();
//
//	//����һ�� static ��̬����
//	static int height;
//
//	int width;
//	int length;
//};
//
//Box::Box(int w, int len)
//{
//	width = w;
//	length = len;
//}
//
//int Box::volume()
//{
//	return (height*width*length);
//}
//
////������ Box �ı��� height ��ʼ��Ϊ10
//int Box::height = 10;
//
//int main()
//{
//	Box a(10, 20);
//	Box b(20, 30);
//
//	cout << a.height << endl;//10
//	cout << b.height << endl;//10
//	cout << Box::height << endl;//10
//	cout << a.volume()<< endl;//2000
//
//
//	system("pause");
//	return 0;
//}
//

class Student
{
public:

	//���캯���Ĳ������ʼ��
	Student(int n,int a,float s):num(n),age(a),score(s){}
	void total();
	static float average();
private:
	int num;
	int age;
	float score;
	static float sum;
	static int count;
};

void Student::total()
{
	sum += score;
	count++;
}

float Student::average()
{
	return (sum / count);
}

float Student::sum = 0;
int Student::count = 0;

int main()
{
	//����Student ����
	Student stud[3] = {
		Student(1001,18,70),
		Student(1002,19,78),
		Student(1003,20,98)
	};

	int n;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		stud[i].total();
	}

	cout << n << Student::average() << endl;

	system("pause");
	return 0;
}