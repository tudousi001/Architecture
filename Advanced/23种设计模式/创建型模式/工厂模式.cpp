/*
@ ����ģʽ
@ ���ɣ�
	���󹤳���Creator����ɫ
		��������ģʽ�ĺ��ģ��κι����඼����ʵ������ӿڡ�
	���幤���� Concrete  Creator����ɫ
		���幤�����ǳ��󹤳���һ��ʵ�֣�����ʵ������Ʒ����
	����Product����ɫ
		��������ģʽ�����������ж���ĸ��࣬��������������ʵ�������еĹ����ӿڡ�
	�����Ʒ��Concrete Product����ɫ
		��������ģʽ�������ľ���ʵ������

@ ����ģʽ��򵥹���ģʽ����
	��������ģʽ��򵥹���ģʽ�ڽṹ�ϵĲ�ͬ���Ǻ����ԡ�
	����������ĺ�����һ�����󹤳��࣬���򵥹���ģʽ�Ѻ��ķ���һ���������ϡ� 
	��������ģʽ֮������һ�������ж�̬�Թ���ģʽ����Ϊ���幤���඼�й�ͬ�Ľӿڣ������й�ͬ�ĳ����ࡣ
	��ϵͳ��չ��Ҫ����µĲ�Ʒ����ʱ��������Ҫ���һ����������Լ�һ�����幤������ԭ�й���������Ҫ�����κ��޸ģ�
	Ҳ����Ҫ�޸Ŀͻ��ˣ��ܺõķ����ˡ����ţ���ա�ԭ��
	���򵥹���ģʽ������²�Ʒ����󲻵ò��޸Ĺ�����������չ�Բ��á���������ģʽ�˻�������ݱ�ɼ򵥹���ģʽ��
	
	ԭ����Ĵ���һ�㲻�ö���ֻ�����2���࣬ʵ�ָ�д����������ʵ�ֹ��ܣ����򵥹���ģʽ��Ҫ�޸�ԭ����Ĵ��롣
@ ����
	ʵ����client������Ʒ�����幤��֮��Ľ����
*/

#include <iostream>
using namespace std;


class Fruit
{
public:
	virtual void  sayname() = 0;
};

class  AbFactory
{
public:
	virtual Fruit *CreateProduct() = 0;
};

class  Banana : public Fruit
{
public:
	void  sayname()
	{
		cout << "�����㽶" << endl;
	}
};
class BananaFactory :public AbFactory
{
public:
	virtual Fruit *CreateProduct()
	{
		return new Banana;
	}
};

class  Apple : public Fruit
{
public:
	void  sayname()
	{
		cout << "���� Apple" << endl;
	}
};
class AppleFactory :public AbFactory
{
public:
	virtual Fruit *CreateProduct()
	{
		return new Apple;
	}
};

//////////////////////////////////////////////////////////////////////////
//����µĲ�Ʒ

class Pear : public Fruit
{
public:
	virtual void sayname()
	{
		cout << "���� pear" << endl;
	}
protected:
private:
};
class PearFactory : public AbFactory
{
public:
	virtual Fruit *CreateProduct()
	{
		return new Pear;
	}
};



void main()
{
	AbFactory		*factory = NULL;
	Fruit			*fruit = NULL;

	//�� �㽶
	factory = new BananaFactory;
	fruit = factory->CreateProduct();
	fruit->sayname();

	delete fruit;
	delete factory;

	//Pear 
	factory = new PearFactory;
	fruit = factory->CreateProduct();
	fruit->sayname();

	delete fruit;
	delete factory;


	cout << "hello..." << endl;
	system("pause");
	return;
}