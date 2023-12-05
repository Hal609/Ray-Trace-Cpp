#define SDL_MAIN_HANDLED
#include <SDL2/SDL.h>
#include "sdl_manager.h"
#include "config.h"
#include "sphere.h"
#include <vector>

#include <iostream>
#include <chrono>



int main() {
    std::chrono::steady_clock::time_point startTime = std::chrono::steady_clock::now();

    // Create SDL window
    SDL_Window* window = SDL_CreateWindow("Title", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, SDL_WINDOW_ALLOW_HIGHDPI);
    SDL_Renderer* sdlRenderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    if (!sdlRenderer || !window) {
        // Handle error
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }

    // Create the SDL Manager object
    int drawableWidth, drawableHeight;
    SDL_GetRendererOutputSize(sdlRenderer, &drawableWidth, &drawableHeight);
    SDLManager SDL_Manager(drawableWidth, drawableHeight, sdlRenderer);

    bool quit = false;
    SDL_Event event;

    // Load scene data from file
    std::vector<Sphere> sphereData = loadSpheresFromFile("sceneData.txt");
    printf("Loaded %lu spheres from file.\n", sphereData.size());

    // Main loop
    while (!quit) {
        // Event handling
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                quit = true;
            }
        }

        // Calculate frame time
        std::chrono::steady_clock::time_point endTime = std::chrono::steady_clock::now();
        std::chrono::duration<double> frameDuration = std::chrono::duration_cast<std::chrono::duration<double>>(endTime - startTime);
        startTime = endTime; // Reset the start time for the next frame

        // Update and render the scene
        SDL_Manager.renderNextFrame(sphereData);

        double frameRate = 1 / frameDuration.count();
        std::cout << "Frame Rate: " << frameRate << " FPS" << std::endl;

    }

    // Clean up
    SDL_DestroyRenderer(sdlRenderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
