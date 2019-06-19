#include <assert.h>
#include <iostream>
#include <stdlib.h>

using namespace std;

class Mystring {
public:
	Mystring(const char* str = "")
		:_str(new char[strlen(str)]+1)
	{
		if (str == nullptr) {
			assert(false);
			return;
		}
		strcpy(_str, str);
	}

	~Mystring() {

	}


	Mystring(const Mystring&s) 
		:_str(new char[strlen(s._str) + 1])
	{
		//�������캯���������������һ���ڴ�
		//Ȼ���ٰѶ�Ӧ��ֵ��������û�п�����ַ
		strcpy(_str, s._str);
	}

private:
	char* _str;
};

int main(){



	system("pause");
	return 0;
}