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
    const char* name() { return _name; }

private:
    const char *_name;
    uint8_t brightness = LED_DEFAULT_BRIGHTNESS;

    void set(uint8_t brightness);
};

#endif /* UTIL_BRIGHTNESSMANAGER_H_ */
