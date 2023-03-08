#pragma once
#include <cstdint>

namespace escript {
class Color {
private:
    uint8_t redValue, greenValue, blueValue, alphaValue;
public:
    Color(uint8_t red, uint8_t green, uint8_t blue);
    Color(uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha);
    static Color interpolate(const Color& start, const Color& stop, double fraction);
    uint8_t red() const;
    uint8_t green() const;
    uint8_t blue() const;
    uint8_t alpha() const;
};
};