#include "Test/Test.h"
#include "Test/Asserts.h"

TEST_CASE(Ptr, NotNull) {
	int* ptr = nullptr;

	ASSERT_NULL(ptr, "ptr must be null");
}

TEST_CASE(Ptr, Null) {
	int i = 67;
	int* ptr = &i;

	ASSERT_NOT_NULL(ptr, "ptr must not be null");
}

TEST_MAIN() {
	Test::runAllTests();
	Test::runSuiteTests("FuncGood");
	Test::runSuiteTests("FuncBad");
}