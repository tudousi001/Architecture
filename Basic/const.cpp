#include<stdio.h>
#include<stdlib.h>
//int  *p

//const int *p   �޶�ֻ�ܶ������Ըģ���ַ�����ƶ������Կ������˻�
//int const *p

//int * const p  �޶������Բ鿴���˵��˻������Լ��˻��ɶ���д

//const int * const p �޶�ֻ�ܿ��Լ��˻���ֻ�ܶ�����д
//int const * const p 

void main1()
{

	 const int num = 10;
	const int data = 20;//ֻ�г�ʼ����ʱ����Ը�
	//data = 10; const�޶����㲻������޸�
	const int *p = &num;//p��ָ������ָ��
	p = &num;//const int *p�޶�Ȩ�ޣ��޶�ֻ�ܶ�������д
	//*p = 3;
	printf("%d", *p);

	getchar();


}
void  main2()
{
	int num = 10;
	int data = 20;
	int const *p = &num;  //const *p �޶�д���Ȩ�ޡ�
	p = &data;
	//*p = 3;
	printf("%d", *p);

	getchar();

}

void main3()
{
	int num = 10;
	int data = 20;
	int * const p = &num;
	//p = &data;//�޶��������һ������
	*p = 13;
	printf("%d", *p);
	getchar();



}

void  main()
{
	int num = 10;
	int data = 20;
	const int * const p = &data;//�޶�Ȩ�ޣ�ֻ�ܿ��������Ըģ������Կ����˵��˻�
	//p = &num;
	//*p = 3;




}