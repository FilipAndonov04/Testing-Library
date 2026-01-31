#include "Test/Test.h"
#include "Test/Asserts.h"

#include <vector>

TEST_CASE(Vector, ElementsSum) {
	std::vector<int> v;
	for (int i = 0; i < 100000000; i++) {
		v.push_back(i + 1);
	}

	unsigned long long sum = 0;
	for (int i = 0; i < v.size(); i++) {
		sum += v[i];
	}

	unsigned long long expected = v.size() * (v.size() + 1) / 2;
	ASSERT_EQUAL(expected, sum, "sum must be correct");
}

TEST_CASE(Vector, ElementsAvarage) {
	std::vector<int> v;
	for (int i = 0; i < 100000000; i++) {
		v.push_back(i + 1);
	}

	unsigned long long sum = 0;
	for (int i = 0; i < v.size(); i++) {
		sum += v[i];
	}

	double expected = (1 + v.size()) / 2.0;
	ASSERT_EQUAL(expected, sum / v.size(), "avarage must be correct");
}

TEST_CASE(Vector, Palindrome) {
	std::vector<int> v(15);
	for (size_t i = 0; i < v.size() / 2; i++) {
		v[i] = i;
		v[v.size() - 1 - i] = i;
	}

	ASSERT_ITERABLE_EQUAL(v.begin(), v.end(), v.rbegin(), v.rend(), "they are palindorme");
}

TEST_CASE(Vector, NotPalindrome) {
	std::vector<int> v(15);
	for (size_t i = 0; i < v.size(); i++) {
		v[i] = i;
	}

	ASSERT_ITERABLE_EQUAL(v.begin(), v.end(), v.rbegin(), v.rend(), "they are not palindromes");
}

TEST_CASE(Vector, EqualElementsAndDifferentLength) {
	std::vector<int> v1(15);
	for (size_t i = 0; i < v1.size(); i++) {
		v1[i] = i;
	}

	std::vector<int> v2(v1);
	v2.push_back(104);

	ASSERT_ITERABLE_EQUAL(v1.begin(), v1.end(), v2.begin(), v2.end(),
						  "collections with same elements but different size are not equal");
}