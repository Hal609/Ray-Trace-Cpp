#ifndef COLOR_H
#define COLOR_H

#include <cmath>

class Color {
public:
    Color(u_int32_t colorVal) : colorVal(colorVal) {}
    Color() : colorVal(0) {} // Default constructor

    u_int32_t getColor();
    void setColor(u_int32_t colorVal);
    void multiplyBrightness(double factor);

private:
    u_int32_t colorVal;
};

#endif