#include<iostream>
#include"Goods.h"
using namespace std;


void main()
{
	int i;
	GoodsQueue * goodsQueue=new GoodsQueue;
	Shop shop(goodsQueue);
	puts("-------�ɽ��е�ҵ�����---------");
	puts("---------1���������-------------");
	puts("---------2����������-------------");
	puts("---------3����ȡ�ܴ����----------");
	puts("------------0���˳�----------------");

	cout << "��ѡ��Ҫ������ҵ��:" << endl;
	cin >> i;

	while (i)
	{
		if (i == 1)
		{
			int wieght;
			cout << "�����빺���ȡ������:" << endl;
			cin >> wieght;
			shop.purchase(wieght);
			cout << "����ɹ�!" << endl;
		}
		else if (i == 2)
		{
			shop.sale();
			cout << "�۳��ɹ�!" << endl;
		}
		else if (i == 3)
		{
			cout << "ʣ����ܿ����Ϊ:" << shop.getTotalWeight() << endl;
		}
		else
		{
			cout << "û����Ӧ�Ĳ�����������ѡ�����" << endl;
		}

		cout << "��ѡ��Ҫ������ҵ��:" << endl;
		cin >> i;
	}

	system("pause");

}