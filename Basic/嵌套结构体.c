#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

//��һ��
//�ṹ���ڲ��ٴζ���һ���ṹ�壬����û�д����ṹ���ʵ��
//�ٴζ���Ľṹ���ڲ��ı������ᱻ����ĸ�ṹ��ĳ�Ա����
struct tianchao
{
	int data;
	char name[100];
	struct  beijing	 
	{
		char str[100];
		int num;
	};
};

//�ڶ���
//�ṹ���ڲ��ٴζ���һ���ṹ�壬�����ṹ��������ñ�����ֱ����Ϊһ����Ա
struct tianchaoA
{
	int data;
	char name[100];
	struct  beijingA	 
	{
		char str[100];
		int num;
	}b1;	 			//�ڲ�����ĵ�һ�ַ�ʽ
	struct  beijingA  b2;  //�ڲ�����ĵڶ��ַ�ʽ

};

void mainA1()
{
	struct tianchao t1;	 //	�ٴζ���Ľṹ���ڲ��ı������ᱻ����ĸ�ṹ��ĳ�Ա����
	//t1.beijing;
	t1.data = 100;
	t1.num = 99;
	sprintf(t1.name, "goA");
	sprintf(t1.str, "goB");
	printf("%d,%d,%s,%s", t1.data, t1.num, t1.name, t1.str);
	getchar();

}

void mai12123n()
{
	struct tianchaoA  t2;	//�����ṹ��������ñ�����ֱ����Ϊһ����Ա
	                           //�ṹ��Ƕ�ף��ö����������
	t2.b1.num = 100;
	sprintf(t2.b1.str, "ABC");
	printf("%d,%s", t2.b1.num, t2.b1.str);


	t2.b2.num = 100;
	sprintf(t2.b2.str, "ABC");
	printf("\n%d,%s", t2.b2.num, t2.b2.str);
	getchar();

}