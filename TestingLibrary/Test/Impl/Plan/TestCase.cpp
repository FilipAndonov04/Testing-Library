#include "TestCase.h"
#include "Logging/Log.hpp"
#include "Exception/TestFailedException.h"
#include "Impl/Timer/TestTimer.h"

namespace Test {

TestCase::TestCase(const char* name, void (*impl)())
    : name(name), impl(impl) {}

const char* TestCase::getName() const {
    return name;
}

bool TestCase::run() const {
    TestTimer timer;
    try {
        impl();
        auto duration = timer.getTimePassedMs();

        setConsoleColour(ConsoleColour::Green);
        logTabbed("[TEST CASE] %s passed (%ums)\n", 
                  name, duration);
        resetConsoleColour();

        return true;
    } catch (const TestFailedException& e) {
        auto duration = timer.getTimePassedMs();

        setConsoleColour(ConsoleColour::Red);
        logTabbed("[TEST CASE] %s (%s:%i) failed: %s (%ums)\n", 
                  name, e.getFile(), e.getLine(), e.what(), duration);
        resetConsoleColour();

        return false;
    } catch (...) {
        auto duration = timer.getTimePassedMs();

        setConsoleColour(ConsoleColour::Red);
        logTabbed("[TEST CASE] %s failed with an unexpected exception (%ums)\n", 
                  name, duration);
        resetConsoleColour();

        return false;
    }
}

}