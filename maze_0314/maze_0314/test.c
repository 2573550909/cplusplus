#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

//����������һ�������ַ������г��ֵ��ַ�
char* find_char(char const* source, char const* chars)
{
	assert(source != NULL);
	assert(chars != NULL);
	
	char* pchars = (char*)chars;//XRCQEF// ����ʼ����: ��ͬ�ġ�const���޶���

	while (*pchars!= '\0')
	{
		char* psource = (char*)source;//ABCDEF	����ʼ����: ��ͬ�ġ�const���޶���
		while (*psource != '\0')
		{
			if (*psource != *pchars)
			{
				++psource;
			}
			else
			{
				return psource;//��return��:��char *���롰char���ļ�Ӽ���ͬ
			}
		}
		pchars++;
	}
	return 0;
}//��find_char��: �������еĿؼ�·��������ֵ

int del_substr(char* str, char const *substr)
{
	assert(str != NULL);
	assert(substr != NULL);

	while (*str != '\0')
	{
		char* psubstr = (char*)substr;//CDE//ACD
		char* pstr = (char*)str;//ABCDEFGH
		while (*psubstr != '\0')
		{
			if (*psubstr != *pstr)
			{
				break;
			}
			else
			{
				++pstr;
				++psubstr;
			}
		}
		if (*psubstr == '\0')
		{
			return 1;
		}
		++str;
	}

	return 0;
}

int main()
{
	char str1[] = "ABCDEFGH";
	char str2[] = "CDE";
	char str3[] = "ACD";
	int n = del_substr(str1, str2);
	if (n == 1)
	{
		printf("%s", str1);
	}

	//char str1[] = "ABGDEF";//����ʼ����: �ӡ�char *������int *�������Ͳ�����
	//char str2[] = "XRCQEF"; //��printf��: ��ʽ�ַ�����%c����Ҫ���͡�int���Ĳ�����
	//						//���ɱ���� 1 ӵ�������͡�int *��
	//char* p = find_char(str1, str2);
	//printf("%c", *p);
	//

	//char str[] = "This is a sample string";
	//char keys[] = "aeiouh";
	//printf("%s\n", str);
	//char *pch = strpbrk(str, keys);
	
	//while (pch != NULL)
	//{
	//	printf("%c", *pch);//iiaaei
	//	pch = strpbrk(pch + 1, keys);
	//}
	
	//getchar();
	//int *p = NULL;
	//printf("%d", sizeof(p));
	//printf("%d", sizeof(int));
	



	system("pause");
	return 0;
}
