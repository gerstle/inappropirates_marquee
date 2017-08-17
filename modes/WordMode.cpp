#include "WordMode.h"
#include <limits.h>

WordMode::WordMode(unsigned long l, const char *n, CHSV c, const bool *f) {
    length_millis = l;
    _name = n;
    _color = c;
    _flags = f;

}

WordMode::~WordMode() {
}

void WordMode::start() {
    for (int i = 0; i < nLETTERS; i++)
        if (!_flags[i])
        {
            letters[i].goOffQuickly(86400000, _color.h, _color.s); // 86400000ms == 1 day
        }
}

void WordMode::frame() {
    for (int i = 0; i < nLETTERS; i++)
    {
        if (_flags[i])
            letters[i].setColor(_color);
        else
            letters[i].offFrame(millis());
    }
}

