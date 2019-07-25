#include <iostream>
#include <vector>
#include <stdlib.h>
#include <algorithm>
using namespace std;

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