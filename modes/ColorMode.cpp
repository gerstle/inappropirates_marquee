#include "ColorMode.h"

ColorMode::ColorMode(long l, const char *name, CHSV color, long delay) {
    length_millis = l;
    _name = name;
    _color = color;
    _lastChange = millis();
    _delay = delay;
}

ColorMode::~ColorMode() {
}

void ColorMode::frame() {
    unsigned long currentTime = millis();
    if (currentTime <= _lastChange + _delay)
        return;

    _lastChange = currentTime;

    int dice = 0;
    CHSV tmp;
    for (int i = 0; i < nLEDS; i++) {
        dice = random8();

        if ((dice <= 10) && (_delay > 0))
            tmp = CHSV(_color.hue, _color.sat, random8(200, 255));
        else
            tmp = _color;
        leds[i] = tmp;
    }

    for (int i = 0; i < nOFF_LETTERS; i++) {
        if (offLetters[i] != NULL)
            offLetters[i]->offFrame();
    }
}
