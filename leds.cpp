#include "leds.h"

Letter letters_inappro[nLETTERS_INAPPRO] = {
		Letter(0, 10, "i"),
		Letter(10, 10, "n"),
		Letter(20, 10, "a")
};

Letter letters_pirates[nLETTERS_PIRATES] = {
		Letter(0, 11, "p"),
		Letter(11, 10, "i")
};


CRGB leds[nLEDS];
CRGB *leds_inappro = &(leds[0]);
CRGB *leds_pirates = &(leds[nLEDS_INAPPRO]);

void leds_init()
{
	for (uint8_t i = 0; i < nLEDS; i++)
	    leds[i] = CHSV(0, 0, 0);

	FastLED.setBrightness(0);
	FastLED.addLeds<WS2811, 4, RGB>(leds_inappro, nLEDS_INAPPRO);
	FastLED.addLeds<WS2811, 6, RGB>(leds_pirates, nLEDS_PIRATES);
	led_show();
}
