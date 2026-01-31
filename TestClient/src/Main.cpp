#include "Test/Test.h"
#include "Test/Asserts.h"

TEST_CASE(Ptr, NotNull) {
	int* ptr = nullptr;

	ASSERT_NULL(ptr, "ptr must not be null");
}

TEST_CASE(Ptr, Null) {
	int* ptr = new int(67);

	ASSERT_NOT_NULL(ptr, "ptr must not be null");

	delete ptr;
}

TEST_MAIN() {
	Test::runAllTests();
	Test::runSuiteTests("Ptr");
	Test::runTestCase("Vector", "Palindrome");
}