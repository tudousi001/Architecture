#include <stdio.h>
#include <stdlib.h>

/*�ļ������д����*/
int main(int argc, char** argv[])
{
	/*���ļ�*/
	FILE* p_file = NULL;
	if ( (p_file = fopen("g://test.bin","wb") ) == NULL )
	{
		printf("���ļ�����\n");
		return 1;
	}

	/*д��һЩ����*/
	for (int i = 0; i < 100; i++)
	{
		fwrite(&i, sizeof(int), 1, p_file);
	}

	/*�ر��ļ�*/
	fclose(p_file);
	
	/*���´��ļ�*/
	p_file = NULL;
	if ((p_file = fopen("g://test.bin", "rb+")) == NULL)
	{
		printf("���ļ�����\n");
		return 1;
	}

	/*ʹ�������������ȡָ��λ�õ�����*/
	/*��ȡ��10������*/
	/*ƫ�������ֽ�Ϊ��λ*/
	/*����˳���ȶ�λ���ٲ���*/
	fseek( p_file, sizeof(int) * 9, SEEK_SET );
	int tmp;
	fread( &tmp, sizeof(int), 1, p_file );
	printf("��ȡ������Ϊ��%d\n", tmp);
	
	/*ȡ������ʮ��Ԫ��*/
	fseek(p_file, -(int)(sizeof(int) * 10 ), SEEK_END);
	fread(&tmp, sizeof(int), 1, p_file);
	printf("��ȡ������Ϊ��%d\n", tmp);

	/*�ӵ�ǰλ�ü���ȡ������Ԫ��*/
	fseek(p_file, sizeof(int)* 3, SEEK_CUR);
	fread(&tmp, sizeof(int), 1, p_file);
	printf("��ȡ������Ϊ��%d\n", tmp);

	fseek(p_file, sizeof(int) * 1000, SEEK_SET);
	fwrite(&tmp, sizeof(int),1, p_file);
	/*��ȡ��ϣ��ر��ļ�*/
	fclose(p_file);
	system("pause");
	return 0;
}