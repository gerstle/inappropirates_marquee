#include "modes.h"
#include "modes/ColorMode.h"
#include "modes/WordMode.h"
#include "modes/RainbowMode.h"

unsigned long ten_s = 10000;
unsigned long twenty_s = 20000;
unsigned long one_m = 60000;
unsigned long two_m = 120000;
unsigned long five_m = 300000;
unsigned long ten_m = 600000;
unsigned long fiften_m = 900000;
unsigned long twenty_m = 1200000;
unsigned long mode_time = ten_s;

// use these for realz
unsigned long color_time = two_m;
unsigned long word_time = five_m;

// good for debugging/checking
// unsigned long color_time = ten_s;
// unsigned long word_time = twenty_s;

CHSV white = CHSV(35, 170,255);
CHSV red = CHSV(0, 255, 255);
CHSV purple = CHSV(192, 255, 255);

ColorMode whiteM = ColorMode(color_time, "white-ish", white, 125);
ColorMode redM = ColorMode(color_time, "red", red, 125);
ColorMode purpleM = ColorMode(color_time, "purple", purple, 125);
RainbowMode rainbowM = RainbowMode(color_time, 125);

//                              -  I  N  A  P  P  R  O  P  I  R  A  T  E  S  -
bool pirateFlags[nLETTERS] =   {1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 1};
bool iAteFlags[nLETTERS] =     {1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 1};
bool iAPirateFlags[nLETTERS] = {1, 1, 0, 1, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 1};
bool piratesFlags[nLETTERS] =  {1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1};
bool ratsFlags[nLETTERS] =     {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 1, 1};
bool napFlags[nLETTERS] =      {1, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1};
bool pitsFlags[nLETTERS] =     {1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 1, 0, 1, 1};
bool irateFlags[nLETTERS] =    {1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 1};
bool pieFlags[nLETTERS] =      {1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 1, 0, 1};
bool popFlags[nLETTERS] =      {1, 0, 0, 0, 0, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1};
bool ropeFlags[nLETTERS] =     {1, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 1, 0, 1};
bool inappropFlags[nLETTERS] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1};

bool test[nLETTERS] =          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
WordMode testM = WordMode(word_time, "test", red, test);

WordMode pirateM = WordMode(word_time, "pirate", red, pirateFlags);
WordMode iAteM = WordMode(word_time, "i ate", red, iAteFlags);
WordMode iAPirateM = WordMode(word_time, "i a pirate", red, iAPirateFlags);
WordMode piratesM = WordMode(word_time, "pirates", red, piratesFlags);
WordMode ratsM = WordMode(word_time, "rats", red, ratsFlags);
WordMode napM = WordMode(word_time, "nap", red, napFlags);
WordMode pitsM = WordMode(word_time, "pits", red, pitsFlags);
WordMode irateM = WordMode(word_time, "irate", red, irateFlags);
WordMode pieM = WordMode(word_time, "pie", red, pieFlags);
WordMode popM = WordMode(word_time, "pop", red, popFlags);
WordMode ropeM = WordMode(word_time, "rope", purple, ropeFlags);
WordMode inappropM = WordMode(word_time, "inapprop", red, inappropFlags);

BaseMode *modes[nModes] = {
	&redM, &pirateM,
	&redM, &iAteM,
	&redM, &ratsM,
	&rainbowM, &inappropM,
	&redM, &napM,
	&purpleM, &piratesM,
	&redM, &pitsM,
	&redM, &irateM,
	&rainbowM, &inappropM,
	&redM, &pieM,
	&redM, &popM,
	&redM, &ropeM
};

// inapproparty
// BaseMode *modes[nModes] = {
// 	&purpleM,
// 	&rainbowM,
// 	&redM,
// 	&rainbowM,
// };
