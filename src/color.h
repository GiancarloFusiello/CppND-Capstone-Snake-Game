#ifndef COLOR_H
#define COLOR_H

#include "SDL_stdinc.h"


struct Color {
    Uint8 red_channel_value;
    Uint8 green_channel_value;
    Uint8 blue_channel_value;
    Uint8 alpha_channel_value;
};

namespace Colors {
    constexpr Color charcoal{0x1E, 0x1E, 0x1E, 0xFF};
    constexpr Color white{0xFF, 0xFF, 0xFF, 0xFF};
    constexpr Color yellow{0xFF, 0xCC, 0x00, 0xFF};
    constexpr Color cyan{0x2F, 0xF3, 0xE0, 0xFF};
    constexpr Color blue{0x00, 0x7A, 0xCC, 0xFF};
    constexpr Color red{0xFF, 0x00, 0x00, 0xFF};
}

#endif
