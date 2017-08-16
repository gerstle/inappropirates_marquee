#include "Letter.h"
#include "Arduino.h"

Letter::Letter(int i, int len, char const *l) {
    index = i;
    length = len;
    letter = l;
}

Letter::~Letter() {
}

void Letter::offFrame() {
    Serial.printf("off: '%s'\n", letter);
}
