#pragma once
#include "Impl/Plan/TestPlan.h"
#include "Impl/Plan/TestCase.h"

namespace Test {

TestPlan& getTestRegister();

class TestRegistration {
public:
	TestRegistration(const char* suite, TestCase testCase);
};

}