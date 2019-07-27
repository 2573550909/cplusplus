#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <string>
#include <vector>
#include <math.h>
#include <queue>
#include <fstream>
using namespace std;
#if 1
int main() {
	int n, m, k;
	while (cin >> n >> m>> k) {
		vector<vector<int>>table(n + 1, vector<int>(m + 1));
		vector<vector<double>>P(n + 1, vector<double>(m + 1));
		//����Ģ����λ��
		int x, y;
		for (int i = 0; i < k; ++i) {
			cin >> x >> y;
			table[x][y] = 1;
		}

		P[1][1] = 1.0; //������Ϊ1
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++){
				//�������
				if (!(i == 1 && j == 1)) { 
					P[i][j] = P[i - 1][j] * (j == m ? 1 : 0.5) + 
						P[i][j - 1] * (i == n ? 1 : 0.5); 

					//�߽��ʱ�򣬸���Ϊ1
					if (table[i][j] == 1) {
						//����õ���Ģ����������Ϊ0
						P[i][j] = 0;
					}
				}
			}
		}

		//fixed ���õ��Ǹ�ʽ��setprccision(2)��˼�Ǳ�����λС��
		cout << fixed << setprecision(2) << P[n][m] << endl;
		printf("%.2f", P[n][m]);
	}

	return 0;
}
#endif
#if 1
class pos {
public:
	int x;
	int y;
};

int bfs(vector<vector<char>>&map, 
	vector<vector<bool>>&visit, pos& start)
{
	int count = 0;
	queue<pos>que;
	const int dit[4][2] = {
		{-1,0},//��
		{1,0},//��
		{0,-1},//��
		{0,1}//��
	};
	int m = map.size();
	int n = map[0].size();
	//���Ȳ�����ʼλ��
	que.push(start);
	++count;
	//ÿ��������Ҫ����һ�� true�������λ���Ѿ��߹���
	visit[start.x][start.y] = true;

	while (!que.empty()){
		pos cur = que.front(), next;
		que.pop();
		//ѭ���Ĵ�����Ϊ���ĸ�����
		for (int i = 0; i < 4; ++i){
			next.x = cur.x + dit[i][0];
			next.y = cur.y + dit[i][1];
			if (next.x >= 0 && next.x < m && next.y >= 0 && next.y < n 
				&& !visit[next.x][next.y] && map[next.x][next.y] == '.')
			{
				que.push(next);
				++count;
				//ÿ��������Ҫ����һ�� true�������λ���Ѿ��߹���
				visit[next.x][next.y] = true;
			}
		}
	}
	return count;
}

int main() {
	int m, n;
	while (cin >> m >> n && m*n) {
		pos start;
		vector<vector<char>>map(m, vector<char>(n));
		vector<vector<bool>>visit(m, vector<bool>(n));
		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < n; ++j) {
				//��ʼ�����еĸ���Ϊfalse
				visit[i][j] = false;
				cin >> map[i][j];
				if (map[i][j]=='@') {
					start.x = i;
					start.y = i;
				}
			}
			cout << bfs(map, visit, start) << endl;
		}
	}
	system("pause");
	return 0;
}

int main() {
	string s1, s2;
	int len1, len2;
	while (cin >> s1 >> s2 >> len1 >> len2) {
		//�ַ������뵽len2�ĳ���
		s1.append(len2 - s1.size(), 'a');
		s2.append(len2 - s2.size(), (char)('z' + 1));

		//ȷ��s2 �� s1 ÿһ��λ���ϵĲ�ֵ
		vector<int>v;
		for (int i = 0; i < len2; ++i) {
			v.push_back(s2[i] - s1[i]);
		}

		//ȷ�� len2 �� len1 ֮�����ɲ�ͬ�ַ��ĸ���
		int result = 0;
		for (int i = len1; i <= len2; i++) {
			for (int j = 0; j < i; j++) {
				result += v[j] * pow(26, i - 1 - j);
			}
		}
		//�����ַ�����󶼲�������s2�����������Ҫ��1��
		cout << result - 1 << endl;
	}

	system("pause");
	return 0;
}

#include <algorithm>

int main(){
	string A, B;
	while (cin >> A >> B) {
		int aLength = A.length();
		int bLength = B.length(); 

		// ��������״̬ת�Ʒ����м����ľ���
		vector<vector<int> > dp(aLength, vector<int>(bLength, 0));

		// ��ʼ��dp����߽磺�߽��ַ�Ҫô�ڣ�Ҫô����
		dp[0][0] = (A[0] == B[0]) ? 1 : 0;
		for (int i = 1; i < aLength; i++) {
			dp[i][0] = (A[i] == B[0]) ? 1 : 0;
			dp[i][0] = max(dp[i - 1][0], dp[i][0]);
		}
		for (int j = 1; j < bLength; j++) {
			dp[0][j] = (A[0] == B[j]) ? 1 : 0;
			dp[0][j] = max(dp[0][j - 1], dp[0][j]);
		}
		
		// ����״̬ת�Ʒ��̽��м���
		for (int i = 1; i < aLength; i++) {
			for (int j = 1; j < bLength; j++) {
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
				if (A[i] == B[j]) {
					dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + 1);
				}
			}
		}
		cout << dp[aLength - 1][bLength - 1] << endl;
	}

	system("pause");
	return 0;
}
#endif


