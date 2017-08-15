#include "inappropirates_marquee.h"

#define RANDOM_PIN 3
#define LED_PIN 13

BrightnessManager brightnessManager;
uint8_t mode = 0;
unsigned long mode_timer = millis();

void setup()
{
	Serial.begin(9600);
	pinMode(LED_PIN, OUTPUT);

	for (uint8_t i = 0; i < nLEDS; i++)
	    leds[i] = CHSV(0, 0, 0);
	leds_init();

    pinMode(RANDOM_PIN, INPUT);
    randomSeed(analogRead(RANDOM_PIN));
    random16_add_entropy(random());

    Serial.printf("starting with mode %s\n", modes[mode]->name());
}

void loop()
{
	if (millis() - mode_timer >= modes[mode]->length_millis)
	{
		mode++;
		if (mode >= nModes)
			mode = 0;
		mode_timer = millis();
        Serial.printf("mode: %s\n", modes[mode]->name());
	}

	brightnessManager.frame();
	modes[mode]->frame();
	led_show();

	// CHSV color = CHSV(35, 170, 255);
	//setColor(color);
}
