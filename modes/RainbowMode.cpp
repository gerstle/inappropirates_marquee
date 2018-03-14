#include "RainbowMode.h"

RainbowMode::RainbowMode(unsigned long l, long d) {
    length_millis = l;
    _name = "rainbow";
    _lastChange = millis();
    _delay = d;

}

RainbowMode::~RainbowMode() {
}

void RainbowMode::frame() {
    unsigned long now = millis();

    if (now > _lastChange + _delay)
    {
        _lastChange = now;

        for (int l = 0; l < nLETTERS; l++) {
			uint8_t hue = l * 18;
        		for (int i = letters[l].index; i < letters[l].index + letters[l].length; i++) {
				if ((random(256) <= 10) && (_delay > 0))
					leds[i] = CHSV(hue, 255, random(215, 255));
				else
					leds[i] = CHSV(hue, 255, 255);
        		}
        }
    }
}
