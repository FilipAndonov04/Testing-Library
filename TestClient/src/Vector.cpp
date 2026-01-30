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