#include<stdio.h>
#include<stdlib.h>

struct  dangdang
{
	char email[30];
	char name[30];
	char addr[100];
	int num;
	int bignum;
	char tel[20];
	char phone[20];
	double RMB;
} dbdd[4] =
{
	{ "gutingyanmaomao@hotmail.com", "������", "�Ϻ��л�����55��103��", 131, 3, "64247341", "13817188037", 12.30 },
	{ "hongyueliu@263.net", "����h", "ѧ��·�ݳɶ�Է6��¥4��Ԫ602��", 111, 1, "82420196", "13501057351", 49.80 },
	{ "740031305@qq.com", "��Ӣ��", "���ݵ��ӿƼ���ѧ����ɳУ�������ѧԺ", 133, 1901, "0108888", "15869027536", 22.50 },
	{ "qiujx930@163.com", "�ü���", "������·30��304��", 131, 3, "", " 13585662411", 14.00 }
};

void main321()
{
	for (struct dangdang *p = dbdd; p < dbdd + 4; p++)
	{
		printf("\nname=%s,addr=%s,phone=%s", p->name, p->addr, p->phone);
		printf("\nname=%s,addr=%s,phone=%s", (*p).name, (*p).addr, (*p).phone);
	}

	getchar();

}






void main23()
{
	int a[5] = { 1, 2, 3, 4, 5 };
	for (int *p = a; p < a + 5; p++)
		//p++��������������һ�������ĸ��ֽڣ���ѯ�ڴ��ַ
	{
		printf("\n%d,%x", *p, p);
	}




	system("pause");
}