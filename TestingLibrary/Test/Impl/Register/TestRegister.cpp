#include "TestRegister.h"
#include "Impl/Plan/TestPlan.h"

namespace Test {

TestPlan& getTestRegister() {
    static TestPlan instance;
    return instance;
}

}