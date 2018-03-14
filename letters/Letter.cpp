#include "Letter.h"
#include "Arduino.h"

Letter::Letter(int i, int len, char const *l) {
    index = i;
    length = len;
    letter = l;
    offStart = 0;
    offTime = 0;

    _hue = 0;
    _sat = 0;
    _val = 255;
    _offCounter = 0.0;
    _counterIncrement = 0.001;
    _popCounter = 0;
}

Letter::~Letter() {
}

float shift = 9.0;
void Letter::calcValue()
{
    _offCounter += _counterIncrement;

    // https://www.desmos.com/calculator/l33omjh6wm
    _val = abs(sin((_offCounter - shift) * 2.0) / pow(2.0, _offCounter - shift));
    if (random(2) == 0)
        _val += random(25, 75);
}

void Letter::offFrame(unsigned long now) {
    CHSV color = CHSV(_hue, _sat, _val);
    for (int i = index; i < index + length; i++)
        leds[i] = color;

    // no point in flickering forever, too dim
    if (now >= (offStart + offTime - 1000))
        _val++;
    else if (_offCounter <= 6.0)
        calcValue();
    else
    {
        if (_popCounter < 3)
        {
            _val = 255;
            _popCounter++;
        }
        else
            _val = 0;
    }
}

void Letter::goOffQuickly(unsigned long t, uint8_t h, uint8_t s) {
    _counterIncrement = 0.8;
    goOff(t, h, s);
}

void Letter::goOff(unsigned long t, uint8_t h, uint8_t s) {
    Serial.printf("off '%s'\n", letter);
    offStart = millis();

    offTime = t;
    _hue = h;
    _sat = s;
    _val = 255;
    _offCounter = 0;
    _counterIncrement = 0.008;

    for (int i = index; i < index + length; i++)
        leds[i] = CRGB::Black;
}

void Letter::goOn() {
    Serial.printf("on '%s'\n", letter);
    offStart = 0;
    offTime = 0;
    _val = 255;
    _popCounter = 0;
}

void Letter::setColor(CHSV color) {
    for (int i = index; i < index + length; i++)
        leds[i] = color;
}
