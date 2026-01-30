#pragma once

#include <stdexcept>
#include <string>

namespace Test {

class TestFailedException : public std::exception {
public:
	TestFailedException(const char* msg, const char* file, int line);
	TestFailedException(const std::string& msg, const char* file, int line);

	const char* getFile() const;
	int getLine() const;

private:
	const char* file;
	int line;
};

}