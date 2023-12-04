#include <SDL2/SDL.h>
#include "sdl_manager.h"
#include "config.h"
#include "sphere.h"
#include <vector>

int main() {
    // Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        // Handle error
        return 1;
    }

    // Create SDL window
    SDL_Window* window = SDL_CreateWindow("Title", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, 0);
    if (!window) {
        // Handle error
        SDL_Quit();
        return 1;
    }

    // Create SDL renderer
    SDL_Renderer* sdlRenderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!sdlRenderer) {
        // Handle error
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }

    // Create the SDL Manager object
    SDLManager SDL_Manager(WIDTH, HEIGHT, sdlRenderer);

    bool quit = false;
    SDL_Event event;

    std::vector<Sphere> sceneData = loadSpheresFromFile("sceneData.txt");
    printf("Loaded %lu spheres from file.\n", sceneData.size());
    
    // Main loop
    while (!quit) {
        // Event handling
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                quit = true;
            }
        }
        // Update and render the scene
        SDL_Manager.renderNextFrame(sceneData);
    }

    // Clean up
    SDL_DestroyRenderer(sdlRenderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
