#include <iostream>
#include <stdlib.h>
using namespace std;

//307 ҳ12��
//��9.14��дΪ��ģ���ⶨ��ĸ���Ա����
template <class numtype>//������ģ��,������������numtype
class Compare//��ģ������ΪCompare
{
public:
	Compare(numtype a, numtype b)
	{
		x = a;
		y = b;
	}
	numtype max();
	numtype min();
private:
	numtype x, y;
};

template <class numtype>
numtype Compare <numtype>::min()
{
	return x < y ? x : y;
}



int main()
{
	Compare<int>cam(3, 7);
	cout << cam.max() << endl;

	//һ����ʽΪ����ģ���� <ʵ��������> ��������������
	system("puase");
	return 0;
}