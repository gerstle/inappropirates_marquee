#ifndef UTIL_BRIGHTNESSMANAGER_H_
#define UTIL_BRIGHTNESSMANAGER_H_

#include "../modes/BaseMode.h"

#define LED_DEFAULT_BRIGHTNESS 100
#define BRIGHTNESS_PIN 1

class BrightnessManager: public BaseMode {
public:
	BrightnessManager();
	virtual ~BrightnessManager();

    void frame();
    void set(uint8_t b);
    uint8_t brightness = LED_DEFAULT_BRIGHTNESS;
};

#endif /* UTIL_BRIGHTNESSMANAGER_H_ */
