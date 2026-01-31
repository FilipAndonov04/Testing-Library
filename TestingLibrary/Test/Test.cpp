#include "Test.h"
#include "Logging/Log.hpp"
#include "Impl/Plan/TestPlan.h"
#include "Impl/Register/TestRegister.h"

namespace Test {

static bool allTestsPassed = true;

bool runAllTests() {
	unsigned passed = getTestRegister().runTests();
	log("\n");

	unsigned total = getTestRegister().totalTests();
	allTestsPassed &= passed == total;
	return allTestsPassed;
}

bool runSuiteTests(const char* testSuite) {
	TestSuite* s = getTestRegister().getTestSuite(testSuite);
	if (!s) {
		setConsoleColour(ConsoleColour::Red);
		log("[ERROR] test suite %s does not exist\n\n", testSuite);
		setConsoleColour(ConsoleColour::Default);

		allTestsPassed = false;
		return false;
	}

	unsigned passed = s->runTests();
	log("\n");

	unsigned total = s->totalTests();
	allTestsPassed &= passed == total;
	return allTestsPassed;
}

bool runTestCase(const char* testSuite, const char* testCase) {
	TestCase* c = getTestRegister().getTestCase(testSuite, testCase);
	if (!c) {
		setConsoleColour(ConsoleColour::Red);
		log("[ERROR] test suite %s does not contain test case %s\n\n",
			testSuite, testCase);
		setConsoleColour(ConsoleColour::Default);

		allTestsPassed = false;
		return false;
	}

	allTestsPassed &= c->run();
	log("\n");

	return allTestsPassed;
}

bool runTestCase(const char* testCase) {
	TestCase* c = getTestRegister().getTestCase(testCase);
	if (!c) {
		setConsoleColour(ConsoleColour::Red);
		log("[ERROR] test case %s does not exist\n\n", testCase);
		setConsoleColour(ConsoleColour::Default);

		allTestsPassed = false;
		return false;
	}

	allTestsPassed &= c->run();
	log("\n");

	return allTestsPassed;
}

bool haveAllTestsPassed() {
	return allTestsPassed;
}

}