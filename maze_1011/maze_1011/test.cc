#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdlib.h>
#include <string>
#include <map>
#include <stack>
using namespace std;

class ListNode {
public:
	int val;
	ListNode *next;
};
class Solution {
public:
	stack<ListNode*>sta1;
	stack<ListNode*>sta2;
	ListNode* FindFirstCommonNode(ListNode* pHead1, ListNode* pHead2) {
		if (pHead1 == nullptr || pHead2 == nullptr) {
			return nullptr;
		}
		while (pHead1 != nullptr) {
			sta1.push(pHead1);
			pHead1 = pHead1->next;
		}
		while (pHead2 != nullptr) {
			sta2.push(pHead2);
			pHead2 = pHead2->next;
		}
		ListNode* top1 = sta1.top();
		ListNode* top2 = sta2.top();
		while (top1->val == top2->val) {
			sta1.pop();
			sta2.pop();
			top1 = sta1.top();
			top2 = sta2.top();
		}
		return top1->next;
	}
};

int main() {
	ListNode* a1 = new ListNode[1];
	ListNode* a2 = new ListNode[2];
	ListNode* a3 = new ListNode[3];
	ListNode* p1 = new ListNode[4];
	ListNode* p2 = new ListNode[5];
	ListNode* m1 = new ListNode[6];
	ListNode* m2 = new ListNode[7];
	a1->next = a2; a2->next = a3; a3->next = m1; 
	m1->next = m2; m2->next = nullptr;
	p1->next = p2; p2->next = m1;

	system("pause");
	return 0;
}
#if 0
int FirstNotRepeatingChar(string str) {
	if (str.size() == 0) {
		return -1;
	}
	int arr[256] = { 0 };
	for (size_t i = 0; i < str.size(); ++i) {
		arr[str[i]]++;
	}


	return -1;
}
#endif

#if 0
int FirstNotRepeatingChar(string str) {
	map<char, int> mp;
	for (int i = 0; i < str.size(); ++i) {
		mp[str[i]]++;
	}
	for (int i = 0; i < str.size(); ++i) {
		if (mp[str[i]] == 1) {
			return i;
		}
	}
	return -1;
}

#endif
#if 0
int main() {
	string s = "google";
	cout << FirstNotRepeatingChar(s) << endl;

	system("pause");
	return 0;
}

void LoopMove(char* pStr,int steps){
	if (pStr == nullptr) {
		return;
	} 
	int len = strlen(pStr);
	char temp[1024];
	strcpy(temp, pStr + len - steps);
	strcpy(temp + steps, pStr);
	*(temp + len) = '\0';
	strcpy(pStr, temp);
}
#endif

// ��дһ�����������ǰ�һ��char���
// ���ַ���ѭ������n��
// ���磺ԭ����abcdefghi ���n = 2,
// ��λ�� Ӧ���� hiabcdefg 
#if 0
void LoopMove(char* pStr,int steps){
	if (pStr == nullptr) {
		return;
	} 
	char temp[1024];
	int len = strlen(pStr);
	memcpy(temp, pStr + len-steps, steps);
	memcpy(temp + steps, pStr, len - steps);
	memcpy(pStr, temp, len);
}
#endif

#if 0
class String {
public:
	String(const char*str = nullptr) {
		if (str == nullptr) {
			str = "";
		}
		m_data = new char[strlen(str) + 1];
		strcpy(this->m_data,str);
	}
	~String(void) {
		if (m_data != nullptr) {
			delete[] m_data;
			m_data = nullptr;
		}
	}
	// �������캯��
	String(const String &s) {
		//�ȹ���һ����ʱ�Ķ���
		String strTemp(s.m_data);
		// m_data ָ���ǵ�ǰ�����m_data ,����ʡ����this
		swap(this->m_data, strTemp.m_data);
	}

	//��ֵ��������� ����1
	String &operator = (const String&other) {
		if (this != &other) {
			char* temp  = new char[strlen(other.m_data) + 1];
			strcpy(temp, other.m_data);
			delete m_data;
			m_data = temp;
		}
		return *this;
	}
	//��ֵ��������� ����2
	String& operator = (const String &s) {
		if (this != &s) {
			String strTemp(s.m_data);
			swap(this->m_data, strTemp.m_data);
		}
		return *this;
	}
	//��ֵ��������� ����3
	String& operator = (String s) {
		swap(this->m_data, s.m_data);
		return *this;
	}

private:
	char* m_data;
};

class String {
public:
	String(const char* str = nullptr) {
		if (str == nullptr) {
			m_data = new char[1];
			*m_data = '\0';
		}
		else {
			int length = strlen(str);
			m_data = new char[length + 1];
			strcpy(m_data, str);
		}
	}
	~String(void) {
		delete[] m_data;
	}
	String(const String&other) {
		int length = strlen(other.m_data);
		m_data = new char[length + 1];
		strcpy(m_data, other.m_data);
	}

	String& operator=(const String& other) {
		if (this == &other) {
			return *this;
		}
		delete[]m_data;
		int length = strlen(other.m_data);
		m_data = new char[length + 1];
		strcpy(m_data, other.m_data);
		return *this;
	}
private:
	char* m_data;
};

int main() {
	String s2("hello");
	String s1;
	s1 = s2;

	//string s = "ss";
	//s.append("abcde");
	//cout << s << endl;

	//string s("hello,bit!!!");
	//cout << s.length() << endl;//12
	//cout << s.size() << endl;//12
	//// capacity��һ�����ʱ���Զ�����15������
	//cout << s.capacity() << endl;//15
	//cout << s << endl;//hello,bit!!!

	//s.clear();
	//cout << s.size() << endl;//0
	//cout << s.capacity() << endl;//15

	//string file("string.cpp");
	////�ҵ�.���ַ�����λ�� �� 6
	//size_t pos = file.rfind('.');
	//// substr ������ �� pos λ�ÿ�ʼ����ȡ4������  

	////�����ǿ������캯��
	//string suffix(file.substr(pos, file.size() - pos));
	//cout << suffix << endl;

	//string file = "abcd.cpp";
	//// find �������ص��� . ���±� 4
	//size_t pos = file.find('.');
	//// substr �ĵ�һ�������Ǵ��Ŀ�ʼ��ȡ
	////        �ڶ��������ǽ�ȡ�����ַ�
	//string end_name = file.substr(pos+1, file.size() - pos);
	//cout << end_name << endl;

	//string url("http://www.cplusplus.com/reference/string/string/find/");

	//// 4
	//size_t start = url.find("://");

	//if (start == string::npos){
	//	cout << "invalid url" << endl;
	//	return 0;
	//}
	////��һ�� w ��λ��
	//start += 3;
	////��start ��λ���� /��λ�ã�����������λ��
	//size_t finish = url.find('/', start);
	////��start ��ʼ��ȡfinish - start ���ȵ��ַ�����ֵ��address
	//string address = url.substr(start, finish - start);
	//cout << address << endl;

	system("pause");
	return 0;
}

#endif
#if 0
int  a = 10;
class {
	int a = 10;
}
//#ifndef  __INCvxWorksh

//
//#define __INCvxWorksh
//
//#ifdef __cplusplus
//
//extern "C" {
//
//}
//#endif // __cplusplus
//
//#endif // ! __INC

void Func(char str[100]) {
	//������٣�
	printf("%d\n",sizeof(str));

	char string[100] = { 0 };
	//������٣�
	printf("%d\n", sizeof(string));

	void* p = malloc(100);
	//������٣�
	printf("%d\n", sizeof(p));
	free(p);p = nullptr;
}


int main() {

	system("pause");
	return 0;
}

char* Strcpy(char* pStrDest,const char* pStrSrc) {
	//�����³�����ж�
	if (pStrDest == nullptr || pStrSrc == nullptr) {
		return nullptr;
	}
	char* add = pStrDest;
	while ((*pStrDest = *pStrSrc) != '\0') {
		++pStrDest;
		++pStrSrc;
	}
	return add;
}

void GetMemory(char** p,int num) {
	if (num <= 0) {
		printf("������ڴ�̫С��\n");
	}
	*p = (char*)malloc(num);
	if (*p == nullptr) {
		return;
	}
}

void test() {
	char* str = nullptr;
	GetMemory(&str, 100);
	strcpy(str, "hello");
	free(str);
	printf("%s",str);
}

void Test() {
	char*str = (char*)malloc(100);
	strcpy(str, "hello");
	free(str);
}

void swap1(int *p1, int* p2) {
	int *p = p1;
	int *n = p2;
	*p1 = *p;
	p2 = p;
}

void swap2(int& p1, int& p2) {
	int p = p1;
	p1 = p2;
	p2 = p;
}

void isfloatequal(float n1, float n2) {
	const float EPSINON = 0.00001;
	int x = n1 - n2;
	if ((x <= EPSINON)&&(x>=-EPSINON)) {
		printf("�����ж����������\n");
	}
	else {
		printf("����\n");
	}
}

int main() {
	isfloatequal(0.0000001,0.00000002);
	isfloatequal(0.0001,1);
	isfloatequal(100,100.0000001);

	system("pause");
	return 0;
}

union temp{
	int a;
	char b;
}temp;

int main(){
	int a = 0x12345;

	if (*(char*)&a == 0x45) {
		cout << "С��ģʽ" << endl;
	}
	else {
		cout << "���ģʽ" << endl;
	}

	system("pause");
	return 0;
}
#endif	