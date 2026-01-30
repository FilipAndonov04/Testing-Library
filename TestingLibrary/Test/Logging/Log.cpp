#include "Log.hpp"

namespace Test {

static unsigned logTabs = 0;

unsigned getLogTabs() {
	return logTabs;
}

void setLogTabs(unsigned tabs) {
	logTabs = tabs;
}

void incrementLogTabs() {
	logTabs++;
}

void decrementLogTabs() {
	if (logTabs != 0) {
		logTabs--;
	}
}

void setConsoleColour(ConsoleColour colour) {
	const char* colourCode;
	switch (colour) {
	case ConsoleColour::Green:
		colourCode = COLOUR_GREEN;
		break;
	case ConsoleColour::Red:
		colourCode = COLOUR_RED;
		break;
	default:
		colourCode = COLOUR_DEFAULT;
		break;
	}

	std::printf(colourCode);
}

void resetConsoleColour() {
	setConsoleColour(ConsoleColour::Default);
}

}