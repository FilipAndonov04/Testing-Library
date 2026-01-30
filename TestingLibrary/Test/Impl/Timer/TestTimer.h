#pragma once

#include <chrono>

namespace Test {

class TestTimer {
public:
	TestTimer();

	unsigned long long getTimePassedMs() const;

private:
	std::chrono::high_resolution_clock::time_point startTick;
};

}