#include "TestRegistration.h"
#include "Impl/Register/TestRegister.h"
#include "Impl/Plan/TestPlan.h"

namespace Test {

TestRegistration::TestRegistration(const char* suiteName, const char* caseName, void(*caseImpl)()) {
    getTestRegister().addTestCase(suiteName, TestCase{caseName, caseImpl});
}

}