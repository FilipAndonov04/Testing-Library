#include "Test/Test.h"
#include "Test/Asserts.h"

#include <exception>

void badFunc() { throw std::runtime_error("I am bad"); }
int goodFunc() { return 42; }

TEST_CASE(FuncGood, DoesNotThrow) {
	ASSERT_DOES_NOT_THROW(goodFunc, "goodFunc should not throw");
}

TEST_CASE(FuncGood, Throw) {
	ASSERT_THROWS(std::exception, goodFunc, "goodFunc should throw Exception");
}

TEST_CASE(FuncBad, DoesNotThrow) {
	ASSERT_DOES_NOT_THROW(badFunc, "badFunc should not throw");
}

TEST_CASE(FuncBad, ThrowsLogicError) {
	ASSERT_THROWS(std::logic_error, badFunc, "badFunc should throw Logic error");
}

TEST_CASE(FuncBad, ThrowsRuntimeError) {
	ASSERT_THROWS(std::runtime_error, badFunc, "badFunc should throw Runtime error");
}