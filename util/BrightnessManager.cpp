#include "BrightnessManager.h"

BrightnessManager::BrightnessManager() {
	set(LED_DEFAULT_BRIGHTNESS);
}

BrightnessManager::~BrightnessManager() {
}

void BrightnessManager::set(uint8_t brightness) {
	led_brightness(brightness);
}

void BrightnessManager::frame() {
	brightness = analogRead(BRIGHTNESS_PIN);
	if (brightness < 5)
		brightness = 0;

	if (verbose)
		Serial.println(brightness);
	set(brightness);
}
