#include <iostream>

class Point
{
public:
	int get_x() {
		return x_;
	};
	int get_y() {
		return y_;
	};
	void set_point(int x, int y) {
		x_ = x;
		y_ = y;
	};

	
private:
	int x_;
	int y_;	
};

class Circle
{
public:
	void set_circle(int r, int x, int y) {
		r_ = r;
		x_ = x;
		y_ = y;
	};
	//��������������ʱ�����װ�����Ժͷ������ڱ����ú������棬 ��������ʹ�����ԣ����ҿ���ʹ�÷�������Ա��������
	//��Ҳ����������������̵�һ����Ҫ����
	int IsPointInCircle(Point &point) {	
		int dd = (point.get_x() - x_)*(point.get_x() - x_) + (point.get_y() - y_)* (point.get_y() - y_);
		if (dd <= r_ * r_)
		{
			return 1;							//Բ���ڲ�
		}
		else
		{
			return 0;							//0����Բ��
		}
	
	};

private:
	int r_;
	int x_;
	int y_;
};



int main()
{
	Circle circle;
	Point point;

	circle.set_circle(2, 3, 3);
	point.set_point(7, 7);

	//��Բ��1  ����Բ�� 0
	int tag = circle.IsPointInCircle(point);
	if (tag == 1)
	{
		std::cout << "����Բ����" << std::endl;
	}
	else
	{
		std::cout << "����Բ����" << std::endl;
	}

	getchar();
	return 0;
}