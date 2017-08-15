#ifndef _leds_h
#define _leds_h

#include "FastLED.h"
#include "Letter.h"

#define nLETTERS_INAPPRO 3
#define nLETTERS_PIRATES 2

extern Letter letters_inappro[];
extern Letter letters_pirates[];

#define nLEDS_INAPPRO 30
#define nLEDS_PIRATES 21
#define nLEDS nLEDS_INAPPRO + nLEDS_PIRATES

extern CRGB leds[];
extern CRGB *leds_inappro;
extern CRGB *leds_pirates;

#define led_show() FastLED.show()
#define led_brightness(b) FastLED.setBrightness(b)
#define led_print(n) Serial.printf("RGB(%d, %d, %d)\n", leds[n].r, leds[n].g, leds[n].b)
#define hsv_print(color) Serial.printf("HSV(%d, %d, %d)\n", color.hue, color.sat, color.val)

void leds_init();

#endif
