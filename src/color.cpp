#include "color.h"
#include <cstdint>

void Color::setColor(uint32_t colorVal){
    this->colorVal = colorVal;
}

uint32_t Color::getColor(){
    return this->colorVal;
}

void Color::multiplyBrightness(double factor){
    uint32_t r = (this->colorVal & 0xff0000) >> 16;
    uint32_t g = (this->colorVal & 0x00ff00) >> 8;
    uint32_t b = (this->colorVal & 0x0000ff);

    r = static_cast<uint32_t>(std::min(255.0, r * factor));
    g = static_cast<uint32_t>(std::min(255.0, g * factor));
    b = static_cast<uint32_t>(std::min(255.0, b * factor));

    this->colorVal = (r << 16) + (g << 8) + b;
}