#pragma once
#include "Impl/Register/TestRegistration.h"
#include "Exception/TestFailedException.h"

namespace Test {

#define TEST_CASE(suite, name) \
	void test##suite##name(); \
	void test##suite##name##_structure() { \
		try { \
			test##suite##name(); \
		} catch (const Test::TestFailedException& e) { \
			throw; \
		} catch (const std::exception& e) { \
			throw Test::TestFailedException(std::string("an unexpected exception occurred, ") + e.what(), __FILE__, __LINE__); \
		} catch (...) { \
			throw Test::TestFailedException("an unexpected exception occurred", __FILE__, __LINE__); \
		} \
	} \
	static Test::TestRegistration testRegistration##name(#suite, {#name, &test##suite##name##_structure}); \
	void test##suite##name()

#define TEST_MAIN() \
	void main_impl(); \
	int main() { \
		main_impl(); \
		return Test::haveAllTestsPassed() ? EXIT_SUCCESS : EXIT_FAILURE; \
	} \
	void main_impl()

bool runAllTests();
bool runSuiteTests(const char* testSuite);
bool runTestCase(const char* testSuite, const char* testCase);
bool runTestCase(const char* testCase);

bool haveAllTestsPassed();

}