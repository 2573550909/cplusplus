#include <stdlisb.h>
#include <iostream>
using namespace std;

// 306 ҳ ��4��
//����һ����������,�ڷ�5��ѧ��������
//��ָ��ָ��������Ԫ��,���135��ѧ��������
class Student
{
public:
	Student(int n,float s):num(n),score(s){}
	void display()
	{
		cout << num << " " << score << endl;
	}
private:
	int num;
	float score;
};
int main()
{
	Student s[5] = {Student(11,91),Student(22,92),
		Student(33,93),Student(44,94),Student(55,95)
	};
	Student *ps  = s;

	for (int i = 0; i < 3; ++i)
	{
		ps->display();
		ps = ps + 2;
	}

	system("pause");
	return 0;
}