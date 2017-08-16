#include "BrightnessManager.h"

BrightnessManager::BrightnessManager() {
	set(LED_DEFAULT_BRIGHTNESS);
}

BrightnessManager::~BrightnessManager() {
}

void BrightnessManager::set(uint8_t b) {
	led_brightness(b);
}

void BrightnessManager::frame() {
	brightness = analogRead(BRIGHTNESS_PIN);
	if (brightness < 5)
		brightness = 0;

	if (verbose)
		Serial.println(brightness);
	set(brightness);
}
