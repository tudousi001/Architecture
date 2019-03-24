/*
	���õĶ�ȡ�ļ������Ļ���ʹ�÷���
		fgets()
		getc()
		fread()
		fscanf()
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>
struct student
{
	char name[100];
	int age;
};

struct student st1 = { 0 };

struct student st5[5] = { 0 };

char c = 0;

int a = 0;
int b = 0;

/*
	feof(p);
		����Ѿ������ļ���β������������
		���û�е��ļ���β����ô��һֱѭ��
*/
void read_str_form_file_fgets(void)
{
	char s[1024] = { 0 };
	FILE *p = fopen("D:\\temp\\a.txt", "r");//�ö��ķ�ʽ��һ���ļ�
	if (NULL == p)
	{
		printf("error\n");
		return;
	}
	else
	{
		while (!feof(p))
		{
			memset(s, 0, sizeof(s));
			fgets(s, sizeof(s), p);		//��һ��������һ���ڴ��ַ���ڶ�������������ڴ�Ĵ�С��������������fopen���ص��ļ�ָ��
		}
		fclose(p);
	}
}

void read_char_form_file_getc(void)
{
	FILE *p = fopen("a.txt", "r");
	if (p == NULL)
	{
		printf("error\n");
		return;
	}
	else
	{
		while ((c = getc(p)) != EOF)//EOF�����ļ�����һ��������ʾ
		{
			//c = getc(p);//һ��ֻ��ȡһ���ַ�
			printf("%c", c);
		}
		fclose(p);
	}
}

void read_struct_form_file_fread(void)
{
	// ��һ�ַ���:����һ���ṹ�������ÿһ�ξͶ�һ���ṹ������ݣ��ظ���ȡ
	FILE *p = fopen("a.dat", "rb");
	for (int i = 0; i < 5; i++)
	{
		size_t ret = fread(&st1, sizeof(struct student), 1, p);
		printf("name = %s, age = %d\n", st1.name, st1.age);
	}

	// �ڶ��ַ���������һ���ṹ�����飬һ�ζ���һ���ṹ������
	fread(&st5, sizeof(struct student), 5, p);

	fclose(p);
}

void read_str_form_file_fscanf(void)
{
	FILE *p = fopen("a.txt", "r");
	while (!feof(p))
	{
		//fscanf��scanf�÷�����һ�£�fscanf�Ǵ�һ���ļ���ȡ���룬scanf�ǴӼ��̶�ȡ����
		fscanf(p, "%d + %d =", &a, &b);
		printf("a = %d, b = %d\n", a, b);
	}
	fclose(p);
	return 0;
}

void read_file_to_memory(void)
{
	clock_t c1 = clock();		//�õ�ϵͳ��ǰʱ�䣬��λ������

	struct stat st = { 0 };		//����һ���ṹ�����ֽ�st
	stat("a.txt", &st);			//������stat����֮��a.txt����ļ�����ص���Ϣ�ͱ�������st�ṹ����
	
	//st.st_size�õ��ļ��Ĵ�С
	char *array = malloc(st.st_size);//�����ļ���С�ڶ��ж�̬�ķ���һ���ڴ�
	FILE *p = fopen("a.txt", "rb");
	fread(array, sizeof(char), st.st_size, p);//�൱��һ�°������ļ��������ڴ�
	fclose(p);

	p = fopen("b.txt", "wb");
	fwrite(array, sizeof(char), st.st_size, p);//�����е���Ϣһ�¶�д���ļ�
	fclose(p);

	clock_t c2 = clock();			//�õ�ϵͳ��ǰʱ�䣬��λ������
	printf("end, %u\n", c2 - c1);	//������������̺ķѵ�ʱ��
}




