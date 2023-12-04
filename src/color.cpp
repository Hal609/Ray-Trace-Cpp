#include "color.h"

void Color::setColor(u_int32_t colorVal){
    this->colorVal = colorVal;
}

u_int32_t Color::getColor(){
    return this->colorVal;
}

void Color::multiplyBrightness(double factor){
    u_int32_t r = (this->colorVal & 0xff0000) >> 16;
    u_int32_t g = (this->colorVal & 0x00ff00) >> 8;
    u_int32_t b = (this->colorVal & 0x0000ff);

    r = static_cast<u_int32_t>(std::min(255.0, r * factor));
    g = static_cast<u_int32_t>(std::min(255.0, g * factor));
    b = static_cast<u_int32_t>(std::min(255.0, b * factor));

    this->colorVal = (r << 16) + (g << 8) + b;
}