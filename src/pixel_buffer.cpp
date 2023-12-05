#include "pixel_buffer.h"
#include <cstring> // For memset
#include <cstdint>

PixelBuffer::PixelBuffer(int width, int height) : width(width), height(height) {
    pixelData = new Uint32[width * height];
}

PixelBuffer::~PixelBuffer() {
    delete[] pixelData;
}

void PixelBuffer::setPixel(int x, int y, Color color) {
    if (x >= 0 && x < width && y >= 0 && y < height) {
        pixelData[y * width + x] = color.getColor();
    }
}

Uint32 PixelBuffer::getPixel(int x, int y) const {
    if (x >= 0 && x < width && y >= 0 && y < height) {
        return pixelData[y * width + x];
    }
    return 0;
}

Uint32* PixelBuffer::getPixelData() const {
    return pixelData;
}

int PixelBuffer::getWidth() const {
    return width;
}

int PixelBuffer::getHeight() const {
    return height;
}

void PixelBuffer::clear(Uint32 clearColor) {
    memset(pixelData, clearColor, width * height * sizeof(Uint32));
}
