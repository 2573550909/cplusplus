//д��һ�����򣬽���һ���ַ�����Ȼ��������ַ�����ת����ַ�����
//��������������N���ַ�
//���������������ַ�����ת����ַ���
//��1  ���룺abcd �����dcba
#include <string>
#include <iostream>
#include <stdlib.h>
using namespace std;

string ReverseString(string& s) {
	size_t start = 0;
	size_t end = s.size() - 1;
	while (start < end) {
		swap(s[start], s[end]);
		++start;
		--end;
	}
	return s;
}

int main()
{
	string str;
	while (getline(cin, str)) {
		cout << ReverseString(str);
	}

	return 0;
	string str;
	string temp;
	while (cin >> str) {
		int i = 0;
		int len = str.size();
		temp.resize(len);
		while (len) {
			temp[i] = str[--len];
			++i;
		}
		cout << temp << endl;
	}


	system("pause");
	return 0;
}