#if 1
#include <stdio.h>
#include <stdlib.h>

union{
	char ch;
	int i;
}un;
#define htonll(x)    (((long long int)x & 0x00000000000000ff) << 7*8)|\
							 (((long long int)x & 0x000000000000ff00) << 5*8)|\
							 (((long long int)x & 0x0000000000ff0000) << 3*8)|\
							 (((long long int)x & 0x00000000ff000000) << 1*8)|\
							 (((long long int)x & 0x000000ff00000000) >> 1*8)|\
							 (((long long int)x & 0x0000ff0000000000) >> 3*8)|\
							 (((long long int)x & 0x00ff000000000000) >> 5*8)|\
							 (((long long int)x & 0xff00000000000000) >> 7*8)


union {
	char a;
	int b;
}um;
int main(void) {
	um.b = 0x00000001;
	if (um.a == 0x00) {
		printf("���\n");
	}
	else {
		printf("С��\n");
	}

	//un.i = 0x12345678;
	//if (un.ch == 0x12) {
	//	printf("big endian\n");
	//}
	//else {
	//	printf("small endain\n");
	//}


//	int a = 1;
//	int b = (*(char*)&a);
//	printf("%d\n", b);
//	htonll(b);
//	printf("%d\n", b);
//
	system("pause");
	return 0;
}
#endif

#include <iostream>
#include <stdlib.h>
#include <vector>
using namespace std;

//����һ������Ľṹ��
class pos {
public:
	int x;
	int y;
	int level;
};

int selectmin(vector<vector<char>>&map){
	int dir[4][2] = {
		(-1,0),(1,0),(0,-1),(0,1)
	};
	//�д�С
	int m = map.size();
	//�д�С
	int n = map[0].size();
	pos start{0, 8, 0};
	pos end{9, 8, 0};

	return 0;
}

int main() {
	//��ʼ��һ�� 10 �� 10 �еĶ�ά����
	vector<vector<char>>map(10, vector<char>(10));
	while (cin >> map[0][0]) {
		for (int i = 0; i < 10; ++i) {
			for (j = 0; j < 10; j++) {
				//������whileѭ���Ѿ�������0,0λ�õ��ַ�
				//���������λ����Ҫ����
				if (i == 0 && j == 0) {
					continue;
				}
				cin >> map[i][j];
			}
		}
		cout << selectmin(map) << endl;
	}

	system("pause");
	return 0;
}