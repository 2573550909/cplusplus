#include <iostream>
#include <algorithm>
#include <stdlib.h>
using namespace std;

#if 1
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

void init(int* arr) {
	for(int i = 0;i < 10;++i)
		arr[i] = 0;
}
void reverse(int* arr) {
	for (int i = 9; i > 0; --i)
		arr[i] = 0;
}
void create() {
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


	int array[10];
	init(array);
	reverse(array);
}


//1.�ݹ�ͷǵݹ�ֱ�ʵ�����n��쳲���������
int FeiBo(int n) {
	if (n == 1) {
		return 1;
	}
	if (n == 2) {
		return 1;
	}
	return FeiBo(n - 1) + FeiBo(n - 2);
}

int FeiBoNor(int n) {
	int first = 1;
	int second = 1;
	int last = 2;
	for (int i = 3; i < n; ++i) {
		first = second;
		second = last;
		last = first + second;
	}
	return last;
}
void test() {
	cout << FeiBo(12) << endl;
	cout << FeiBoNor(12) << endl;
}
//2.��дһ������ʵ��n^k��ʹ�õݹ�ʵ��
int zhishu(int n,int k) {
	if (k == 1) {
		return n;
	}
	else {
		return n * zhishu(n, k - 1);
	}
}

int zhishuNor(int n, int k) {
	int result = 1;
	for (int i = 0; i < k; ++i) {
		result = result * n;
	}
	return result;
}
void test() {
	int n = 2;
	int k = 10;
	cout << zhishu(n, k) << endl;
	cout << zhishuNor(n, k) << endl;
}

//3. дһ���ݹ麯��DigitSum(n)������һ���Ǹ����������������������֮�ͣ�
//���磬����DigitSum(1729)����Ӧ�÷���1 + 7 + 2 + 9�����ĺ���19
int DigitSum(int n) {
	if (n < 10) {
		return n;
	}
	return DigitSum(n / 10) + (n%10);
}

int DigitSumNor(int n) {
	int res = n % 10;
	while (n) {
		n = n / 10;
		res += n % 10;
	}
	return res;
}

void test() {
	int a = 1729;
	cout << DigitSum(a) << endl;
	cout << DigitSumNor(a) << endl;
}
//4. ��дһ������ reverse_string(char * string)���ݹ�ʵ�֣�
//ʵ�֣��������ַ����е��ַ��������С�
//Ҫ�󣺲���ʹ��C�������е��ַ�������������
char* reverse_string(char*string) {
	char* q = string;
	int n = strlen(string);
	if (n > 1) {
		char tmp = q[0];
		q[0] = q[n - 1];
		q[n - 1] = '\0';
		reverse_string(string + 1);
		q[n - 1] = tmp;
	}
	return q;
}
void test() {
	char str[] = "hehemaze";
	printf("%s\n", str);
	char* ret = reverse_string(str);
	printf("%s\n", ret);
}
//5.�ݹ�ͷǵݹ�ֱ�ʵ��strlen
int Strlen(char* string ) {
	int count = 0;
	while (*string != '\0') {
		string++;
		count++;
	}
	return count;
}
int strlenNor(char* str) {
	if (*str == '\0') {
		return 0;
	}
	return 1 + strlenNor(str + 1);
}
void test() {
	char str[] = "hehehe";
	cout << Strlen(str) << endl;
	cout << strlenNor(str) << endl;
}
//6.�ݹ�ͷǵݹ�ֱ�ʵ����n�Ľ׳�
int jiechen(int n) {
	if (n == 1) {
		return 1;
	}
	return n * jiechen(n - 1);
}
int jiechengxunhuan(int n) {
	int result = 1;
	for (int i = 1; i <= n; ++i) {
		result *= i;
	}
	return result;
}
void test() {
	cout<<jiechen(5);
	cout << endl;
	cout << jiechengxunhuan(5) << endl;
}
//7.�ݹ鷽ʽʵ�ִ�ӡһ��������ÿһλ
void print(int n) {
	if (n > 9) {
		print(n / 10);
	}
	printf("%d ", n % 10);
}
void Print(int n) {
	if (n < 10) {
		printf("%d ", n);
	}
	else {
		Print(n / 10);
		printf("%d ", n % 10);
	}
}

void test() {
	print(1729);
	printf("\n");
	Print(1729);
	printf("\n");
}

#endif
/*
1.
5λ�˶�Ա�μ���10��̨��ˮ����������������Ԥ��������
Aѡ��˵��B�ڶ����ҵ�����
Bѡ��˵���ҵڶ���E���ģ�
Cѡ��˵���ҵ�һ��D�ڶ���
Dѡ��˵��C����ҵ�����
Eѡ��˵���ҵ��ģ�A��һ��
����������ÿλѡ�ֶ�˵����һ�룬����ȷ�����������Ρ�
*/
int partion() {
	for (int);
}
/*
2.
�ձ�ĳ�ط�����һ��ıɱ��������ͨ���Ų�ȷ��ɱ�����ֱ�Ϊ4��
���ɷ���һ��������Ϊ4�����ɷ��Ĺ��ʡ�
A˵�������ҡ�
B˵����C��
C˵����D��
D˵��C�ں�˵
��֪3����˵���滰��1����˵���Ǽٻ���
�����������Щ��Ϣ��дһ��������ȷ������˭�����֡�
*/
void mudder() {
	char muder = 'A';
	for (muder = 'A'; muder < 'D'; ++muder) {
		if ((muder != 'A') + (muder == 'C') + (muder == 'D') + (muder != 'D') == 3) {
			printf("������ %c\n", muder);
		}
	}
}
void test() {
	mudder();
}
/*
3.����Ļ�ϴ�ӡ������ǡ�
1
1 1
1 2 1
1 3 3 1

*/
int main() {
	test();
	system("pause");
	return 0;
}