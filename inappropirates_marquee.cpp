#include "inappropirates_marquee.h"

#define RANDOM_PIN 3
#define LED_PIN 13

BrightnessManager brightnessManager;
uint8_t mode = 0;
unsigned long mode_timer = millis();
boolean mode_starting = false;
unsigned long transition_time = 1000;

unsigned long fade_in_timer;
unsigned long fade_delay = 7;
uint8_t tmp_brightness = 0;

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
	modes[mode]->start();
	mode_starting = true;
}

unsigned long current_time = millis();
unsigned long millis_passed;
void loop()
{
	current_time = millis();
	millis_passed = current_time - mode_timer;
	if (millis_passed >= modes[mode]->length_millis)
	{
		mode++;
		if (mode >= nModes)
			mode = 0;

        Serial.printf("starting: %s\n", modes[mode]->name());
        modes[mode]->start();
		millis_passed = 0;
		mode_timer = current_time;
        mode_starting = true;
	}

	// if we just started a frame, slowly ease in
	if (millis_passed <= transition_time)
	{
		if (mode_starting)
		{
			Serial.println("mode starting");
			modes[mode]->frame();
			fade_in_timer = current_time;

			tmp_brightness = 0;
			Serial.println(tmp_brightness);
			brightnessManager.set(tmp_brightness++);

			mode_starting = false;
		}

		if (current_time - fade_in_timer >= fade_delay && tmp_brightness < brightnessManager.brightness)
		{
			Serial.println(tmp_brightness);
			brightnessManager.set(tmp_brightness++);
			fade_in_timer = current_time;
		}
	}
	else if (modes[mode]->length_millis - millis_passed <= transition_time)
	{
		Serial.println("dim");
		leds_dim(1);
	}
	else
	{
		Serial.println("frame");
		brightnessManager.frame();
		modes[mode]->frame();
	}

	led_show();
}
