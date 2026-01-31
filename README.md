# TestingLibrary

Library for testing code with simple interface.

## Testing

Testing is done with test cases. 
Test cases have a suite, by which they are grouped, and a name. 
They are automatically registered. 

```
TEST_CASE(suit, name) {
    ...
}
```

## Asserts

Asserts are used to validate the test case. 
If any assert fails, the test stops execution at that point and fails. 

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

The entry point of the test client program is the function `TEST_MAIN()`. 
In it the client can specify which tests to run. 
It can be skipped if the file `Test/EntryPoint.h` is included, in which case all tests will be run. 

Functions for running the tests:
```
bool Test::runAllTests();
bool Test::runSuiteTests(const char* testSuite);
bool Test::runTestCase(const char* testSuite, const char* testCase);
bool Test::runTestCase(const char* testCase);
```

The success of all run tests up to this moment in time can be checked with `Test::haveAllTestsPassed()`.

## Testing Result

The testing results are printed in the console. 
They consist of success of cases and suites and their time duration. 
On test case failure the following things are shown: the assertion message, the filename and line and the expected value, if there was any. 
If an exception is thrown, its error message and the filename and line will be shown. 
The program returns 0 if all tests pass and 1 otherwise. 

Screenshot of test results:

![Screenshot of test results](/example-images/testing-results-example.png)

## Example Client Program

A simple test program: 
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
