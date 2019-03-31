/*
@ �򵥹���ģʽ��������23�����ģʽ֮��,�����Ͽ���ԭ��
@ ���壺
	ͨ��ר�Ŷ���һ���������𴴽��������ʵ������������ʵ��ͨ�������й�ͬ�ĸ��ࡣ
@ ���ɣ�
	1.������Creator����ɫ
		�򵥹���ģʽ�ĺ��ģ�������ʵ�ִ�������ʵ�����ڲ��߼�����������Ա����ֱ�ӵ��ã���������Ĳ�Ʒ����
	2.����Product����ɫ
		������
		�򵥹���ģʽ�����������ж���ĸ��࣬��������������ʵ�������еĹ����ӿڡ�
	3.�����Ʒ��Concrete Product����ɫ
		�Գ�������и�д
		�򵥹���ģʽ�������ľ���ʵ������	

@ ����
	��������������һ���װ����������ָ��ָ���ĸ������ࡣ
	�Ͷ�̬��ȣ������Լ��ֶ�������ָ��ָ���ĸ�����������࣬���˼򵥹���ģʽ�Ͳ����ˡ�
*/


#include <iostream>
using namespace std;

//���������
class Fruit
{
public:
	virtual void getFruit() = 0;

protected:
private:
};

class Banana : public Fruit
{
public:
	virtual void getFruit()
	{
		cout << "�����㽶...." << endl;
	}
protected:
private:
};

class Apple : public Fruit
{
public:
	virtual void getFruit()
	{
		cout << "����ƻ��...." << endl;
	}
protected:
private:
};


class Factory
{
public:
	Fruit *create(char *p)
	{

		if (strcmp(p, "banana") == 0)
		{
			return new Banana;
		}
		else if (strcmp(p, "apple") == 0)
		{
			return new Apple;
		}
		else
		{
			printf("��֧��\n");
			return NULL;
		}
	}
};


void main()
{
	Factory *f = new Factory;
	Fruit *fruit = NULL;

	//���� ���� �㽶
	//���ص���ָ��������Ļ���ָ��
	//��������������һ���װ����������ָ��ָ���ĸ�������
	//��ǰ�Ķ�̬�������Լ��ֶ�������ָ��ָ���ĸ�����������࣬���˼򵥹���ģʽ�Ͳ�����
	
	fruit = f->create("banana");
	fruit->getFruit();
	delete fruit;


	fruit = f->create("apple");
	fruit->getFruit();
	delete fruit;

	delete f;

	cout << "hello..." << endl;
	getchar();
	return;
}