#include<iostream>
#include<stdio.h>


//���Ա����ָ�룬���Ա����ָ�����飬���Ա��������ָ��



class com
{
private:
	int a;
	int b;
public:
	com(int x, int y) :a(x), b(y)
	{

	}
	int  jia(int a, int b)
	{
		return a + b;
	}
	int  jian(int a, int b)
	{
		return a - b;
	}
	int  cheng(int a, int b)
	{
		return a * b;
	}
	int  chu(int a, int b)
	{
		return a / b;
	}



};


void main1x()
{
	com com1(100, 20);
	auto fun1 = &com::jia;
	int(com::*p)(int, int) = &com::jia;
	std::cout << (com1.*p)(10, 20) << std::endl;//���ö������Ա����ָ��
	std::cout << typeid(p).name() << std::endl;
	std::cout << typeid(fun1).name() << std::endl;


	std::cin.get();

}

typedef int(com::*P)(int, int);
void main()
{
	com com1(100, 20);
	//P fun1[4] = { &com::jia, &com::jian, &com::cheng, &com::chu };
	//���Ա����ָ������
	int(com::*fun1[4])(int, int) = { &com::jia, &com::jian, &com::cheng, &com::chu };
	for (int i = 0; i < 4; i++)
	{
		std::cout << (com1.*fun1[i])(10, 20) << std::endl;
	
	}
	int(com::**funp)(int, int) = fun1;//ָ�����Ա����ָ���ָ��
	for (; funp < fun1 + 4; funp++)
	{
		std::cout << (com1.**funp)(10, 20) << std::endl;
		printf("%p", *funp);
	}
	for (int i = 0; i < 4; i++) 
	{
		auto func = fun1[i];
		std::cout << typeid(func).name() << std::endl;
		printf("%p", func);
	     
	}

	std::cin.get();

}