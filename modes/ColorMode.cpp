#include "ColorMode.h"

ColorMode::ColorMode(unsigned long l, const char *name, CHSV color, long delay) {
    length_millis = l;
    _name = name;
    _color = color;
    _lastChange = millis();
    _delay = delay;
}

ColorMode::~ColorMode() {
}

void ColorMode::frame() {
    unsigned long now = millis();
    int dice = 0;

    if (now > _lastChange + _delay)
    {
        _lastChange = now;

        CHSV tmp;
        for (int i = 0; i < nLEDS; i++) {
            dice = random(256);

            if ((dice <= 10) && (_delay > 0))
                tmp = CHSV(_color.hue, _color.sat, random(215, 255));
            else
                tmp = _color;
            leds[i] = tmp;
        }
    }

    uint8_t availableOffIndex = -1;
    for (int i = 0; i < nOFF_LETTERS; i++) {
        if (offLetters[i] != NULL)
        {
            offLetters[i]->offFrame(now);

            if (now - offLetters[i]->offStart > offLetters[i]->offTime)
            {
                offLetters[i]->goOn();
                offLetters[i] = NULL;
            }
        }
        else
            availableOffIndex = i;
    }

    dice = random(1000000);
    if (availableOffIndex > -1 && availableOffIndex < nOFF_LETTERS && dice == 0)
    {
        dice = random(0, nLETTERS);

        // only turn off if it's not already off
        if (letters[dice].offTime == 0)
        {
            offLetters[availableOffIndex] = &letters[dice];
            offLetters[availableOffIndex]->goOff(random(30, 300) * 1000, _color.hue, _color.sat);
        }
    }
}
