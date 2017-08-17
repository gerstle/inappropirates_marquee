#include "modes.h"
#include "modes/ColorMode.h"
#include "modes/WordMode.h"

unsigned long mode_time = 20000;
// unsigned long mode_time = 1200000; // 20 minutes

ColorMode whiteMode = ColorMode(mode_time, "white-ish", CHSV(35, 170, 255), 150);
ColorMode redMode = ColorMode(mode_time, "red", CHSV(0, 255, 255), 125);
// ColorMode blueMode = ColorMode(mode_time, "blue", CHSV(160, 255, 255), 125);

bool pirateFlags[nLETTERS] = {0, 0, 0, 0, 1};
WordMode pirateMode = WordMode(mode_time, "pirate", CHSV(35, 170, 255), pirateFlags);
bool iAteFlags[nLETTERS] = {1, 0, 0, 0, 0};
WordMode iAteMode = WordMode(mode_time, "i ate", CHSV(192, 170, 255), iAteFlags);


BaseMode *modes[nModes] = { &iAteMode, &whiteMode, &pirateMode, &redMode };
