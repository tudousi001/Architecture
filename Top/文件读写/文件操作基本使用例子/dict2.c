#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct dict
{
	char *key;
	char *content;
	struct dict *next;//ָ��������һ���ڵ��ָ��
};

//���ֵ��ļ�������ȡ�ļ�����
int open_dict(struct dict **p, const char *dict_filename)//open dict.txt,and read dict
{
	FILE *pfile = fopen(dict_filename, "r");//ֻ����ʽ���ļ�
	if (pfile == NULL)
		return 0;//���ļ�ʧ�ܣ���������

	char buf[2048] = { 0 };
	size_t len = 0;
	int i = 0;//����������¼�������Ĵ�������

	*p = (struct dict *)malloc(sizeof(struct dict));//���������׽ڵ��ڴ�
	memset(*p, 0, sizeof(struct dict));

	struct dict *pD = *p;//pDָ�������׵�ַ
	while (!feof(pfile))//ѭ����ȡ�ļ���ֱ���ļ�ĩβ
	{
		memset(buf, 0, sizeof(buf));
		fgets(buf, sizeof(buf), pfile);//��ȡ�ļ�һ��
		len = strlen(buf);//�õ���ȡ���ַ�������
		if (len > 0)
		{
			pD->key = (char *)malloc(len);//�����ַ������ȷ����ڴ�
			memset(pD->key, 0, len);
			strcpy(pD->key, &buf[1]);//����ȡ�������ݿ�����key��
		}

		memset(buf, 0, sizeof(buf));
		fgets(buf, sizeof(buf), pfile);
		len = strlen(buf);
		if (len > 0)
		{
			pD->content = (char *)malloc(len);
			memset(pD->content, 0, len);
			strcpy(pD->content, &buf[6]);
		}
		pD->next = (struct dict *)malloc(sizeof(struct dict));//Ϊ�������һ���ڵ�����ڴ�
		memset(pD->next, 0, sizeof(struct dict));

		pD = pD->next;//��pDָ����һ���ڵ�λ��
		i++;
	}
	fclose(pfile);//�ر��ֵ��ļ�
	return i;//���ض�ȡ�����ֵ������
}

//���ݹؼ���key,���ֵ��в�������
int search_dict(const struct dict *p, int size, const char *key, char *content)
{
	const struct dict *pD = p;
	while (pD)//�����ֵ�
	{
		if ((pD->key) && (pD->content))
		{
			if (strncmp(pD->key, key, strlen(key)) == 0)
			{
				strcpy(content, pD->content);
				return 1;//�ҵ�����������¼������1
			}
		}
		pD = pD->next;//ָ��������һ���ڵ�λ��
	}
	return 0;//û���ҵ�����������¼������0
}

//�ͷ������ڴ�
void free_dict(struct dict *p, int size)
{
	struct dict *pD = p;
	while (pD)
	{
		if (pD->key)//ɾ������ڵ���key��Ա�ڴ�
			free(pD->key);
		if (pD->content)//ɾ������ڵ���content��Ա�ڴ�
			free(pD->content);

		struct dict *tmp = pD->next;//����������һ���ڵ�ĵ�ַ
		free(pD);//ɾ������ǰ�ڵ�
		pD = tmp;//pָ����һ���ڵ��λ��
	}
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

	start_ms = clock();
	struct dict *p = NULL;
	int size = open_dict(&p, args[1]);//���������е�һ��������Ϊ�ֵ��ļ��������ֵ��ļ�
	if (size == 0)
		return 0;//���ֵ��ļ�ʧ�ܣ������˳�

	end_ms = clock();
	printf("open_dict used %ld ms\n", end_ms - start_ms);//��ӡ����ִ��ʱ�䣬��λ������

	char key[2048];
	char content[2048];
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
	};

	start_ms = clock();
	free_dict(p, size);//�ͷ������ڴ�
	end_ms = clock();
	printf("free_dict used %ld ms\n", end_ms - start_ms);//��ӡ����ִ��ʱ�䣬��λ������
	return 0;
}
