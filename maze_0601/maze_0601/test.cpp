#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>

����һ�������ľ��������̣������һ����Ч�㷨�жϵ�ǰ����Ƿ��ʤ��
����һ����ά����board������ǰ����
����Ԫ��Ϊ 1 �Ĵ����ǵ�ǰ��ҵ����ӣ�Ϊ 0 ��ʾû�����ӣ�
Ϊ -1 �����ǶԷ���ҵ����ӡ�
����������

class Board {
public:
	bool checkWon(vector<vector<int>> board) {
		 write code here
		int row = board.size();
		int sum = 0;
		int i = 0;
		int j = 0;
		for (i = 0; i < row; ++i)
		{
			for (j = 0; j < row; ++j)
			{
				sum += board[i][j];
			}
			if (sum == row) {
				return true;
			}
		}

		sum = 0;
		for (i = 0; i < row; ++i)
		{
			for (j = 0; j < row; ++j)
			{
				sum += board[j][i];
			}
			if (sum == board) {
				return true;
			}
		}

		sum = 0;
		for (i = 0; i < row; ++i)
		{
			sum += board[i][i];
		}
		if (sum == row) {
			return true;
		}

		sum = 0;
		for (i = 0; i < row; ++i)
		{
			sum += board[i][row - i - 1];
		}
		if (row == sum)
		{
			return true;
		}
		return false;
	}
};


#include<iostream>
#include<string>
using namespace std;

int numChar(string str, int k)
{
	����ASCII���ж���ĸ��Сд
	int small = 0;
	int big = 0;
	for (int i = 0; i < k; i++){
		if (str[i] >= 65 && str[i] <= 90){
			big++;
		}
		else if (str[i] >= 97 && str[i] <= 122) {
			small++;
		}
	}
	if ((small + big) == 0) {
		return 0;
	}
	else if (small == k || big == k) {
		return 10;
	}
	else if (small > 0 && big > 0) {
		return 20;
	}

	return 0;
}

int numNumber(string str, int k)
{
	����ASCII���ж����ָ�������ȥ�ַ���0��֮����0~9֮��ļ�Ϊ����
	int num = 0;
	for (int i = 0; i < k; i++){
		if (str[i] - '0' >= 0 && str[i] - '0' <= 9) {
			num++;
		}
	}
	if (num == 0){
		return 0;
	}
	else if (num == 1) {
		return 10;
	}
	else {return 20;}
}

int numSymbal(string str, int k)
{
	int num = 0;
	for (int i = 0; i < k; i++){
		��ȥ��ĸ�����֣�������Ϊ����
		if (!(str[i] >= 65 && str[i] <= 90)
			&& !(str[i] >= 97 && str[i] <= 122)
			&& !(str[i] - '0' >= 0 && str[i] - '0' <= 9))
			num++;
	}
	if (num == 0) {
		return 0;
	}
	else if (num == 1) {
		return 10;
	}
	else{return 25;}
}
int main()
{
	string str;
	while (cin >> str)
	{
		int sum1 = 0, sum2 = 0, sum3 = 0, sum4 = 0, sum5 = 0;
		int k = str.size();
		if (k <= 4)
			sum1 = 5;
		else if (k >= 8)
			sum1 = 25;
		else
			sum1 = 10;

		sum2 = numChar(str, k);
		sum3 = numNumber(str, k);
		sum4 = numSymbal(str, k);
		if ((sum2 > 0) && (sum3 > 0) && (sum4 > 0))
		{
			if (sum2 == 10)
				sum5 = 3;
			else
				sum5 = 5;
		}
		else if (sum2 > 0 && sum3 > 0 && sum4 == 0)
			sum5 = 2;
		if (sum1 + sum2 + sum3 + sum4 + sum5 >= 90)
			cout << "VERY_SECURE" << endl;
		else if (sum1 + sum2 + sum3 + sum4 + sum5 >= 80)
			cout << "SECURE" << endl;
		else if (sum1 + sum2 + sum3 + sum4 + sum5 >= 70)
			cout << "VERY_STRONG" << endl;
		else if (sum1 + sum2 + sum3 + sum4 + sum5 >= 60)
			cout << "STRONG" << endl;
		else if (sum1 + sum2 + sum3 + sum4 + sum5 >= 50)
			cout << "AVERAGE" << endl;
		else if (sum1 + sum2 + sum3 + sum4 + sum5 >= 25)
			cout << "WEAK" << endl;
		else
			cout << "VERY_WEAK" << endl;
	}
	return 0;
}

#define N 9

int x[N];
int count = 0;

void dump() {
	int i = 0;
	for (i = 0; i < N; i++) {
		printf("%d", x[i]);
	}
	printf("\n");
}
void swap(int a, int b) {
	int t = x[a];
	x[a] = x[b];
	x[b] = t;
}

void run(int n) {
	int i;
	if (N - 1 == n) {
		dump();
		count++;
		return;
	}
	for (i = n; i < N; i++) {
		swap(n, i);
		run(n + 1);
		swap(n, i);
	}
}

int main() {
	int i;
	for (i = 0; i < N; i++) {
		x[i] = i + 1;
	}
	run(0);
	printf("* Total: %d\n", count);

	system("pause");
	return 0;
}

#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int func(int x) {
	int count = 0;
	while (x)
	{
		count++;
		x = x & (x - 1);//������
		0010 0111 0000 1111
		0010 0111 0000 1110
	}
	return count;
}

int main()
{
	int ret = func(999);
	cout << ret << endl;

	system("pause");
	return 0;
}

int main()
{
	int n;
	while (cin >> n){
		int count = 0, maxCount = 0;
		 n����32�ξͱ�Ϊ0
		while (n){
			��ȡ��ǰλ�Ķ�����ֵ
			if (n & 1){
				���1��ֵ�����������ۼӣ����Ҹ���������
				++count;
				maxCount = max(count, maxCount);
			}
			else{
				���1��ֵ�������������ۼ�
				count = 0;
			}
			����һ�Σ�Ϊ��ȡ��һλ������ֵ��׼��
			n = n >> 1;
		}
		cout << maxCount << endl;
	}
	return 0;
}

#include <iostream>
#include <string>
using namespace std;
int main()
{
	string str;
	while (getline(cin, str))
	{
		int count = 0;
		 ���ȼ����������
		for (int i = 0; i < str.size(); i++)
		{
			if (str[i] == ' ')
				count++;
			 �����˫���ţ���������ֱ����һ��˫���Ž���
			if (str[i] == '"')
			{
				do
				{
					i++;
				} while (str[i] != '"');
			}
		}
		 �Կո����������ո������Ȳ��������� 1
		cout << count + 1 << endl;
		 �� flag ��ʾ�Ƿ����˫���ţ� 0 ��ʾ��˫����
		 ˫�����еĿո�Ҫ��ӡ����
		 �����ı� flag ��ֵ������˫���ſ���ʹ flag ��ԭ
		int flag = 1;
		for (int i = 0; i < str.size(); i++)
		{
			��˫���ţ�flagͨ������Ϊ0����һ��������˫���ţ�flag��Ϊ1
			if (str[i] == '"')
				flag ^= 1;
			 ˫���ź���ͨ�ո񲻴�ӡ
			if (str[i] != ' ' && str[i] != '"')
				cout << str[i];
			 ˫�����еĿո�Ҫ��ӡ
			if (str[i] == ' ' && (!flag))
				cout << str[i];
			 ����˫����֮��Ŀո�ͻ���
			if (str[i] == ' ' && flag)
				cout << endl;
		}
		cout << endl;
	}
	return 0;
}