#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;

int main()
{
	string str1;//hellmdo worldte 
	string str2;// lor
	getline(cin, str1);
	getline(cin, str2);

	 ʹ�ù�ϣӳ��˼����str2ͳ���ַ����ֵĴ���
	int hashtable[256] = { 0 };
	for (size_t i = 0; i < str2.size(); ++i)
	{
		hashtable[str2[i]]++;
	}
	 ����str1��str1[i]ӳ��hashtable��Ӧλ��Ϊ0�����ʾ����ַ���
	 str2��û�г��ֹ�������+=��ret��ע��������ò�Ҫstr1.erases(i)
	 ��Ϊ�߱�������erase�����׳���
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


#include <stdio.h>
#include <stdlib.h>

#include <iostream>
#include <vector>
#include <string>
using namespace std;

void reverse(char* start, char* end)
{
	while (start < end)
	{
		char temp = *start;
		*start = *end;
		*end = temp;
		--end;
		++start;
	}
}

void str_reverse(char* str1)
{
	int len = strlen(str1);
	reverse(str1, str1 + len - 1);
	while (*str1 != '\0')
	{
		char* pos = str1;
		while ((*str1 != ' ') && (*str1 != '\0'))
		{
			str1++;
		}
		reverse(pos, str1 - 1);
		if (*str1 != '\0')
		{
			str1++;
		}
	}
}

int main()
{
	char str[100] = "hellp ";// hello wrold! maze 

	while (1) {
		scanf("%[^\n]", &str);
		str_reverse(str);
	}

	printf("%s\n", str);
	system("pause");
	return 0;
}














int main()
{
	int n;
	while(1){	//�������и���
		cin >> n;

		vector<int> a;
		a.resize(n+1);
		a[n] = 0;

		��������
		int i;
		for (i = 0; i < n; ++i)
		{
			cin >> a[i];
		}

		i = 0;
		int count = 0;
		while (i < n){
			�����һ�����ִ��ڵڶ������֣��ǵ���
			if (a[i] > a[i + 1])
			{
				while (i < n&&a[i] >= a[i + 1])
				{//��һֱ�����ߣ�ֱ��ǰһ������С���һ������
					i++;
				}
				count++;
				i++;
			}

			else if (a[i] < a[i + 1])
			{
				while (a[i] <= a[i + 1])
				{
					i++;
				}
				count++;
				i++;
			}

			else
			{
				i++;
			}
		}
		cout << count << endl;
	}
	system("pause");
	return 0;
}
int main()
{
	 IO��OJ���ܻ��ж��������������������Ҫ������������������������
	int n;
	while (cin >> n)
	{
		long long sum = 0;
		vector<int> a;
		a.resize(3 * n);
		for (int i = 0; i < (3 * n); i++)
		{
			cin >> a[i];
		}
		/*����Ȼ��ȡ�±�Ϊ3n - 2��3n - 4 ��3n - 4... n+2��nλ�õ�Ԫ���ۼӼ��ɣ�
		�൱�±�Ϊ[0,n-1]��n������ÿ�������ߵ�����ʣ�µ�2����������Ϊһ�飬
		���ֵ�����ұߵ������δ�����м�ֵ��������ǰ�����δ��ֵ������*/
		std::sort(a.begin(), a.end());
		reverse(a.begin(), a.end());
		for (int i = 1; i <= 3 * n-2; i += 2)
		{
			sum += a[i];
		}
		cout << sum << endl;
	}
}


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void reverse(char* start, char* end)
{
	while (start < end)
	{
		char tmp = *start;
		*start = *end;
		*end = tmp;
		start++;
		end--;
	}
}

void str_reverse(char* str)
{
	int len = strlen(str);
	reverse(str, str + len - 1);  //ȫ������
	while (*str != '\0')
	{
		char* pos = str;
		while ((*str != ' ') && (*str != '\0'))
		{
			str++;
		}
		reverse(pos, str - 1);    //ÿ�����ʵ�����
		if (*str != '\0')
		{
			str++;
		}
	}
}

int main()
{
	char str[1024];
	printf("ԭ�ַ���:");
	scanf("%[^\n]", &str)

	str_reverse(str);
	printf("��ת����ַ���Ϊ��%s\n", str);

	system("pause");
	return 0;
}

#include <iostream>
#include <stdlib.h>
#include <string>
using namespace std;

int main()
{
	string str1,str2;
	cin>>str2;

	while (cin>> str1)
	{
		str2 = str1 + " " + str2;
	}

	cout << str2 << endl;

	system("pause");
	return 0;
}
#include<iostream>
#include<string>
#include <stdlib.h>
using namespace std;
cin��ȡstringʱ�Զ��ᱻ�ո�ָ���������һ���ַ����洢�����������
int main()
{
	string s1, s2;
	cin >> s2;

	while (cin >> s1)
		s2 = s1 + " " + s2;

	cout << s2 << endl;
	system("pause");
	return 0;
}

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main()
{
	string s;
	 ע������Ҫʹ��getline��cin>>s�����ո�ͽ��ս�����
	getline(cin, s);
	 ��ת��������
	reverse(s.begin(), s.end());
	 ��ת����
	auto start = s.begin();
	while (start != s.end())
	{
		auto end = start;
		while (end != s.end() && *end != ' ')
			end++;
		reverse(start, end);
			if (end != s.end())
				start = end + 1;
			else
				start = end;
	}
	cout << s << endl;
	return 0;
}