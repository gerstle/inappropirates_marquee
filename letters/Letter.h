#ifndef LETTER_H_
#define LETTER_H_

#include "../leds.h"

class Letter {
public:
    Letter(int index, int length, char const *letter);
    virtual ~Letter();
    void offFrame(unsigned long now);
    void goOffQuickly(unsigned long t, uint8_t h, uint8_t s);
    void goOff(unsigned long t, uint8_t h, uint8_t s);
    void goOn();
    void setColor(CHSV color);

    int index;
    int length;
    char const *letter;

    unsigned long offStart;
    unsigned long offTime;

private:
    void calcValue();

    uint8_t _hue;
    uint8_t _sat;
    uint8_t _val;
    float _offCounter;
    float _counterIncrement;
};

#endif /* LETTER_H_ */
