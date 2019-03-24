/*
@ һЩӦ���ṩ���ڽ���build in���Ľű����ߺ����������û����Զ��������ܹ���ϵͳ�н��еĲ�����
	Interpreterģʽ��Ŀ�ľ���ʹ��һ��������Ϊ�û��ṩһ��һ�Ŷ������Ե��﷨��ʾ�Ľ�������Ȼ��ͨ����������������������еľ���

@ Context
	�����������Ļ����ࡣ�����洢�������������Ļ�����������Ҫ���͵��ķ��ȡ� 
	�����������룬���ֵ
@ AbstractExpression
	�����������ࡣ
@ ConcreteExpression
	����������ʵ���ࡣ
	����������������Ƕ�����������ֲ����ı�ʶ
*/


#include <iostream>
using namespace std;

// Context 

// Expression 

// PlusExpression   MinusExpression 

class Context
{
public:
	Context(int num)
	{
		this->m_num = num;
	}

	int getNum()
	{
		return m_num;
	}
	void setNum(int num)
	{
		this->m_num = num;
	}

	int getRes()
	{
		return m_res;
	}
	void  setRes(int res)
	{
		this->m_res = res;
	}

private:
	int m_num;
	int m_res;
};

class Expression
{
public:
	virtual void  interpreter(Context *context) = 0;
private:
	Context *m_context;
};


//�ӷ�������
class PlusExpression : public Expression
{
public:
	PlusExpression()
	{
		this->context = NULL;
	}
	virtual void  interpreter(Context *context)
	{
		int num = context->getNum();
		num++;
		context->setNum(num);
		context->setRes(num);
	}
private:
	Context *context;
};

//����������
class MinusExpression : public Expression
{
public:
	MinusExpression()
	{
		this->context = NULL;
	}
	virtual void  interpreter(Context *context)
	{
		int num = context->getNum();
		num--;
		context->setNum(num);
		context->setRes(num);
	}
private:
	Context *context;
};



void main()
{
	Context *context = NULL;
	context = new Context(10);

	Expression *expression = NULL;
	Expression *expression2 = NULL;

	cout << context->getNum() << endl;

	expression = new PlusExpression;
	expression->interpreter(context);

	cout << context->getRes() << endl;

	//////////////////////////////////////////////////////////////////////////
	expression2 = new MinusExpression;
	expression2->interpreter(context);
	cout << context->getRes() << endl;


	cout << "hello..." << endl;
	system("pause");
	return;
}