#pragma once

#include <string>

class Box {
public:
	bool isEmpty() const;

	const std::string& getContent() const;
	void setContent(std::string content);

private:
	std::string content;
};