#include "Test/Test.h"
#include "Test/Asserts.h"

#include <exception>

void badFunc() { throw std::runtime_error("I am bad"); }
int goodFunc() { return 42; }

TEST_CASE(FuncGood, DoesNotThrow) {
	ASSERT_NO_THROW(goodFunc, "goodFunc should not throw");
}

TEST_CASE(FuncGood, Throw) {
	ASSERT_THROW(std::exception, goodFunc, "goodFunc should throw Exception");
}

TEST_CASE(FuncBad, DoesNotThrow) {
	ASSERT_NO_THROW(badFunc, "badFunc should not throw");
}

TEST_CASE(FuncBad, ThrowsLogicError) {
	ASSERT_THROW(std::logic_error, badFunc, "badFunc should throw Logic error");
}

TEST_CASE(FuncBad, ThrowsRuntimeError) {
	ASSERT_THROW(std::runtime_error, badFunc, "badFunc should throw Runtime error");
}