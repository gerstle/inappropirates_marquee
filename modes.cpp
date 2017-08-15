#include "modes.h"

ColorMode redMode = ColorMode("red", CHSV(0, 255, 255), 150);
ColorMode purpleMode = ColorMode("purple", CHSV(192, 255, 255), 125);

BaseMode *modes[nModes] = {
		&redMode,
		&purpleMode
};


