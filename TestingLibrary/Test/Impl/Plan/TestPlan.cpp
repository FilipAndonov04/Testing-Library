#include "TestPlan.h"
#include "Logging/Log.hpp"
#include "Impl/Timer/TestTimer.h"

namespace Test {

void TestPlan::addTestCase(const char* suiteName, const char* caseName, void(*caseImpl)()) {
    for (auto& suite : suites) {
        if (suite.getName() == suiteName) {
            suite.addTestCase(caseName, caseImpl);
            return;
        }
    }

    suites.emplace_back(suiteName);
    suites.back().addTestCase(caseName, caseImpl);
}

const TestSuite* TestPlan::getTestSuite(const char* suiteName) const {
    for (auto& suite : suites) {
        if (suite.getName() == suiteName) {
            return &suite;
        }
    }
    return nullptr;
}

TestSuite* TestPlan::getTestSuite(const char* suiteName) {
    for (auto& suite : suites) {
        if (suite.getName() == suiteName) {
            return &suite;
        }
    }
    return nullptr;
}

const TestCase* TestPlan::getTestCase(const char* suiteName, const char* caseName) const {
    const TestSuite* suite = getTestSuite(suiteName);
    if (!suite) {
        return nullptr;
    }

    return suite->getTestCase(caseName);
}

TestCase* TestPlan::getTestCase(const char* suiteName, const char* caseName) {
    TestSuite* suite = getTestSuite(suiteName);
    if (!suite) {
        return nullptr;
    }

    return suite->getTestCase(caseName);
}

unsigned TestPlan::totalTests() const {
    unsigned total = 0;
    for (const auto& suite : suites) {
        total += suite.totalTests();
    }
    return total;
}

unsigned TestPlan::run() const {
    logTabbed("[ALL TESTS] tests are running\n");
    incrementLogTabs();

    TestTimer timer;
    unsigned passed = runTests();
    auto duration = timer.getTimePassedMs();
    unsigned total = totalTests();

    decrementLogTabs();
    setConsoleColour(passed == total ? ConsoleColour::Green : ConsoleColour::Red);
    logTabbed("[ALL TESTS] tests passed %u/%u (%ums)\n", 
              passed, total, duration);
    setConsoleColour(ConsoleColour::Default);

    return passed;
}

unsigned TestPlan::runTests() const {
    unsigned passed = 0;
    for (const auto& suite : suites) {
        passed += suite.run();
    }
    return passed;
}

}