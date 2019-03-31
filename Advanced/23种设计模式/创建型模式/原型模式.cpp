/*
@ Prototypeģʽ��һ�ֶ��󴴽���ģʽ������ȡ����ԭ�Ͷ���ķ��������������ʵ����ʹ��Prototypeģʽ������ʵ����������ԭ��һ�������ݡ�
	1����ԭ�Ͷ���������Ŀ�����Ҳ����˵�����󴴽���һ��������ԭ�Ͷ�����
	2��Ŀ�������ԭ�Ͷ����һ����¡��Ҳ����˵��ͨ��Prototypeģʽ�����Ķ���
		��������ԭ�Ͷ��������ͬ�Ľṹ������ԭ�Ͷ��������ͬ��ֵ��
	3�����ݶ����¡��Ȳ�εĲ�ͬ����ǳ�ȿ�¡����ȿ�¡��

@ ԭ��ģʽ��Ҫ��Ե������ǣ���ĳЩ�ṹ���ӵĶ��󡱵Ĵ�����������������ı仯����Щ���󾭳������ž��ҵı仯��
	��������ȴӵ�бȽ��ȶ�һ�µĽӿڡ�
@ ���������
	һ�����Ӷ��󣬾������Ҹ��ƹ��ܣ�ͳһһ�׽ӿڡ�

*/



#define _CRT_SECURE_NO_WARNINGS 
#include <string>
#include <iostream>
using namespace std;


class Person
{
public:
	virtual Person* clone() = 0;
	virtual void printT() = 0;
};

class  CPlusPlusProgrammer : public Person
{
public:
	CPlusPlusProgrammer()
	{
		m_name = "";
		m_age = 0;
		m_resume = NULL;
		setResume("aaaa");
	}
	CPlusPlusProgrammer(string name, int age)
	{
		m_name = name;
		m_age = age;
		m_resume = NULL;
		setResume("aaaa");
	}
	void setResume(char *p)
	{
		if (m_resume != NULL)
		{
			delete m_resume;
		}
		m_resume = new char[strlen(p) + 1];
		strcpy(m_resume, p);
	}


	virtual void printT()
	{
		cout << "m_name" << m_name << " m_age" << m_age << "m_resume:" << m_resume << endl;
	}
	virtual Person* clone()
	{
		CPlusPlusProgrammer *tmp = new CPlusPlusProgrammer;
		//tmp->m_name = this->m_name;
		*tmp = *this; // =  ǳ����
		return tmp;
	}
protected:
private:
	string	m_name;
	int		m_age;
	char	*m_resume;

};

void main()
{
	Person *c1 = new CPlusPlusProgrammer("����", 32);
	c1->printT();

	Person *c2 = c1->clone();
	c2->printT();

	cout << "hello..." << endl;
	system("pause");
	return;
}