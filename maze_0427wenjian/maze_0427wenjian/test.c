#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

int main()
{

	FILE* fp = fopen("d:/tex.txt", "wb");
	fwrite("aa", 1, 4, fp);
	fclose(fp);
	fp = NULL;
	system("pause");
	return 0;
}

//int main()
//{
//
//	//��һ��������һ��·�������Ժ���Զ��У�
//	//�ڶ��������Ǵ򿪷�ʽ��rֻ��  wֻд  a׷��
//	//�ļ�ָ��Ҳ���Խ� ���
//	FILE* fp = fopen("d:/text.txt","w");
//	//strerror
//	if (fp == NULL)
//	{
//		printf("�ļ���ʧ�ܣ�%s\n",strerror(errno));
//		system("pause");
//		return 1;
//	}
//	//�����ݴ��ڴ���д��������
//	//char buf[1024] = "maze";
//	//fwrite(buf,1,strlen(buf),fp);
//
//	fprintf(fp, "a=%d\n", 10);
//	
//	//�ļ��������д
//	//fseek(fp,);
//
//	////fread�Ѵ��̶����ڴ���
//	//char buf[1024] = { 0 };
//	//fread(buf,1,4,fp);
//	//printf("%s\n", buf);
//	//������ļ������ǹرգ���զ�죿
//	//һ���ļ��򿪵����������޵ģ�����ɾ��й¶����Դй¶/�ļ�������й¶��
//	fclose(fp);
//
//	system("pause");
//	return 0;
//}

//�����ļ�
//�����ļ�
//�ļ���

//C:\Users\lenovo\Desktop\C���Խ���
//����·��

//.txt  .c   
//�ı��ļ�   �������ļ�

//��������

//10000
//�����ַ���д���ļ���Ҫ5���ֽڣ��ı��ļ�����
//�����������Ƕ������ļ���Ҫд��2���ֽ�
