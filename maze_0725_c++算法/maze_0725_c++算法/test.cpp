#if 1
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <stdlib.h>
#include <algorithm>
#include <cstdio>
using namespace std;

#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n = 20;
	int m = 20;
	vector<vector<char>>v(m, vector<char>(n, '.'));
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> v[i][j];
		}
		cout << endl;
	}

	int flag = 0;
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			if (v[i][j] == '*' && v[i][j + 1] == '*' && v[i][j + 2] == '*'
				&& v[i][j + 3] == '*'&& v[i][j + 4] == '*' && (j + 4) < n) {
				cout << "Yes" << endl;
				flag = 1;
				return 0;
			}

			if (v[i][j] == '+' && v[i][j + 1] == '+' && v[i][j + 2] == '+'
				&& v[i][j + 3] == '+'&& v[i][j + 4] == '+' && (j + 4) < n) {
				cout << "Yes" << endl;
				flag = 1;
				return 0;
			}
			if (v[i][j] == '+' && v[i + 1][j] == '+' && v[i + 2][j] == '+'
				&& v[i + 3][j] == '+'&& v[i + 4][j] == '+' && (i + 4) < m) {
				cout << "Yes" << endl;
				flag = 1;
				return 0;
			}
			if (v[i][j] == '*' && v[i + 1][j] == '*' && v[i + 2][j] == '*'
				&& v[i + 3][j] == '*'&& v[i + 4][j] == '*' && (i + 4) < m) {
				cout << "Yes" << endl;
				flag = 1;
				return 0;
			}

			if (v[i][j] == '*' && v[i + 1][j + 1] == '*'  && v[i + 2][j + 2] == '*'
				&& v[i + 3][j + 3] == '*' && v[i + 4][j + 4] == '*' && (i + 4) < m && (j + 4) < n) {
				cout << "Yes" << endl;
				flag = 1;
				return 0;
			}
			if (v[i][j] == '+' && v[i + 1][j + 1] == '+'  && v[i + 2][j + 2] == '+'
				&& v[i + 3][j + 3] == '+' && v[i + 4][j + 4] == '+' && (i + 4) < m && (j + 4) < n) {
				cout << "Yes" << endl;
				flag = 1;
				return 0;
			}
			if (v[i][j] == '+' && v[i - 1][j - 1] == '+'  && v[i - 2][j - 2] == '+'
				&& v[i - 3][j - 3] == '+' && v[i - 4][j - 4] == '+' && (i - 4) > 0 && (j - 4) > 0){
				cout << "Yes" << endl;
				flag = 1;
				return 0;
			}

			if (v[i][j] == '*' && v[i - 1][j - 1] == '*'  && v[i - 2][j - 2] == '*'
				&& v[i - 3][j - 3] == '*' && v[i - 4][j - 4] == '*' && (i - 4) > 0 && (j - 4) > 0) {
				cout << "Yes" << endl;
				flag = 1;
				return 0;
			}
		}
	}
	if (flag == 0) {
		cout << "No" << endl;
	}
	return 0;
}
int main() {

	int a[5] = { 1,2,3,20,3 };
	int v[5] = { 24,1,1000,100,500 };
	int m = 8;
	vector<int>A(a, a + 5);
	vector<int>V(v, v + 5);
	if (A.empty() || V.empty() || m < 1) {
		return 0;
	}

	const int N = A.size();
	//���һ�У��������ó�ʼ��������Ϊ��һ����ƷҪ�õ�ǰ��ĳ�ʼֵ
	const int M = m + 1;
	vector<int> result;
	//��ʼ������λ��Ϊ0����һ�ж�Ϊ0����ʼ����
	result.resize(M, 0);
	//������Ʒ������λ�ò���Ҫƫ�ƣ�Ҫ��δ�Ż��ķ������ֿ�
	//�����i-1���Ϊ��һ�У�����δ���µ�һά����ֵ
	for (int i = 0; i != N; ++i) {
		for (int j = M - 1; j > 0; --j) {
			//�����i����Ʒ����j,˵���Ų��£� 
			//����(i,j)������ֵ��(i-1,j)��ͬ
			if (A[i] > j) {
				result[j] = result[j];
			}
			//�������װ�£������������װ���߲�װ
			//�����װ����Ϊ(i-1, j)
			//���װ����Ҫ�ڳ��ŵ�i����Ʒ��С�Ŀռ䣺j - A[i],
			//װ��֮�������ֵ(i - 1, j-A[i - 1])+ ��i����Ʒ�ļ�ֵV[i]
			//�����װ�벻װ��ѡ�����ļ�ֵ
			else {
				int newValue = result[j - A[i]] + V[i];
				result[j] = max(newValue, result[j]);
			}
		}
	}
	//����װ��ǰN����Ʒ����Ʒ��СΪm������ֵ
	cout << result[m] << endl;
	return 0;
}

int main() {
	long long d[20] = { 0,0,1 };
	for (int i = 3; i < 20; ++i) {
		d[i] = (i - 1)*(d[i - 1] + d[i - 2]);
	}

	int n = 0;
	while (cin >> n) {
		cout << d[n] << endl;
	}

	system("pause");
	return 0;
}

#include<stdio.h>

int main(void){
	long long der[21] = { 0, 0, 1 };
	int i;
	for (i = 3; i < 21; i++) {
		der[i] = (i - 1) * (der[i - 2] + der[i - 1]);
	}

	int n;
	while (scanf("%d", &n) != EOF) {
		printf("%lld\n", der[n]);
	}
	return 0;
}

int main() {
	int n;
	while (cin >> n) {
		//����ĳ�ʼ���붨��
		vector<int> height(n, 0);
		for (int i = 0; i < n; i++) {
			cin >> height[i];
		}

		vector<int> f(n, 1);
		int result = 1;
		for (int i = 1; i < n; i++) {
			for (int j = 0; j < i; j++) {
				if (height[i] > height[j]) {
					f[i] = max(f[i], f[j] + 1);
				}
			}
			result = max(result, f[i]);
		}
		cout << result << endl;
	}
}

#endif

#include <iostream>
#include <stack>
#include <stdlib.h>
#include <vector>
using namespace std;

#include <iostream>
#include <stack>
#include <string>
#include <stdlib.h>
using namespace std;

int main() {
	int n;
	int m;
	stack<char>s;
	while (cin >> n) {
		string a;
		a.resize(n);
		for (int i = 0; i < n; ++i) {
			cin >> a[i];
		}

		for (int i = 0; i < n; ++i) {
			if (a[i] == '+') {
				char a1 = s.top();
				s.pop();
				char a2 = s.top();
				s.pop();
				m = a1 + a2;
				s.push(m);
			}
			if (a[i] == '-') {
				int a1 = s.top();
				s.pop();
				int a2 = s.top();
				s.pop();
				m = a1 - a2;
				s.push(m);
			}
			if (a[i] == '/') {
				int a1 = s.top();
				s.pop();
				int a2 = s.top();
				s.pop();
				m = a1 / a2;
				s.push(m);
			}
			if (a[i] == '*') {
				int a1 = s.top();
				s.pop();
				int a2 = s.top();
				s.pop();
				m = a1 * a2;
				s.push(m);
			}
			else {
				s.push(a[i]);
			}
		}

		cout << s.top()<< endl;
		s.empty();
	}

	system("pause");
	return 0;
}
