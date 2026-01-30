#pragma once
#include "Impl/Register/TestRegistration.h"

namespace Test {

#define TEST_CASE(suite, name) \
	void _test##name(); \
	Test::TestRegistration testRegistration##name(#suite, {#name, &_test##name}); \
	void _test##name()

#define TEST_MAIN() \
	void _main_impl(); \
	int main() { \
		_main_impl(); \
		return Test::haveAllTestsPassed() ? EXIT_SUCCESS : EXIT_FAILURE; \
	} \
	void _main_impl()

bool runAllTests();
bool runSuiteTests(const char* testSuite);
bool runTestCase(const char* testCase);

bool haveAllTestsPassed();

}