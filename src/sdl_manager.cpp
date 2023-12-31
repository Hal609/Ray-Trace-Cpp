#include "sdl_manager.h"
#include <iostream>
#include <cstdint>

SDLManager::SDLManager(int width, int height, SDL_Renderer* sdlRenderer)
    : sdlRenderer(sdlRenderer), pixelBuffer(width, height), width(width), height(height) {
    
    int drawableWidth, drawableHeight;
    SDL_GetRendererOutputSize(sdlRenderer, &drawableWidth, &drawableHeight);

    // Create the back buffer texture
    backBufferTexture = SDL_CreateTexture(sdlRenderer, SDL_PIXELFORMAT_ARGB8888, SDL_TEXTUREACCESS_STREAMING, drawableWidth, drawableHeight);
    if (!backBufferTexture) {
        std::cerr << "Failed to create back buffer texture: " << SDL_GetError() << std::endl;
        // Handle error (perhaps throw an exception or set an error flag)
    }

    // Create the front buffer texture
    frontBufferTexture = SDL_CreateTexture(sdlRenderer, SDL_PIXELFORMAT_ARGB8888, SDL_TEXTUREACCESS_TARGET, drawableWidth, drawableHeight);
    if (!frontBufferTexture) {
        std::cerr << "Failed to create front buffer texture: " << SDL_GetError() << std::endl;
        // Handle error (perhaps throw an exception or set an error flag)
    }
}

SDLManager::~SDLManager() {
    if (backBufferTexture) {
        SDL_DestroyTexture(backBufferTexture);
    }
    if (frontBufferTexture) {
        SDL_DestroyTexture(frontBufferTexture);
    }
    // Note: sdlRenderer is managed elsewhere and should not be destroyed here
}

void SDLManager::renderNextFrame(std::vector<Sphere> sphereData) {
    this->pixelBuffer.clear();
    renderScene(sphereData, this->pixelBuffer, this->width, this->height, this->frameCount);
    updateTextureFromPixelBuffer();
}

void SDLManager::updateTextureFromPixelBuffer() {
    // Check if textures are valid
    if (!backBufferTexture || !frontBufferTexture) {
        std::cerr << "Texture not initialized properly." << std::endl;
        return;
    }

    // Update the entire back buffer texture
    SDL_UpdateTexture(backBufferTexture, NULL, pixelBuffer.getPixelData(), this->width * sizeof(Uint32));

    // Copy the back buffer to the front buffer
    SDL_SetRenderTarget(sdlRenderer, frontBufferTexture);
    SDL_RenderCopy(sdlRenderer, backBufferTexture, NULL, NULL);

    // Reset the render target to the default (screen)
    SDL_SetRenderTarget(sdlRenderer, NULL);

    // Render the front buffer to the screen
    SDL_RenderCopy(sdlRenderer, frontBufferTexture, NULL, NULL);
    SDL_RenderPresent(sdlRenderer);

    this->frameCount++;
}

unsigned long SDLManager::getFrameCount() const {
    return frameCount;
}
