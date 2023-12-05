#ifndef COLOR_H
#define COLOR_H

#include <cmath>
#include <cstdint>

class Color {
public:
    Color(uint32_t colorVal) : colorVal(colorVal) {}
    Color() : colorVal(0) {} // Default constructor

    uint32_t getColor();
    void setColor(uint32_t colorVal);
    void multiplyBrightness(double factor);

private:
    uint32_t colorVal;
};

#endif