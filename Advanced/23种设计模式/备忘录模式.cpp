/*
MementoģʽҲ�б���¼ģʽ������Ϊģʽ֮һ�����������Ǳ��������ڲ�״̬��������Ҫ��ʱ��undo/rollback���ָ�������ǰ��״̬��

���һ��������Ҫ����״̬����ͨ��undo��rollback�Ȳ����ָ�����ǰ��״̬ʱ������ʹ��Mementoģʽ��
1��һ������Ҫ�������Ķ����״̬���൱��Originator��ɫ��
2�����һ���࣬����ֻ�������������������״̬���൱��Memento��ɫ��
3����Ҫ��ʱ��Caretaker��ɫҪ��Originator����һ��Memento�����Ա���
4��undo��rollback����ʱ��ͨ��Caretaker�����Memento�ָ�Originator�����״̬

Originator��ԭ���ߣ�
��Ҫ������״̬�Ա�ָ����Ǹ�����
Memento������¼��
�ö�����Originator��������Ҫ��������Originator���ڲ�״̬��
Caretaker�������ߣ�
�������ʵ���ʱ�䱣��/�ָ�Originator�����״̬��
�����ڣ�
�ڲ��ƻ���װ�Ե�ǰ���£�����һ��������ڲ�״̬�����ڸö���֮�Ᵽ�����״̬�������Ϳ��Խ��Ժ�Ķ���״̬�ָ�����ǰ�����״̬��
�����ڹ��ܱȽϸ��ӵģ�����Ҫ��¼��ά��������ʷ���ࣻ������Ҫ���������ֻ���ڶ������е�һС����ʱOriginator���Ը��ݱ����Memo��ԭ��ǰһ״̬��
*/
#include <iostream>
#include <string>
using namespace std;

//Caretaker ������
// MememTo  ����¼

class MememTo
{
public:
	MememTo(string name, int age)
	{
		m_name = name;
		m_age = age;
	}
	string getName()
	{
		return m_name;
	}
	int getAge()
	{
		return m_age;
	}

	void setName(string name)
	{
		this->m_name = name;
	}
	void setAge(int age)
	{
		this->m_age = age;
	}
private:
	string	m_name;
	int		m_age;
};

class  Person
{
public:
	Person(string name, int age)
	{
		m_name = name;
		m_age = age;
	}
	string getName()
	{
		return m_name;
	}
	int getAge()
	{
		return m_age;
	}

	void setName(string name)
	{
		this->m_name = name;
	}
	void setAge(int age)
	{
		this->m_age = age;
	}

	//����
	MememTo* createMememTo()
	{
		return new MememTo(m_name, m_age);
	}
	//��ԭ 
	void setMememTo(MememTo* memto)
	{
		this->m_age = memto->getAge();
		this->m_name = memto->getName();
	}
public:
	void printT()
	{
		cout << "m_name:" << m_name << " m_age:" << m_age << endl;
	}
private:
	string	m_name;
	int		m_age;
};

class Caretaker
{
public:
	Caretaker(MememTo *memto)
	{
		this->memto = memto;
	}
	MememTo *getMememTo()
	{
		return memto;
	}
	void setMememTo(MememTo *memto)
	{
		this->memto = memto;
	}
protected:
private:
	MememTo *memto;
};

void main26_02()
{
	//MememTo *memto = NULL;
	Caretaker *caretaker = NULL;
	Person *p = new Person("����", 32);
	p->printT();

	//���� Person�����һ��״̬
	printf("---------\n");
	caretaker = new Caretaker(p->createMememTo());
	p->setAge(42);
	p->printT();

	printf("��ԭ�ɵ�״̬\n");
	p->setMememTo(caretaker->getMememTo());
	p->printT();

	delete caretaker;
	delete p;
}

void main26_01()
{
	MememTo *memto = NULL;
	Person *p = new Person("����", 32);
	p->printT();

	//���� Person�����һ��״̬
	printf("---------\n");
	memto = p->createMememTo();
	p->setAge(42);
	p->printT();

	printf("��ԭ�ɵ�״̬\n");
	p->setMememTo(memto);
	p->printT();

	delete memto;
	delete p;
}
void main()
{
	//main26_01();
	main26_02();
	system("pause");
	return;
}