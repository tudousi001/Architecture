
#include <iostream>
using namespace std;

/*
��̬�������������� 
	1)Ҫ�м̳�  
	2)�麯����д  
	3)����ָ��ָ��������� 
*/
class Parent
{
public:
	Parent(int a = 0)
	{
		this->a_ = a;
	}

	virtual void print()  //1 ���ֽ�  дvirtal�ؼ��� �����⴦�� //�麯����
	{
		cout<<"my is parent  1"<<endl;
	}
	virtual void print2()  //1 ���ֽ�  дvirtal�ؼ��� �����⴦�� //�麯����
	{
		cout << "my is parent  2" << endl;
	}
private:
	int a_;
};

class Child : public Parent
{
public:
	Child(int a = 0, int b = 0) :Parent(a)
	{
		this->b_ = b;
	}

	virtual void print()
	{
		cout<<"my is son"<<endl;
	}
private:
	int b_;
};

//�ж�̬����  //2 ���ֽ�  
//Ч��:��������� ִ�������print���� ���������ִ�и����print���� 
//C++��������������Ҫ������������� ���Ǹ������
//���������������ֲ���vptrָ�� , ==>�麯����===>��������ڵ�ַ
//�ٰ� (����ʱ��ʱ��,c++��������ȥ�ж�)
void HowToPlay(Parent *base)
{
	base->print(); 
}

int mian()
{
	//3 ���ֽ� ��ǰ����  
	//���ඨ������ʱ�� C++���������ڶ��������һ��vptrָ�� 
	//��������Ҳ��һ��vptrָ��
	Parent	p1; 
	Child	c1; 

	HowToPlay(&p1);
	HowToPlay(&c1);

	cout<<"hello..."<<endl;
	system("pause");
	return 0;
}