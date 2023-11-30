#include "scene.h"
#include "sphere.h"
#include <cmath> // For sin and M_PI

void drawScene(std::vector<Sphere> sceneData, PixelBuffer& pixelBuffer, int width, int height, unsigned long frameCount) {
    // Parameters for the sine wave
    float amplitude = height / 4; // Height of the wave
    float frequency = 0.05; // Frequency of the wave
    float phaseShift = frameCount * 0.05; // Phase shift based on frame count

    printf("Drawing scene with %lu spheres\n", sceneData.size());
    // Draw the sine wave
    for (int x = 0; x < width; x++) {
        int y = static_cast<int>(height / 2 + amplitude * std::sin(frequency * x + phaseShift));
        if (y >= 0 && y < height) {
            for (int i = 0; i < 5; i++)
            pixelBuffer.setPixel(x, y + i, 0xFF0000FF); // Red color
        }
    }
}
