#include <iostream>
#include <stdlib.h>

using namespace std;
class Student
{
public:
	Student(int n,float s):num(n),score(s){}
	int num;
	float score;
};

void max (Student *pt,int n)
{
	Student *p = pt, ma(0, 0);
	float max;
	for (max = pt->score; p < pt + n; ++p)
	{
		if (p->score > max)
		{
			max = p->score;
			ma = *p;
		}
	}
	cout << "student info:" << ma.num << ' ' << ma.score << endl;
}
int main()
{
	//����һ������������5��ѧ�������ݣ���ӡ���ɼ���õ���λѧ����Ϣ
	Student stu[5] = {
		Student(11,59),
		Student(12,69),
		Student(13,79),
		Student(14,89),
		Student(15,99)
	};
	max(stu, 5);
	
	system("pause");
	return 0;
}