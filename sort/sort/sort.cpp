#if 0
#include<iostream>
#include<vector>
using namespace std;

void help(int n, int m, vector<int>& v, int beg) {
	// m == 0 Ϊ�ݹ��������. ��ʱ v �п����Ѿ����������ɸ�Ԫ����. ���� v �е����ݾ���һ����.
	if (m == 0) {
		for (int i = 0; i < v.size(); i++) {
			// ��� ? : ֻ��Ϊ���ý���ĸ�ʽ�ܹ���Ҫ��һ��.
			i == 0 ? cout << v[i] : cout << " " << v[i];
		}
		cout << endl;
	}
	for (int i = beg; i <= n && i <= m; i++) {
		// ���¼��д����Ǹ���Ŀ�Ĺؼ�. �����ת��.
		// Ϊ���� i -> n �ж����������Ϊ m, �������ת��Ϊ
		// i + 1 -> n �ж����������Ϊ m - i
		v.push_back(i);
		help(n, m - i, v, i + 1);
		v.pop_back();
	}
}


int main() {
	int n, m;
	while (cin >> n >> m) {
		vector<int>v;
		help(n, m, v, 1);
	}

	system("pause");
	return 0;
}
#endif

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

// ABCDFYE CDE
// ABCDGEAS CDECDE
int main() {
	string strA, strB;
	while (cin >> strA >> strB) {
		int arr[256] = { 0 };
		for (int i = 0; i < strA.size(); ++i) {
			arr[strA[i]]++;
		}
		for (int i = 0; i < strB.size(); ++i) {
			if (arr[strB[i]]) {
				arr[strB[i]]--;
			}
			else {
				cout << "No" << endl;
				return 0;
			}
		}
		cout << "Yes" << endl;
	}
	system("pause");
	return 0;
}

