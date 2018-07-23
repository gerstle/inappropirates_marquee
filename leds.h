#ifndef _leds_h
#define _leds_h

#include "FastLED.h"

#define nLEDS_INAPPRO 98
#define nLEDS_PIRATES 93
#define nLEDS nLEDS_INAPPRO + nLEDS_PIRATES
#define OFF_LENGTH 25

extern CRGB leds[];
extern CRGB *leds_inappro;
extern CRGB *leds_pirates;
extern uint8_t off[];

#define led_show() FastLED.show()
#define led_brightness(b) FastLED.setBrightness(b)
#define led_print(n) Serial.printf("RGB(%d, %d, %d)\n", leds[n].r, leds[n].g, leds[n].b)
#define hsv_print(color) Serial.printf("HSV(%d, %d, %d)\n", color.hue, color.sat, color.val)

void leds_init();
void leds_dim(uint8_t amount);

#endif
