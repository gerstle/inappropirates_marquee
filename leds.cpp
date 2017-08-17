#include "leds.h"

CRGB leds[nLEDS];
CRGB *leds_inappro = &(leds[0]);
CRGB *leds_pirates = &(leds[nLEDS_INAPPRO]);

void leds_init() {
    for (uint8_t i = 0; i < nLEDS; i++)
        leds[i] = CHSV(0, 0, 0);

    FastLED.setBrightness(0);
    FastLED.addLeds<WS2811, 4, RGB>(leds_inappro, nLEDS_INAPPRO);
    FastLED.addLeds<WS2811, 6, RGB>(leds_pirates, nLEDS_PIRATES);
    led_show();
}

void leds_dim(uint8_t amount) {
    for (uint8_t i = 0; i < nLEDS; i++)
        leds[i].fadeToBlackBy(amount);
}
