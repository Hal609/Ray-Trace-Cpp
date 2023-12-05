#ifndef COLOR_H
#define COLOR_H

#include <cmath>
#include <cstdint>

class Color {
public:
    Color(uint32_t colorVal) : colorVal(colorVal) {}
    Color() : colorVal(0) {} // Default constructor

    uint32_t getColorVal();
    void setColor(uint32_t colorVal);
    void multiplyBrightness(double factor);
    
    inline bool operator==(const Color& other) const {
        return colorVal == other.colorVal;
    }

    inline bool operator!=(const Color& other) const {
        return !(*this == other);
    }

private:
    uint32_t colorVal;
};

#endif