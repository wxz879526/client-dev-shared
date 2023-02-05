#include "DeadLock.h"
#include <string>
#include <thread>
#include <chrono>
#include <windows.h>

using namespace std::literals::chrono_literals;

CRITICAL_SECTION m1;
CRITICAL_SECTION m2;

int g1;
int g2;

void fun1()
{
	EnterCriticalSection(&m1);
	g1 += 1;

	std::this_thread::sleep_for(10s);

	EnterCriticalSection(&m2);
	g2 += 1;

	LeaveCriticalSection(&m1);
	LeaveCriticalSection(&m2);
}

void fun2()
{

	EnterCriticalSection(&m2);
	g2 += 1;

	std::this_thread::sleep_for(10s);


	EnterCriticalSection(&m1);
	g1 += 1;

	LeaveCriticalSection(&m2);
	LeaveCriticalSection(&m1);
}

void DeadLock()
{
	InitializeCriticalSection(&m1);
	InitializeCriticalSection(&m2);

	std::thread t1(fun1);
	std::thread t2(fun2);

	t1.join();
	t2.join();

	DeleteCriticalSection(&m1);
	DeleteCriticalSection(&m2);

	char szResult[100]{ 0 };

	sprintf(szResult, "g1=%d, g2=%d\n", g1, g2);

	MessageBoxA(nullptr, szResult, "DeadLock", MB_OK);
}