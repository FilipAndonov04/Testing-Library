#pragma once
#include "Exception/TestFailedException.h"

#include <string>
#include <sstream>

namespace Test {

#define ASSERT_TRUE(condition, msg) ASSERT_TRUE_IMPL(condition, msg)
#define ASSERT_FALSE(condition, msg) ASSERT_TRUE_IMPL(!(condition), msg)
#define ASSERT_EQUAL(expected, actual, msg) ASSERT_EQUAL_IMPL(expected, actual, msg)
#define ASSERT_NOT_EQUAL(expected, actual, msg) ASSERT_NOT_EQUAL_IMPL(expected, actual, msg)
#define ASSERT_NULL(ptr, msg) ASSERT_TRUE((ptr) == nullptr, msg)
#define ASSERT_NOT_NULL(ptr, msg) ASSERT_TRUE((ptr) != nullptr, msg)
#define ASSERT_ITERABLE_EQUAL(first1, last1, first2, last2, msg) ASSERT_ITERABLE_EQUAL_IMPL(first1, last1, first2, last2, msg)
#define ASSERT_THROWS(exception, function, msg) ASSERT_THROWS_IMPL(exception, function, msg)
#define ASSERT_DOES_NOT_THROW(function, msg) ASSERT_DOES_NOT_THROW_IMPL(function, msg)

template <typename T>
std::string toString(T&& t);

#define ASSERT_TRUE_IMPL(condition, msg) \
	do { \
		if (!(condition)) { \
			throw Test::TestFailedException((msg), __FILE__, __LINE__); \
		} \
	} while (false)

#define ASSERT_EQUAL_IMPL(expected, actual, msg) \
	do { \
		auto&& _expected = (expected); \
		auto&& _actual = (actual); \
		if (!(_expected == _actual)) { \
			throw Test::TestFailedException("Expected: " + Test::toString(_expected) + \
											", Actual: " + Test::toString(_actual) + ", " + (msg) , \
											__FILE__, __LINE__); \
		} \
	} while (false)

#define ASSERT_NOT_EQUAL_IMPL(expected, actual, msg) \
	do { \
		auto&& _expected = (expected); \
		auto&& _actual = (actual); \
		if (_expected == _actual) { \
			throw Test::TestFailedException("Expected: " + Test::toString(_expected) + \
											", Actual: " + Test::toString(_actual) + ", " + (msg) , \
											__FILE__, __LINE__); \
		} \
	} while (false)

#define ASSERT_ITERABLE_EQUAL_IMPL(first1, last1, first2, last2, msg) \
	do { \
		auto&& _first1 = (first1); \
		auto&& _last1 = (last1); \
		auto&& _first2 = (first2); \
		auto&& _last2 = (last2); \
		size_t _iteration = 0; \
		while (_first1 != _last1 && _first2 != _last2) { \
			if (!(*_first1 == *_first2)) { \
				throw Test::TestFailedException("missmatch at " + std::to_string(_iteration) + \
												"th iteration, " + (msg), __FILE__, __LINE__); \
			} \
			++_first1; \
			++_first2; \
			++_iteration; \
		} \
		if (_first1 != _last1) { \
			throw Test::TestFailedException(std::string("first collection has more elements, ") + \
											(msg), __FILE__, __LINE__); \
		} else if (_first2 != _last2) { \
			throw Test::TestFailedException(std::string("first collection has less elements, ") + \
											(msg), __FILE__, __LINE__); \
		} \
	} while (false)

#define ASSERT_THROWS_IMPL(exceptionType, function, msg) \
	do { \
		auto&& _func = (function); \
		try { \
			_func(); \
		} catch (const exceptionType##& e) { \
			break; \
		} catch (...) { \
			throw Test::TestFailedException(std::string("another exception was thrown, ") + \
											(msg), __FILE__, __LINE__); \
		} \
		throw Test::TestFailedException(std::string("expected exception was not thrown, ") + \
											(msg), __FILE__, __LINE__); \
	} while (false)

#define ASSERT_DOES_NOT_THROW_IMPL(function, msg) \
	do { \
		auto&& _func = (function); \
		try { \
			_func(); \
		} catch (...) { \
			throw Test::TestFailedException(std::string("an expected was thrown, ") + \
											(msg), __FILE__, __LINE__); \
		} \
	} while (false) 

template <typename T>
std::string toString(T&& t) {
	std::ostringstream ss;
	ss << t;
	return ss.str();
}

}