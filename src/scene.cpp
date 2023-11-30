#include "scene.h"
#include "sphere.h"
#include <cmath> // For sin and M_PI

void drawScene(std::vector<Sphere> sceneData, PixelBuffer& pixelBuffer, int width, int height, unsigned long frameCount) {
    // Parameters for the sine wave
    float amplitude = height / 4; // Height of the wave
    float frequency = 0.05; // Frequency of the wave
    float phaseShift = frameCount * 0.05; // Phase shift based on frame count

    // Draw the sine wave
    for (int x = 0; x < width; x++) {
        int y = static_cast<int>(height / 2 + amplitude * std::sin(frequency * x + phaseShift));
        if (y >= 0 && y < height) {
            for (int i = -1; i < 2; i++) {
                for (int j = -1; j < 2; j++) {
                    pixelBuffer.setPixel(x + i, y + j, 0xFF0000FF); // Red color
                }
            }
        }
    }
}
