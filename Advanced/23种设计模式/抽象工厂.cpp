/*
@ ����ģʽ
@ ���ɣ�
	1.���󹤳���Creator����ɫ 
		���󹤳�ģʽ�ĺ��ģ������Զ����Ʒ�ṹ���������κι����඼����ʵ������ӿڡ�

	2.���幤���� Concrete  Creator����ɫ
		���幤�����ǳ��󹤳���һ��ʵ�֣�����ʵ����ĳ����Ʒ���еĲ�Ʒ����

	3.����Product����ɫ
		����ģʽ�����������ж���ĸ��࣬��������������ʵ�������еĹ����ӿڡ�

	4.�����Ʒ��Concrete Product����ɫ
		����ģʽ�������ľ���ʵ������

@ ����ģʽ����󹤳�����
	����ģʽ�е�һ�����幤��ֻ������һ����Ʒ����Ҫô�㽶��Ҫôƻ����
	���󹤳��е�һ�����幤������һ������һ����Ʒ�壨�����кܶ��Ʒ��ɣ�

@ ����
	�����Ʒ����˫�����ԣ������㽶;�Ϸ�ƻ��
	Ҫ��һ�����Ը����󹤳���һ�����Ը����幤��
*/

#include <iostream>
using namespace std;

class Fruit
{
public:
	virtual void SayName() = 0;
};

class AbstractFactory
{
public:
	virtual Fruit* CreateBanana() = 0;
	virtual Fruit* CreateApple() = 0;
};

class NorthBanana : public Fruit
{
public:
	virtual void SayName()
	{
		cout << "���Ǳ����㽶" << endl;
	}
};

class NorthApple : public Fruit
{
public:
	virtual void SayName()
	{
		cout << "���Ǳ���ƻ��" << endl;
	}
};

class SourthBanana : public Fruit
{
public:
	virtual void SayName()
	{
		cout << "�����Ϸ��㽶" << endl;
	}
};

class SourthApple : public Fruit
{
public:
	virtual void SayName()
	{
		cout << "�����Ϸ�ƻ��" << endl;
	}
};

class NorthFacorty : public AbstractFactory
{
	virtual Fruit * CreateBanana()
	{
		return new NorthBanana;
	}
	virtual Fruit * CreateApple()
	{
		return new NorthApple;
	}
};

class SourthFacorty : public AbstractFactory
{
	virtual Fruit * CreateBanana()
	{
		return new SourthBanana;
	}
	virtual Fruit * CreateApple()
	{
		return new SourthApple;
	}
};


void main()
{
	Fruit			*fruit = NULL;
	AbstractFactory *af = NULL;

	///--------------
	af = new SourthFacorty;
	fruit = af->CreateApple();
	fruit->SayName();
	delete fruit;
	fruit = af->CreateBanana();
	fruit->SayName();
	delete fruit;

	///------
	af = new NorthFacorty;
	fruit = af->CreateApple();
	fruit->SayName();
	delete fruit;
	fruit = af->CreateBanana();
	fruit->SayName();
	delete fruit;

	delete af;
	system("pause");
	return;
}