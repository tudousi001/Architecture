/*
@ ����������ʽ
@ ���췽����
	1)���캯��˽�л�
	2)�ṩһ��ȫ�ֵľ�̬������ȫ�ַ��ʵ㣩
	3)�����ж���һ����ָ̬�룬ָ����ı����ľ�̬����ָ��
*/

#include <iostream>
using namespace std;

class Singelton
{
private:
	Singelton()
	{
		cout << "Singelton ���캯��ִ��" << endl;
	}
public:
	static Singelton *get_singelton()
	{
		if (singelton_ == NULL)
		{
			singelton_ = new Singelton;
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
	static Singelton *singelton_;
};

Singelton *Singelton::singelton_ = NULL;


void main01()
{
	Singelton *p1 = Singelton::get_singelton();
	Singelton::FreeSingelton();

}