#include <iostream>
#include <cstdio>

// ���� ��-��-�� ͨ�����չ�ʽ���㵱ǰ���ڼ�
// 1: ����һ ... 7: ������
int day_of_week(int year, int month, int day){
	if (month == 1 || month == 2){
		month += 12;
		year -= 1;
	}
	
	int century = year / 100;
	year %= 100;
	int week = year + (year / 4) + (century / 4) - 2 * century + 
		26 * (month + 1) / 10 + day -1;

	week = (week % 7 + 7) % 7;
	if (week == 0){
		week = 7;
	}
	return week;
}

int day_of_demand(int year, int month, int count, int d_of_week){
	int week = day_of_week(year, month, 1);
	//���1��������
	// 1 + 7(n - 1) + (���������� + 7 - 1��������) % 7

	int day = 1 + (count - 1) * 7 + (7 + d_of_week - week) % 7;
	return day;
}

// Ԫ��
void new_year_day(int year){
	printf("%d-01-01\n", year);
}

// ����·�¡�������գ�1�µĵ���������һ��
void martin_luther_king_day(int year){
	printf("%d-01-%02d\n", year, day_of_demand(year, 1, 3, 1));
}

// ��ͳ�գ�2�µĵ���������һ��
void president_day(int year){
	printf("%d-02-%02d\n", year, day_of_demand(year, 2, 3, 1));
}

// ������ʿ�����գ�5�µ����һ������һ��
void memorial_day(int year){
	// �� 6 ����ǰ��
	int week = day_of_week(year, 6, 1);
	// ����һ�Ļ����� 31 ����ǰ�� 6 �죬������ week - 2 ��
	int day = 31 - ((week == 1) ? 6 : (week - 2));
	printf("%d-05-%02d\n", year, day);
}

// ����
void independence_day(int year){
	printf("%d-07-04\n", year);
}

// �Ͷ��ڣ�9�µĵ�һ������һ��
void labor_day(int year){
	printf("%d-09-%02d\n", year, day_of_demand(year, 9, 1, 1));
}

// �ж��ڣ�11�µĵ��ĸ������ģ�
void thanks_giving_day(int year){
	printf("%d-11-%02d\n", year, day_of_demand(year, 11, 4, 4));
}

// ʥ����
void christmas(int year){
	printf("%d-12-25\n", year);
}

// ��������
void holiday_of_usa(int year){
	new_year_day(year);
	martin_luther_king_day(year);
	president_day(year);
	memorial_day(year);
	independence_day(year);
	labor_day(year);
	thanks_giving_day(year);
	christmas(year);
}

int main(){
	int year;
	while (std::cin >> year){
		holiday_of_usa(year);
		putchar('\n');
	}
}
#include <cstdio>
#include <cmath>
#include <iostream>
int main(){
	unsigned int n;
	while (std::cin >> n){
		printf("%d =", n); 
		���90 =
		for (unsigned i = 2; i <= std::sqrt(n); i++){
			������ͬһ������ֱ�����������ų��պ��Ǹ�����n�η������
			while (n % i == 0 && n != i) {
				��һ�δ�ӡ 2 *,�ڶ��δ�ӡ���� 3 *
				printf(" %u *", i); 
				n /= i; //���������޸�n��ֵ
			}
		}
		������n�Ѿ��Ǵ������һ���������������һ����������5
		printf(" %d\n", n); 
	}
	return 0;
}

#include <iostream>
#include <stdlib.h>
#include <string>
using namespace std;

int main() {
	int n = 0;
	int k = 1;
	while (cin>>n) {
		for (int i = 2; i < sqrt(n); ++i) {
			if ((n % i) == 0) {
				while ((n%i) == 0) {
					n /= i;
				}
				++k;
			}
		}
		if (n != 1) {
			++k;
		}
		cout << k << endl;
	}

	return 0;
}

#include <stdio.h>
int main() {
	char c;
	while ((c = getchar()) != EOF) {
		if ('A' <= c && 'Z' >= c) {
			c = (c > 'E') ? (c - 5) : (c + 21);
		}
		putchar(c);
	}
	return 0;
}
int main() {
	int n;
	while (cin >> n) {
		int first = 1;
		int second = 1;
		int sum = 1;
		while (n) {
			if (n == 1 || n == 2) {
				break;
			}
			sum = first + second;
			first = second;
			second = sum;
			n--;
		}
		cout << sum << endl;
	}
	return 0;
}
class TimeKeeper {
public:
	TimeKeeper();
	virtual ~TimeKeeper();
};
class AtomicClock:public TimeKeeper{};
class WatchClock:public TimeKeeper{};
class WristClock:public TimeKeeper{};

TimeKeeper* ptk = getTimeKeeper();

delete ptk;
//

template<class T>
class NameObject {
public:
	NameObject(string& name, const T& value);
private:
	string& nameValue;
	const T objectValue;
};

int main() {
	string newDog("Persephone");
	string oldDog("stach");

	NameObject<int> p(newDog, 2);
	NameObject<int> s(oldDog, 36); 


	//p =s;
	return 0;
}

int digui(int num) {
	int first = 1;
	int second = 1;
	int sum = 2;
	num -= 2;
	while (num--) {
		sum = first + second;
		first = second;
		second = sum;
	}
	return sum;
}

int main() {
	int from = 0;
	int to = 0;
	int ret = 0;
	while (cin >> from, cin >> to) {
	int sums = 0;
		for (int i = from; i < to + 1; ++i) {
			ret = digui(i);
			sums += ret;
		}

		cout << sums << endl;
	}
	return 0;
}
int FeiBoNa(int num) {


	int first = 1;
	int second = 1;
	int sum = 2;
	num -= 2;
	while (num--) {
		sum = first + second;
		first = second;
		second = sum;
	}
	return sum;
}

int main() {
	int number = 0;
	while (cin >> number) {
		int n = FeiBoNa(number);
		cout << n << endl;
	}

	system("pause");
	return 0;
}



class TextBlock {
public:
	TextBlock(const char* str = "") {
		text = str;
	}

	const char& operator[](size_t position)const {
		return text[position];
	}

	char& operator[](size_t position){
		return text[position];
	}

private:
	string text;
};

int main() {
	
	TextBlock tb("hello");
	cout << tb[0] << endl;

	return 0;
}