#include "Test/EntryPoint.h"
#include "Test/Test.h"
#include "Test/Asserts.h"
#include "Test/EntryPoint.h"

TEST_CASE(Ptr, NotNull) {
	int* ptr = nullptr;

	ASSERT_NULL(ptr, "ptr must not be null");
}

TEST_CASE(Ptr, Null) {
	int* ptr = new int(67);

	ASSERT_NOT_NULL(ptr, "ptr must not be null");

	delete ptr;
}