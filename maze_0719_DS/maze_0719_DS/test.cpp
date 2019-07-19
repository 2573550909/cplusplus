#include <iostream>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

#if 1
typedef int(*Cmp)(int, int);


// ð������(����
void BubbleSort(int* array,int n) {
	// �����������һ����Ҫ���ٴ�����
	for (int i = 0; i < n - 1; ++i) {
		int flag = 0;
		for (int j = 0; j < n - 1 - i; ++j) {
			// �����ر�ע�����  Խ�����
			if (array[j + 1] < array[j]) {
				swap(array[j], array[j + 1]);
				flag = 1;
			}
		}
		//��һ�ָ�����û�бȽϣ�˵���Ѿ��ź�����,ֱ�ӷ��غ���
		// û��Ҫ�������ѭ����
		if (flag == 0) {
			return;
		}
	}
}


int BubbleSortCmp(int* arr, int size, Cmp cmp) {
	for (int bound = 0; bound < size; ++bound) {
		for (int cur = size - 1; cur > bound; --cur) {
			if (cmp(arr[cur-1], arr[cur]) == 0) {
				swap(arr[cur - 1], arr[cur]);
			}
		}
	}
}

// ����/������
int Less(int x, int y) {
	if (x > y) {
		return 1;
	}
	else {
		return 0;
	}
}

void TestBubble() {
	int arr[10] = { 2,4,6,8,0,1,3,5,7,9 };
	BubbleSort(arr, 10);
	for (int i = 0; i < 10; ++i) {
		cout << arr[i] << " ";
	}
	cout << endl;

	int arr1[10] = { 2,4,6,8,0,1,3,5,7,9 };
	int len = sizeof(arr1) / sizeof(arr1[0]);
	BubbleSortCmp(arr1, len, Less);
	for (int i = 0; i < 10; ++i) {
		cout << arr1[i] << " ";
	}
	cout << endl;

}
#endif 


int main() {


	system("pause");
	return 0;
}

