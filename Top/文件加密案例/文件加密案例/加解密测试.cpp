#define  _CRT_SECURE_NO_WARNINGS 
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "des.h"

/*

//�û�ʹ�õĺ���
int DesEnc(
unsigned char *pInData,
int            nInDataLen,
unsigned char *pOutData,
int           *pOutDataLen);

//�û�ʹ�ú���des����
int DesDec(
unsigned char *pInData,
int            nInDataLen,
unsigned char *pOutData,
int           *pOutDataLen);

*/



int main111()
{
	int		ret = 0;
	char *plain = "1232343444";
	int plainlen = strlen(plain);

	char plain2[4096] = {0};
	int plainlen2 = 0;

	unsigned char cryptbuf[4096] = {0};
	int cryptlen = 0;
	//�û�ʹ�õĺ���
	ret =  DesEnc(plain, plainlen, cryptbuf, &cryptlen);
	if (ret != 0)
	{
		printf("func DesEnc() err:%d \n");
		return ret;
	}

	//�û�ʹ�ú���des����
	ret =   DesDec(cryptbuf, cryptlen,  plain2, &plainlen2);
	if (ret != 0)
	{
		printf("func DesDec() err:%d \n");
		return ret;
	}

	if (plainlen != plainlen2)
	{
		ret = -2;
		printf("���ĳ��Ⱥͽ��ܺ�����ĳ��� ��һ�� \n");
		return ret;
	}

	if (memcmp(plain2, plain, plainlen) == 0 )
	{
		printf("���ĳ��Ⱥͽ��ܺ�����ĳ��� һ�� ok \n");
	}
	else
	{
		printf("���ĳ��Ⱥͽ��ܺ�����ĳ��� ��һ�� err \n");
	}

	system("pause");
	return ret ;
}


int FileSymEnc(const char *pfile1, const char *pfile2)
{
	int		ret = 0;
	FILE *fp1 = NULL, *fp2 = NULL;
	unsigned char plain[4096];
	int plainlen = 0;

	unsigned char cryptbuf[4096] = { 0 };
	int cryptlen = 0;

	int tmplen;

	fp1 = fopen(pfile1, "rb");
	if (fp1 == NULL)
	{
		goto END;
	}

	fp2 = fopen(pfile2, "wb");
	if (fp2 == NULL)
	{
		goto END;
	}

	while (!feof(fp1))
	{
		plainlen = fread(plain, 1, 4096, fp1);
		if (feof(fp1))  //���������Ժ��ж��Ƿ��ļ�����
		{
			break;
		}

		//����==4k������
		ret = DesDec_raw(plain, plainlen, cryptbuf, &cryptlen);
		if (ret != 0)
		{
			printf("func DesEnc() err:%d \n", ret);
			goto END;
		}

		tmplen = fwrite(cryptbuf, 1, cryptlen, fp2);
		if (tmplen != cryptlen)
		{
			ret = -3;
			printf("д�����ļ�ʧ�ܣ������Ƿ��������\n");
			goto END;
		}

		//if (plainlen == 4096)
	}

	//����С��4k������
	ret = DesEnc(plain, plainlen, cryptbuf, &cryptlen);
	if (ret != 0)
	{
		printf("func DesEnc() err:%d \n", ret);
		goto END;
	}

	tmplen = fwrite(cryptbuf, 1, cryptlen, fp2);
	if (cryptlen != tmplen)
	{
		ret = -3;
		printf("дС��4k�ļ�����ʧ�ܣ������Ƿ��������\n");
		goto END;
	}

END:
	if (fp1 != NULL)
	{
		fclose(fp1);
	}
	if (fp2 != NULL)
	{
		fclose(fp2);
	}
	return 0;
}

void main()
{
	int		ret = 0;
	const char *file1 = "c:/socketclient.dll";
	const char *file2 = "c:/socketclientend.dll";

	//const char *file1 = "c:/22.txt";
	//const char *file2 = "c:/22enc.txt";

	ret = FileSymEnc(file1, file2);
	if (ret != 0)
	{
		printf("func FileSymEnc() err\n ");
		return;
	}

	system("pause");
	return;
}