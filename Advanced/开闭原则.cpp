/*
����ԭ��
������ĸĶ���ͨ�����Ӵ�����еģ������޸�Դ���롣
*/
#include <iostream>
using namespace std;

class AbstractBankWorker {
public:
    virtual void doSomething() = 0;
};
class saveBankWorker : public AbstractBankWorker {
public:
    virtual void doSomething() {
        cout << "���" << endl;
    }
};
class transBankWorker : public AbstractBankWorker {
public:
    virtual void doSomething() {
        cout << "ת��" << endl;
    }
};
/*�������뿪ͨ����ҵ��ֻ��Ҫ�ټ̳л��࣬ʵ��ҵ���麯������*/
class payBankWorker : public AbstractBankWorker {
public:
    virtual void doSomething() {
        cout << "����" << endl;
    }
};

int main(int argc, char **argv) 
{
    /*
        ������̬��3����Ҫ����
        1.�м̳�
        2.Ҫ����д
        3.����ָ��ָ���������
    */
    AbstractBankWorker *worker = NULL;
    worker = new saveBankWorker;
    worker->doSomething();
    delete worker;
    worker = NULL;
    return 0;
}