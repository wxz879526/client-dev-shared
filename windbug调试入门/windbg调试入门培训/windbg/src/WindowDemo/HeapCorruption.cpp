#include "HeapCorruption.h"
#include <string>
#include <stdio.h>

void HeapCorruption()
{
	int *a = new int[10]{ 0 };
	for (int i = 0; i < 15; ++i)
		a[i] = i;
	
	printf("%s-%d\n", "demo", a[0]);
	delete[]a;
}