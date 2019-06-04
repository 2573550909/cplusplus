//#include <iostream>
//#include <stdlib.h>
//#include <math.h>
//using namespace std;
//
//int mult(int n) {
//	static int max_ = 0;
//	for (int i = 2; i <= n/2; ++i) {
//		if (n % i == 0) {
//			max_ = i;
//		}
//	}
//	return max_;
//}
//
//int main()
//{
//	int N, M;
//	while (cin >> N, cin >> M) {
//		if (mult(N) == 0) {
//			cout << -1;
//			continue;
//		}
//		int max = 0;
//		int count = 0;
//		while ((N + max) < M) {
//			N += max;
//			max = mult(N);
//			++count;
//		}
//
//		int temp = M - N;
//		if (temp == 0 || temp%2 == 0) {
//			cout << count;
//		}
//		else {
//			cout << -1;
//		}
//	}
//	system("pause");
//	return 0;
//}
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// ����Լ��������� 1 �ͱ����Լ��
void divisorNum(int n, vector<int> &divNum)
{
	for (int i = 2; i <= sqrt(n); i++)
	{
		if (n%i == 0)
		{
			divNum.push_back(i);
			//��ƽ����ʱ������һ����ҲҪ����
			if (n / i != i)
				divNum.push_back(n / i);
		}
	}
}
int Jump(int N, int M)
{
	// ����ĵ���� stepNum ��Ĳ�������ʼ N Ϊ 1 ������ N �� N Ϊ 1 ��
	vector<int> stepNum(M + 1, 0);
	stepNum[N] = 1;
	for (int i = N; i < M; i++)
	{
		//N ������Լ������Ϊ�ӱ�������㿪ʼ���ߵ�����
		vector<int> divNum;
		//0 ��������㲻�ܵ�
		if (stepNum[i] == 0)
			continue;
		//����������ߵĲ���������divNum��������
		divisorNum(i, divNum);
		for (int j = 0; j < divNum.size(); j++)
		{
			// ��λ�� i �����ܵ���ĵ�Ϊ stepNum[divNum[j]+i]
			if ((divNum[j] + i) <= M && stepNum[divNum[j] + i] != 0)
				stepNum[divNum[j] + i] = min(stepNum[divNum[j] + i], stepNum[i] + 1);
			else if ((divNum[j] + i) <= M)
				stepNum[divNum[j] + i] = stepNum[i] + 1;
		}
	}
	if (stepNum[M] == 0)
		return -1;
	else
		//��ʼ��ʱ�����һ��������Ҫ��1
		return stepNum[M] - 1;
}
int main()
{
	int n, m;
	cin >> n >> m;
	cout << Jump(n, m) << endl;
	return 0;
}