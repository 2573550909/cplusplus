#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdlib.h>
using namespace std;

class Date
{
public:
	Date(int year = 1900, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
	}
	// bool operator==(Date* this, const Date& d2)
	// ������Ҫע����ǣ����������thisָ��ĵ��ú����Ķ���
	bool operator==(const Date& d2)
	{
		return _year == d2._year
			&& _month == d2._month
			&& _day == d2._day;
	}
private:
	int _year;
	int _month;
	int _day;
};

void Test()
{
	Date d1(2018, 9, 26);
	Date d2(2018, 9, 27);
	cout << (d1 == d2) << endl;
}

class Date
{
public:
	Date(int year = 1900, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
	}
	Date(const Date& d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}

	void operator=(const Date& d)
	{
		if (this != &d)
		{
			_year = d._year;
			_month = d._month;
			_day = d._day;
		}
	}

private:
	int _year;
	int _month;
	int _day;
};

//���ؼӷ������
class Box
{
public:

	double getVolume()
	{
		return length * breadth * height;
	}

	void setLength(double len)
	{
		length = len;
	}

	void setBreadth(double bre)
	{
		breadth = bre;
	}

	void setHeight(double hei)
	{
		height = hei;
	}

	// ���� + ����������ڰ����� Box �������
	Box operator + (const Box& b)
	{
		Box box;
		//this ��ָ����Box1�ĵ�ַ   b.lengthָ����Box2�ĳ���
		box.length = this->length + b.length;
		box.breadth = this->breadth + b.breadth;
		box.height = this->height + b.height;
		return box;
	}
private:
	double length;      // ����
	double breadth;     // ���
	double height;      // �߶�
};


//��ֵ���������
class Distance
{
private:
	int feet;             // 0 ������
	int inches;           // 0 �� 12
public:
	// ����Ĺ��캯��
	Distance()
	{
		feet = 0;
		inches = 0;
	}

	Distance(int f, int i) 
	{
		feet = f;
		inches = i;
	}

	void operator=(const Distance &D)
	{
		this->feet = D.feet;
		this->inches = D.inches;
	}
	// ��ʾ����ķ���
	void displayDistance()
	{
		cout << "F: " << this->feet << " I:" << this->inches << endl;
	}
};

class String
{
public:
	String(const char* str = "jack")
	{
		_str = (char*)malloc(strlen(str) + 1);
		strcpy(_str, str);
	}

	~String()
	{
		cout << "~String()" << endl;
		free(_str);
	}
private:
	char* _str;
};

class Date
{
public:
	Date(int year = 0,int month = 0,int day = 0)
	{
		_year =  year;
		_month = month;
		_day = day;
	}
	void Display()
	{
		cout << "Display ()" << endl;
		cout << "year:" << _year << endl;
		cout << "month:" << _month << endl;
		cout << "day:" << _day << endl << endl;
	}

	void Display() const
	{
		cout << "Display () const" << endl;
		cout << "year:" << _year << endl;
		cout << "month:" << _month << endl;
		cout << "day:" << _day << endl << endl;
	}
private:
	int _year; // ��
	int _month; // ��
	int _day; // ��
};

class Date
{
public:
	Date(int year = 1900, int month = 1, int day = 1);
	
	�������캯��
	Date(const Date& d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}

	Date& operator=(const Date& d)
	{
		if (this != &d)
		{
			this->_year = d._year;
			this->_month = d._month;
			this->_day = d._day;
		}
		return *this;
	}

	Date operator+(int days)
	{
		return this->_day + days;
	}

	Date operator-(int days)
	{
		return this->_day - days;
	}

	int operator-(const Date& d)
	{
		Date d1;
		this->_year - d._year;
		this->_month - d._month;
		this->_day - d._day;
	}


	Date& operator++();
	Date operator++(int);
	Date& operator--();
	Date operator--(int);
	bool operator>(const Date& d)const;
	bool operator>=(const Date& d)const;
	bool operator<(const Date& d)const;
	bool operator<=(const Date& d)const;
	bool operator==(const Date& d)const;
	bool operator!=(const Date& d)const;
private:
	int _year;
	int _month;
	int _day;
};

int main()
{
	Date d1(1990, 1, 2);
	Date d2(d1);



	1. const������Ե��÷�const��Ա������
	Date const d1;
	d1.Display();
	
	//2. ��const������Ե���const��Ա������
	Date d2;
	d2.Display();


	3. const��Ա�����ڿ��Ե��������ķ�const��Ա������


	4. ��const��Ա�����ڿ��Ե���������const��Ա������

	String s1("hello");
	String s2("world");
	s2 = s1;

	
	Distance D1(11, 10), D2(5, 11);

	cout << "First Distance : ";
	D1.displayDistance();
	cout << "Second Distance :";
	D2.displayDistance();

	// ʹ�ø�ֵ�����
	D1 = D2;
	cout << "First Distance :";
	D1.displayDistance();


	Box Box1;                // ���� Box1������Ϊ Box
	Box Box2;                // ���� Box2������Ϊ Box
	Box Box3;                // ���� Box3������Ϊ Box
	double volume = 0.0;     // ������洢�ڸñ�����

	// Box1 ����
	Box1.setLength(6.0);
	Box1.setBreadth(7.0);
	Box1.setHeight(5.0);

	// Box2 ����
	Box2.setLength(12.0);
	Box2.setBreadth(13.0);
	Box2.setHeight(10.0);

	// Box1 �����
	volume = Box1.getVolume();
	cout << "Volume of Box1 : " << volume << endl;

	// Box2 �����
	volume = Box2.getVolume();
	cout << "Volume of Box2 : " << volume << endl;

	// ������������ӣ��õ� Box3
	Box3 = Box1 + Box2;

	// Box3 �����
	volume = Box3.getVolume();
	cout << "Volume of Box3 : " << volume << endl;

	
	Date d1(2019, 5, 15);
	Date d2(2019, 6, 15);

	d2 = d1;



	Test();


	system("pause");
	return 0;
}