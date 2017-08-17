#ifndef MODES_WORDMODE_H_
#define MODES_WORDMODE_H_

#include "BaseMode.h"
#include "../letters.h"

class WordMode: public BaseMode {
public:
    WordMode(unsigned long l, const char *n, CHSV c, const bool *f);
    virtual ~WordMode();

public:
    void start();
    void frame();

private:
    const bool *_flags;
    CHSV _color;
};

#endif /* MODES_WORDMODE_H_ */
