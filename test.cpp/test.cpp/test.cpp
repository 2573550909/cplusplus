#include <iostream>
#include <vector>
using namespace std;

int main(){
	try {
		vector<int> v(10, 5);
		 �������ϵͳ�ڴ治��Ҳ�����쳣
		v.reserve(1000000000);
		 ����Խ������쳣
		v.at(10) = 100;
		 ���ﲶ�������Ϳ���
	}catch (const exception& e) {
		cout << e.what() << endl;
	}catch (...){
		cout << "Unkown Exception" << endl;
	}

	return 0;
}
class Exception{
protected:
	string _errmsg;
	int _id;
	//list<StackInfo> _traceStack;
	// ...
};

class SqlException : public Exception{};
class CacheException : public Exception{};
class HttpServerException : public Exception{};

int main(){
	try {
		// server.Start();
		// �׳����������������
	}
	catch (const Exception& e) // ���ﲶ�������Ϳ���
	{}

	catch (...){
		cout << "Unkown Exception" << endl;
	}

	return 0;
}
double Division(int a, int b){
	// ��b == 0ʱ�׳��쳣
	if (b == 0){
		throw "Division by zero condition!";
	}
	return (double)a / (double)b;
}

void Func(){
	// ������Կ������������0�����׳��쳣�����������arrayû�еõ��ͷš�
	// �������ﲶ���쳣�󲢲������쳣���쳣���ǽ������洦��
	//���ﲶ�����������׳�ȥ��
	int* array = new int[10];
	try {
		int len, time;
		cin >> len >> time;
		cout << Division(len, time) << endl;
	}catch (...){
		cout << "delete []" << array << endl;
		delete[] array;
		throw;
	}

	// ...
	cout << "delete []" << array << endl; 
	delete[] array;
}

int main(){
	try{
		Func();
	}catch (const char* errmsg){
		cout << errmsg << endl;
	}

	return 0;
}

double Division(int a, int b){
	// ��b == 0ʱ�׳��쳣
	if (b == 0) {
		throw "Division by zero condition!";
	}else {
		return ((double)a / (double)b);
	}
}

void Func(){
	int len, time;
	cin >> len >> time;
	cout << Division(len, time) << endl;
}

int main() {
	try {
		Func();
	}

	catch (const char* errmsg){
		cout << errmsg << endl;
	}

	catch (...){
		cout << "unkown exception" << endl;
	}

	return 0;
}