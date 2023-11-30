#ifndef SDL_MANAGER_H
#define SDL_MANAGER_H

#include <SDL2/SDL.h>
class SDLManager {
public:
    SDLManager();
    ~SDLManager();

    bool init();
    bool processEvents();
    SDL_Window* getWindow() const;
    bool createRenderer();
    bool createDoubleBufferTextures();

    SDL_Texture* getFrontBufferTexture() const;
    SDL_Texture* getBackBufferTexture() const;

private:
    SDL_Window* window;
    SDL_Renderer* renderer;
    SDL_Texture* frontBufferTexture;
    SDL_Texture* backBufferTexture;
    int windowWidth;
    int windowHeight;
};

#endif // SDL_MANAGER_H
