#include "JIT.h"
#include <thread>
#include <chrono>

void Caculate()
{
	int i = 0;
	while (1)
	{
		++i;
		using namespace std::chrono_literals;
		//std::this_thread::sleep_for(10ms);
	}
}

void HighCpu()
{
	std::thread t([]() {
		Caculate();
		});

	t.detach();
}