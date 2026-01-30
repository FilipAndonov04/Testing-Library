#include "TestRegistration.h"

namespace Test {

TestPlan& getTestRegister() {
    static TestPlan instance;
    return instance;
}

TestRegistration::TestRegistration(const char* suite, TestCase testCase) {
    getTestRegister().addTestCase(suite, std::move(testCase));
}

}