#pragma once

namespace Test {

class TestCase {
public:
	TestCase(const char* name, void (*impl)());

	const char* getName() const;

	bool run() const;

private:
	const char* name;
	void (*impl)();
};

}