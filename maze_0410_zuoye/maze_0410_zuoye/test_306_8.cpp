#include <iostream>
#include <stdlib.h>

using namespace std;
class Student
{
public:
	Student(int n, float s) :num(n), score(s) {}
	void change(int n, float s)
	{
		num = n;
		score = s;
	}
	void display()
	{
		cout << num << " " << score << endl;
	}
private:
	int num;
	float score;
};

void fun(Student &ps)
{
	ps.display();
	ps.change(101, 80.5);
	ps.display();
}

int main()
{
	//�޸ĵ�6��ĳ��򣬸�дfun������
	Student stud(101, 78.5);
	fun(stud);


	system("pause");
	return 0;
}