#include <iostream>
#include <string>
#include <stdlib.h>
#include <vector>
using namespace std;


// ��֤B����������ַ���A�ж��У�����ÿһ������ĸ���ҪС��B������
int main() {
	string strA, strB;
	while (cin >> strA, cin >> strB) {
		int lenB = strB.size();
		int arr[10000] = { 0 };

		// ��¼ A ������ĸ����Ƿ񳬹��� B������
		bool flagCount = true;
		for (size_t i = 0; i < strA.size(); ++i){
			arr[strA[i]]++;
			if (arr[strA[i]] > lenB) {
				flagCount = false;
			}
		}
		
		int flag = 0;
		for (size_t i = 0; i < strB.size(); ++i) {
			flag = 0;
			for (size_t j = 0; j < strA.size(); ++j) {
				if (strB[i] == strA[j]) {
					flag = 1;
					break;
				}
			}
		}

		if (flag==1 && flagCount==true) {
			cout << "Yes" << endl;
		}else {
			cout << "No" << endl;
		}
	}
	return 0;
}

//int main() {
//	string str;
//	while (getline(cin, str)) {
//		int count = 0;
//		int len = str.size();
//		for (size_t i = 0; i < len; ++i) {
//			if (str[i] == '_') {
//				++count;
//			}
//		}
//		vector<char>v;
//		v.reserve(len - count + 1);
//		for (int i = 0; i < len; ++i) {
//			if (str[i] != '_') { 
//				v.push_back(str[i]);
//			}
//
//			if (str[i] == '_') {
//				v.push_back(str[++i] - 32);
//			}
//		}
//
//		for (char i = 0; i < v.size(); ++i) {
//			cout << v[i];
//		}
//		cout << endl;
//	}
//
//	system("pause");
//	return 0;
//}
//
