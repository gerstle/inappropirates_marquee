#include "BaseMode.h"

BaseMode::BaseMode() {
    _name = "base";
}

BaseMode::~BaseMode() {
}

void BaseMode::start() {
}

void BaseMode::frame() {
}

const char* BaseMode::name() {
    return _name;
}
