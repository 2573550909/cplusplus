
int main()
{
	int w, h, res = 0;
	cin >> w >> h;
	����һ����ά����
	vector<vector<int>> a;
	��ά������д�СΪ w��Ҳ����˵�� w ��
	a.resize(w);
	for (auto& e : a) {
		Ϊÿһ������ h �������Ĵ�С�����ҳ�ʼ��Ϊ1
		 a �ķ�Χ���� w �Ĵ�С
		e.resize(h, 1);
	}

	for (int i = 0; i < w; i++)
	{
		for (int j = 0; j < h; j++)
		{
			if (a[i][j] == 1)
			{
				res++;
				 ��ǲ��ܷŵ����λ��
				if ((i + 2) < w)
					a[i + 2][j] = 0;
				if ((j + 2) < h)
					a[i][j + 2] = 0;
			}
		}
	}
	cout << res;

	system("pause");
	return 0;
}

#include <iostream>
#include <stdlib.h>
#include <vector>
using namespace std;
class Solution {
public:
	int StrToInt(string str){
		if (str.empty())
			return 0;

		int symbol = 1;
		������
		if (str[0] == '-'){
			symbol = -1;
			str[0] = '0'; //�������ַ�'0',����0
		}else if (str[0] == '+') {
			��������
			symbol = 1;
			str[0] = '0';
		}
		int sum = 0;
		for (int i = 0; i < str.size(); ++i){
			if (str[i] < '0' || str[i] > '9'){
				sum = 0;
				break;
			}
			sum = sum * 10 + str[i] - '0';
		}
		return symbol * sum;
	}
};

#include <iostream>
#include <string>
using namespace std;
void func(char **m){
	++m;
	cout << *m << endl;
}

int main() 
{
	const char* a[] = { "morning", "afternoon", "evening" };
	char **p;
	p = (char**)a;
	func(p);

	return 0;
}

#include <iostream>
using namespace std;
void func(char **m) {
	++m;
	cout << *m << endl;
}
int main() {
	static char *a[] = { "morning", "afternoon", "evening" };
	char **p;
	p = a;
	func(p);
	return 0;
}

class UnusualAdd {
public:
	int addAB(int A, int B) {
		int sum = 0, carry = 0;
		while (B != 0) {
			��Ӧλ�ĺ�
			sum = A ^ B;
			��Ӧλ�͵Ľ�λ����Ȼ�ǽ�λ����Ҫ��������һλ
			carry = (A&B) << 1;
			A = sum;
			B = carry;
		}
		return sum;
	}
};

#include<iostream>
using namespace std;
int pathNum(int n, int m)
{
	if (n > 1 && m > 1)
		b������ݹ�
		return pathNum(n - 1, m) + pathNum(n, m - 1);
	else if (((n >= 1) && (m == 1)) || ((n == 1) && (m >= 1)))
		 a�������ֹ����
		return n + m;
	else
		����Ϊ0ʱ�� ·��Ϊ0
		return 0;
}
int main()
{
	int n, m;
	while (cin >> n >> m){
		cout << pathNum(n, m) << endl;
	}
	return 0;
}


#include <iostream>
#include <stdlib.h>
using namespace std;

int Water(int n) {
	if (n == 2) {
		return 1;
	}
	if (n < 2) {
		return 0;
	}

	return (n / 3 + Water(n / 3 + n % 3));
}

int main()
{
	3���տ�Ȫˮƿ���Ի�һƿ��ˮ
	int n;
	while (cin >> n) {
		Water(n);
	}

	system("pause");
	return 0;
}

#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;

int main()
{
	string str1;
	string str2;
	string str;
	size_t i = 0;
	size_t j = 0;
	while (cin >> str1, cin >> str2) {
		int max = 0;
		string s;
		while(j < str2.size() && i<str1.size()) {
			if(str1[i] == str2[j]) {
				str += str1[i];
				++i; ++j;
			}
			else {
				if (str.size() > s.size()){
					s = str;
				}
				str = '0';
				++i;
			}
		}
		cout << s << endl;
	}

	system("pause");
	return 0;
}