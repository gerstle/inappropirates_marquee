#include "leds.h"
#include "letters.h"

CRGB leds[nLEDS];
CRGB *leds_inappro = &(leds[0]);
CRGB *leds_pirates = &(leds[nLEDS_INAPPRO]);

uint8_t off[OFF_LENGTH] = {
		// orppani
		11, 19, 20, 33, 34, 44, 49, 50, 57, 60, 63, 66, 83, 84, 94,
		// pirates
		112, 113, 121, 133, 146, 147, 162, 163, 176, 177
};

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
