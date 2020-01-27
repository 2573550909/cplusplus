#include <iostream>
#include <algorithm>
#include <stdlib.h>
#include <vector>
using namespace std;

class A{
public:
	A(){
		printf("A ");
	}
	~A(){
		printf("deA ");
	}
};
class B{
public:
	B(){
		printf("B ");
	}
	~B(){
		printf("deB ");
	}
};
class C : public A, public B{
public:
	C(){
		printf("C ");
	}
	~C(){
		printf("deC ");
	}
};
int main(){
	A *a = new C();
	delete a;
	return 0;
}

#if 0
class A{
public:
	void f(){
		printf("A\n");
	}
};
class B : public A{
public:
	virtual void f(){
		printf("B\n");
	}
};

int main(){
	A *a = new B;
	a->f();
	delete a;
	return 0;
}

void fun3(void) { 
	static int a = 4; 
}
int main(int argc, char** args) {
	printf("%d",a);
	fun3();
	printf("%d", a);

	return 0;
}
#include <iostream>
#include <algorithm>
#include <stdlib.h>
#include <vector>
/*
getLuckyPacket:�ӵ�ǰλ�ÿ�ʼ��������Ҫ�����ϣ�һֱ���������һ��λ�ý���
x: �����е�������
n: �������
pos: ��ǰ������λ��
sum: ��Ŀǰλ�õ��ۼӺ�
multi: ��Ŀǰλ�õ��ۻ�ֵ
*/
int getLuckyPacket(vector<int>&x, int n, int pos, int sum, int multi){
	int count = 0;
	//ѭ����������λ��i��ʼ���п��ܵ����
	for (int i = pos; i < n; i++){
		sum += x[i];
		multi *= x[i];
		if (sum > multi){
			// �ҵ�����Ҫ�����ϣ��� 1 �������ۼӺ�����ֵ�����Ƿ��з���Ҫ��ļ���
			count += 1 + getLuckyPacket(x, n, i + 1, sum, multi);
		}
		else if (x[i] == 1){
			// ��β�����Ҫ���ҵ�ǰԪ��ֵΪ 1 ��������������
			count += getLuckyPacket(x, n, i + 1, sum, multi);
		}
		else{
			// ��� sum ���� multi, ������û�з���Ҫ��������
			break;
		}
		// Ҫ������һ��λ��֮ǰ�����Ȼָ� sum �� multi
		sum -= x[i];
		multi /= x[i];
		// ������ͬ����û��ʲô���𣬶�ֻ����һ����ϣ�����ֱ������
		while (i < n - 1 && x[i] == x[i + 1]){
			i++;
		}
	}
	return count;
}
int main(){
	char a[] = "ABCDEF"; 
	char b[] = { 'A','B','C','D','E','F','0' }; 
	cout << sizeof(a) << endl;
	cout<<sizeof(b) << endl;
	//cout << "A:" << sizeof(a) / sizeof(a[0]) << endl;
	//cout << "B:" << sizeof(b) / sizeof(b[0]) << endl;

	//int n;
	//while (cin >> n){
	//	vector<int>x(n);
	//	for (int i = 0; i < n; i++){
	//		cin >> x[i];
	//	}
	//	sort(x.begin(), x.end());
	//	// �ӵ�һ��λ�ÿ�ʼ����
	//	cout << getLuckyPacket(x, n, 0, 0, 1) << endl;
	//}

	return 0;
}

#include <iostream>
#include <stdlib.h>
using namespace std;

int main() {
	int y, m, d;
	while (cin >> y >> m >> d) {
		int arr[] = { 0,31,59,90,120,151,181,212,243,273,304,334,335 };
		int days = arr[m - 1];
		days += d;
		if (m > 2) {
			if (y % 400 == 0 || (y % 4 == 0 && y & 100 != 0)) {
				days += 1;
			}
		}
		cout << days << endl;
	}

	system("pause");
	return 0;
}


#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <queue>
#include <unordered_map>
#include <string>
using namespace std;

int minDistance(string word1, string word2) {
	// word��մ�֮��ı༭����Ϊword�ĳ���
	if (word1.empty() || word2.empty()) {
		return max(word1.size(), word2.size());
	}
	int len1 = word1.size();
	int len2 = word2.size();
	// F(i,j)��ʼ��
	vector<vector<int> > f(1 + len1, vector<int>(1 + len2, 0));
	for (int i = 0; i <= len1; ++i) {
		f[i][0] = i;
	}
	for (int i = 0; i <= len2; ++i) {
		f[0][i] = i;
	}
	for (int i = 1; i <= len1; ++i) {
		for (int j = 1; j <= len2; ++j) {
			// F(i,j) = min { F(i-1,j��+1, F(i,j-1) +1, F(i-1,j-1) +
			//(w1[i]==w2[j]?0:1) }
			// �ж�word1�ĵ�i���ַ��Ƿ���word2�ĵ�j���ַ����
			if (word1[i - 1] == word2[j - 1]) {
				f[i][j] = 1 + min(f[i][j - 1], f[i - 1][j]);
				// �ַ���ȣ�F(i-1,j-1)�༭���벻��
				f[i][j] = min(f[i][j], f[i - 1][j - 1]);
			}
			else {
				f[i][j] = 1 + min(f[i][j - 1], f[i - 1][j]);
				// �ַ�����ȣ�F(i-1,j-1)�༭���� + 1
				f[i][j] = min(f[i][j], 1 + f[i - 1][j - 1]);
			}
		}
	}
	return f[len1][len2];
}

int main() {
	int a = 2180;
	if ((a % 4 == 0 && a % 100 != 0) || a % 400 == 0) {
		cout << "������" << endl;
	}

	system("pasue");
	return 0;
}

int DFS(int x, int y, vector<vector<int>>& matrix,\
		vector<vector<int>>& dp){
	if (dp[x][y] != 0) {
		return dp[x][y];
	}

	int maxNum = 1;
	for (int i = -1; i <= 1; ++i){
		for (int j = -1; j <= 1; ++j){
			if ((i + j == -1 || i + j == 1) 
				&& x + i < matrix.size() 
				&& x + i >= 0 
				&& y + j < matrix[0].size() 
				&& y + j >= 0){
				if (matrix[x][y] < matrix[x + i][y + j]){
					int k = DFS(x + i, y + j, matrix, dp) + 1;
					maxNum = max(maxNum, k);
				}
			}
		}
	}
	dp[x][y] = maxNum;
	return maxNum;
}

int longestIncreasingPath(vector<vector<int>>& matrix) {
	int Max = 0;
	if (matrix.empty())
		return 0;
	vector<vector<int>> dp(matrix.size(), \
		vector<int>(matrix[0].size()));

	for (int i = 0; i < matrix.size(); ++i) {
		for (int j = 0; j < matrix[0].size(); ++j) {
			Max = max(DFS(i, j, matrix, dp), Max);
		}
	}
	return Max;
}


int numBusesToDestination(vector<vector<int>>& routes, int S, int T) {
	if (S == T) {
		return 0;
	}
	//�������������������
	queue<int> myQue;
	myQue.push(S);
	//hashMap[station]��¼������·�д���station���վ�����·�±�
	unordered_map<int, vector<int>> hashMap;
	//minStepsΪ������Ҫ�����Ĺ���������
	int minSteps = 1;
	int routesSize = (int)routes.size();
	//����Ѿ����ʹ�����·
	vector<bool> visitedRoute(routesSize, false);
	//����hashMap��Ϣ��ͳ��ÿ��վ����ֵ���·
	for (int i = 0; i < routesSize; ++i) {
		for (const auto &station : routes[i]) {
			hashMap[station].push_back(i);
		}
	}
	while (!myQue.empty()) {
		//����ǰ���������е�վ�㶼����Ѱ��һ����·
		for (int i = (int)myQue.size(); i > 0; --i) {
			int frontStation = myQue.front();
			myQue.pop();
			//����frontStation���վ���ܹ������������·
			for (const auto &routeIndex : hashMap[frontStation]) {
				//������·������δ���ʹ���
				if (!visitedRoute[routeIndex]) {
					visitedRoute[routeIndex] = true;
					//����routeIndex������·�е�����վ��
					for (const auto &station : routes[routeIndex]) {
						//������Ŀ�ĵ�
						if (station == T) {
							return minSteps;
						}
						myQue.push(station);
					}
				}
			}
		}
		//ʵ����size������һ��Ķ���
		minSteps++;
	}
	return -1;//�޷�����
}

#endif

#if 0
class Base {
public:
	Base(int j) : i(j) 
	{}

	virtual~Base() 
	{}
	void func1() {
		i *= 10;
		func2();
	}
	int getValue() {
		return i;
	}
protected:
	virtual void func2() {
		i++;
	}
protected:
	int i;
};
class Child : public Base {
public:
	Child(int j) : Base(j) {}
	void func1() {
		i *= 100;
		func2();
	}
protected:
	void func2() {
		i += 2;
	}
};
int main() {
	Base * pb = new Child(1);
	pb->func1();
	cout << pb->getValue() << endl; 
	delete pb;

	system("pause");
	return 0;
}

int main() {
	char ccString1[] = "Is Page Fault??";
	char ccString2[] = "No Page Fault??";
	strcpy(ccString1, "No");
	if (strcmp(ccString1, ccString2) == 0) {
		cout << ccString2;
	}
	else {
		cout << ccString1;
	}

	//int a[] = { 2, 4, 6, 8, 10 }, *p, **k;
	//p = a;
	//k = &p;
	//printf(" % d", *(p++));
	//printf(" % d\n", **k);

	//int a = 10;

	//int b = 20;
	//int c = max(a, b);
	//cout << c << endl;
	//
	system("pause");
	return 0;
}
#endif


