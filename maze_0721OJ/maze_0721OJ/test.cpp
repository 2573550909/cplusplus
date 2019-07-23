

#include <iostream>
#include <stdlib.h>
using namespace std;
#if 1
int main() {
	long long CD[3] = {0, 0,1 };
	long long JC[3] = {0, 1,2 };
	for (int i = 3; i < 22; ++i) {
		CD[i] = (i - 1)*(CD[i - 1] + CD[i - 2]);
		JC[i] = JC[i - 1] * JC[i - 2];
	}

	cout << JC[4] << endl;

	system("pause");
	return 0;
}

#include <iostream>
#include <cstdio>
using namespace std;
int main(){
	long long d[22] = { 0, 0, 1 };
	// ����������Ԥ����һ��Ϊ 0 ���������������� n
	long long f[22] = { 0, 1, 2 }; 
	// �� ��
	for (int i = 3; i < 22; i++){
		d[i] = (i - 1) * (d[i - 1] + d[i - 2]); // ���ŵĵ��ƹ�ʽ
		f[i] = i * f[i - 1]; // �׳˵ĵ��ƹ�ʽ
	}

	int n;
	while (std::cin >> n){
		printf("%.2f%%\n", 100.0 * d[n] / f[n]);
		// �� 100.0 ���ѽ������� double ��������λС��
	}

	system("pause");
	return 0;
}

#include <iostream>
#include <cstdio>
using namespace std;
int main() {
	long long d[22] = { 0, 0, 1 };
	// ����������Ԥ����һ��Ϊ 0 ���������������� n
	long long f[22] = { 0, 1, 2 };
	// �� ��
	for (int i = 3; i < 22; i++) {
		d[i] = (i - 1) * (d[i - 1] + d[i - 2]); // ���ŵĵ��ƹ�ʽ
		f[i] = i * f[i - 1]; // �׳˵ĵ��ƹ�ʽ
	}

	int n;
	while (std::cin >> n) {
		printf("%.2f%%\n", 100.0 * d[n] / f[n]);
		// �� 100.0 ���ѽ������� double ��������λС��
	}

	system("pause");
	return 0;
}
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <string>
int main(){
	std::string line;
	// ��һ�ε�����ץ�� line ��
	while (std::getline(std::cin, line)) {
		std::vector<std::string> names; 
		//names �������е�����
		size_t pos = 0;
		// λ��������ڵ����˳��ȣ���ô֤�������ˣ�˫���ŵ��������������
		while (pos < line.length()) {
			// �ҵ�˫����Ҫ����˫�����ڲ�
			if (line[pos] == '\"') {
				size_t end = line.find("\"", pos + 1);
				names.push_back(line.substr(pos + 1, end - pos - 1)); 
				// ��ȡ�����ŵ� names ��
				pos = end + 2;
				// ���������˫���źͶ���
			}else{
				size_t end = line.find(",",pos+1);
				// �Ҳ�������֤���������һ���ַ����ˣ�ֱ�Ӵ�������ַ���������ne.find(",", pos + 1);
				if (end == -1) {
					names.push_back(line.substr(pos, line.size() - pos));
					break;
				}
				names.push_back(line.substr(pos, end - pos));
				pos = end + 1; // ��������Ķ���
			}
		}

		std::getline(std::cin, line);
		if (names.end() == std::find(names.begin(), names.end(), line))
			//std::find �������������������м���ң����һ��������Ҫ�ҵ�ֵ��
			// �ҵ��˷��ض�Ӧ���������Ҳ����ͷ�������ĩβ��λ�á��������� end() ��
		{
			printf("Important!\n"); // û�ҵ�
		}else{
			printf("Ignore\n"); // �ҵ���
		}
	}
	return 0;
}
#endif

#include <iostream>
#include <stdlib.h>
using namespace std;

//ͨ��һ�׿����������з�Ϊ������
#if 1
int Partion1(int* arr, int left, int right) {
	int key = arr[right - 1];
	int begin = left;
	int end = right - 1;
	//���������±� begin ָ����Ԫ�أ�end ָ��βԪ��
	// �����һ��Ԫ�ر�����һ�������У������һ�����±�С��key��һֱ��ǰ��
	while (begin < end) {
		while (begin < end && arr[begin] <= key) {
			++begin;
		}
		while (begin < end && arr[end] >= key) {
			--end;
		}
		//��������±��Ӧ����ͬһ��ֵҲ�Ͳ���Ҫ������
		if (begin < end) {
			swap(arr[end], arr[begin]);
		}
	}
	//���begin �����һ��λ�õĻ�˵��ǰ���ֵ����keyС
	// Ҳ�Ͳ���Ҫ������
	if (begin != right - 1) {
		swap(arr[begin], arr[right -1]);
	}
	return begin;
}

void QuickSort(int* array, int left, int right) {
	if (right - left > 1) {
		//���ֻ�׼ֵ
		int div = Partion1(array, left, right);

		QuickSort(array, left, div);
		QuickSort(array, div + 1, right);
	}
}

int Partion1(int* array, int left, int right) {
	int begin = left;
	int end = right - 1;
	int key = array[right - 1];

	while (begin < end) {
		while (begin < end && array[begin] <= key){
			++begin;
		}
		while (begin < end && array[end] >= key) {
			--end;
		}

		if (begin < end) {
			swap(array[begin], array[end]);
		}
	}
	if (begin != right - 1) {
		swap(array[begin], array[right - 1]);
	}
	return begin;
}

int Partion2(int* array, int left, int right) {
	int begin = left;
	int end = right - 1;
	int key = array[right - 1];

	while (begin < end) {
		while (begin < end && array[begin] <= key) {
			++begin;
		}
		if (begin < end) {
			array[end] = array[begin];
			--end;
		}

		while (begin < end && array[end] >= key) {
			--end;
		}
		if (begin < end) {
			array[begin] = array[end];
			++begin;
		}
	}
	array[begin] = key;
	return begin;
}

int Partion3(int* array, int left, int right) {
	int key = array[right - 1];
	int cur = left;
	int pre = cur - 1;

	while (cur < right) {
		if (array[cur] < key && ++pre != cur) {
			swap(array[cur], array[pre]);
		}
		++cur;
	}
	if (++pre != right - 1) {
		swap(array[pre], array[right - 1]);
	}
	return pre;
}


void QuickSort(int* array, int left, int right) {
	if (right - left  > 1) {
		//int div = Partion1(array, left, right);
		//int div = Partion2(array, left, right);
		int div = Partion3(array, left, right);

		QuickSort(array, left, div);
		QuickSort(array, div + 1, right);
	}
}

#include <stack>
void QuickSortNor(int* array, int size) {
	int left = 0;
	int right = size;

	stack<int>st;
	st.push(right);
	st.push(left);
	while (!st.empty()) {
		left = st.top();
		st.pop();
		right = st.top();
		st.pop();
		if (left < right) {
			int div = Partion2(array, left, right);
			st.push(right);
			st.push(div + 1);
			st.push(div);
			st.push(left);
		}
	}
}

int main() {
	int a[10] = { 3,5,1,6,9,0,7,2,8,4 };
	QuickSort(a, 0, 10);
	for (int i = 0; i < 10; ++i) {
		cout << a[i] << " ";
	}
	cout << endl;

	int b[10] = { 3,5,1,6,9,0,7,2,8,4 };
	QuickSortNor(b, 10);
	for (int i = 0; i < 10; ++i) {
		cout << b[i] << " ";
	}
	cout << endl;

	system("pause");
	return 0;
}
#endif

#if 1
void BubbleSort(int* array, int size) {
	for (int i = 0; i < size - 1; ++i) {
		int flag = 0;
		for (int j = 1; j < size - i; ++j) {
			if (array[j-1] > array[j]) {
				swap(array[j], array[j - 1]);
				flag = 1;
			}
		}
		if (flag == 0) {
			return;
		}
	}
}

void BubbleSort(int* array, int size) {
	for (int i = 0; i < size - 1; ++i) {
		int flag = 1;
		for (int j = size-1; j > 0; --j) {
			if (array[j] < array[j - 1]) {
				swap(array[j], array[j - 1]);
				flag = 0;
			}
		}
		if (flag == 1) {
			return;
		}
	}
}
#endif

//ѡ������ ����˼·��
//���������Ļ� ����������ҵ�����Ԫ�أ����������һ��Ԫ�ؽ���
// ÿ����һ�Σ������ķ�Χ����Сһ�Σ�ֱ�������������ź�
#if 1
void SelectSortLess(int* array, int size) {
	for (int i = 0; i < size - 1; ++i) {
		int maxpos = 0;
		//�ҵ����Ԫ�ص��±�
		for (int j = 1; j < size - i; ++j) {
			if (array[maxpos] < array[j]) {
				maxpos = j;
			}
		}
		if (maxpos != size - i - 1) {
			swap(array[maxpos], array[size - i - 1]);
		}
	}
}

void SelectSortGreat(int* array, int size) {
	for (int i = 0; i < size - 1; ++i) {
		int minpos = 0;
		for (int j = 0; j < size - i; ++j) {
			if (array[minpos] > array[j]) {
				minpos = j;
			}
		}
		if (minpos != size - i - 1) {
			swap(array[minpos], array[size - i - 1]);
		}
	}
}
#endif

void AdjustDown(int* array, int size, int last) {
	int child = last * 2 + 1;
	while (child < size) {
		if (child + 1 < size && array[child] < array[child + 1]) {
			++child;
		}
		if (array[child] > array[last]) {
			swap(array[child], array[last]);
			last = child;
			child = 2 * last + 1;
		}
		else {
			return;
		}
	}
}

void HeapSort(int* array, int size) {
	int last = (size - 2) / 2;
	//����
	for (; last >= 0; --last) {
		AdjustDown(array, size,last);
	}

	//ɾ���Ѷ�Ԫ��
	int end = size - 1;
	while (end) {
		swap(array[end], array[0]);
		AdjustDown(array, end,0);
		end--;
	}
}

int main() {

	int b[10] = { 3,5,1,6,9,0,7,2,8,4 };
	HeapSort(b, 10);
	for (int i = 0; i < 10; ++i) {
		cout << b[i] << " ";
	}
	cout << endl;
	
	int b[10] = { 3,5,1,6,9,0,7,2,8,4 };
	SelectSortLess(b, 10);
	for (int i = 0; i < 10; ++i) {
		cout << b[i] << " ";
	}
	cout << endl;

	SelectSortGreat(b, 10);
	for (int i = 0; i < 10; ++i) {
		cout << b[i] << " ";
	}
	cout << endl;

	system("pause");
	return 0;
}