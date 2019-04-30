#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>

#define MAX_CMD 1024
char command[MAX_CMD];

int do_face()
{
	memset(command, 0x00, MAX_CMD);
	//memset����������һ���ڴ�������ĳ��������ֵ��
	//		  ���ǶԽϴ�Ľṹ�������������������һ����췽�� [1] 
	//memset()����ԭ����extern void *memset(void *buffer, int c, int count)
	//buffer��Ϊָ���������, c���Ǹ���buffer��ֵ, count����buffer�ĳ���.

	printf("minishell$ ");
	fflush(stdout);//ˢ�±�׼������������ѻ�������Ķ�����ӡ����׼�豸��

	if (scanf("%[^\n]%*c", command) == 0)//�ӻ�����ȡ����ֱ������\n����\nȡ��������
	{
		//�������0����ʧ��
		getchar();	//��ȡ���з��������ֻ�ܽ���һ���ַ�
		return -1;
	}
	//scanf(%[^\n]%*c)��ʾ����һ���ַ���
	return 0;
}

char **do_parse(char *buff)
{
	int argc = 0;
	static char *argv[32];
	char *ptr = buff;
	while (*ptr != '\0')//��û��Խ��������
	{
		if (!isspace(*ptr))//���ptr��һ�����ǿհ��ַ��Ļ�
		{
			argv[argc++] = ptr;//���Ȱ�ptr��ֵ��argv[argc] ��argc++;
			
			//
			while ((!isspace(*ptr)) && (*ptr) != '\0')
			{
				ptr++;
			}
		}

		else
		{
			while (isspace(*ptr))
			{
				*ptr = '\0';
				ptr++;
			}
		}
	}

	argv[argc] = NULL;
	return argv;
}

int do_exec(char *buff)
{
	char **argv = { NULL };
	int pid = fork();
	
	//	�ڼ���ѧϰ��֪ʶǰ��������˼�������ͽ���֮���������
	//	exec / exit����call / return
	//	һ��C�����кܶຯ����ɡ�һ���������Ե�������һ��������ͬʱ���ݸ���һЩ�����������õĺ���ִ��һ����
	//	������Ȼ�󷵻�һ��ֵ��ÿ�������������ľֲ���������ͬ�ĺ���ͨ��call / returnϵͳ����ͨ�š�
	//	����ͨ�������ͷ���ֵ��ӵ��˽�����ݵĺ�����ͨ�ŵ�ģʽ�ǽṹ��������ƵĻ�����Linux����������Ӧ���ڳ�
	//	��֮�ڵ�ģʽ��չ������֮�䡣����ͼ
	//	һ��C�������fork / exec��һ�����򣬲�������һЩ��������������õĳ���ִ��һ���Ĳ�����Ȼ��ͨ��exit(n)��
	//	����ֵ���������Ľ��̿���ͨ��wait��&ret������ȡexit�ķ���ֵ��
		if (pid == 0) {
			argv = do_parse(buff);
			if (argv[0] == NULL) {
				exit(-1);
			}
			execvp(argv[0], argv);
		}
		else {
			waitpid(pid, NULL, 0);
		}
	return 0;
}

int main(int argc, char *argv[])
{
	while (1) {
		if (do_face() < 0)
			continue;
		do_exec(command);
	}
	return 0;
}