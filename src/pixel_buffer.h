#ifndef PIXELBUFFER_H
#define PIXELBUFFER_H

#include <SDL2/SDL.h>
#include <color.h>

class PixelBuffer {
private:
    int width, height;
    Uint32* pixelData;

public:
    PixelBuffer(int width, int height);
    ~PixelBuffer();

    void setPixel(int x, int y, Color color);
    Uint32 getPixel(int x, int y) const;
    Uint32* getPixelData() const;

    int getWidth() const;
    int getHeight() const;

    void clear(Uint32 clearColor = 0xFF000000);
};

#endif // PIXELBUFFER_H
