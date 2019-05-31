#include <iostream>
#include <stdlib.h>
#include <math.h>
using namespace std;

int isSuShu(int n){
	for (int i = 2; i < sqrt(n)+1; ++i){
		if (n%i == 0){
			return 0;
		}
	}
	return 1;
}

int main()
{
	int n;
	while (cin >> n)
	{
		int N = n / 2;
		int small = N;
		int big = N;

		while (big != n) {
			while (isSuShu(big) != 1 && big < n) {
				++big;
			}

			small = N;
			while (small > 1) {
				if ((isSuShu(small) == 1) && small + big == n) {
					break;
				}
				else { --small; }
			}

			if (small + big == n) {
				break;
			}
			else { ++big; }
		}

		cout << small << endl;
		cout << big << endl;
	}
	system("pause");
	return 0;
}

#include <iostream>
#include <stdlib.h>
using namespace std;

class Date
{
public:
	Date(int year)
		:_year(year)
	{}
	//	explicit Date(int year)
	//	:_year(year)
	//{}
private:
	int _year;
	int _month;
	int _day;
};

void TestDate()
{
	Date d1(2018);

	// ��һ�����α������������Ͷ���ֵ
	// ʵ�ʱ������������2019����һ������������������������d1������и�ֵ
	d1 = 2019;
}


int main()
{
	TestDate();

	system("pause");
	return 0;
}

���ؿƼ�
��������ɶ��Բ��Ǻܺã���explicit���ι��캯����
�����ֹ���ι��캯������ʽת����

2. static��Ա
����Ϊstatic�����Ա��Ϊ��ľ�̬��Ա����static���εĳ�Ա��������֮Ϊ��̬��Ա��������static���ε�
��Ա��������֮Ϊ��̬��Ա��������̬�ĳ�Ա����һ��Ҫ��������г�ʼ��
�����⣺ʵ��һ���࣬�����г����д������˶��ٸ������

1. ��̬��ԱΪ���������������������ĳ�������ʵ��
