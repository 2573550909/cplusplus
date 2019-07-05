#include <iostream>
#include <stdlib.h>
using namespace std;

//��������
void InsertSort(int *array, int size){
	for (int i = 0; i < size; ++i){
		//ÿ���õ�һ�������Ȱ�����������
		int key = array[i];
		//end �±���Ǻ�ǰһ�����Ƚ�
		int end = i - 1;
		while (end >= 0 && array[end] > key){
			array[end + 1] = array[end];
			end--;
		}
		//���ڽ���ѭ�����end��һ���������Ĳ������� end+1 λ��
		array[end + 1] = key;
	}
}

void InsertInto(int array[], int size) {
	for (int i = 0; i < size; ++i) {
		int key = array[i];
		int index = i - 1;
		while (index >= 0 && array[index] > key) {
			array[index + 1] = array[index];
			--index;
		}
		array[index + 1] = key;
	}
}

int main() {
	int array[10] = { 3,5,1,8,4,9,7,2,0,6 };
	InsertSort(array, 10);
	//InsertInto(array, 10);


	for (int i = 0; i < 10; ++i) {
		cout << array[i] << " ";
	}
	cout << endl;

	system("pause");
	return 0;
}