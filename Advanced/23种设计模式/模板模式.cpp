/*
@ Template MethodģʽҲ��ģ�巽��ģʽ������Ϊģʽ֮һ��
	���Ѿ����ض������㷨�е�ĳЩ��Ҫ�Ĵ���ί�ø����󷽷���ͨ������̳жԳ��󷽷��Ĳ�ͬʵ�ָı������㷨����Ϊ��
@ Template Methodģʽһ��Ӧ���ھ�������������Ӧ���У�
- ����ͳһ�Ĳ���������������
- ���в�ͬ�Ĳ���ϸ��
- ���ڶ������ͬ�����������Ӧ�ó�������ĳЩ����Ĳ���ϸ��ȴ������ͬ
@ �ܽ᣺
	�ڳ�������ͳһ�������裬���涨�ýӿڣ�������ʵ�ֽӿڡ��������԰Ѹ������������Ͳ�����������

@ AbstractClass��
	������ĸ���
@ ConcreteClass��
	�����ʵ������
@ templateMethod()��
	ģ�巽��
@ method1()��method2()��
	���岽�跽��
*/


#include <iostream>
using namespace std;


class MakeCar
{
public:
	virtual void MakeHead() = 0;
	virtual void MakeBody() = 0;
	virtual void MakeTail() = 0;

public:
	void Make() //ģ�庯�� ��ҵ���߼�������
	{
		MakeTail();
		MakeBody();
		MakeHead();
	}
};

//
class Jeep : public MakeCar
{
public:
	virtual void MakeHead()
	{
		cout << "jeep head" << endl;
	}

	virtual void MakeBody()
	{
		cout << "jeep body" << endl;
	}

	virtual void MakeTail()
	{
		cout << "jeep tail" << endl;
	}
};

class Bus : public MakeCar
{
public:
	virtual void MakeHead()
	{
		cout << "Bus head" << endl;
	}

	virtual void MakeBody()
	{
		cout << "Bus body" << endl;
	}

	virtual void MakeTail()
	{
		cout << "Bus tail" << endl;
	}
};

void main()
{
	MakeCar *car = new Bus;
	car->Make();
	delete car;

	MakeCar *car2 = new Jeep;
	car2->Make();
	delete car2;


	cout << "hello..." << endl;
	system("pause");
	return;
}