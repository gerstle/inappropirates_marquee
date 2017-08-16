#ifndef COLORMODE_H_
#define COLORMODE_H_

#include "BaseMode.h"

class ColorMode: public BaseMode {
public:
    ColorMode(long l, const char *name, CHSV color, long delay);
    virtual ~ColorMode();

public:
    void frame();

private:
    CHSV _color;
    unsigned long _lastChange;
    long _delay;
};

#endif /* COLORMODE_H_ */
