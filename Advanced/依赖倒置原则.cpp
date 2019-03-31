/*
��������ԭ������㣺�����ϸ�ڵĶ���ԣ�����Ķ���Ҫ�ȶ��Ķࡣ
�Գ���Ϊ����������ļܹ�����ϸ��Ϊ����������ļܹ�Ҫ�ȶ��Ķࡣ
ͨ�����󣨳������ӿڣ�ʹ�������ģ���ʵ�ֱ˴˶��������໥Ӱ�죬ʵ��ģ��������ϡ�
ʹ�ýӿڻ��߳������Ŀ�����ƶ��ù淶����Լ������ȥ�漰�κξ���Ĳ�������չ��ϸ�ڵ����񽻸����ǵ�ʵ����ȥ��ɡ���Ҳ�ǿ���ԭ��Ļ�����

��������ԭ�������ʵ�ַ�ʽ:
(1).ͨ�����캯��������������
		�����ڹ��캯���е���Ҫ���ݵĲ����ǳ������ӿڵķ�ʽʵ�֡�
(2).ͨ��setter����������������
		�����������õ�set�����еĲ���Ϊ�������ӿڣ���ʵ�ִ�����������
(3).�ӿ�����ʵ����������Ҳ�нӿ�ע�룻
       ���ں��������в���Ϊ�������ӿڣ���ʵ�ִ����������󣬴Ӷ��ﵽֱ��ʹ�����������Ŀ�ġ�
       ���ܽ�Ϊ�ӿڴ��ݣ����췽�����ݺ�setter�������ݡ�
	   ��������ԭ��ĺ��ľ���Ҫ��������ӿڱ�̣����������ӿڱ�̣�Ҳ��������������ã�

��������ԭ��ʹ���ܽ᣺
	(1).�Ͳ�ģ�龡����Ҫ�г������ӿڣ��������߶��С�
	(2).�������������;����ǳ������ӿڡ�
	(3).ʹ�ü̳�ʱ��ѭ�����滻ԭ��

*/
#include <iostream>
using namespace std;

//�� Computer���  �� ����ĳ��� ���н����

class  HardDisk
{
public:
	virtual void work() = 0;
};

class  Memory
{
public:
	virtual void work() = 0;
};

class  Cpu
{
public:
	virtual void work() = 0;
};

class Computer
{
public:
	Computer(HardDisk *handdisk, Memory *memory, Cpu *cpu)
	{
		m_handdisk = handdisk;
		m_memory = memory;
		m_cpu = cpu;
	}
	// HardDisk
	// Memory
	// Cpu
public:
	void work()
	{
		m_handdisk->work();
		m_memory->work();
		m_cpu->work();
	}
protected:
private:
	HardDisk *m_handdisk;
	Memory *m_memory;
	Cpu *m_cpu;
};


class  InterCpu : public Cpu
{
public:
	void work()
	{
		cout << "����iterl cpu �ҹ�������" << endl;
	}
};


class  XSDisk : public HardDisk
{
public:
	void work()
	{
		cout << "��������Ӳ�� ��������" << endl;
	}
};

class  JSDMem : public Memory
{
public:
	void work()
	{
		cout << "JSDMem ��������" << endl;
	}
};

void main()
{
	HardDisk * harddisk = NULL;
	Memory * memory = NULL;
	Cpu * cpu = NULL;

	harddisk = new XSDisk;
	memory  = new JSDMem;
	cpu = new InterCpu;

	Computer *mycomputer = new Computer(harddisk ,memory,  cpu);

	mycomputer->work();

	delete mycomputer;
	delete cpu;
	delete memory;
	delete harddisk;

	cout<<"hello..."<<endl;
	system("pause");
	return ;
}