#include "Box.h"

bool Box::isEmpty() const {
    return content.empty();
}

const std::string& Box::getContent() const {
    return content;
}

void Box::setContent(std::string content) {
    this->content = std::move(content);
}