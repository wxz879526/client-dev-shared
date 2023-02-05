#include "JIT.h"
#include <atlconv.h>
#include <tchar.h>
void StackOverrun()
{
	USES_CONVERSION;
	for (int i = 0; i < 1000000; ++i)
	{
		wprintf(L"%s: %d", A2W("test"), i);
	}
}