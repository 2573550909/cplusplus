#include <iostream>
#include <algorithm>
#include <stdlib.h>
using namespace std;

//��ӡ100 -200 ֮�������
void print() {
	for (int i = 100; i <= 200; ++i) {
		bool flag = true;
		for (int j = 2; j < i / 2; ++j) {
			if (i % j == 0) {
				flag = false;
			}
		}
		if (flag) {
			printf("%d ", i);
		}
	}
	printf("\n");
}

//����˷��ھ���
void mult_pintf() {
	printf("������˷��ھ��������\n");
	int num = 0;
	cin >> num;
	for (int i = 1; i <= num; ++i) {
		for (int j = 1; j <= i; ++j) {
			printf("%d*%d==%2d ", j, i, i*j);
		}
		printf("\n");
	}
}

//�ж�1000��---2000��֮�������
void print_year() {
	int year = 1000;
	printf("������������Ե����\n");
	while (cin >> year) {
		if (year % 400 == 0 || ((year % 4 == 0) && year % 100 !=0)){
			printf("%d ������", year);
		}
		else {
			printf("%d ��������", year);
		}
		printf("\n");
	}
	printf("\n");
}

//�����������α�����ֵ
void swap_temp(int* a1,int* a2) {
	int temp = *a1;
	*a1 = *a2;
	*a2 = temp;
}

void swap(int* a1,int* a2) {
	*a1 = *a1 + *a2;
	*a2 = *a1 - *a2;
	*a1 = *a1 - *a2;
}

void test() {
	int a = 10;
	int b = 20;
	printf("a=%d  ",a);
	printf("b=%d\n",b);
	swap(&a,&b);
	printf("a=%d  ",a);
	printf("b=%d\n",b);
}

//3.��10 �����������ֵ�� 
#include <vector>
void int_max() {
	vector<int>vec(10);
	for (int i = 0; i < 10; ++i) {
		cin >> vec[i];
	}
	int max = 0;
	for (int i = 0; i < 10; ++i) {
		if (max < vec[i]) {
			max = vec[i];
		}
	}
	printf("�������� %d\n", max);
}
//4.�����������Ӵ�С�����
bool cmp(int a, int b) {
	return a > b;
}

bool cmp_dec(int a, int b) {
	return a < b;
}

void Greet_num() {
	vector<int>vec(10);
	for (int i = 0; i < 10; ++i) {
		vec[i] = i;
	}

	sort(vec.begin(),vec.end(),cmp_dec);
	for (int i = 0; i < 10; ++i) {
		cout << vec[i]<<" ";
	}
	cout << endl;
	sort(vec.begin(),vec.end(),cmp);
	for (int i = 0; i < 10; ++i) {
		cout << vec[i]<<" ";
	}
	cout << endl;

}

//5.�������������Լ����
void max_yueshu() {
	int a = 1;
	int b = 1;
	printf("������������\n");
	while (cin >> a >> b) {
		int Max = max(a, b);
		int Min = min(a, b);
		for (int i = Min; i > 1; --i) {
			if (Max % i == 0 && Min % i == 0) {
				printf("���Լ���� %d\n", i);
				break;
			}
		}
	}
}

//������A�е����ݺ�����B�е����ݽ��н�����������һ����
void array_swap() {
	vector<int>a(11);
	vector<int>b(11);
	for (int i = 0; i < 10; ++i) {
		a[i] = i;
	}
	for (int i = 10; i > 0; --i) {
		b[i] = i;
	}

	cout << "a�����е�Ԫ��" << endl;
	for (int i = 0; i < 10; ++i) {
		cout << a[i]<<" ";
	}
	cout << "b�����е�Ԫ��" << endl;
	for (int i = 10; i > 0; --i) {
		cout << b[i]<<" ";
	}
	for (int i = 0; i < 10; ++i) {
		int temp = a[i];
		a[i] = b[i];
		b[i] = temp;
	}
	cout << "a�����е�Ԫ��" << endl;
	for (int i = 0; i < 10; ++i) {
		cout << a[i]<<" ";
	}
	cout << "b�����е�Ԫ��" << endl;
	for (int i = 0; i < 0; ++i) {
		cout << b[i]<<" ";
	}
	cout << endl;
}
//2. ����1 / 1 - 1 / 2 + 1 / 3 - 1 / 4 + 1 / 5 ���� + 1 / 99 - 1 / 100 ��ֵ��
void calc() {
	int j = 1;
	int result = 0;
	for (int i = 1; i < 100; ++i) {
		if (i % 2 == 0) {
			result -= j / i;
		}
		else {
			result += j / i;
		}
	}
	cout << result << endl;
}

//3. ��д������һ�� 1�� 100 �����������г��ֶ��ٴ�����9��
void calc_count() {
	int count = 0;
	for (int i = 0; i < 100; ++i) {
		if (i % 9 == 0 || i / 9 == 0) {
			++count;
		}
	}
	cout << count << endl;
}

// ��ӡһ��* �ŵ�ͼ��
void print_xin() {
	for (int i = 1; i <= 11; i+=2){
		for (int j = 0; j < i; ++j) {
			printf("*");
		}
		cout << endl;
	}
	for (int i = 9; i >= 1; i-=2){
		for (int j = 0; j < i; ++j) {
			printf("*");
		}
		cout << endl;
	}
}

//2.���0��999֮������С�ˮ�ɻ������������
//��ˮ�ɻ�������ָһ����λ�������λ���ֵ�������ȷ�õ��ڸ�������
//	�磻153��1��5��3 ? ����153��һ����ˮ�ɻ�������

/*
�������У�ˮ�ɻ�����Narcissistic number��Ҳ��Ϊ������������������ķ˹׳����ķ˹��������Armstrong number������ָһNλ�����������֮N�η��͵��ڸ�����
����153��370��371��407������λ����ˮ�ɻ������������֮�����͵��ڸ�����
153 = 1^3 + 5^3 + 3^3��
370 = 3^3 + 7^3 + 0^3��
371 = 3^3 + 7^3 + 1^3��
407 = 4^3 + 0^3 + 7^3��
*/
void printWater() {
	for (int i = 0; i <= 999; ++i) {
		int a1 = i % 10;
		int a2 = i / 10 % 10;
		int a3 = i / 10 / 10 % 10;
		if (a1*a1*a1 + a2 * a2*a2 + a3 * a3*a3 == i) {
			printf("%d ��һ��ˮ�ɻ���\n",i);
			printf("%d = %d^3 + %d^3 + %d^3\n", i, a3, a2, a1);
		}
	}
}

//��Sn = a + aa + aaa + aaaa + aaaaa��ǰ5��֮�ͣ�����a��һ�����֣�
//���磺2 + 22 + 222 + 2222 + 22222

//����һ�����飬
//ʵ�ֺ���init������ʼ�����顢
//ʵ��empty����������顢
//ʵ��reverse���������������Ԫ�ص����á�
//Ҫ���Լ���ƺ����Ĳ���������ֵ��

int main() {
	int result = 0;
	int a = 0;
	cout << "������ a ���ֵ�ֵ" << endl;
	cin >> a;
	int an = 0;
	for (int i = 1; i <= 5; ++i) {
		an = an * 10 + a;
		result += an;
	}
	cout << result << endl;

	system("pause");
	return 0;
}

