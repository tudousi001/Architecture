﻿/*
@ 单例：饿汉式：		程序运行时就创建好
@ 构造方法：
	在懒汉式的基础上，将类中定义一个静态指针直接指向本类（不管本类有没有new对象）

饿汉式不能用析构函数去delete，会造成死锁。析构调delete，delete会去调析构。
两种方法解决：
	1、自定义函数例如：FreeSingelton()，绝对禁止使用析构函数
	2、定义对象，而非对象指针。（猜测可以，未验证）
*/

#include <iostream>
using namespace std;

class Singleton
{
private:
	Singleton()									// C++的构造函数 不能保证是线程安全
	{
		cout << "Singelton 构造函数执行" << endl;
	}
public:
	static Singleton *GetSingelton()
	{
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

Singleton *Singleton::singelton_ = new Singleton();

void main()
{
	//验证类的构造函数是在hello world之前调用
	printf("hello world\n");
	Singleton *single = Singleton::GetSingelton();
	Singleton::FreeSingelton();

	return;
}

