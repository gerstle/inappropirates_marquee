#include "modes.h"
#include "modes/ColorMode.h"
#include "modes/WordMode.h"
#include "modes/RainbowMode.h"

unsigned long ten_s = 10000;
unsigned long five_m = 300000;
unsigned long ten_m = 600000;
unsigned long fiften_m = 900000;
unsigned long twenty_m = 1200000;
unsigned long mode_time = ten_s;

unsigned long color_time = ten_m;
unsigned long word_time = five_m;

CHSV white = CHSV(35, 170,255);
CHSV red = CHSV(0, 255, 255);
ColorMode whiteM = ColorMode(color_time, "white-ish", white, 125);
ColorMode redM = ColorMode(color_time, "red", red, 125);
RainbowMode rainbowM = RainbowMode(color_time, 125);

//                              I  N  A  P  P  R  O  P  I  R  A  T  E  S
bool pirateFlags[nLETTERS] =   {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0};
bool iAteFlags[nLETTERS] =     {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0};
bool iAPirateFlags[nLETTERS] = {1, 0, 1, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0};
bool piratesFlags[nLETTERS] =  {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1};
bool ratsFlags[nLETTERS] =     {0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 1};
bool napFlags[nLETTERS] =      {0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
bool pitsFlags[nLETTERS] =     {0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 1, 0, 1};
bool irateFlags[nLETTERS] =    {0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0};
bool pieFlags[nLETTERS] =      {0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 1, 0};
bool popFlags[nLETTERS] =      {0, 0, 0, 0, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0};
bool ropeFlags[nLETTERS] =     {0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 1, 0};
bool inappropFlags[nLETTERS] = {1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0};

WordMode pirateM = WordMode(word_time, "pirate", red, pirateFlags);
WordMode iAteM = WordMode(word_time, "i ate", white, iAteFlags);
WordMode iAPirateM = WordMode(word_time, "i a pirate", red, iAPirateFlags);
WordMode piratesM = WordMode(word_time, "pirates", red, piratesFlags);
WordMode ratsM = WordMode(word_time, "rats", red, ratsFlags);
WordMode napM = WordMode(word_time, "nap", white, napFlags);
WordMode pitsM = WordMode(word_time, "pits", white, pitsFlags);
WordMode irateM = WordMode(word_time, "irate", red, irateFlags);
WordMode pieM = WordMode(word_time, "pie", white, pieFlags);
WordMode popM = WordMode(word_time, "pop", red, popFlags);
WordMode ropeM = WordMode(word_time, "rope", red, ropeFlags);
WordMode inappropM = WordMode(word_time, "inapprop", red, ropeFlags);

BaseMode *modes[nModes] = {
		&redM, &pirateM,
		&whiteM, &iAteM,
		&redM, &ratsM,
		&rainbowM, &inappropM,
		&redM, &napM,
		&redM, &piratesM,
		&whiteM, &pitsM,
		&redM, &irateM,
		&rainbowM, &inappropM,
		&redM, &pieM,
		&whiteM, &popM,
		&redM, &ropeM
};
