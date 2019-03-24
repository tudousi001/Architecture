/*
@ StateģʽҲ��״̬ģʽ������Ϊ���ģʽ��һ�֡�
	Stateģʽ����ͨ���ı������ڲ�״̬���ı�������Ϊ�����������ֵþͺ����޸���������һ����
	״̬ģʽ��Ҫ������ǵ�����һ������״̬ת�����������ʽ���ڸ���ʱ�������
	��״̬���ж��߼�ת�뵽���ֲ�ͬ״̬��һϵ���൱�У����԰Ѹ��ӵ��ж��߼��򻯡�

@ Context���û�����
	ӵ��һ��State���͵ĳ�Ա���Ա�ʶ����ĵ�ǰ״̬��
@ State���ӿڻ����
	��װ��Context���ض�״̬��ص���Ϊ��
@ ConcreteState���ӿ�ʵ���������
	ʵ����һ����Contextĳ��״̬��ص���Ϊ��
@ �����ڣ�
	�������Ϊ���������������ĵ�ǰ״̬����Ϊ��״̬�ı���ı�ĳ�����
	�����ڣ�ͨ���û���״̬���ı�������Ϊ��
*/

#include <iostream>
using namespace std;

class Worker;

class State
{
public:
	virtual void doSomeThing(Worker *w) = 0;
};

class Worker
{
public:
	Worker();
	int getHour()
	{
		return m_hour;
	}
	void setHour(int hour) //�ı�״̬ 7 
	{
		m_hour = hour;
	}
	State* getCurrentState()
	{
		return m_currstate;
	}
	void setCurrentState(State* state)
	{
		m_currstate = state;
	}

	void doSomeThing() //
	{
		m_currstate->doSomeThing(this);
	}
private:
	int		m_hour;
	State	*m_currstate; //����ĵ�ǰ״̬
};

class State1 : public State
{
public:
	void doSomeThing(Worker *w);
};

class State2 : public State
{
public:
	void doSomeThing(Worker *w);
};

void State1::doSomeThing(Worker *w)
{
	if (w->getHour() == 7 || w->getHour() == 8)
	{
		cout << "���緹" << endl;
	}
	else
	{
		delete w->getCurrentState();  //״̬1 ������ Ҫת��״̬2
		w->setCurrentState(new State2);
		w->getCurrentState()->doSomeThing(w); //
	}
}

void State2::doSomeThing(Worker *w)
{
	if (w->getHour() == 9 || w->getHour() == 10)
	{
		cout << "����" << endl;
	}
	else
	{
		delete w->getCurrentState(); //״̬2 ������ Ҫת��״̬3 ���߻ָ�����ʼ��״̬
		w->setCurrentState(new State1); //�ָ�������״̬
		cout << "��ǰʱ��㣺" << w->getHour() << "δ֪״̬" << endl;
	}
}

Worker::Worker()
{
	m_currstate = new State1;
}

void main()
{
	Worker *w1 = new Worker;
	w1->setHour(7);
	w1->doSomeThing();

	w1->setHour(9);
	w1->doSomeThing();

	delete w1;
	cout << "hello..." << endl;
	system("pause");
	return;
}