/*
@ Proxyģʽ�ֽ�������ģʽ���ǹ����͵����ģʽ֮һ��������Ϊ���������ṩһ�ִ���Proxy���Կ��ƶ��������ķ��ʡ�
-��ν������ָ���������Ԫ��������Ķ��󣩾�����ͬ�Ľӿڵ��࣬
-�ͻ��˱���ͨ�������뱻�����Ŀ���ཻ����������һ���ڽ����Ĺ����У�����ǰ�󣩣�����ĳЩ�ر�Ĵ���

@ subject�����������ɫ����
	��ʵ�������������Ĺ�ͬ�ӿڡ�
@ RealSubject����ʵ�����ɫ����
??	�����˴����ɫ���������ʵ����
@ Proxy�����������ɫ����
?	���ж���ʵ�����ɫ�����ã������ɫͨ���ڽ��ͻ��˵��ô��ݸ������������֮ǰ����֮��ִ��ĳЩ�����������ǵ���������ʵ�Ķ���
			
@ �ʺ��ڣ�
	Ϊ���������ṩһ�ִ����Կ��ƶ��������ķ��ʡ�
	��ʾ��a�а���b�ࣻa��b��ʵ��Э����protocol
*/


#include <iostream>
using namespace std;

class Subject
{
public:
	virtual void sailbook() = 0;
};

class RealSubjectBook : public Subject
{
public:
	virtual void sailbook()
	{
		cout << "����" << endl;
	}
};

//a�а���b�ࣻa��b��ʵ��Э����protocol 
class dangdangProxy : public Subject
{
public:
	virtual void sailbook()
	{
		RealSubjectBook *rsb = new RealSubjectBook;
		dazhe();
		rsb->sailbook();
		dazhe();
	}
public:
	void dazhe()
	{
		cout << "˫ʮһ����" << endl;
	}
private:
	Subject *m_subject;
};

void main()
{
	Subject *s = new dangdangProxy;
	s->sailbook();
	delete s;
	system("pause");
	return;
}