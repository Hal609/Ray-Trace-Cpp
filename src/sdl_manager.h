#ifndef SDLMANAGER_H
#define SDLMANAGER_H

#include "renderer.h"
#include "sphere.h"
#include <vector>
#include <SDL2/SDL.h>

class SDLManager {
public:
    SDLManager(int width, int height, SDL_Renderer* sdlRenderer);
    ~SDLManager();
    
    void renderNextFrame(std::vector<Sphere> sceneData);
    unsigned long getFrameCount() const;

private:
    SDL_Renderer* sdlRenderer;
    SDL_Texture* backBufferTexture;
    SDL_Texture* frontBufferTexture;
    PixelBuffer pixelBuffer;
    int width, height;
    unsigned long frameCount = 0;

    void updateTextureFromPixelBuffer();
};

#endif // SDLMANAGER_H
