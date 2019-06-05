#include <iostream>
using namespace std;

int perfect(int m)
{
	int sum = 0;
	for (int i = 1; i < m; ++i) {
		if (m%i == 0) {
			sum += i;
		}
	}
	if (sum == m) {
		return 1;
	}
	else {
		return 0;
	}
}

void count(int n)
{
	int num = 0;
	for (int i = 3; i < n + 1; ++i) {
		if (perfect(i) == 1) {
			++num;
		}
	}
	if (num != 0) {
		cout << num;
	}
	else {
		cout << -1;
	}
}

int main()
{
	int N = 0;
	while (cin >> N) {
		count(N);
	}

	return 0;
}
#include<iostream>
#include<algorithm>
using namespace std;
�ж�����
bool isPrime(int num){
	int tmp = sqrt(num);
	ֻ�����������������ܱ�������ߵ�����������һ�����ܱ������ұߵ�������
	for (int i = 2; i <= tmp; i++){
		if (num %i == 0)
			return false;
	}
	return true;
}
int main()
{
	int num;
	int half;
	int i;
	while (cin >> num){
		half = num / 2;
		���м���������
		for (i = half; i > 0; i--){
			if (isPrime(i) && isPrime(num - i))
				break;
		}
		cout << i << endl << num - i << endl;
	}
	return 0;
}

#include < iostream>
using namespace std;

void func(const int& v1, const int& v2)
{
	cout << "v1��ַ"<<&v1 << endl;
	cout << "v2��ַ"<<&v2 << endl;
	std::cout<<"v1 = " << v1 << ' ';
	std::cout << "v2 = "<< v2 << ' ';
}

int main(int argc, char* argv[])
{
	int i = 0;
	func(++i, i++);
	return 0;
}

struct st_task
{
	uint16_t id;
	uint32_t value;
	uint64_t timestamp;
};

void fool()
{
	st_task task = {};
	uint64_t a = 0x00010001;
	memcpy(&task, &a, sizeof(uint64_t));
	printf("%11u,%11u,%11u", task.id, task.value, task.timestamp);
}

��Ϊ�ֽڶ����ԭ������idռ��4���ֽڣ�value��timestamp�ֱ���4���ֽڡ�8���ֽڡ�
��Ȼidռ���ĸ��ֽڵĵ�ַ������ֻ�е���λ��ַ����ֵ��Ч
���ֽڶ���Ļ��ƣ���value�洢ʱ�ĵ�ַ��4���������ֵ������ӦΪ0����
����idΪ 0001 0001������λ��Ч������Ϊ0001��value��timestamp�ֱ�Ϊ0.
���磺��ַ��0x0000��ʼ��id�洢��ַ����Ϊ0x0000 - 0x0001��
��value�洢��ַҪ��0x0004��ʼ����Ϊ0x0004 % 4 == 0��
����id�洢��ַΪ0x0000 - 0x0003, value�洢��ַΪ0x0004 - 0x0007, 
timestamp�洢��ַΪ0x0008 - 0x000F.
����id == 0x00010001��ȥ����4λ��id = 0x0001������Ϊ0.

int main()
{
	fool();

	system("pause");
	return 0;
}

#define SQR(A) A*A

int main() {
	int x = 6, y = 3, z = 2;
	x /= SQR(y + z) / SQR(y + z);
	x = 5 * 5 / 5 * 5;
	cout << x << endl;
	system("pause");
}

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int c = 0;
void move(char x, int n, char z){
	��n��Բ�̴�����x�ᵽ����z
	printf("��%-2d������%d���̴�%c�Ƶ�%c\n", ++c, n, x, z);
}

void hanoi(int n, char x, char y, char z){
	if (n == 1){
		move(x, 1, z);
	}else{
		/*���nΪ��������ֱ�Ӱ�1�����Ƶ�z��λ��
		�������nΪż�������Ȱ�1�����Ƶ�y��λ��
		������Ҫ�����βε�λ��,��� n ��������
		�������ֽ�����ȥ�ˣ��൱��û�н���*/
		hanoi(n - 1, x, z, y);
		move(x, n, z);

		/*����x �� y ��λ�ã���Ϊִ�е��ⲽ֮ǰ
		���Ѿ���xλ�õ�����ȫ���Ƶ�y���ˣ����Ե�
		����һ��x y λ�ã���y λ�õ������Ƶ�zλ�� */
		hanoi(n - 1, y, x, z);
	}
}

int main(){
	int n = 0;
	printf("����Բ������\n");
	scanf("%d", &n);
	hanoi(n, 'a', 'b', 'c');

	system("pause");
	return 0;
}

