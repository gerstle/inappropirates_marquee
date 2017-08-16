#include "modes.h"

ColorMode redMode = ColorMode(10000, "red", CHSV(0, 255, 255), 150);
ColorMode purpleMode = ColorMode(10000, "purple", CHSV(192, 255, 255), 125);

BaseMode *modes[nModes] = {
		&redMode,
		&purpleMode
};


