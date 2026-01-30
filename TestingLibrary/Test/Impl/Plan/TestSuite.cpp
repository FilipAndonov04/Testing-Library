#include "TestSuite.h"
#include "Logging/Log.hpp"
#include "Impl/Timer/TestTimer.h"

namespace Test {

TestSuite::TestSuite(const char* name) 
    : name(name) {}

TestSuite::TestSuite(const char* name, TestCase testCase) 
    : name(name), cases{testCase} {}

const char* TestSuite::getName() const {
    return name;
}

unsigned TestSuite::totalTests() const {
    return cases.size();
}

const std::vector<TestCase>& TestSuite::getTestCases() const {
    return cases;
}

std::vector<TestCase>& TestSuite::getTestCases() {
    return cases;
}

void TestSuite::addTestCase(TestCase testCase) {
    cases.push_back(std::move(testCase));
}

unsigned TestSuite::runTests() const {
    logTabbed("[TEST SUITE] %s is running\n", name);

    incrementLogTabs();
    TestTimer timer;
    unsigned passed = runTestsImpl();
    auto duration = timer.getTimePassedMs();
    decrementLogTabs();

    unsigned total = totalTests();
    setConsoleColour(passed == total ? ConsoleColour::Green : ConsoleColour::Red);
    logTabbed("[TEST SUITE] %s: tests passed %u/%u (%ums)\n", 
              name, passed, total, duration);
    setConsoleColour(ConsoleColour::Default);

    return passed;
}

unsigned TestSuite::runTestsImpl() const {
    unsigned passed = 0;
    for (const auto& c : cases) {
        passed += c.run();
    }
    return passed;
}

}