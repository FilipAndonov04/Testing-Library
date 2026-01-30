#include "Test/Test.h"
#include "Test/Asserts.h"

#include <string>

TEST_CASE(String, SubstringWithValidInterval) {
	std::string s = "abcdef";

	ASSERT_EQUAL("cde", s.substr(2, 3), "substr should work correctly");
}

TEST_CASE(String, SubstringWithInvalidSize) {
	std::string s = "abcdef";

	ASSERT_EQUAL("cdef", s.substr(2, 1000), "substr should work correctly");
}

TEST_CASE(String, SubstringWithInvalidStart) {
	std::string s = "abcdef";

	ASSERT_EQUAL("", s.substr(20, 3), "substr should work correctly");
}

TEST_CASE(String, SubstringWithZeroLength) {
	std::string s = "abcdef";

	ASSERT_NOT_EQUAL("", s.substr(1, 0), "substr should work correctly");
}