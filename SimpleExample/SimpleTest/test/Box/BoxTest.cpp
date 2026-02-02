#include "Box/Box.h"

#include <Test/Test.h>
#include <Test/Asserts.h>
#include <Test/EntryPoint.h>

TEST_CASE(Box, EmptyOnConstruction) {
	Box box;

	ASSERT_TRUE(box.isEmpty(), "box should be empty on default contruction");
}