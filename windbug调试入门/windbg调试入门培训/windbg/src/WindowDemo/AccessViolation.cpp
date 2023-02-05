#include "JIT.h"

const char* g_mess = "123";
void AccessViolation()
{
	char* p = (char*)g_mess;
	p[0] = 'a';
}