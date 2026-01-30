#include "TestPlan.h"
#include "Logging/Log.hpp"
#include "Impl/Timer/TestTimer.h"

namespace Test {

void TestPlan::addTestCase(const char* suiteName, TestCase testCase) {
    std::lock_guard<std::mutex> lock{mutex};
    
    for (auto& suite : suites) {
        if (suite.getName() == suiteName) {
            suite.addTestCase(std::move(testCase));
            return;
        }
    }
    suites.emplace_back(suiteName, std::move(testCase));
}

TestSuite* TestPlan::getTestSuite(const char* suiteName) {
    for (auto& suite : suites) {
        if (suite.getName() == suiteName) {
            return &suite;
        }
    }
    return nullptr;
}

TestCase* TestPlan::getTestCase(const char* suiteName, const char* caseName) {
    TestSuite* suite = getTestSuite(suiteName);
    if (!suite) {
        return nullptr;
    }

    for (auto& c : suite->getTestCases()) {
        if (c.getName() == caseName) {
            return &c;
        }
    }
    return nullptr;
}

TestCase* TestPlan::getTestCase(const char* caseName) {
    for (auto& suite : suites) {
        for (auto& c : suite.getTestCases()) {
            if (strcmp(c.getName(), caseName) == 0) {
                return &c;
            }
        }
    }
    return nullptr;
}

unsigned TestPlan::totalTests() const {
    unsigned total = 0;
    for (const auto& suite : suites) {
        total += suite.totalTests();
    }
    return total;
}

unsigned TestPlan::runTests() const {
    logTabbed("[ALL TESTS] are running\n");

    incrementLogTabs();
    TestTimer timer;
    unsigned passed = runTestsImpl();
    auto duration = timer.getTimePassedMs();
    decrementLogTabs();

    unsigned total = totalTests();
    setConsoleColour(passed == total ? ConsoleColour::Green : ConsoleColour::Red);
    logTabbed("[ALL TESTS] results: passed %u/%u and failed %u/%u (%ums)\n", 
              passed, total, total - passed, total, duration);
    setConsoleColour(ConsoleColour::Default);

    return passed;
}

unsigned TestPlan::runTestsImpl() const {
    unsigned passed = 0;
    for (const auto& suite : suites) {
        passed += suite.runTests();
    }
    return passed;
}

}