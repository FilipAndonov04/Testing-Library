#pragma once
#include "Impl/Plan/TestCase.h"

#include <vector>

namespace Test {

class TestSuite {
public:
	explicit TestSuite(const char* name);
	TestSuite(const char* name, TestCase testCase);

	const char* getName() const;
	unsigned totalTests() const;
	const std::vector<TestCase>& getTestCases() const;
	std::vector<TestCase>& getTestCases();

	void addTestCase(TestCase testCase);

	unsigned runTests() const;

private:
	unsigned runTestsImpl() const;

	const char* name;
	std::vector<TestCase> cases;
};

}