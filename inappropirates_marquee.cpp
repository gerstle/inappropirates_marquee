#include "inappropirates_marquee.h"

#define RANDOM_PIN 3
#define LED_PIN 13

BrightnessManager brightnessManager;
uint8_t mode = 0;
unsigned long mode_timer = millis();
boolean mode_starting = false;
unsigned long transition_time = 1000;

unsigned long fade_timer;
unsigned long fade_delay = 7;
uint8_t tmp_brightness = 0;

void setup()
{
	Serial.begin(9600);
	pinMode(LED_PIN, OUTPUT);

	leds_init();

    pinMode(RANDOM_PIN, INPUT);
    randomSeed(analogRead(RANDOM_PIN));
    random16_add_entropy(random());

	modes[mode]->start();
	mode_starting = true;
}

unsigned long now = millis();
unsigned long millis_passed;
unsigned long statusTimer = millis();
int frameCounter = 0;
bool blink = true;

void loop()
{
	now = millis();
	millis_passed = now - mode_timer;

    frameCounter++;
    if (now >= (statusTimer + 1000))
    {
        statusTimer = now;
        // Serial.print("["); Serial.print(frameCounter); Serial.println("]");
        frameCounter = 0;
        if (blink)
        {
            digitalWrite(LED_PIN, HIGH);
            blink = false;
        }
        else
        {
            digitalWrite(LED_PIN, LOW);
            blink = true;
        }

    }

	if (millis_passed >= modes[mode]->length_millis)
	{
		mode++;
		if (mode >= nModes)
			mode = 0;

        modes[mode]->start();
		millis_passed = 0;
		mode_timer = now;
        mode_starting = true;
	}

	// if we just started a frame, slowly ease in
	if (millis_passed <= transition_time)
	{
		if (mode_starting)
		{
            Serial.printf("starting: %s\n", modes[mode]->name());
			modes[mode]->frame();
			fade_timer = now;

			tmp_brightness = 0;
			brightnessManager.set(tmp_brightness++);

            for (int i = 0; i < nLETTERS; i++)
                letters[i].goOn();

			mode_starting = false;
		}

		if (now - fade_timer >= fade_delay && tmp_brightness < brightnessManager.brightness)
		{
			brightnessManager.set(tmp_brightness++);
			fade_timer = now;
		}
	}
	else if (modes[mode]->length_millis - millis_passed <= transition_time)
	{
        leds_dim(1);
	}
	else
	{
		brightnessManager.frame();
		modes[mode]->frame();
	}

	for (uint8_t i = 0; i < OFF_LENGTH; i++)
	{
		leds[off[i]] = CRGB::Black;
	}

	led_show();
}
