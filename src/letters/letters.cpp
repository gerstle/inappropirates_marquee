#include "letters.h"

Letter letters[nLETTERS] = {
        //    index start, length, name
        // -- first string, indexes are reversed
        Letter(98, 50, "-"),
        Letter(85, 13, "i"),
        Letter(64, 19, "n"),
        Letter(51, 12, "a"),
        Letter(35, 14, "p"),
        Letter(21, 13, "p"),
        Letter(12, 7, "r"),
        Letter(0, 11, "o"),
        // -- second string, normal
        Letter(148, 14, "p"), // 14 + 2 = 16
        Letter(164, 10, "i"), // 10 + 0 = 10
        Letter(174, 9, "r"),  // 9  + 1 = 10 -> 3 & 4 are dead?
        Letter(184, 12, "a"), // 12 + 1 = 13
        Letter(197, 15, "t"), // 15 + 2 = 17
        Letter(214, 12, "e"), // 12 + 2 = 14
        Letter(228, 13, "s"), // 13 + 0 = 13
        Letter(241, 50, "-")
        // party
        // Letter(148, 14, "p"),
        // Letter(164, 12, "a"),
        // Letter(178, 10, "r"),
        // Letter(189, 13, "t"),
        // Letter(203, 18, "y"),
        // Letter(225, 10, "!"),
        // Letter(235, 6, "-"),
        // Letter(241, 50, "-")
};
