#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector>
using namespace std;

class String {
public:
	String(const char* str = ""){
		if (str == nullptr) {
			str = "";
		}
		_str = new char[strlen(str) + 1];
		strcpy(_str, str);
	}

	//����posλ�õ��ַ���const string��������
	const char& operator[] (size_t pos)const{
		return _str[pos];
	}

	char& operator[] (size_t pos){
		return _str[pos];
	}

private:
	char * _str;
};

int main()
{



	//String s1("hehe");
	//s1[1] = 'E';

	//String const s2("hehe");
	//cout << s2[0];

	//string& operator+= (const char* s);
	//const char c_str()const;

	system("pause");
	return 0;
}