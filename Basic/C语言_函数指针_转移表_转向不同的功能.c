//��
/*
	����ָ�룺
		1�����庯��ָ�� typedef (*pfun)()
		2��������Ϣ�б�--ö��
		3��д�����б�
		4: ����ӳ��ṹ��
		5������ӳ���ϵ��ת�Ʊ�
		6�����Ժ���

	�������һ�����ܣ������Ĳ������£�
		1������ʵ�ֺ���
		2������һ����Ϣ
		3��ӳ����Ϣ�����ܺ���
*/


#include <stdio.h>
#include <tchar.h>
#include <filesystem>
#include <stdlib.h>

//����һ������ָ������ pFun pFun1;
typedef int(*pFun)(int a, int b, int c, int *out);

int My_Fun_Sum(int a, int b, int c, int *out)
{
	*out = a + b + c;
	return 0;
}

int My_Fun_QSum(int a, int b, int c, int *out)
{
	*out = a * a + b * b + c * c;
	return 0;
}

int My_Fun_SSum(int a, int b, int c, int *out)
{
	*out = a * a*a + b * b*b + c * c*c;
	return 0;
}

typedef enum MSG_TYPE
{
	ACT_SUM = 1,
	ACT_QSUM = 2,
	ACT_SSUM,
	PROJ2_ACT_2,
	ACT_3,

	ACT_INVALID = 0xff, //16��������
}MSG_TYPE_E;

typedef struct MY_PROC
{
	int act;
	pFun pAct;
}MY_PROC_S;

MY_PROC_S g_astProc[] =
{
	{ ACT_SUM, My_Fun_Sum },
	{ ACT_QSUM, My_Fun_QSum },
	{ ACT_SSUM, My_Fun_SSum },
	{ ACT_INVALID, NULL },
};
/*
	�����ⲿ�����ӹ��ܡ�
	ǰ������һ�������飬��������䡣
*/
/*
int Register_Proc(int act, pFun fun)
{
	int index = sizeof(g_astProc) / sizeof(MY_PROC_S);
	g_astProc[index].act = act;
	g_astProc[index].pAct = fun;
	
	return 0;
}
*/

int main(int argc, char* argv[])
{
	int i;
	int act;
	int num1;
	int num2;
	int num3;
	int out;

	if (argc < 5)
	{
		return -1;
	}
	act = atoi((char*)argv[1]);
	num1 = atoi((char*)argv[2]);
	num2 = atoi((char*)argv[3]);
	num3 = atoi((char*)argv[4]);
	printf("%d, %d, %d, %d\r\n", act, num1, num2, num3);

	for (i = 0; i < sizeof(g_astProc) / sizeof(MY_PROC_S); i++)
	{
		if (act == g_astProc[i].act)
		{
			g_astProc[i].pAct(num1, num2, num3, &out);
			break;
		}
	}
	printf("%d\r\n", out);
	system("pause");
	return 0;
}

