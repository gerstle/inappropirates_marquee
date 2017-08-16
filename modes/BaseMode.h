#ifndef UTIL_BASEMODE_H_
#define UTIL_BASEMODE_H_

#include "../leds.h"

class BaseMode {
public:
	BaseMode();
	virtual ~BaseMode();

	virtual void start();
	virtual void frame();
    virtual const char* name();
    unsigned long length_millis = 5000;

protected:
    bool verbose = false;
    const char* _name;
};

#endif /* UTIL_BASEMODE_H_ */
