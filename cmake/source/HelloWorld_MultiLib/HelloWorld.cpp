#include <iostream>

#include "Helper.h"

int main(int argc, char* argv[])
{
	if (3 == argc)
	{
		printf("%d\n", atoi(argv[1]) + atoi(argv[2]));
		return 0;
	}
	
	std::cout << "Hello Word, " << TestLib::getResult() << std::endl;
	return 2;
}