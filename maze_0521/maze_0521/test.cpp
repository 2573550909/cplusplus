#include <iostream>
#include <stdlib.h>
#include <string>
using namespace std;

int main()
{
	string str1;//hellmdo worldte 
	string str2;// lor
	getline(cin,str1);
	getline(cin,str2);
	// ʹ�ù�ϣӳ��˼����str2ͳ���ַ����ֵĴ���
	int hashtable[256] = { 0 };
	for (size_t i = 0; i < str2.size(); ++i)
	{
		hashtable[str2[i]]++;
	}
	// ����str1��str1[i]ӳ��hashtable��Ӧλ��Ϊ0�����ʾ����ַ���
	// str2��û�г��ֹ�������+=��ret��ע��������ò�Ҫstr1.erases(i)
	// ��Ϊ�߱�������erase�����׳���
	string ret;
	for (size_t i = 0; i < str1.size(); ++i)
	{
		if (hashtable[str1[i]] == 0)
			ret += str1[i];
	}
	cout << ret << endl;

	system("pause");
	return 0;
}