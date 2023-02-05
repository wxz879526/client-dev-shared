#include "HandleLeak.h"
#include <string>
#include <thread>
#include <chrono>

using namespace std::literals::chrono_literals;
void HandleLeak()
{
	std::thread t([]() {

		for (;;)

		{

			FILE* f = fopen("D:\\1.txt", "rb");

			std::this_thread::sleep_for(10ms);

		}

		});

	t.detach();
}