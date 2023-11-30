#ifndef RENDERER_H
#define RENDERER_H

#include "pixel_buffer.h"
#include <SDL2/SDL.h>

class Renderer {
public:
    Renderer(int width, int height, SDL_Renderer* sdlRenderer);
    ~Renderer();
    
    void drawScene(); // Method to draw your scene, which eventually calls updateTextureFromPixelBuffer
    void updateTextureFromPixelBuffer();
    void clearBackBuffer();
    unsigned long getFrameCount() const;

private:
    SDL_Renderer* sdlRenderer;
    SDL_Texture* backBufferTexture; // Texture for the back buffer
    SDL_Texture* frontBufferTexture; // Texture for the front buffer (new)
    PixelBuffer pixelBuffer;
    int width, height;
    unsigned long frameCount;
};

#endif // RENDERER_H
