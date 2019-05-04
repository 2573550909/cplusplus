/********************************************************************
��̬��:��ͬ�Ķ�����ͬһ����Ϣ,��ͬ�Ķ�����ڽ��յ�ʱ�������ͬ����Ϊ

c++��Ķ�̬��:	���в�ͬ�Ĺ��ܺ���������ͬһ��������,������
				����ʵ����һ�����������ò�ͬ���ݵĺ���
��̬�Է�Ϊ����
	��̬��̬��:ͨ����������ʵ��,�ɺ������غ�������γɵ�.
			   Ҫ���ڱ����ʱ�����֪�����ú�����ȫ����Ϣ
			   �����ֳ�֮Ϊ����ʱ�Ķ�̬��,��ȻЧ�ʸ�,��ȱ�����
								
	��̬��̬��:�����е�ʱ��ȷ�������Ķ���,��Ϊ֮����ʱ�Ķ�̬��,ͨ���麯��ʵ��
***********************************************************************/
#include <iostream>
#include <stdlib.h>
using namespace std;

class Point
{
public:
	//��Ĭ�ϲ����Ĺ��캯��
	Point(double x = 0, double y = 0);

	//������������ֵ�ĺ���
	void setpoint(double, double);

	//�����ȡ����ĺ���
	//const ������:ֻ�������������е�����,�������޸�
	double get_x() const{ return x; }
	double get_y() const{ return y; }

	//��Ԫ���������
	friend ostream & operator<<(ostream &, const Point &);

protected:
	double x, y;

};

Point::Point(double a, double b)
{
	x = a;
	y = b;
}

void Point::setpoint(double a, double b)
{
	x = a;
	y = b;
}

//���������"<<" ,ʹ֮������������
ostream & operator<<(ostream &output, const Point &p)
{
	output << "[" << p.x << "," << p.y << "]" << endl;
	return output;
}

//Circle �� Point �Ĺ�������
class Circle :public Point
{
public:
	Circle(double x = 0, double y = 0, double r = 0);

	void setRadius(double);
	double getRadius()const;
	double area()const;

	//���������"<<"
	friend ostream & operator<<(ostream &, const Circle &);
private:
	double radius;
};

//int main()
//{
//	//��������ͬʱ��ʿ���ù��캯��
//	Point p(3.5, 6.4);
//	cout << "x=" << p.get_x() << ",y=" << p.get_y() << endl;
//	
//	p.setpoint(8.5, 6.8);
//	cout << "p(new):" << p << endl;
//
//
//	system("pause")9;
//	return 0;
//}

/************************************************************************
�����麯��ʵ�ֶ�̬��̬��
	�麯����������:���������������¶��������ͬ���ĺ���,���ҿ���ͨ������ָ��
				   �����������ʻ�����������ͬ������

	ʹ�÷���:�ڻ������� virtual ������Ա����Ϊ�麯��,�����ⶨ���ʱ�򲻼�virtual

	��ν�麯������:�ڻ������������������,������ʵ�ʴ��ڵ�,Ȼ������������
				   �����Ķ��庯��,
*************************************************************************/


