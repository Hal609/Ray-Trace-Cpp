#include "sdl_manager.h"
#include <SDL2/SDL.h>
#include <iostream>

SDLManager::SDLManager() : window(nullptr), renderer(nullptr), frontBufferTexture(nullptr), backBufferTexture(nullptr), windowWidth(800), windowHeight(600) {
    // Constructor code if needed
}

SDLManager::~SDLManager() {
    // Cleanup textures and renderer
    if (frontBufferTexture) {
        SDL_DestroyTexture(frontBufferTexture);
    }
    if (backBufferTexture) {
        SDL_DestroyTexture(backBufferTexture);
    }
    if (renderer) {
        SDL_DestroyRenderer(renderer);
    }
    if (window) {
        SDL_DestroyWindow(window);
    }
    SDL_Quit();
}

bool SDLManager::init() {
    // Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        std::cerr << "Failed to initialize SDL: " << SDL_GetError() << std::endl;
        return false;
    }

    // Create SDL window
    window = SDL_CreateWindow("SDL Window", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, windowWidth, windowHeight, SDL_WINDOW_SHOWN);
    if (window == nullptr) {
        std::cerr << "Failed to create SDL window: " << SDL_GetError() << std::endl;
        SDL_Quit();
        return false;
    }

    return createRenderer() && createDoubleBufferTextures();
}

bool SDLManager::createRenderer() {
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (renderer == nullptr) {
        std::cerr << "Failed to create SDL renderer: " << SDL_GetError() << std::endl;
        return false;
    }
    return true;
}

bool SDLManager::createDoubleBufferTextures() {
    frontBufferTexture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, windowWidth, windowHeight);
    if (frontBufferTexture == nullptr) {
        std::cerr << "Failed to create front buffer texture: " << SDL_GetError() << std::endl;
        return false;
    }

    backBufferTexture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, windowWidth, windowHeight);
    if (backBufferTexture == nullptr) {
        std::cerr << "Failed to create back buffer texture: " << SDL_GetError() << std::endl;
        SDL_DestroyTexture(frontBufferTexture);
        return false;
    }

    return true;
}

bool SDLManager::processEvents() {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) {
            return true; // Indicates it's time to quit
        }
        // Handle other events if necessary
    }
    return false;
}

SDL_Window* SDLManager::getWindow() const {
    return window;
}

SDL_Texture* SDLManager::getFrontBufferTexture() const {
    return frontBufferTexture;
}

SDL_Texture* SDLManager::getBackBufferTexture() const {
    return backBufferTexture;
}
