#pragma once
#include "Impl/Plan/TestSuite.h"

namespace Test {

class TestPlan {
public:
	void addTestCase(const char* suiteName, TestCase testCase);

	TestSuite* getTestSuite(const char* suiteName);
	TestCase* getTestCase(const char* suiteName, const char* caseName);
	TestCase* getTestCase(const char* caseName);

	unsigned totalTests() const;

	unsigned runTests() const;

private:
	unsigned runTestsImpl() const;

	std::vector<TestSuite> suites;
};

}