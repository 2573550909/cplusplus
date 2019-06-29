#include <iostream>
#include <vector>
#include <queue>
#include <functional>
#include <stdlib.h>
using namespace std;

int main() {
	vector<int> v{ 3,2,7,6,0,4,1,9,8,5 };
	priority_queue<int> q1;
	for (auto& e : v) {
		q1.push(e);
	}

	//priority_queueĬ���Ǵ�ѵķ�ʽ����Ѷ�Ӧ���ǽ�������
	for (auto &e : v) {
		cout << q1.top() << " " ;
		q1.pop();
	}

	cout << endl;
	// ���Ҫ����С�ѣ���������ģ���������greater�ȽϷ�ʽ
	priority_queue<int, vector<int>, greater<int>> q2(v.begin(), v.end());
	for (auto &e : v) {
		cout << q2.top() << " " ;
		q2.pop();
	}
	cout << endl;

	system("pause");
	return 0;
}