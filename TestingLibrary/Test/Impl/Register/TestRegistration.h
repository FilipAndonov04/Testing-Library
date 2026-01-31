#pragma once

namespace Test {

class TestRegistration {
public:
	TestRegistration(const char* suiteName, const char* caseName, void(*caseImpl)());
};

}