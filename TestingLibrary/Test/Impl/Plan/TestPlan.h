#pragma once
#include "Impl/Plan/TestSuite.h"

namespace Test {

class TestPlan {
public:
	unsigned totalTests() const;

	const TestSuite* getTestSuite(const char* suiteName) const;
	TestSuite* getTestSuite(const char* suiteName);
	const TestCase* getTestCase(const char* suiteName, const char* caseName) const;
	TestCase* getTestCase(const char* suiteName, const char* caseName);

	void addTestCase(const char* suiteName, const char* caseName, void(*caseImpl)());

	unsigned run() const;

private:
	unsigned runTests() const;

	std::vector<TestSuite> suites;
};

}