#include "mainwindow.h"
#include <QtWidgets/QApplication>
#include <QDebug>
#include <thread>
#include <Windows.h>

class A
{
public:
	A() 
	{ 
		qDebug() << "A::A()"; 
	}
	~A() 
	{ 
		qDebug() << "A::~A()";
	}
};

void demoMakeSharedMemoryLayout()
{
	//constexpr int ssss = sizeof(std::aligned_union_t<1, A>);
	A* aaa = new A;
	std::shared_ptr<A> ptr1(aaa);

	std::shared_ptr<A> ptr2(std::make_shared<A>());

	int x = 0;
}

class AA
{
	char a;
	int* j;
};

class Task
{
public:
	Task()
	{

	}

	~Task()
	{

	}

	void func()
	{
		++a;
	}

	void doAsync()
	{
		std::thread t([=]() {
			Sleep(3000);
			func();
		});

		t.detach();
	}

private:
	int a{ 10 };
};

class TaskSafe : public std::enable_shared_from_this<TaskSafe>
{
public:
	TaskSafe()
	{

	}

	~TaskSafe()
	{

	}

	void func()
	{
		++a;
	}

	void doAsync()
	{
		std::thread t([self = shared_from_this()]() {
			Sleep(3000);
			self->func();
		});

		t.detach();
	}

private:
	int a{ 10 };
};

void demoEnableSharedFromThis()
{
	std::shared_ptr<Task> a1;
	{
		a1 = std::make_shared<Task>();
		a1->doAsync();
	}
	
	/*
	// using enable_shared_from_this 
	std::shared_ptr<TaskSafe> a2;
	{
		a2 = std::make_shared<TaskSafe>();
		a2->doAsync();
	}*/
	int x = 0;
}

#include <QPointer>
int main(int argc, char *argv[])
{
	A * aaa = new A;
	std::shared_ptr<A> cc(aaa);
	constexpr int sss = sizeof(std::shared_ptr<int>);
	std::shared_ptr<int> ptr2(std::make_shared<int>(10));
	// 演示make_shared和new XX使用方式上的内存分配的不同
	//demoMakeSharedMemoryLayout();

	// 演示 std::enable_shared_from_this<TaskSafe>
	//demoEnableSharedFromThis();

    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
