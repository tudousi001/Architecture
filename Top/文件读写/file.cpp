#include <stdio.h>
#include <string.h>

int main01(void)//д�ļ�
{
	char s[1024] = { 0 };

	//	"w"��˼��������ļ������ڣ��ͽ���һ��������ļ����ھ͸���
	FILE *p = fopen("D:\\temp\\a.txt", "w");

	while (1)
	{
		memset(s, 0, sizeof(s));
		//scanf("%s", s);
		gets_s(s);
		if (strcmp(s, "exit") == 0)
		{
			break;
		}

		int len = strlen(s);
		s[len] = '\n';
		fputs(s, p);
	}

	fclose(p);
	return 0;
}

int main02()
{
	char s[1024] = { 0 };
	FILE *p = fopen("D:\\temp\\main.c", "r");

	//feof(p);//����Ѿ������ļ���β������������
	while (!feof(p))//���û�е��ļ���β����ô��һֱѭ��
	{
		memset(s, 0, sizeof(s));
		fgets(s, sizeof(s), p);//��һ��������һ���ڴ��ַ���ڶ�������������ڴ�Ĵ�С��������������fopen���ص��ļ�ָ��
		printf("%s", s);
	}
	fclose(p);
	return 0;
}

void code(char *s)
{
	while (*s)
	{
		(*s)++;
		s++;
	}
}

void decode(char *s)
{
	while (*s)
	{
		(*s)--;
		s++;
	}
}

int main03()//����
{
	char s[1024] = { 0 };
	FILE *p = fopen("D:\\temp\\a.txt", "r");//�ö��ķ�ʽ��һ���ļ�
	FILE *p1 = fopen("D:\\temp\\b.txt", "w");//��д�ķ�ʽ��һ���ļ�

	//feof(p);//����Ѿ������ļ���β������������
	while (!feof(p))//���û�е��ļ���β����ô��һֱѭ��
	{
		memset(s, 0, sizeof(s));
		fgets(s, sizeof(s), p);//��һ��������һ���ڴ��ַ���ڶ�������������ڴ�Ĵ�С��������������fopen���ص��ļ�ָ��
		code(s);//
		fputs(s, p1);
	}
	fclose(p);
	fclose(p1);
	return 0;
}

int main()//����
{
	char s[1024] = { 0 };
	FILE *p = fopen("D:\\temp\\b.txt", "r");//�ö��ķ�ʽ��һ���ļ�
	FILE *p1 = fopen("D:\\temp\\c.txt", "w");//��д�ķ�ʽ��һ���ļ�
	//feof(p);//����Ѿ������ļ���β������������
	while (!feof(p))//���û�е��ļ���β����ô��һֱѭ��
	{
		memset(s, 0, sizeof(s));
		fgets(s, sizeof(s), p);//��һ��������һ���ڴ��ַ���ڶ�������������ڴ�Ĵ�С��������������fopen���ص��ļ�ָ��
		decode(s);//
		fputs(s, p1);
	}
	fclose(p);
	fclose(p1);
	return 0;
}



