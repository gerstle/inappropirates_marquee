#include "modes.h"

unsigned long mode_time = 3000000;
// unsigned long mode_time = 1200000; // 20 minutes

ColorMode redMode = ColorMode(mode_time, "white-ish", CHSV(35, 170, 255), 150);
ColorMode purpleMode = ColorMode(mode_time, "red", CHSV(0, 255, 255), 125);

BaseMode *modes[nModes] = { &redMode, &purpleMode };
