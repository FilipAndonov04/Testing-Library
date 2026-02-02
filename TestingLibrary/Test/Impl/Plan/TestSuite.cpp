#include "TestSuite.h"
#include "Logging/Log.hpp"
#include "Impl/Timer/TestTimer.h"

namespace Test {

TestSuite::TestSuite(const char* name) 
    : name(name) {}

const char* TestSuite::getName() const {
    return name;
}

unsigned TestSuite::totalTests() const {
    return cases.size();
}

const TestCase* TestSuite::getTestCase(const char* caseName) const {
    for (auto& c : cases) {
        if (c.getName() == caseName) {
            return &c;
        }
    }
    return nullptr;
}

TestCase* TestSuite::getTestCase(const char* caseName) {
    for (auto& c : cases) {
        if (c.getName() == caseName) {
            return &c;
        }
    }
    return nullptr;
}

void TestSuite::addTestCase(const char* caseName, void(*caseImpl)()) {
    cases.emplace_back(caseName, caseImpl);
}

unsigned TestSuite::run() const {
    logTabbed("[TEST SUITE] %s tests are running\n", name);
    incrementLogTabs();

    TestTimer timer;
    unsigned passed = runTests();
    auto duration = timer.getTimePassedMs();
    unsigned total = totalTests();
    
    decrementLogTabs();
    setConsoleColour(passed == total ? ConsoleColour::Green : ConsoleColour::Red);
    logTabbed("[TEST SUITE] %s tests passed %u/%u (%ums)\n", 
              name, passed, total, duration);
    setConsoleColour(ConsoleColour::Default);

    return passed;
}

unsigned TestSuite::runTests() const {
    unsigned passed = 0;
    for (auto& c : cases) {
        passed += c.run();
    }
    return passed;
}

}