#include "TestTimer.h"

namespace Test {

TestTimer::TestTimer() 
    : startTick(std::chrono::steady_clock::now()) {}

unsigned long long TestTimer::getTimePassedMs() const {
    auto stopTick = std::chrono::high_resolution_clock::now();
    return std::chrono::duration_cast<std::chrono::milliseconds>(stopTick - startTick).count();
}

}