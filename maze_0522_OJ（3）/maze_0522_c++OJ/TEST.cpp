#include <iostream>
#include <string>
using namespace std;

int main()
{
	unsigned int i = 0;
	int max = 0;//��¼������ִ�����
	string ret;//��¼������ִ�
	string str;
	string s;
	int len = 0;
	int n = 10;
	while (n--)
	{
		cin >> str;
		while (i < str.size())
		{
			//ÿһ����Ҫ��ֵΪ0�������ſ��ԱȽϳ������ֵĳ���
			len = 0;
			while (isdigit(str[i]))
			{
				s += str[i++];
				++len;
			}

			if (len >= max)
			{
				max = len;
				ret = s;
				s.clear();
			}
			++i;
		}
	}
	cout << ret << endl;
	return 0;
}

#include <iostream>
#include <vector>
using namespace std;

int main()
{
	unsigned int n = 0;
	unsigned int i = 0;
	while (cin >> n)
	{
		vector<int> a;
		a.resize(n);
		for (; i < n; ++i)
		{
			cin >> a[i];
		}

		unsigned int array[50] = { 0 };
		i = 0;
		for (; i < a.size(); ++i)
		{
			array[a[i]]++;
		}

		i = 0;
		for (; i < a.size(); ++i)
		{
			if (array[a[i]] >= (n/2))
			{
				cout << a[i] << endl;
				break;
			}
		}
	}
	system("pause");
	return 0;
}