#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

#if 1

vector<int> printMatrix(vector<vector<int> > matrix) {
	int row = matrix.size();
	int col = matrix[0].size();
	vector<int>temp;
	if (row == 0 || col == 0) {
		return temp;
	}
	int left = 0;
	int right = col;
	int up = 0;
	int down = row;
	while (left < right && up < down) {
		//��ӡ�����ҵ�
		for (int i = left; i < right; ++i) {
			temp.push_back(matrix[up][i]);
		}
		up++;
		// ���ϵ��µ�
		for (int i = up; i < down; ++i) {
			temp.push_back(matrix[i][right - 1]);
		}
		--right;
		//���ҵ���
		for (int i = right - 1; i >= left && up != down; --i) {
			temp.push_back(matrix[down - 1][i]);
		}
		--down;
		for (int i = down - 1; i >= up && left != right; --i) {
			temp.push_back(matrix[i][left]);
		}
		++left;
	}
	return temp;
}

int main() {
	vector<vector<int>>vec(4,vector<int>(4,0));
	int n = 1;
	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 4; ++j) {
			vec[i][j] = n;
			++n;
		}
	}
	printMatrix(vec);
	system("pause");
	return 0;
}
vector<int> printMatrix(vector<vector<int> > matrix) {
	int row = matrix.size();
	int col = matrix[0].size();
	vector<int> res;

	// ����Ķ�ά����Ƿ������ؿյ�����
	if (row == 0 || col == 0)  return res;

	// �����ĸ��ؼ���������ʾ���Ϻ����µĴ�ӡ��Χ
	int left = 0, top = 0, right = col - 1, bottom = row - 1;
	while (left <= right && top <= bottom){
		// left to right
		for (int i = left; i <= right; ++i)
			res.push_back(matrix[top][i]);
		// top to bottom
		for (int i = top + 1; i <= bottom; ++i)
			res.push_back(matrix[i][right]);
		// right to left
		if (top != bottom)
			for (int i = right - 1; i >= left; --i)
				res.push_back(matrix[bottom][i]);
		// bottom to top
		if (left != right)
			for (int i = bottom - 1; i > top; --i)  
				res.push_back(matrix[i][left]);

		left++, top++, right--, bottom--;
	}
	return res;
}
vector<int> printMatrix(vector<vector<int> > matrix) {
	vector<int>res;
	res.clear();
	int row = matrix.size();//����
	int collor = matrix[0].size();//����
	//�����ӡ��Ȧ��
	int circle = ((row < collor ? row : collor) - 1) / 2 + 1;//Ȧ��

	for (int i = 0; i < circle; i++) {
		//�������Ҵ�ӡ
		for (int j = i; j < collor - i; j++)
			res.push_back(matrix[i][j]);
		//�������µ�ÿһ������
		for (int k = i + 1; k < row - i; k++)
			res.push_back(matrix[k][collor - 1 - i]);
		//�ж��Ƿ���ظ���ӡ(���������ÿ������)
		for (int m = collor - i - 2; (m >= i) && (row - i - 1 != i); m--)
			res.push_back(matrix[row - i - 1][m]);
		//�ж��Ƿ���ظ���ӡ(�������ϵ�ÿһ������)
		for (int n = row - i - 2; (n > i) && (collor - i - 1 != i); n--)
			res.push_back(matrix[n][i]);
	}
	return res;
}
class Solution {
public:
	bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2){
		if (pRoot2 == NULL || pRoot1 == NULL)
			return false;

		return dfs(pRoot1, pRoot2) 
			|| HasSubtree(pRoot1->left, pRoot2)
			|| HasSubtree(pRoot1->right, pRoot2);
	}
	bool dfs(TreeNode* node, TreeNode* pRoot2) {
		if (pRoot2 == NULL)
			return true;

		else if (node != NULL) {
			return (node->val == pRoot2->val) 
				&& dfs(node->left, pRoot2->left)
				&& dfs(node->right, pRoot2->right);
		}
		else 
			return false;
	}
};
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
}; 

class Solution {
public:
	bool isSubtree(TreeNode *t1, TreeNode *t2) {
		// ��ζ�� t2 �ѽ���������
		if (t2 == NULL) {
			return true;
		}
		// ��ζ�� t1�����꣬����t2��û�У����Է���false
		if (t1 == NULL && t2 != NULL) {
			return false;
		}
		if (t1->val == t2->val) {
			bool lTree = isSubtree(t1->left, t2->left);
			bool rTree = isSubtree(t1->right, t2->right);
			return lTree && rTree;
		}else {
			return false;
		}
	}

	bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2){
		//����ڵ�Ϊ���򷵻�nullptr
		if (pRoot1 == NULL || pRoot2 == NULL) 
			return false;

		// �������һ����˳��ģ���Ҫ���ҵ�ֵһ���Ľڵ�
		return isSubtree(pRoot1, pRoot2) 
			|| HasSubtree(pRoot1->left, pRoot2)
			|| HasSubtree(pRoot1->right, pRoot2);
		// ֱ���ҵ�������ֵ��ȵ������ڵ�
	}
};
#endif

#if 0
struct ListNode {
	int val;
	ListNode *next;
};

int main() {
	ListNode* p1 = new ListNode;
	ListNode* p2 = new ListNode;
	ListNode* p3 = new ListNode;
	ListNode* p4 = new ListNode;
	ListNode* p5 = nullptr;
	p1->next = p2; p2->next = p3;
	p3->next = p4; p4->next = p5;
	p1->val = 1; p2->val = 2;
	p3->val = 3; p4->val = 4;
	ListNode* Node = p1;
	while (Node != nullptr) {
		cout << Node->val << ' ';
		Node = Node->next;
	}
	cout << endl;
	delete p1;
	delete p2;
	delete p3;
	delete p4;
	system("pause");
	return 0;
}


void reOrderArray(vector<int> &array) {
	vector<int>::iterator even = array.begin();
	int size = array.size();
	while (size){
		if (*even % 2 == 0){
			int tmp = *even;
			even = array.erase(even);
			array.push_back(tmp);
		}
		else {
			even++;
		}
		size--;
	}
}

void reOrderArray(vector<int> &array) {
	int size = array.size();
	vector<int>::iterator it = array.begin();
	for (int i = 0; i < size; ++i) {
		if ((*it & 1) == 0) {
			int temp = *it;
			it = array.erase(it);
			array.push_back(temp);
		}
		else {
			++it;
		}
	}
}
#endif

#if 0
void reOrderArray(vector<int>& array) {
	//���λ�ò��䣬�ȶ���
	//���������˼��
	int m = array.size();

	//��¼�Ѿ��ں�λ�õ������ĸ���
	int k = 0;
	// �� k ֮ǰ�����ݶ��Ѿ���������

	for (int i = 0; i < m; i++) {
		if (array[i] % 2 == 1) {
			int j = i;
			// �ҵ�������������ŵ�ż����ǰ��
			while (j > k) {
				int tmp = array[j];
				array[j] = array[j - 1];
				array[j - 1] = tmp;
				j--;
			}
			k++;
		}
	}
}

int main() {
	vector<int>array{ 1,4,5,6,2,3,8,9,4 };
	for (auto& e : array) {
		cout << e << ' ';
	}
	cout << endl;
	reOrderArray(array);
	for (auto& e : array) {
		cout << e << ' ';
	}
	cout << endl;

	system("pause");
	return 0;
}
class A {
	A() {
		printf("A()\n");
	}
public:
	static A& get() {
		static A a;
		return a;
	}
};

// 696609771
int main() {
	A::get();
	// Ҫ��1������һ��ָ����10��Ԫ�ص�����ָ��
	// Ҫ��2������ÿһ��Ԫ����һ������ָ��
	// Ҫ��3���ú����ķ���ֵ�� int 
	// Ҫ��4������������ int*
	// int (*(*p)[10])(int*);

	char s[] = "\\123456\123456\t";
	printf("%d\n", strlen(s));

	int c[4][5] = {
		{0, 1, 2, 3, 8 },
		{4, 7, 6, 7, 9 },
		{10,11,12,13,14},
		{15,16,17,18,19}
	};
	cout << (*c)[1] + 1 << endl;

	int(*pc)[5] = c;
	cout << (*pc[1]+2) << endl;
	cout << *(*(pc+1) + 2) << endl;

	 char str[20];
	str = gets();
	 ����һ���Զ�ȡ��������ַ���ֱ�������س��Ž���
	 gets(str);
	 �﷨����
	str[] = getch();
	 �����ܿո񣬿ո�ᱻ�ŵ��������ȴ���һ�α�ȡ��
	scanf("%s", str);
	 cout << str << endl;
	char a[80] = "0123\1399";
	cout << sizeof(a) << endl;
	// ����\����������ܷ�ת�ƣ�������ܱ�ת������Ѿ���ĩβ��
	cout << strlen(a) << endl;

	�� C�����ǿ���ͨ������ģ�����C++�в����ԣ�
	 ��Ϊsp��������char* ����hello�������� const char*
	char* sp;
	char s[10];
	sp = "hello";

	 ��Ϊ������֪ʶ������׵�ַ���޷���Ϊָ��ȥָ��hello
	char* sp, s[10];
	s = "hello";

	char str1[10] = "computer";
	char str2[10];//û�б���ʼ�� �������̡�
	// ����str1���׵�ַ���ڴ��е�ֵ��computer
	// ���Ե���ҪҪһ��ָ��ȥָ�򣬶�str2Ҳ��һ��������������ָ��
	str2 = str1;

	/* �����ʼ������
	char mark[];
	mark = "program";
	*/

	system("pause");
	return 0;
}

struct Goods{
	string _name;
	double _price;
};

struct Compare{
	bool operator()(const Goods& gl, const Goods& gr){
		return gl._price <= gr._price;
	}
};

int main() {
	Goods gds[] = 
	{ 
		{ "ƻ��", 2.1 }, { "�ཻ", 3 }, 
		{ "����", 2.2 }, {"����", 1.5}
	};
	sort(gds, gds + sizeof(gds) / sizeof(gds[0]), 
		[](const Goods& l, const Goods& r){
		return l._price <= r._price;
	});
	for (int i = 0; i < sizeof(gds) / sizeof(gds[0]);++i) {
		cout << gds[i]._name <<" "<< gds[i]._price << endl;
	}
	cout << endl;

	Goods gds[] = 
	{ 
		{ "ƻ��", 2.1 }, { "�㽶", 3 },
		{ "����", 2.2 }, {"����", 1.5} 
	};
	sort(gds, gds + sizeof(gds) / sizeof(gds[0]), Compare());

	for (auto&e : gds) {
		cout << e._price<<' ';
		cout << e._name << endl;
	}
	cout << endl;

	int a[10] = { 1,4,5,2,7,8,0,6,3,9 };
	std::sort(a, a+sizeof(a) / sizeof(a[0]),less<int>());
	for (auto& e : a) {
		cout << e << ' ';
	}
	cout << endl;


	system("pause");
	return 0;
}
int main() {
	int a = 10;
	int &b = a;

	int a = 10;
	int &&b = a + 1;
	cout << b << endl;

	system("pause");
	return 0;
}

int main(){
	cout << "-------������������ֵ--------" << endl;
	int a = 5;
	int &add_a = a;

	cout << "   a  =" << a << "    " << "    &a = " << &a << endl;
	cout << "add_a =" << add_a << "    " << "&add_a = " << &add_a << endl;

	cout << "-------������������ֵ--------" << endl;
	int b = 10;
	int &&add_b = b + 1;
	cout << "   b  =" << b << "    " << "    &b = " << &b << endl;
	cout << "add_b =" << add_b << "    " << "&add_b = " << &add_b << endl;
	add_b++;
	cout << "add_b++ =" << add_b << "    " << "&add_b++ = " << &add_b << endl;
	cout << "-----------------------" << endl;

	system("pause");
	return 0;
}

class Person{
public:
	Person(string name, char* sex, int age)
		: _name(name)
		, _sex(sex)
		, _age(age)
	{}
	Person(const Person& p)
		: _name(p._name)
		, _sex(p._sex)
		, _age(p._age)
	{}
#if 0
	Person(Person&& p)
		: _name(p._name)
		, _sex(p._sex)
		, _age(p._age)
	{}
#else
	Person(Person&& p)
		: _name(move(p._name))
		, _sex(move(p._sex))
		, _age(p._age)
	{}
#endif
private:
	string _name;
	string _sex;
	int _age;
};

Person GetTempPerson(){
	Person p("prety", "male", 18);
	return p;
}

int main() {
	Person p(GetTempPerson());

	system("pause");
	return 0;
}
class String{
public:
	// ���캯��
	String(const char* str = "") {
		if (str == nullptr) {
			str = "";
		}
		_str = new char[strlen(str) + 1];
		strcpy(_str, str);
	}
	String(const String& str) {
		_str = new char[strlen(str._str) + 1];
		strcpy(_str, str._str);
	}

	// ��ֵ���������
	String& operator=(const String& str) {
		if (this != &str) {
			char* temp = new char[strlen(str._str) + 1];
			strcpy(temp, str._str);
			delete[]_str;
			_str = temp;
		}
		return *this;
	}

	//�ƶ����캯��
	String(String&& s) : _str(s._str){
		s._str = nullptr;
	}

	// ��������
	~String() {
		if (_str) {
			delete[]_str;
			_str = nullptr;
		}
	}

private:
	char* _str;

};

int main(){
	String s1("hello world");
	/*C++11�У�std::move()����λ�� ͷ�ļ��У�����������־����Ի��ԣ�
		�����������κζ�����Ψһ�Ĺ��ܾ��ǣ���һ����ֵǿ��ת��Ϊ��ֵ���ã�
		ͨ����ֵ����ʹ�ø�ֵ��ʵ���ƶ����塣
		ע�⣺��ת������ֵ�����������ڲ�û����������ֵ��ת�����ı䣬
		��std::moveת������ֵ����lvalue���ᱻ���١�*/
	String s2(move(s1));

	String s3(s2);

	system("pause");
	return 0;
}

int main() {
	int a = 10;
	// int&& ra; // ����ʧ�ܣ�û�н��г�ʼ��
	int&& ra = a; // ����ʧ�ܣ�a��һ����ֵ
	// ra����������10�ı���
	//const int&& ra = 10;
	cout << ra << endl;

	system("pause");
	return 0;
}

class String {
public:
	// ���캯��
	String(const char* str = "") {
		if (str == nullptr) {
			str = "";
		}
		_str = new char[strlen(str) + 1];
		strcpy(_str, str);
	}
	String(const String& str) {
		_str = new char[strlen(str._str) + 1];
		strcpy(_str, str._str);
	}

	// ��ֵ���������
	String& operator=(const String& str) {
		if (this != &str) {
			char* temp = new char[strlen(str._str) + 1];
			strcpy(temp, str._str);
			delete[]_str;
			_str = temp;
		}
		return *this;
	}
	// ��������
	~String() {
		if (_str) {
			delete[]_str;
			_str = nullptr;
		}
	}

private:
	char* _str;
};

String GetString(const char* pStr) {
	return String(pStr);
}

int main() {
	// ��һ����������ȡ����
	// �ӳ������������������
	String&& s = GetString("hello");
	
	system("pause");
	return 0;
}
#endif