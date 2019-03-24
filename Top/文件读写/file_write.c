/*
	���õ��ļ�д�����Ļ���ʹ�÷���
		fwrite()
		putc()
		fputs()
		fprintf()
		fflush()
			/*
				fflush������������������д���ļ�
				�����ǣ�������Ϊͣ�磬���ߵ��������ȹ��ϵ��»����������ݶ�ʧ
				���õģ�Ӳ�̶�д�������ӣ����³���Ч�ʵ��£�ͬʱӲ���������
				�޸������ļ���ʱ����ʱ���ʹ�ã�������һЩ�������޸ĵ����ݣ�������Ҫ���ݣ���ô��fflush
			*/
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

struct student
{
	char name[100];
	int age;
};

struct student st1 = { "���»�", 31 };

struct student st5[5] =
{
	{ "���»�", 31 },
	{ "���»�", 32 },
	{ "���»�", 33 },
	{ "���»�", 34 },
	{ "���»�", 35 },
};

char str[1024] = { 0 };

void write_struct_to_file_fwrite(void)
{
	FILE *p = fopen("a.dat", "wb");
		
	// ��һ�֣�һ���ṹ��һ���ṹ���д
	for (int i = 0; i < 5; i++)
	{
		fwrite(&st1, sizeof(struct student), 1, p);
	}

	// �ڶ��֣������ṹ������д��
	fwrite(&st5, sizeof(struct student), 5, p);

	fclose(p);
}

void write_str_to_file_fputs(void)//д�ļ�
{
	//	"w"��˼��������ļ������ڣ��ͽ���һ��������ļ����ھ͸���
	FILE *p = fopen("a.txt", "w");
	fputs(str, p);
	fclose(p);
}

void write_char_to_file_putc(void)
{
	FILE *p = fopen("a.txt", "w");
	if (NULL == p)
	{
		printf("error\n");
		return;
	}
	else
	{
		putc('a', p);
		putc('b', p);
		putc('c', p);
		fclose(p);
	}
}

void write_str_to_file_fprintf(void)
{
	FILE *p = fopen("a.txt", "w");
	fprintf(p, "%s\n", str);
	fclose(p);
}


void write_immediately_to_file_fflush(void)
{
	FILE *p = fopen("a.txt", "w");
	fprintf(p, "%s\n", str);
	fflush(p);		
	fclose(p);
}