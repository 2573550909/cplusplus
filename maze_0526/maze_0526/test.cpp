#include <iostream>
#include <stdlib.h>
#include <string>
using namespace std;

int main()
{	

	string line;
	 ��Ҫʹ��cin>>line,��Ϊ���������ո�ͽ�����
	 while(cin>>line)
	while (getline(cin, line))
	{
		size_t pos = line.rfind(' ');
		cout << line.size() - pos - 1 << endl;
	}


	string url("http://www.cplusplus.com/reference/string/string/find/");
	cout << url << endl;
	strst��ð�ŵ�λ��
	size_t start = url.find("://"); 

	if (start == string::npos)
	{
		cout << "invalid url" << endl;
		return 0;
	}
	//��һ�� w ��λ��
	start += 3;
	size_t finish = url.find('/', start);
	string address = url.substr(start, finish - start);
	cout << address << endl;

	size_t pos = url.find("://");
	url.erase(0, pos + 3);
	cout << url << endl;

	string file("string.cpp");
	size_t pos = file.rfind('.');
	string suffix(file.substr(pos, file.size() - pos));
	cout << suffix << endl;


	string str = "hello maze";
	s.push_back('a');
	s.append("bbb");
	cout << str << endl;
	cout << str.c_str() << endl;

	string s = "hello maze";
	const string s1 = "hehe";
	cout << s << " " << s1 << endl;
	cout << s[0] << " " << s1[0] << endl;

	s[0] = 'H';
	cout << s[0] << endl;
	s1[0] = 'H';
	string s;
	// ����reserve�Ƿ��ı�string����ЧԪ�ظ���
	s.reserve(100);
	cout << s.size() << endl;
	cout << s.capacity() << endl;
	// ����reserve����С��string�ĵײ�ռ��Сʱ���Ὣ�ռ���С
	s.reserve(50);
	cout << s.size() << endl;
	cout << s.capacity() << endl;


	
	s.resize(25);
	cout << s.capacity() << endl;


	string s;

	s.resize(10, 'a');
	cout << s.size() << endl;
	cout << s.capacity() << endl;
	// ��s����Ч�ַ��������ӵ�15�������λ����ȱʡֵ'\0'�������
	// "aaaaaaaaaa\0\0\0\0\0"
	// ע���ʱs����Ч�ַ������Ѿ����ӵ�15��
	s.resize(15);
	cout << s.size() << endl;
	cout << s.capacity() << endl;
	cout << s << endl;
	// ��s����Ч�ַ�������С��5��
	//��Ч�ַ�������С����������������С
	s.resize(5);
	cout << s.size() << endl;
	cout << s.capacity() << endl;
	cout << s << endl;

	string s("hello, bit!!!");
	//�ַ����ĳ���
	cout << s.length();
	//�ַ�������Ч�ַ�����
	cout << s.size() << endl;
	//�ַ������������ռ��ܴ�С
	cout << s.capacity() << endl;
	cout << s << endl;

	s.resize(20, 'a');
	
	//s.clear();
	cout << s.length();
	//�ַ�������Ч�ַ�����
	cout << s.size() << endl;
	//�ַ������������ռ��ܴ�С
	cout << s.capacity() << endl;
	cout << s << endl;

	s.resize(5, 'a');
	cout << s.length() << endl;
	cout << s.size() << endl;
	cout << s.capacity() << endl;
	//��C��ʽ�ַ����������str1
	string str1 = "haha";
	//��������str2
	string str2(str1);
	//��10���ַ�q ����str3
	string str3(10, 'q');
	//��str1�е�ǰ2���ַ�����str4
	string str4(str1, 2);


	system("pause");
	return 0;
}3