/*
@ Observerģʽ����Ϊģʽ֮һ�����������ǵ�һ�������״̬�����仯ʱ���ܹ��Զ�֪ͨ�������������Զ�ˢ�¶���״̬��
@ Observerģʽ�ṩ����������һ��ͬ��ͨ�ŵ��ֶΣ�ʹĳ������������������������֮�䱣��״̬ͬ����

@ Subject�����۲��ߣ�
	���۲�Ķ��󡣵���Ҫ���۲��״̬�����仯ʱ����Ҫ֪ͨ���������й۲��߶���
	Subject��Ҫά�֣���ӣ�ɾ����֪ͨ��һ���۲��߶���Ķ����б�
@ ConcreteSubject
	���۲��ߵľ���ʵ�֡�����һЩ����������״̬������������
@ Observer���۲��ߣ�
	�ӿڻ�����ࡣ��Subject��״̬�����仯ʱ��Observer����ͨ��һ��callback�����õ�֪ͨ��
@ ConcreteObserver
	�۲��ߵľ���ʵ�֡��õ�֪ͨ�����һЩ�����ҵ���߼�����

- �����¼�������������е��ⲿ�¼�
- ����/����ĳ�������״̬�仯
- ������/������(publisher/subscriber)ģ���У���һ���ⲿ�¼����µĲ�Ʒ����Ϣ�ĳ��ֵȵȣ�������ʱ��֪ͨ�ʼ��б��еĶ�����
								
@ �����ڣ�
	��������һ��һ�Զ��������ϵ��ʹ��ÿһ������ı�״̬�����������������ǵĶ��󶼻�õ�֪ͨ��

@ ʹ�ó�����
	������һ��һ�Զ�Ĺ�ϵ���ö���۲���󣨹�˾Ա����ͬʱ����һ������������飩��
	�������״̬�����仯ʱ����֪ͨ���еĹ۲��ߣ�ʹ�����ܹ������Լ���
*/

#include <iostream>
#include <string>
#include <list>
using namespace std;

class Secretary;


//�۲��� 
class PlayserObserver
{
public:
	PlayserObserver(Secretary *secretary)
	{
		this->m_secretary = secretary;
	}
	void update(string action)
	{
		cout << "action:" << action << endl;
		cout << "�ϰ����� �Һܺ��°�..." << endl;

	}
private:
	Secretary *m_secretary;
};
//
class Secretary
{
public:
	Secretary()
	{
		m_list.clear();
	}
	void Notify(string info)
	{
		//�����е� �۲��� ���� �鱨
		for (list<PlayserObserver *>::iterator it = m_list.begin(); it != m_list.end(); it++)
		{
			(*it)->update(info); //
		}
	}

	void setPlayserObserver(PlayserObserver *o)
	{
		m_list.push_back(o);
	}

private:
	list<PlayserObserver *> m_list;
};

void main()
{
	Secretary			*secretary = NULL;
	PlayserObserver		*po1 = NULL;
	PlayserObserver		*po2 = NULL;

	secretary = new Secretary;
	po1 = new PlayserObserver(secretary);
	po2 = new PlayserObserver(secretary);

	secretary->setPlayserObserver(po1);
	secretary->setPlayserObserver(po2);

	secretary->Notify("�ϰ�����");
	secretary->Notify("�ϰ�����");
	delete secretary;
	delete po1;
	delete po2;

	system("pause");
	return;
}