#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX 111111 //����¼��

struct dict
{
	char *key;//����
	char *content;//������Ӧ�ķ���
};

//���ֵ��ļ�������ȡ�ļ�����
int open_dict(struct dict **p, const char *dict_filename)
{
	FILE *pfile = fopen(dict_filename, "r");
	if (pfile == NULL)
		return 0;//���ļ�ʧ�ܣ���������

	*p = (struct dict *)malloc(sizeof(struct dict) * MAX);//�̶�����MAX��С�ڴ�
	memset(*p, 0, sizeof(struct dict) * MAX);//�������ڴ��ʼ��Ϊ0
	struct dict *pD = *p;//pDָ������p���׵�ַ

	char buf[1024] = { 0 };
	size_t len = 0;
	int i = 0;//������
	while (!feof(pfile))//ѭ����ȡ�ļ���ֱ���ļ�ĩβ
	{
		memset(buf, 0, sizeof(buf));
		fgets(buf, sizeof(buf), pfile);//��ȡ�ļ�һ��
		len = strlen(buf);//�õ���ȡ���ַ�������
		if (len > 0)
		{
			pD[i].key = (char *)malloc(len);//�����ַ������ȷ����ڴ�
			memset(pD[i].key, 0, len);
			strcpy(pD[i].key, &buf[1]);//����ȡ�������ݿ�����key��
		}

		memset(buf, 0, sizeof(buf));
		fgets(buf, sizeof(buf), pfile);
		len = strlen(buf);
		if (len > 0)
		{
			pD[i].content = (char *)malloc(len);
			memset(pD[i].content, 0, len);
			strcpy(pD[i].content, &buf[6]);
		}

		i++;//��������1
	}
	fclose(pfile);//�ر��ֵ��ļ�

	return i;//���ض�ȡ�����ֵ������
}

//���ݹؼ���key,���ֵ��в�������
int search_dict(const struct dict *p, int size, const char *key, char *content)
{
	int i = 0;
	for (i = 0; i < size; i++)//�����ֵ�
	{
		if ((p[i].key == NULL) || (p[i].content == NULL))
			continue;

		if (strncmp(p[i].key, key, strlen(key)) == 0)
		{
			strcpy(content, p[i].content);
			return 1;//�ҵ�����������¼������1
		}
	}
	return 0;//û���ҵ�����������¼������0
}

//�ͷ��ڴ�
void free_dict(struct dict *p, int size)
{
	int i = 0;
	for (i = 0; i < size; i++)//ѭ���ͷ�key��content��Ա�ڴ�
	{
		if (p[i].key)
			free(p[i].key);
		if (p[i].content)
			free(p[i].content);
	}
	free(p);//�ͷ�p�ڴ�
}


int main(int argc, char *args[])
{
	if (argc < 2)
	{
		printf("usage: %s dict-filename\n", args[0]);
		return 0;//�������㣬�����˳�
	}
	long start_ms = 0;//��¼����ִ�еĿ�ʼʱ��
	long end_ms = 0;//��¼����ִ�еĽ���ʱ��
	struct dict *p = NULL;
	start_ms = clock();//��¼����ִ�еĿ�ʼʱ�䣬��λ������
	int size = open_dict(&p, args[1]);//���������е�һ��������Ϊ�ֵ��ļ��������ֵ��ļ�
	if (size == 0)
		return 0;//���ֵ��ļ�ʧ�ܣ������˳�

	end_ms = clock();//�õ�ϵͳ��ǰʱ�䣬��λ������
	printf("open_dict used %ld ms\n", end_ms - start_ms);//��ӡ����ִ��ʱ�䣬��λ������

	char key[1024];
	char content[1024];
	while (1)
	{
		memset(key, 0, sizeof(key));
		memset(content, 0, sizeof(content));
		scanf("%s", key);//�Ӽ��̵õ��û�����
		if (strncmp(key, "command=exit", 12) == 0)
			break;
		start_ms = clock();
		if (search_dict(p, size, key, content))//�����û����룬���ֵ��м���
		{
			printf("%s", content);
		} else
		{
			printf("not found\n");
		}
		end_ms = clock();
		printf("search_dict used %ld ms\n", end_ms - start_ms);//��ӡ����ִ��ʱ�䣬��λ������
	}

	start_ms = clock();
	free_dict(p, size);
	end_ms = clock();
	printf("free_dict used %ld ms\n", end_ms - start_ms);//��ӡ����ִ��ʱ�䣬��λ������
	return 0;
}
