/*
@ ����������ʽ			ʹ�õ�ʱ���ֶ�����
@ ���췽����
	1)���캯��˽�л�
	2)�ṩһ��ȫ�ֵľ�̬������ȫ�ַ��ʵ㣩
	3)�����ж���һ����ָ̬�룬ָ����ı����ľ�̬����ָ��
*/

#include <iostream>
using namespace std;

class Singleton
{
private:
	Singleton()
	{
		cout << "Singelton ���캯��ִ��" << endl;
	}
public:
	static Singleton *get_singelton()
	{
		if (singelton_ == NULL)
		{
			singelton_ = new Singleton;
		}
		return singelton_;
	}

	static void FreeSingelton()
	{
		if (singelton_ != NULL)
		{
			delete singelton_;
			singelton_ = NULL;
		}
	}

private:
	static Singleton *singelton_;
};

Singleton *Singleton::singelton_ = NULL;


void main()
{
	Singleton *single = Singleton::get_singelton();
	single->FreeSingelton();

}