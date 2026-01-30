#pragma once

#include <cstdio>

namespace Test {

template <typename... Ts>
inline void log(const char* fmt, const Ts&... ts) {
	std::printf(fmt, ts...);
}

unsigned getLogTabs();
void setLogTabs(unsigned tabs);
void incrementLogTabs();
void decrementLogTabs();

template <typename... Ts>
inline void logTabbed(const char* fmt, const Ts&... ts) {
	for (unsigned i = 0; i < getLogTabs(); i++) {
		log("\t");
	}
	log(fmt, ts...);
}

constexpr const char* COLOUR_DEFAULT = "\x1B[39m";
constexpr const char* COLOUR_GREEN = "\x1B[32m";
constexpr const char* COLOUR_RED = "\x1B[31m";

enum class ConsoleColour {
	Default,
	Green,
	Red
};

void setConsoleColour(ConsoleColour colour);
void resetConsoleColour();

}