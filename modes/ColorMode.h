#ifndef COLORMODE_H_
#define COLORMODE_H_

#include "BaseMode.h"
#include "../letters.h"

#define nOFF_LETTERS 3

class ColorMode: public BaseMode {
public:
    ColorMode(unsigned long l, const char *name, CHSV color, long delay);
    virtual ~ColorMode();

public:
    void frame();

private:
    CHSV _color;
    unsigned long _lastChange;
    long _delay;
    Letter *offLetters[nOFF_LETTERS];
};

#endif /* COLORMODE_H_ */
