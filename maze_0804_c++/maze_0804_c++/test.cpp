#include <iostream>
#include <vector>
#include <stdlib.h>
#include <map>
#include <string>
#include <set>
using namespace std;

#if 1
class Printer {
public:
	vector<int> clockwisePrint(vector<vector<int> > mat, int n, int m) {
		vector<int> ret;
		int x1 = 0, y1 = 0; //���Ͻ�����
		int x2 = n - 1, y2 = m - 1; //���½�����
		// �����������ʾ��һ������(�ʼ�ľ���)
		// Ȼ����Ҫ���ӡ����Ȧ������.
		// ��ӡ���֮��, ��С���εĴ�С.
		while (x1 <= x2 && y1 <= y2) {
			for (int j = y1; j <= y2; ++j) {
				ret.push_back(mat[x1][j]);
			}
			for (int i = x1 + 1; i < x2; ++i) {
				ret.push_back(mat[i][y2]);
			}
			for (int j = y2; x1 < x2 && j >= y1; --j) {
				//x1 < x2��ֻ���ڲ��ǵ�һ�ĺ���ʱ��ִ�����ѭ
				ret.push_back(mat[x2][j]);
			}
			for (int i = x2 - 1; y1 < y2 && i > x1; --i) {
				//y1 < y2��ֻ���ڲ��ǵ�һ������ʱ��ִ�����ѭ
				ret.push_back(mat[i][y1]);
			}
			x1++; y1++;
			x2--; y2--;
		}
		return ret;
	}
};

void TestMap() {
	map<string, string> m;
	m.insert(pair<string, string>("pear", "����"));
	m.insert(make_pair("banan", "�㽶"));
	m["apple"] = "ƻ��";
	cout << m.size() << endl;

	//Ĭ�ϰ����ֵ���ķ�ʽ��������
	for (auto& e : m) {
		cout << e.first << "---->" << e.second << endl;
	}
}
void TestMultiMap() {
	multimap<string, string>mu;
	mu.insert(pair<string, string>("maze", "����"));
	mu.insert(make_pair("xiao maze", "С����"));
	mu.insert(pair<string, string>("maze", "������"));
	for (auto& e : mu) {
		cout << e.first << "-->" << e.second << endl;
	}
}

void Testset(){
	// ������array�е�Ԫ�ع���set
	int array[] = { 1, 3, 5, 7, 9, 2, 4, 6, 8, 0, 1, 3,
		5, 7, 9, 2, 4, 6, 8, 0 };
	set<int> s(array, array + sizeof(array) / sizeof(array[0]));
	cout << s.size() << endl;
	// �����ӡset�е�Ԫ�أ��Ӵ�ӡ����п��Կ�����set��ȥ��
	for (auto& e : s) {
		cout << e << " ";
	}
	cout << endl;
	for (auto it = s.rbegin(); it != s.rend(); ++it) {
		cout << *it << " ";
	}
	cout << endl;

	cout << s.count(3) << endl;
}

void TestMultiset() {
	int array[] = { 2, 1, 3, 9, 6, 0, 5, 8, 4, 7 };
	// ע�⣺multiset�ڵײ�ʵ�ʴ洢����<int, int>�ļ�ֵ��
	multiset<int> s(array, array + sizeof(array) / sizeof(array[0]));
	for (auto& e : s)
		cout << e << " ";

	cout << endl;
}

int main() {
	//TestMap();
	//TestMultiMap();
	//Testset();
	TestMultiset();

	system("pause");
	return 0;
}
#endif


