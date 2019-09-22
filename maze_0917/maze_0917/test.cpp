#include "head.h"


#if 1
class String {
public:
	// ���캯��
	String(const char* str = ""){
		if (str == nullptr) {
			str = "";
		}
		_str = new char[strlen(str) + 1];
		strcpy(_str, str); 
	}
	
	// �������캯��
	String(const String& str) {
		//str �Ѿ�����һ��������
		_str = new char[strlen(str._str) + 1];
		strcpy(_str, str._str);
	}
	//��ֵ����
	String& operator=(const String& str) {
		//ע���1 �����ķ���ֵ����
		//ע���2 �ǲ����Լ����Լ���ֵ 
		//ע���3 �����Ĳ���������
		//ע���4 �������ص� *this
		if (&str != this) {
			char* temp = new char[strlen(str._str) + 1];
			strcpy(temp, str._str);
			// _str ������� str2����
			delete[] _str;
			_str = temp;
		}
		return *this;
	}

	~String() {
		if (_str) {
			delete[]  _str;
			_str = nullptr;
		}
	}


	String(String&& s)
		: _str(s._str)
	{
		s._str = nullptr;
	}
private:
	char* _str;
};

String&& GetString(const char* pStr){
	String strTemp(pStr);
	return strTemp;
}
int main(){
	String s1("hello");
	String s2(GetString("world"));

	system("pause");
	return 0;
}


class Info {
public:
	Info() : _type(0), _name('a') {
		InitRSet();
	}
	Info(int type) : _type(type), _name('a') {
		InitRSet();
	}
	Info(char a) : _type(0), _name(a) {
		InitRSet();
	}
private:
	void InitRSet() {
		//��ʼ����������
	}
private:
	int _type;
	char _name;
};

class Info {
public:
	// Ŀ�깹�캯��
	Info() : _type(0), _a('a'){
		InitRSet();
	}
	// ί�ɹ��캯��
	Info(int type) : Info(){
		_type = type;
	}
	// ί�ɹ��캯��
	Info(char a) : Info(){
		_a = a;
	}
private:
	void InitRSet() { 
		//��ʼ����������
	}
private:
	int _type = 0;
	char _a = 'a';
	//...
};

void* GetMemory(size_t size) {
	return malloc(size);
}

	int main() {
	// ���û�д��������Ƶ�����������
	cout << typeid(decltype(GetMemory)).name() << endl;
	// ����������б��Ƶ����Ǻ�������ֵ������,
	// ע�⣺�˴�ֻ�����ݣ�����ִ�к���
	cout << typeid(decltype(GetMemory(0))).name() << endl;
	int a = 0;
	cout << typeid(a).name();

	system("pause");
	return 0;
}
//���������Ҫ֧���б��ʼ�����������(ģ����)���һ��
//����initializer_list���Ͳ����Ĺ��캯�����ɡ�
//ע�⣺initializer_list��ϵͳ�Զ������ģ�壬
//	  ����ģ������Ҫ������������begin()��end()������
//	  �Լ���ȡ������Ԫ�ظ����ķ���size()��
template<class T>
class Vector {
public:
	Vector(initializer_list<T> l) 
		: _capacity(l.size())
		, _size(0)
	{
		_array = new T[_capacity];

		for (auto e : l) {
			_array[_size++] = e;
		}
	}

	Vector<T>& operator=(initializer_list<T> l) {
		delete[] _array;
		size_t i = 0;
		for (auto e : l) {
			_array[i++] = e;
		}
		return *this;
	}
// ...
private:
	T* _array;
	size_t _capacity;
	size_t _size;
};

class Point{
public:
	Point(int x = 0, int y = 0)
		: _x(x)
		, _y(y)
	{}
private:
	int _x;
	int _y;
};
int main(){
	//��׼��֧�ֵ���������б��ʼ��
	Point p{ 1, 2 };

	system("pause");
	return 0;
}
#endif

#if 0
class TreeNode {
public:
	int val;
	TreeNode *left;
	TreeNode *right;
};
class Solution {
public:
	TreeNode* reConstructBinaryTree(vector<int> pre, vector<int> vin) {
		//�ݹ齨�����������зֿ��ֱ���������
		//ע��ݹ����������
		if (pre.empty())
			return nullptr;

		//pre�ĵ�һ���������ù��ġ�����findҲ��Ҫ��������

		vector<int>::iterator iter = pre.begin();
		vector<int>::const_iterator VauleIter;

		//��������
		while ((VauleIter = find(vin.begin(), vin.end(), *iter)) == pre.end()) {
			iter++;
		}
		if (VauleIter == pre.end()) {
			return nullptr;
		}
		//int k = *(pre.begin());
		TreeNode*root = new TreeNode(*VauleIter);
		//vector<int>::iterator index = find(vin.begin(), vin.end(),*VauleIter);

		//�ҿ�����
		vector<int> newLeftVin(vin.begin(), VauleIter + 1);
		vector<int> newRigthVin(VauleIter + 1, vin.end());

		//vector<int> newLeftVin(vin.begin(),);
			  //pre��Ӧ�ú�iter�й�
		vector<int> newPre(iter + 1, pre.end());
		root->left = reConstructBinaryTree(newPre, newLeftVin);
		root->right = reConstructBinaryTree(newPre, newRigthVin);

		return root;
	}
};
int main() {
	int *a = new int[5]{ 1,2,3,4,5 };
	for (int i = 0; i < 5; ++i) {
		cout << *(a + i) << ' ';
	}
	cout << endl;
	delete[] a; 

	system("pause");
	return 0;
}



#define N 54


int main() {
	int cnt = 0;
	for (int i = 0; i < 1000; ++i) {
		cnt = rand() % (9-1);
		cout << cnt << " ";
	}
	cout << endl;

	system("pause");
	return 0;
}

void xipai(vector<int>&data) {
	int cnt;
	for (int i = 0; i < N; ++i) {
		cnt = rand() % (N - i);
		swap(data[cnt], data[N - i - 1]);
	}
}

int main() {
	vector<int>data(N);
	for (int i = 0; i < N; ++i) {
		data[i] = i + 1;
	}
	xipai(data);
	for (int i = 0; i < N; ++i) {
		cout << data[i] << " ";
	}

	system("pause");
	return 0;
}


bool isNumberNotOnce(int a[], int length) {
	for (int i = 0; i < length; ++i) {
		while(a[i] != i){
			if (a[i] == a[a[i]]) {
				return true;
			}
			else {
				swap(a[i], a[a[i]]);
			}
		}
	}
	return false;
}

int main() {
	int a[] = { 1,4,5,2,7,8,6,3,0 };
	int len = sizeof(a)/sizeof(a[0]);
	if (isNumberNotOnce(a, len)) {
		cout << "���ظ�������" << endl;
	}
	else {
		cout << "û���ظ�������" << endl;
	}

	system("pause");
	return 0;
}

bool IsDuplicateNumber(int *array, int n){
	if (array == NULL) 
		return false;

	int i, temp;
	for (i = 0; i < n; i++){
		while (array[i] != i){
			if (array[array[i]] == array[i]) {
				return true;
			}
			temp = array[array[i]];
			array[array[i]] = array[i];
			array[i] = temp;
		}
	}
	return false;
}

//���л������뱣��һ��������������Ȼ�����һ��ǰ����ߺ���������
//�����л����������α������ɵĽ���ָ�����������������(ǰ�������)��
TreeNode* helper(vector<int>pre, int startPre, int endPre,
	vector<int>in, int startIn, int endIn){
	if (startPre > endPre || startIn > endIn) {
		return nullptr;
	}
	TreeNode * root = new TreeNode(pre[startPre]);
	for (int i = startIn; i <= endIn; ++i){
		if (in[i] == pre[startPre]){
			root->left = helper(pre, startPre + 1, startPre + i - startIn,
								in, startIn, i - 1);

			root->right = helper(pre, i - startIn + startPre + 1, endPre,
								in, i + 1, endIn);

			break;
		}
	}
	return root;
}
TreeNode* reConstructBinaryTree(vector<int> pre, vector<int> vin){
	TreeNode *root = helper(pre, 0, pre.size() - 1, vin, 0, vin.size() - 1);
	return root;
}

void replaceSpace(const char *str, int length) {
	if (str == nullptr || length <= 0) {
		return;
	}
	int num = 0;
	for (int i = 0; i < length; ++i) {
		if (str[i] == ' ') {
			++num;
		}
	}
	int len = length + (num * 2);
	vector<char>vec(len);
	int j = 0;
	for (int i = 0; i < length; ++i) {
		if (str[i] == '  ') {
			vec[j++] = '%';
			vec[j++] = '2';
			vec[j++] = '0';
		}
		else {
			vec[j++] = str[i];
		}
	}
	for (int i = 0; i < len; ++i) {
		cout << vec[i];
	}
	cout << endl;
}

#endif
#if 0
void replaceSpace(const char *str, int length) {
	int num = 0;
	for (int i = 0; i < length; ++i) {
		if (str[i] == ' ') {
			++num;
		}
	}
	int len = length + num * 2 ;
	vector<char>vec;
	vec.reserve(len);
	for (int i = 0; i < length; ++i) {
		if (str[i] != ' ') {
			vec.push_back(str[i]);
		}
		else {
			vec.push_back('%');
			vec.push_back('2');
			vec.push_back('0');
		}
	}
	for (int i = 0; i < len; ++i) {
		cout << vec[i];
	}
	cout << endl;
}
int main() {
	const char* str = "hello world";
	int length = strlen(str);
	replaceSpace(str, length);

	system("pause");
	return 0;
}
#endif
#if 0
int main(){
	int n;
	while (cin >> n) {
		int a[n], dp[n][n];
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			dp[i][i] = a[i];
		}
		for (int i = 1; i < n; i++) {
			for (int j = i - 1; j >= 0; j--) {
				if (a[i] == a[j]) {
					dp[j][i] = dp[j + 1][i - 1] + 2 * a[j];
				}
				else {
					dp[j][i] = min(dp[j + 1][i] + 2 * a[j],
						dp[j][i - 1] + 2 * a[i]);
				}
			}
			cout << dp[0][n - 1] << endl;
		}
		return 0;
	}
}

int BackMinSum(vector<int>&a, int sum) {
	int length = a.size();
	int left = length - 1;
	int right = length + 1;
	//43 35 14 51 2 15 42 39 38 38 39 42 15 2 51 14 35 57 43 
	while (left >= 0 && right < a.size()) {
		if (a[left] < a[right]) {
			sum += a[left];
			--left;
		}
		else if (a[left] > a[right]) {
			sum += a[right];
			--right;
		}
		else {
			--left;
			++right;
		}
	}
	for (int i = 0; i < a.size(); ++i) {
		sum += a[i];
	}
	return sum;
}


int BackMinSum(vector<int>&a, int sum) {
	int start = 0;
	int end = a.size() - 1;
	while (start < end) {
		if (a[start] < a[end]) {
			sum += a[start];
			++start;
		}
		else if (a[start] > a[end]) {
			sum += a[end];
			--end;
		}
		else {
			--end;
			++start;
		}
	}
	for (int i = 0; i < a.size(); ++i) {
		sum += a[i];
	}

	return sum;
}

int main() {
	int n = 0;
	while (cin >> n) {
		vector<int>a;
		a.resize(n);
		for (int i = 0; i < n; ++i) {
			cin >> a[i];
		}
		int sum = 0;
		cout << BackMinSum(a, sum) << endl;
	}

	system("pause");
	return 0;
}

bool Find(int target, vector<vector<int> > array) {
	int row = array.size();
	int col = array[0].size();
	int i = 0;
	while (i < row && col >= 0) {
		if (array[i][col] > target) {
			--col;
		}
		else if (array[i][col] < target) {
			++i;
		}
		else {
			return true;
		}
	}
	return false;
}

int main() {
	int array[3][3] = { {1,2,3},{4,5,6},{7,8,9} };
	vector<vector<int>>vec(3,vector<int>(3));
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			vec[i][j] = array[i][j];
		}
	}
	int target = 5;
	bool flag = Find(target, vec);
	if (flag) {
		cout << "�ҵ���" << endl;
	}
	else {
		cout << "û�ҵ�" << endl;
	}

	system("pause");
	return 0;
}
#endif
#if 0
int main() {
	const char* p = "Heelo World1";

	char a[] = "Hello World2";

	cout << p[2] << endl;

	a[2] = 'A';
	cout << a << endl;

	const char* p1 = "Hello World1";
	// 16384 �ֽ�
	//cout << sizeof(a) / 1024 << endl;
	system("pause");
	return 0;
}
class BOOK  {
private:
	string _bookISBN;  //���ISBN��
	float _price;    //��ļ۸�

public:
	//������һ����Ա������������������Ǹ����ڴ�һ��ʵ��Ϊ�����͵ĺ�����
	//����������ڱȽ��������ISBN���Ƿ���ͬ
	bool isSameISBN(const BOOK & other) {
		return (other._bookISBN == _bookISBN);
	}

	//��Ĺ��캯�������Ǹ����ܹ���һ���������е��õĹ��캯����
	//����Ȼ���������βΣ�������һ����Ĭ��ʵ�Σ�ֻ��һ������Ҳ�ܽ��е��ã�
	BOOK(string ISBN, float price = 0.0f)
		:_bookISBN(ISBN)
		, _price(price) 
	{}
};

int main(){
	BOOK A("A-A-A");
	BOOK B("B-B-B");

	cout << A.isSameISBN(B) << endl;   //�����ؽ��бȽϣ����跢��ת��

	cout << A.isSameISBN(string("A-A-A")) << endl; 
	//�˴�������һ����ʽת����string����-->BOOK���ͣ�
	//����BOOK�Ĺ��캯������ת����������isSameISBN�����Ĳ����ڴ���

	cout << A.isSameISBN(BOOK("A-A-A")) << endl; 
	//��ʽ������ʱ����Ҳ���Ǳ������ɵ����顣

	system("pause");
	return 0;
}

class A {
public:
	A() {
		cout << "hehe" << endl;
	}
	~A() {
		cout << "~hehe" << endl;
	}
	void dispaly()const {
		cout << "display()" << endl;
	}
	void dis() {
		cout << "haha" << endl;
	}

	void dis()const {
		cout << "haha" << endl;
	}
private:
	int a;
};


int main() {

	//A a;
	//a.dispaly();
	//A const a1;
	//a1.dispaly();
	//a.~A();

	system("pause");
	return 0;
}
int main() {
	const char * arr = "123";
	char * brr = "123";
	const char crr[] = "123";
	char drr[] = "123";

	system("pause");
	return 0;
}

#include <iostream>
#include <string>
using namespace std;

int isbig(string s1, string s2) {
	if (s1 == "") {
		return -1;
	}
	if (s2 == "") {
		return 1;
	}
	for (int i = 0; i < s1.size()&& s2.size(); ++i) {
		while (s1[i] != s2[i] && i < s1.size() && i<s2.size()) {
			if (s1[i] > s2[i]) {
				return 1;
			}
			if (s1[i] < s2[i]) {
				return -1;
			}
			++i;
		}
		if (s1[i] == s2[i]) {
			return 0;
		}
	}
}

int main() {
	string str1, str2;
	while (cin >> str1 >> str2) {
		int s = isbig(str1, str2);
		if(s > 0){}
		cout << s << endl;
	}
	return 0;
}

__attribute((constructor))void before(){
	printf("before main\n");
}

int main() {
	//dis();
	cout << "this is main()\n" << endl;
	system("pause");
	return 0;
}

class A {
public:
	A() {
		cout << "A()" << endl;
	}
	~A() {
		cout << "~A()" << endl;
	}
};
class B :public A{
public:
	B() {
		cout << "B()" << endl;
	}
	~B() {
		cout << "~B()" << endl;
	}
};
extern int a;
void test() {
	cout << a << endl;
}
int a = 10;
int main() {
	//dis();
	test();
	cout << a << endl;
	system("pause");
	return 0;
}
#endif
