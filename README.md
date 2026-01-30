# TestingLibrary

Library for testing code with simple interface.

## Testing

Testing is done with test cases. <br>
Test cases have a suite, by which they are grouped, and a name. <br>
They are automatically registered. <br>

```
TEST_CASE(suit, name) {
    ...
}
```

## Asserts

Asserts are used to validate the test case. <br>
If any assert fails, the test stops execution at that point and fails. <br>

```
ASSERT_TRUE(condition, msg);
ASSERT_FALSE(condition, msg);
ASSERT_EQUAL(expected, actual, msg);
ASSERT_NOT_EQUAL(expected, actual, msg);
ASSERT_NULL(ptr, msg);
ASSERT_NOT_NULL(ptr, msg);
ASSERT_ITERABLE_EQUAL(first1, last1, first2, msg);
```

## Entry Point

The entry point of the test client program is the function `TEST_MAIN()`. <br>
In it the client can specify which tests to run. <br>
It can be skipped if the file `Test/EntryPoint.h` is included, in which case all tests will be run. <br>

Functions for running the tests: <br>
```
bool Test::runAllTests();
bool Test::runSuiteTests(const char* testSuite);
bool Test::runTestCase(const char* testCase);
```

The success of all run tests up to this moment in time can be checked with `Test::haveAllTestsPassed()`. <br>

## Testing Result

The testing results are printed in the console. <br>
They consist of success of cases and suites and their time duration. <br>
On test case failure the following things are shown: the assertion message, the filename and line and the expected value, if there was any. <br>
If an exception is thrown, its error message and the filename and line will be shown. <br>
The program returns 0 if all tests pass and 1 otherwise.

## Examples

An example test program:<br>
```
#include <Test/Test.h>
#include <Test/Asserts.h>
#include <Test/EntryPoint.h>

#include "Box.h"

TEST_CASE(Box, DefaultConstructor) {
    Box box;

    ASSERT_TRUE(box.isEmpty(), "Box should be empty on construction");
}
```
