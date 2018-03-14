#ifndef MODES_RAINBOWMODE_H_
#define MODES_RAINBOWMODE_H_

#include "BaseMode.h"
#include "../letters.h"

class RainbowMode: public BaseMode {
public:
	RainbowMode(unsigned long l, long d);
	virtual ~RainbowMode();

public:
    void frame();

private:
    unsigned long _lastChange;
    long _delay;
};

#endif /* MODES_RAINBOWMODE_H_ */
