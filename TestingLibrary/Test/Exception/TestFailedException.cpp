#include "TestFailedException.h"

namespace Test {

static const char* getFilename(const char* path);

TestFailedException::TestFailedException(const char* msg, const char* file, int line)
    : std::exception(msg), file(getFilename(file)), line(line) {}

TestFailedException::TestFailedException(const std::string& msg, const char* file, int line) 
    : TestFailedException(msg.c_str(), file, line) {}

const char* TestFailedException::getFile() const {
    return file;
}

int TestFailedException::getLine() const {
    return line;
}

const char* getFilename(const char* path) {
    const char* filename = path;

    while (*path) {
        if (*path == '/' || *path == '\\') {
            filename = path + 1;
        }
        path++;
    }

    return filename;
}

}