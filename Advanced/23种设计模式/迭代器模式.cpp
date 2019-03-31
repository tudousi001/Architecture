/*
@ IteratorģʽҲ�е���ģʽ������Ϊģʽ֮һ�����Ѷ������а������ڲ�����ķ���ί�ø��ⲿ�࣬
	ʹ��Iterator����������˳����б������ʵ����ģʽ��
@ ��Ӧ��Iteratorģʽ֮ǰ������Ӧ������Iteratorģʽ�������ʲô���⡣����˵�������ʹ��Iteratorģʽ�������ʲô���⡣
	1)�������Լ�ʵ��˳�������ֱ������������ֱ�����˳���������
	2)�õ������Լ�ʵ�ֱ�����ֱ�ӱ�¶����ϸ�ڸ��ⲿ��

���Ϸ���1�뷽��2������ʵ�ֶԱ����������������أ�
1��������е���̫�๦�ܣ�һ������Ҫ�ṩ���ɾ���ȱ���Ӧ�еĹ��ܣ�һ���滹��Ҫ�ṩ�������ʹ��ܡ�
2������������ʵ�ֱ����Ĺ����У���Ҫ�������״̬������Ԫ�ص����ɾ���ȹ��ܼ�����һ�𣬺�����������Һͳ������д���ȡ�

@ Iteratorģʽ����Ϊ����Ч�ش���˳����б������ʵ�һ�����ģʽ��
	�򵥵�˵��Iteratorģʽ�ṩһ����Ч�ķ������������ξۼ����󼯺ϵ��������ʵ��ϸ�ڣ�
	���ܶ������ڰ����Ķ���Ԫ�ذ�˳�������Ч�ı������ʡ����ԣ�Iteratorģʽ��Ӧ�ó������Թ���Ϊ�������¼���������
- ���������а������ڲ�����
- ��˳�����
��ɫ��ְ��
GOOD���ṩһ�ַ���˳�����һ����������ĸ���Ԫ�أ����ֲ���¶�ö�����ڲ���ʾ��
Ϊ������ͬ�ľۼ��ṹ�ṩ�翪ʼ����һ�����Ƿ��������ǰһ���ͳһ�ӿڡ�

@ Iterator���������ӿڣ���
	�ýӿڱ��붨��ʵ�ֵ������ܵ���С���巽����
	�����ṩhasNext()��next()������
@ ConcreteIterator��������ʵ���ࣩ��
	�������ӿ�Iterator��ʵ���ࡣ���Ը��ݾ����������ʵ�֡�

@ Aggregate�������ӿڣ���
	������������Լ��ṩ����Iterator iterator()�ķ�����

@ concreteAggregate������ʵ���ࣩ��
	�����ӿڵ�ʵ���ࡣ����ʵ��Iterator iterator()������
	�ڵ������� ���� һ�����ϵ� ���ã�����ͨ�����������Ϳ��Է��ʼ���
*/


#include <iostream>
using namespace std;

// MyIterator  Aggregate ContreteIterator ConcreteAggregate

//	a	 b	c	d
//      ��


typedef int Object;
#define SIZE 5 

class MyIterator
{
public:
	virtual void First() = 0;
	virtual void Next() = 0;
	virtual bool IsDone() = 0;
	virtual Object CurrentItem() = 0;
};

class Aggregate
{
public:
	virtual MyIterator *CreateIterator() = 0;
	virtual Object getItem(int index) = 0;
	virtual int getSize() = 0;
};

class ContreteIterator : public MyIterator
{
public:
	ContreteIterator(Aggregate *ag)
	{
		_ag = ag;
		_current_index = 0;
	}
	virtual void First()
	{
		_current_index = 0;  //�õ�ǰ �α� �ص�λ��0
	}
	virtual void Next()
	{
		if (_current_index < _ag->getSize())
		{
			_current_index++;
		}
	}
	virtual bool IsDone()
	{
		return  (_current_index == _ag->getSize());
	}
	virtual Object CurrentItem()
	{
		return _ag->getItem(_current_index);
	}
protected:
private:
	int			_current_index;
	Aggregate	 *_ag;
};


class ConcreteAggregate : public Aggregate
{
public:
	ConcreteAggregate()
	{
		for (int i = 0; i<SIZE; i++)
		{
			object[i] = i + 100;
		}
	}
	virtual MyIterator *CreateIterator()
	{
		return new ContreteIterator(this); //�õ����� ����һ�� ���ϵ� ���� 
	}
	virtual Object getItem(int index)
	{
		return object[index];
	}
	virtual int getSize()
	{
		return SIZE;
	}
private:
	Object object[SIZE];
};

void main()
{
	Aggregate * ag = new ConcreteAggregate;

	MyIterator *it = ag->CreateIterator();

	for (; !(it->IsDone()); it->Next())
	{
		cout << it->CurrentItem() << " ";
	}

	delete it;
	delete ag;

	system("pause");
	return;
}