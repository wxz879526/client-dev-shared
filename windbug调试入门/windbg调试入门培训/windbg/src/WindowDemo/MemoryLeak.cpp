#include "MemoryLeak.h"
#include <Windows.h>

void doLeak()
{
	int* a = new int[100];
}

void MemoryLeak()
{
	while (1)
	{
		doLeak();
		Sleep(1);
	}
}