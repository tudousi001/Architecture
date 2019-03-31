/*
���󹤳�ģʽʵ�ֶԲ�Ʒ����Ĵ�����һ����Ʒ������������һϵ�в�Ʒ��
	���в�ͬ����ά�ȵĲ�Ʒ��ϣ����ó��󹤳�ģʽ���ǲ���Ҫ���Ĺ������̣�ֻ����ʲô��Ʒ��ʲô�����������ɡ�
	
��������ģʽ����Ҫ����ָ������ͼ�����Ʒ��������ҪĿ����ͨ����װ�����������һ���²�Ʒ�����ߵ������ǱȽ����Եġ�
����
�ִ��������������ܹ����������������������ֹ�����ĺ���������
��ͬ�Ĺ���������ͬ�������������������������ӵĳ������۹��������������ӵĳ���
���������в�ͬƷ�ƣ����в�ͬ����;���࣬������Van���˶��ͳ�SUV�ȣ����ǰ����������ģʽ�ֱ�ʵ�ֳ������������̡�

ע�⿴����������������ڳ��󹤳�ģʽ��ʹ�á������������������ߣ����ڽ�����ģʽ��ʹ�á����䡱�����������ߣ�
��ʵ�����Ѿ���˵�������ߵ������ˣ����󹤳�ģʽ�ͺñ���һ��һ���Ĺ���������������������SUV�ͱ���VAN�����۳������������۳�SUV�ͱ���VAN��
���Ǵ�һ�����߲��ȥ������Ĺ��������嵽�����ڲ����кܶ�ĳ��䣬����������ĳ��䡢װ������ĳ���ȣ�
����Щ���������ڹ����ڲ���ϸ�ڣ����ⲻ������

Ҳ���Ƕ��쵼����˵����ֻҪ����һ����������������ʲô��Ʒ�ģ����ù��ľ�����ô������
��������ģʽ�Ͳ�ͬ�ˣ������ɳ�����ɣ���ͬ�ĳ�����ɲ�ͬ�Ĵ�����װ������
һ����������������������Ҫ�������쳵�䡢����װ�䳵�����ϲ�����ɣ�������ϵĻ������������ͼ��
�������ͼ�������ڳ������Σ������ࣩ���У��������쳵��ʲô��ͼ��������ʲô��Ʒ��������ģʽ�����Ľ�����̡�
��Ȼ����翴��һ�����仹������������������������ת���Ƿǳ���ģ�ֻҪ�������һ����ͼ�����ɲ�����ͬ�Ĳ�Ʒ���������ڽ�����ģʽ�Ĺ��͡�

�����˵�����󹤳�ģʽ�Ƚ�����ģʽ�ĳ߶�Ҫ������ע��Ʒ���壬��������ģʽ��ע�������̣�
��˽�����ģʽ���Ժ����׵ع�����һ��ո�µĲ�Ʒ��ֻҪ�������ܹ��ṩ����Ĺ������̡�
Ҳ����Ϊ��ˣ����ߵ�Ӧ�ó�����Ȼ��ͬ�����ϣ�����ζ���Ĵ������̣�ֻ�ṩһ����װ���õĶ��������ѡ����󹤳�����ģʽ��
��������ģʽ�������ڹ�����װ�䷽�棬��ͨ��װ�䲻ͬ�����������ͬ����Ĳ�ͬ˳�򣬿��Բ�����һ���µĶ��������Բ���һ���ǳ����ļܹ���
�������չ��ά��ϵͳ��

*/


// ������ģʽ����  ���Ի�ϴ�����һ������BMW�������BZNE�ĳ���������ģʽ�Ͳ��ô����ˡ�
#include <iostream>
using namespace std;

#include "string"

class House
{
public:
	void setDoor(string door)
	{
		this->m_door = door;
	}

	void setWall(string wall)
	{
		this->m_wall = wall;
	}
	void setWindow(string window)
	{
		this->m_window = window;
	}

	//--
	string getDoor( )
	{
		cout << m_door << endl;
		return this->m_door ;
	}

	string getWall()
	{
		cout << m_wall << endl;
		return this->m_wall;
	}
	string getWindow()
	{
		cout << m_window << endl;
		return m_window;
	}

private:
	string	m_door;
	string	m_wall;
	string	m_window;
};

class  Builder
{
public:
	virtual void buildWall() = 0;
	virtual void buildDoor() = 0;
	virtual void buildWindow() = 0;
	virtual House* getHouse() = 0;
};

//��Ԣ���̶�
class  FlatBuilder : public Builder
{
public:
	FlatBuilder()
	{
		m_house = new House;
	}
	virtual void buildWall()
	{
		m_house->setWall(" flat wall");
	}

	virtual void buildDoor()
	{
		m_house->setDoor("flat door");
	}

	virtual void buildWindow()
	{
		m_house->setWindow("flat window");
	}

	virtual House* getHouse()
	{
		return m_house;
	}
private:
	House *m_house;
};

//���� villa ���̶�
class  VillaBuilder : public Builder
{
public:
	VillaBuilder()
	{
		m_house = new House;
	}
	virtual void buildWall()
	{
		m_house->setWall(" villa wall");
	}

	virtual void buildDoor()
	{
		m_house->setDoor("villa door");
	}

	virtual void buildWindow()
	{
		m_house->setWindow("villa window");
	}

	virtual House* getHouse()
	{
		return m_house;
	}
private:
	House *m_house;
};

//���ʦ(ָ����) �������߼�  
//������ �ɾ���Ļ�
class Director 
{
public:
	Director( Builder * build)
	{
		m_build = build;
	}
	void Construct()
	{
		m_build_1->buildWall();
		m_build_1->buildWindow();
		m_build_2->buildDoor();
	}
private:
	 VillaBuilder * m_build_1;
	 FlatBuilder *m_build_2;
};


void main()
{
	House		*house  = NULL;
	Builder		*builder = NULL;
	Director	*director = NULL;

	// ��VillaBuilder ��������Ĺ��̶�
	builder = new VillaBuilder;

	//���ʦ ָ�� ���̶� �ɻ�
	director = new Director(builder);
	director->Construct(); 
	house  =  builder->getHouse();
	house->getWindow();
	house->getDoor();

	delete house;
	delete builder;

	//�� FlatBuilder ��Ԣ
	builder = new FlatBuilder;
	director = new Director(builder);
	director->Construct(); 
	house  =  builder->getHouse();
	house->getWindow();
	house->getDoor();
	delete house;
	delete builder;


	delete director;
	system("pause");
	return ;
}